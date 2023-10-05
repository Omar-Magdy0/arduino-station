#include "display.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>




void MainMenuSelectRectangle(){
display.fillRect(0,22,128,20,WHITE);
}




  
textBox::textBox(String str,int8_t x,int8_t y){
  text = str;cursorX = x;cursorY = y;
}

void textBox::textRectCenterer(uint8_t rectX ,uint8_t rectY,uint8_t rectWidth,uint8_t rectHeight,int8_t TEXT_SIZE){
uint16_t width,height;int16_t x2,y2;
display.getTextBounds(text, cursorY, cursorY, &x2, &y2, &width, &height);
cursorX = rectX + ((rectWidth - (width))/2);
cursorY = rectY + ((rectHeight - (height))/2);
}



void textBox::setCursor(uint8_t x,uint8_t y){cursorX = x;cursorY = y;};


#define default 0

void textBox::textDisplaySans(int8_t TEXT_COLOR,int8_t font) {
  if(font == 0){display.setFont();}
  display.setCursor(cursorX, cursorY);
  display.setTextSize(1);
  display.setTextColor(TEXT_COLOR);
  display.print(text);
}
