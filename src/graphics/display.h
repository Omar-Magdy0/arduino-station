#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>


extern Adafruit_SSD1306 display;
void checkForScreen();
void MainMenuSelectRectangle();

struct textBox{
String text;uint8_t cursorX;uint8_t cursorY;
textBox(String str , int8_t x, int8_t y);
void textRectCenterer(uint8_t rectX,uint8_t rectY, uint8_t rectWidth, uint8_t rectHeight);
void textDisplaySans(int8_t TEXT_COLOR);
};


#endif 
