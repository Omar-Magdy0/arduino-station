#include "lightDisplay.h"
#include "Arduino.h"


#define wireClk 400e3
#define restoreClk 100e3
#define TRANSACTION_START wire->setClock(wireClk)    ///< Set before I2C transfer
#define TRANSACTION_END wire->setClock(restoreClk) ///< Restore after I2C xfer

/******************************************************************************/
//CONSTRUCTOR
lightDisplay::lightDisplay(uint8_t w, uint8_t h, TwoWire *twi)
:  buffer(NULL),wire(twi ? twi : &Wire),width(w),height(h)
{
}

/******************************************************************************/
//DECONSTRUCTOR
lightDisplay::~lightDisplay(){
      if (buffer) {
    free(buffer);
    buffer = NULL;
  }
}

/******************************************************************************/
//SEND SINGLE COMMAND BYTES
void lightDisplay::sendCommand(uint8_t command){
    wire->beginTransmission(I2Caddr);
    wire->write((uint8_t)0X00); // Co=0 , D/C = 0
    wire->write((uint8_t)command);
    wire->endTransmission();
}

/******************************************************************************/
//SEND ARRAYS OF COMMAND BYTES
void lightDisplay::sendCommandList(const uint8_t *command, uint8_t n){
    wire->beginTransmission(I2Caddr);
    wire->write((uint8_t)0x00); // Co = 0, D/C = 0
    uint16_t bytesOut = 1;
    while (n--) {
        if (bytesOut >= WIRE_MAX) {
            wire->endTransmission();
            wire->beginTransmission(I2Caddr);
            wire->write((uint8_t)0x00); // Co = 0, D/C = 0
            bytesOut = 1;
        }
    wire->write(pgm_read_byte(command++));
    bytesOut++;
    }
    wire->endTransmission();
}

/******************************************************************************/
/*!
    @brief allocate memory for buffer and initiate screen with settings 
    @param vcc Power source for the screen affects choice for contrast
    @param address I2C address 
    @param periphBegin affects if we are going to initialize a peripheral or not Default true
*/
bool lightDisplay::begin(uint8_t vcc,uint8_t address,bool periphBegin){
    uint8_t contrast;
    uint8_t comPins = 18; 
  if ((!buffer) && !(buffer = (uint8_t *)malloc(width * ((height) / 8))))return false;
    if(vcc == SSD1306_SWITCHCAPVCC){contrast = 0x7F;}
    if(periphBegin){wire->begin();}
    I2Caddr = address;

    TRANSACTION_START;
    sendCommand(SSD1306_SETCOMPINS);
    sendCommand(comPins);
    sendCommand(SSD1306_SETCONTRAST);
    sendCommand(contrast);
    sendCommand(SSD1306_SETPRECHARGE); // 0xd9
    sendCommand((vcc == SSD1306_EXTERNALVCC) ? 0x22 : 0xF1);
    static const uint8_t PROGMEM init1[] = {SSD1306_DISPLAYOFF,
                                            SSD1306_SETMULTIPLEX,
                                            0x3F,
                                            SSD1306_SETDISPLAYOFFSET,
                                            0x00};
    sendCommandList( init1 , sizeof(init1));
    static const uint8_t PROGMEM init2[] = {SSD1306_SETDISPLAYCLOCKDIV,
                                            0x80,
                                            SSD1306_MEMORYMODE,
                                            0x02,
                                            SSD1306_SEGREMAP | 0x1,
                                            SSD1306_COMSCANDEC};
    sendCommandList(init2, sizeof(init2));
    static const uint8_t PROGMEM init3[] = {SSD1306_SETSTARTLINE | 0x00,
                                            SSD1306_CHARGEPUMP,
                                            SSD1306_SETVCOMDETECT, 
                                            0x40,
                                            };
    sendCommandList(init3, sizeof(init3)); 
    static const uint8_t PROGMEM init4[] = {SSD1306_DISPLAYALLON_RESUME,
                                            SSD1306_NORMALDISPLAY,      
                                            SSD1306_DEACTIVATE_SCROLL,
                                            SSD1306_DISPLAYON
                                            };                                          
    sendCommandList(init4, sizeof(init4));  

    TRANSACTION_END;
    return true;
}

/******************************************************************************/

#ifdef __AVR__
// Bitmask tables of 0x80>>X and ~(0x80>>X), because X>>Y is slow on AVR
const uint8_t PROGMEM setBit[] = {0x01, 0x02, 0x04, 0x08,
                                 0x10, 0x20, 0x40, 0x80};
const uint8_t PROGMEM clrBit[] = {0xFE, 0xFD, 0xFB, 0xF7,
                                  0xEF, 0xDF, 0xBF, 0x7F};
#endif

/******************************************************************************/

void lightDisplay::drawPixel(uint8_t COORDX,uint8_t COORDY,uint8_t COLOR){
    uint8_t *ptr = &buffer[COORDX];
    if((COORDY / 8) != currentPage)return;
    else if((COORDX >= width)||(COORDY >= height)){
    return;
}
if((COORDY / 8) == this->currentPage){
#ifdef __AVR__
    if (COLOR){
        *ptr |= pgm_read_byte(&setBit[COORDY & 7]);}
    else
      *ptr &= pgm_read_byte(&clrBit[COORDY & 7]);
#else
    if (COLOR)
      *ptr |= 1 << (COORDY & 7);
    else
      *ptr &= ~(1 << (COORDY & 7));
#endif
}
}

/******************************************************************************/
/*!
    @brief THE WORKING PRINCIPLE IS AS FOLLOWS first we checK for the screen pages we gonna NEED
    THEN we check if current page we are pointing to is a page we will need to write and if yes
    we write accordingly and Set YStart and YEnd for the needed page
    @param COORDX X coordinate for the first point on line
    @param COORDY Y coordinate for the first point on line
    @param ENDX   X coordinate for the last point on line
    @param ENDY   Y coordinate for the last point on line
    @param COLOR  Color of the drawn line WHITE/BLACK supported
*/
void lightDisplay::drawLine(uint8_t X0,uint8_t Y0,uint8_t X1,uint8_t Y1,uint8_t COLOR){
    uint8_t steep = abs((Y1 - Y0)/(X1 - X0));
    if(steep){
        uint8_t t = X0;
        X0 = Y0; Y0 = t;
        t = X1;
        X1 = Y1; Y1 = t; 
    }
    if(X0 > X1){
        uint8_t t = X0;
        X0 = X1; X1 = t;
        t = Y0;
        Y0 = Y1; Y1 = Y0;
    }
    uint8_t dy = abs(Y1 - Y0);
    uint8_t dx = X1 - X0;
    int8_t err = dx/2;
    int8_t ystep;

    if (Y0 < Y1) {
        ystep = 1;
    } else {
        ystep = -1;
    }

    for (; X0 <= X1; X0++) {
        if (steep) {
            drawPixel(Y0, X0, COLOR);
        } else {
            drawPixel(X0, Y0, COLOR);
        }
    err -= dy;
        if (err < 0) {
            Y0 += ystep;
            err += dx;
        }
  }
}
/******************************************************************************/
void lightDisplay::pageSelect(uint8_t page){
this->currentPage = page;
}
/******************************************************************************/
void lightDisplay::pageDisplay(){
    uint8_t count = width;
    uint8_t *ptr = buffer;

    sendCommand(0 & 0b0001111);
    sendCommand( ((0>>4) & 0b00001111) | (0x10));
    sendCommand(0xB0 | currentPage);

    wire->beginTransmission(I2Caddr);
    wire->write((uint8_t)0x40); // Co = 0, D/C = 1
    uint16_t bytesOut = 1;
    while (count--) {
        if (bytesOut >= WIRE_MAX) {
            wire->endTransmission();
            wire->beginTransmission(I2Caddr);
            wire->write((uint8_t)0x40); // Co = 0, D/C = 1
            bytesOut = 1;
        }
        wire->write(*ptr++);
        bytesOut++;
    }
    wire->endTransmission();
}
/******************************************************************************/
void lightDisplay::clearPage(){
        for(uint8_t j = 0; j < width; j++){
            buffer[j] = 0;   
        }
}

/******************************************************************************/
void lightDisplay::wholeScreenClearDisplay(){
    for(uint8_t i = 0; i < NUMOFPAGES; i++){
        pageSelect(i);
        clearPage();
        pageDisplay();
        }
    }
/******************************************************************************/






