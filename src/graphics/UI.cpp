#include "UI.h"
#include "HardwareSerial.h"





TextBox::TextBox(const char* txt ,bool Prog){
    text = txt;
    Progmem = Prog;
}

void TextBox::textRectCenterer(uint8_t X0,uint8_t Y0,uint8_t width,uint8_t height){
    uint8_t w,h;int16_t x1,y1;
    if(Progmem){
        char txt[20] = "";
        for(uint8_t i = 0;pgm_read_byte(&text[i]) != '\0';i++){
            txt[i] = pgm_read_byte(&text[i]);
        }
        Screen.getTextBounds(txt,0,0,&x1,&y1,&w,&h);
    }
    else
        Screen.getTextBounds(text,0,0,&x1,&y1,&w,&h);
    x = (width - w)/2 + X0;
    y = (height - h)/2 + Y0 + h;
}

void TextBox::display(){
    Screen.setCursor(x,y);
    if(Progmem){
        char txt[20] = "";
        for(uint8_t i = 0;pgm_read_byte(&text[i]) != '\0';i++){
            txt[i] = pgm_read_byte(&text[i]);
        }
        Screen.print(txt);
    }
    else
        Screen.print(text);
}

void TextBox::setPosition(uint8_t X,uint8_t Y){
    x = X;
    y = Y;
}

