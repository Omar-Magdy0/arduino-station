#include <Arduino.h>
#include "hotAirGun.h"


#define AirGunNTC A2
#define Fan 10
#define Heater 11


BEGIN_FLASH_STRING_TABLE(hotAirGuntxt)
/*0*/    ADD_FLASH_STRING("== Hot AIR GUN ==")
/*1*/    ADD_FLASH_STRING("* Temperature *")
/*2*/    ADD_FLASH_STRING("Current")
/*3*/    ADD_FLASH_STRING("Target")
/*4*/    ADD_FLASH_STRING("")




END_FLASH_STRING_TABLE()


void hotAirGunStaticDisplay_1(){
textBox BOX1 = textBox("",0,0),
        BOX2 = textBox("",0,0),
        BOX3 = textBox("",0,0),
        BOX4 = textBox("",0,0);
BOX1.text = hotAirGuntxt[0];
BOX2.text = hotAirGuntxt[1];
BOX3.text = hotAirGuntxt[2];
BOX4.text = hotAirGuntxt[3];
display.clearDisplay();
BOX1.textRectCenterer(0,0,128,14,1);
display.drawRect(0,0,128,14,WHITE);
BOX2.textRectCenterer(0,14,128,14,1);
BOX3.textRectCenterer(0,28,64,14,1);
display.drawRect(0,28,64,36,1);
BOX4.textRectCenterer(64,28,64,14,1);
display.drawRect(64,28,64,36,1);
BOX1.textDisplaySans(WHITE,1);
BOX2.textDisplaySans(WHITE,1);
BOX3.textDisplaySans(WHITE,1);
BOX4.textDisplaySans(WHITE,1);
display.display();
}







void hotAirGun(){
if(appJustRun){INIT_FLASH_STRING_TABLE(hotAirGuntxt);hotAirGunStaticDisplay_1();appJustRun = false;}



}
