#include <Arduino.h>
#include "hotAirGun.h"
#include <stdio.h>


#define AirGunNTC 
#define Fan 10
#define Heater 11
int8_t fanSpeed = 0;
bool fanOn = false,heatingElementOn = false;
int16_t targetTemp = 0;

BEGIN_FLASH_STRING_TABLE(hotAirGuntxt)
/*0*/    ADD_FLASH_STRING("Hot AIR GUN")
/*1*/    ADD_FLASH_STRING("* Temperature *")
/*2*/    ADD_FLASH_STRING("Current")
/*3*/    ADD_FLASH_STRING("Target")
/*4*/    ADD_FLASH_STRING("Fan")
/*5*/    ADD_FLASH_STRING("Heating Element")


END_FLASH_STRING_TABLE()




void hotAirGunStaticDisplay_1(){
display.clearDisplay();
//First text
Box1.text = hotAirGuntxt[0];
Box1.textRectCenterer(0,0,128,16,1);
Box1.textDisplaySans(WHITE,0);
//second text
Box1.text = hotAirGuntxt[1];
Box1.textRectCenterer(0,14,128,14,1);
Box1.textDisplaySans(WHITE,0);
//third text
Box1.text = hotAirGuntxt[2];
Box1.textRectCenterer(0,28,64,14,1);
Box1.textDisplaySans(WHITE,0);
//fourth text
Box1.text = hotAirGuntxt[3];
Box1.textRectCenterer(64,28,64,14,1);
Box1.textDisplaySans(WHITE,0);
//end text
display.drawRect(0,0,128,14,WHITE);
display.drawRect(0,28,64,36,WHITE);
display.drawRect(64,28,64,36,WHITE);
display.display();
}


void dynamicDisplay_1(int16_t currentTemp,int16_t targetTemp){
display.fillRect(0,40,63,22,BLACK);
display.fillRect(65,40,63,22,BLACK);
char numString[5];
char Celcius[5] = {'\367','C'};
//first text
sprintf(numString,"%d",currentTemp);
strcat(numString,Celcius);
Box1.text = numString;
Box1.textRectCenterer(0,40,64,22,1);
Box1.textDisplaySans(WHITE,0);
//second text
sprintf(numString,"%d",targetTemp);
strcat(numString,Celcius);
Box1.text = numString;
Box1.textRectCenterer(64,40,64,22,1);
Box1.textDisplaySans(WHITE,0);
//end text
display.display();
}


void hotAirGunStaticDisplay_2(){
display.clearDisplay();
//first text
Box1.text = hotAirGuntxt[4];
Box1.textRectCenterer(0,0,128,14,1);
Box1.textDisplaySans(WHITE,0);
//second text
Box1.text = hotAirGuntxt[5];
Box1.textRectCenterer(0,32,128,14,1);
Box1.textDisplaySans(WHITE,0);
// end text
display.drawRect(0,0,128,14,WHITE);
display.drawRect(0,32,128,14,WHITE);
display.drawLine(63,14,63,32,WHITE);
display.drawLine(64,14,64,32,WHITE);
display.display();
}

void dynamicDisplay_2(){
display.fillRect(1,15,62,17,BLACK);
display.fillRect(66,15,62,17,BLACK);
display.fillRect(1,47,127,17,BLACK);
//first text
if(fanOn == true){Box1.text = "ON";}else{Box1.text = "OFF";}
Box1.textRectCenterer(0,14,64,18,1);
Box1.textDisplaySans(WHITE,0);
//second text
if(heatingElementOn == true){Box1.text = "ON";}else{Box1.text = "OFF";}
Box1.textRectCenterer(0,46,128,18,1);
Box1.textDisplaySans(WHITE,0);
//third text
char numString[4];
char perc[2] = {"%"};
sprintf(numString,"%d",fanSpeed);
strcat(numString,perc);
Box1.text = numString;
Box1.textRectCenterer(64,14,64,18,1);
Box1.textDisplaySans(WHITE,0);
//end text
display.display();
}



int8_t screenNum = 1;
bool editModeOn = false;
int8_t pageSettingsIndex = 1;



void hotAirGun(){
if(gestureType == longClick && (!editModeOn) ){screenNum++;if(screenNum > 2)screenNum = 1;
if(screenNum == 1){hotAirGunStaticDisplay_1();}
else if (screenNum == 2){hotAirGunStaticDisplay_2();}
}
if(appJustRun){INIT_FLASH_STRING_TABLE(hotAirGuntxt);delay(10);appJustRun = false;hotAirGunStaticDisplay_1();}



if(screenNum == 1){
    dynamicDisplay_1(30,targetTemp);
    if(gestureType == doubleClick){
          if(editModeOn == false){editModeOn = true;}else{editModeOn = false;}
     }
     if(editModeOn){targetTemp = (controlPot-10)*0.2964;;}
}
    


else if(screenNum == 2){
     
     dynamicDisplay_2();
     if(gestureType == shortClick && (!editModeOn) ){pageSettingsIndex++; if(pageSettingsIndex > 3)pageSettingsIndex = 1;}

     if(pageSettingsIndex == 1){
          display.drawLine(0,28,63,28,WHITE);
          display.display();
          if(gestureType == doubleClick){
               if(fanOn == true){fanOn = false;}else{fanOn = true;}}
     }


else if(pageSettingsIndex == 2){
          display.drawLine(0,28,63,28,BLACK);
          display.drawLine(65,28,127,28,WHITE);
          display.display();
          if(gestureType == doubleClick){
               if(editModeOn == false){editModeOn = true;}else{editModeOn = false;}
                     }
          if(editModeOn){               fanSpeed = (controlPot-10)*0.0988;if(fanSpeed > 100){fanSpeed = 100;}else if(fanSpeed < 0){fanSpeed = 0;}}
               }


else if(pageSettingsIndex == 3){
          display.drawLine(65,28,127,28,BLACK);
          display.drawLine(0,60,127,60,WHITE);
          display.display();
          if(gestureType == doubleClick){
               if(heatingElementOn == true){heatingElementOn = false;}else{heatingElementOn = true;}}
     }
}
}
