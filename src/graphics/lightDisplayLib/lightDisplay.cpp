#include "lightDisplay.h"
#include "Arduino.h"


#define wireClk 400e3
#define restoreClk 100e3
#define TRANSACTION_START wire->setClock(wireClk)    ///< Set before I2C transfer
#define TRANSACTION_END wire->setClock(restoreClk) ///< Restore after I2C xfer


//CONSTRUCTOR
lightDisplay::lightDisplay(uint8_t w, uint8_t h, TwoWire *twi)
:  buffer(NULL),wire(twi ? twi : &Wire),width(w),height(h)
{
}
//DECONSTRUCTOR
lightDisplay::~lightDisplay(){
      if (buffer) {
    free(buffer);
    buffer = NULL;
  }
}

//SEND SINGLE COMMAND BYTES
void lightDisplay::sendCommand(uint8_t command){
    wire->beginTransmission(I2Caddr);
    wire->write((uint8_t)0X00); // Co=0 , D/C = 0
    wire->write((uint8_t)command);
    wire->endTransmission();
}

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

/*!
    @brief allocate memory for buffer and initiate screen with settings 
    @param vcc Power source for the screen affects choice for contrast
    @param address I2C address 
    @param periphBegin affects if we are going to initialize a peripheral or not Default true
*/
bool lightDisplay::begin(uint8_t vcc,uint8_t address,bool periphBegin){
    uint8_t contrast;
    uint8_t comPins = 18; 
  if ((!buffer) && !(buffer = (uint8_t *)malloc(width * ((height + 7) / 8))))return false;
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


for(int j = 0; j<8 ;j++){
    sendCommand(0 & 0b0001111);
    sendCommand( ((0>>4) & 0b00001111) | (0x10));
    sendCommand(0xB0 | j);
    wire->beginTransmission(I2Caddr);                                      
    wire->write(0x40);
    uint8_t b = 1;
for(int i = 0; i<128 ;i++){
    if(b >= 32){
    wire->endTransmission();
    wire->beginTransmission(I2Caddr);                                      
    wire->write(0x40);b = 1;}
    b++;
    if(i%3){wire->write(0);}else{wire->write(0b01111110);}
}
wire->endTransmission();
}

    TRANSACTION_END;
    return true;
}


void lightDisplay::drawPixel(uint8_t COORDX,uint8_t COORDY,uint8_t COLOR){
}



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

void lightDisplay::drawLine(uint8_t COORDX,uint8_t COORDY,uint8_t ENDX,uint8_t ENDY,uint8_t COLOR){
uint8_t startPage,endPage;
uint8_t YSTART = COORDY,YEND = ENDY;
if(YSTART > YEND){startPage = ENDY/8;endPage = COORDY/8;YSTART = ENDY;YEND = COORDY;}
// Default current Page is equal start Page YSTART is as is and YEND 
if((currentPage >= startPage) || (currentPage <= endPage)){//SINCE this a middle page
    YSTART = currentPage*8;YEND = currentPage*8 + 7;
}
else if(currentPage == endPage){//HERE WE set the YSTART the start of our end Page and YEND remains the ENDY
    YSTART = currentPage*8;
}
// YSTART and YEND all set for the CURRENT PAGE WE ARE POINTING TO




}
