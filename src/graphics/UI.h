#ifndef UI_H
#define UI_H

#include "display.h"

class TextBox{
    uint8_t x;
    uint8_t y;
    const char *text ;
    bool Progmem;

    public:
    TextBox(const char *txt,bool Prog);
    void textRectCenterer(uint8_t X0,uint8_t Y0,uint8_t width,uint8_t height);
    void display();
    void setPosition(uint8_t X, uint8_t Y);
};




#endif