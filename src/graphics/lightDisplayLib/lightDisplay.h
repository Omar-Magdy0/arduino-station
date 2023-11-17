#ifndef LIGHTDISPLAY_H
#define LIGHTDISPLAY_H

#include <Wire.h>
#include "SSD1306.h"
// FUNCTIONS AND THE WHOLE LIBRARY IS WORKING WITH 128BYTE buffer allocated with the begin() method
// SUITABLE FOR LOW RAM SITUATIOONS
// THE IMPLEMENTATION AND GRAPHIC WORK AS FOLOWS YOU HAVE A ROW IN THE FORM YOU WANT THEN SEND
// THEN CHECK FOR THE NEXT ROW AND SEND WHERE ROW IS A PAGE(CHECK DATASHEET) 8BITS HEIGHT AND ROW WIDTH 128BYTE
// SO THINGS GO AS FOLLOWS YOU HAVE THE FIRST ROW READY THEN SEND THEN CHECK FOR NEXT ROW THEN READY AND SOO ON




#define WIRE_MAX 32
#define LIGHTDISPBLACK 0
#define LIGHTDISPWHITE 1

class lightDisplay{
private:


public:
lightDisplay(uint8_t w, uint8_t h, TwoWire *twi = &Wire);
~lightDisplay();
bool begin(uint8_t vcc = SSD1306_SWITCHCAPVCC,uint8_t address = 0x3C,bool periphBegin = true);
void display();
void drawPixel(uint8_t COORDX,uint8_t COORDY,uint8_t COLOR);
void drawLine(uint8_t COORDX,uint8_t COORDY,uint8_t ENDX,uint8_t ENDY,uint8_t COLOR);
void drawRext(uint8_t COORDX,uint8_t COORDY,uint8_t WIDTH,uint8_t HEIGHT,uint8_t COLOR);
void writeText(char *text,uint8_t cursor,uint8_t COLOR);
void drawBitMap(unsigned char *BITMAP,uint8_t COORDX,uint8_t COORDY,uint8_t WIDTH,uint8_t HEIGHT,uint8_t COLOR);


protected:
uint8_t *buffer;
TwoWire *wire;
uint8_t width;
uint8_t height;
uint8_t I2Caddr;
uint8_t currentPage;
void sendCommand(uint8_t command);
void sendCommandList(const uint8_t *command, uint8_t n);
};







#endif