#include <Arduino.h>
#include "hotAirGun.h"
#include <stdio.h>


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
display.drawRect(0,28,64,36,WHITE);
BOX4.textRectCenterer(64,28,64,14,1);
display.drawRect(64,28,64,36,WHITE);
BOX1.textDisplaySans(WHITE,0);
BOX2.textDisplaySans(WHITE,0);
BOX3.textDisplaySans(WHITE,0);
BOX4.textDisplaySans(WHITE,0);
display.display();
}


void dynamicDisplay_1(int16_t currentTemp,int16_t targetTemp){
textBox BOX1 = textBox("",0,0),
        BOX2 = textBox("",0,0);
char numString[5];
char Celcius[5] = {'\367','C'};
sprintf(numString,"%d",currentTemp);
strcat(numString,Celcius);
BOX1.text = numString;
BOX1.textRectCenterer(0,40,64,22,1);
sprintf(numString,"%d",targetTemp);
strcat(numString,Celcius);
BOX2.text = numString;
BOX2.textRectCenterer(64,40,64,22,1);
display.fillRect(0,40,63,22,BLACK);
display.fillRect(65,40,63,22,BLACK);
BOX1.textDisplaySans(WHITE,0);
BOX2.textDisplaySans(WHITE,0);
display.display();
}


void dynamicDisplay_1(int16_t currentTemp,int16_t targetTemp){
textBox BOX1 = textBox("",0,0),
        BOX2 = textBox("",0,0);
char numString[5];
char Celcius[5] = {'\367','C'};
sprintf(numString,"%d",currentTemp);
strcat(numString,Celcius);
BOX1.text = numString;
BOX1.textRectCenterer(0,40,64,22,1);
sprintf(numString,"%d",targetTemp);
strcat(numString,Celcius);
BOX2.text = numString;
BOX2.textRectCenterer(64,40,64,22,1);
display.fillRect(0,40,63,22,BLACK);
display.fillRect(65,40,63,22,BLACK);
BOX1.textDisplaySans(WHITE,0);
BOX2.textDisplaySans(WHITE,0);
display.display();
}


int8_t screenNum = 1;

void hotAirGun(){
 int16_t FOO = analogRead(A0);
FOO = (FOO-10)*0.2964   ;
if(gestureType == longClick){screenNum++;if(screenNum > 2)screenNum = 1;}
if(appJustRun){INIT_FLASH_STRING_TABLE(hotAirGuntxt);hotAirGunStaticDisplay_1();appJustRun = false;}
if(screenNum == 1){
    dynamicDisplay_1(30,FOO);
}
else if(screenNum == 2){


}





}
