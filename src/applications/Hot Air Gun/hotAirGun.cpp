#include <Arduino.h>
#include "hotAirGun.h"
#include <stdio.h>
#include <FastPID.h>

#ifdef sad

#define AirGunNTC A2
#define Fan 9
#define Heater 10
#define acDimPin 11
#define acZeroRead 12
#define noVar 0
int8_t fanSpeed = 0;
bool fanOn = false,heatingElementOn = false;
int16_t targetTemp = 0;


/*0*/    const char hotAirGun1[] PROGMEM = "Hot AIR GUN";
/*1*/    const char hotAirGun2[] PROGMEM = "Temperature";
/*2*/    const char hotAirGun3[] PROGMEM = "Current";
/*3*/    const char hotAirGun4[] PROGMEM = "Target";
/*4*/    const char hotAirGun5[] PROGMEM = "Fan";
/*5*/    const char hotAirGun6[] PROGMEM = "Heating Element";


//AC Object and functions for DIMMING and AC wave manipulation


float calcAcOffTime(int8_t freq,uint8_t intensity){
     float z;float c = 4*PI*freq*(intensity/255.0);
     for(int i = 0;i < 3;i++){
          z = z - ((z - sin(z) - c)/(1 - cos(z))); 
     };
     float onTime = z/(4*PI*freq) ;    
     float offTime = (1/freq) - onTime ; 
     Serial.print(offTime);
     return offTime;
}

uint16_t acZeroTime1st = 0;
bool highTriggered = false;


class AC{
private:
int8_t frequency;

public:
AC(){};
int8_t getFrequency(){
uint16_t acZeroTime2nd;

if((digitalRead(acZeroRead) == LOW)  && (highTriggered == true)){
     if(acZeroTime1st == 0)acZeroTime1st = noVar;}
     else if (acZeroTime1st != 0){
          acZeroTime2nd = noVar;
          frequency = 1/( (acZeroTime2nd - acZeroTime1st) *2);
          acZeroTime1st = acZeroTime2nd;
          highTriggered = false;
          return frequency;
     }
if(digitalRead(acZeroRead) == HIGH){highTriggered = true;}

}



void dim(){
float offTime = calcAcOffTime(frequency,127);
if((noVar - acZeroTime1st) >= offTime)digitalWrite(acDimPin,HIGH);
else(pinMode(acDimPin,LOW));
}
};





void hotAirGunStaticDisplay_1(){
display.clearDisplay();
char text[14];
//First text
for (uint8_t i = 0; i < sizeof(hotAirGun1); i++) {
    text[i] = pgm_read_byte(&hotAirGun1[i]);}
Box1.text = text;
Box1.textRectCenterer(0,0,128,16,1);
Box1.textDisplaySans(WHITE,0);
//second text
for (uint8_t i = 0; i < sizeof(hotAirGun2); i++) {
    text[i] = pgm_read_byte(&hotAirGun2[i]);}
Box1.text = text;
Box1.textRectCenterer(0,14,128,14,1);
Box1.textDisplaySans(WHITE,0);
//third text
for (uint8_t i = 0; i < sizeof(hotAirGun3); i++) {
    text[i] = pgm_read_byte(&hotAirGun3[i]);}
Box1.text = text;
Box1.textRectCenterer(0,28,64,14,1);
Box1.textDisplaySans(WHITE,0);
//fourth text
for (uint8_t i = 0; i < sizeof(hotAirGun4); i++) {
    text[i] = pgm_read_byte(&hotAirGun4[i]);}
Box1.text = text;
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
display.clearDisplay();char text[16];
//first text
for (uint8_t i = 0; i < sizeof(hotAirGun5); i++) {
    text[i] = pgm_read_byte(&hotAirGun5[i]);}
Box1.text = text;
Box1.textRectCenterer(0,0,128,14,1);
Box1.textDisplaySans(WHITE,0);
//second text
for (uint8_t i = 0; i < sizeof(hotAirGun6); i++) {
    text[i] = pgm_read_byte(&hotAirGun6[i]);}
Box1.text = text;
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
display.fillRect(1,15,62,13,BLACK);
display.fillRect(66,15,62,13,BLACK);
display.fillRect(1,47,127,13,BLACK);
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

/*
void pinsOutput(uint8_t feedbackPin,uint8_t outputPin,int16_t target){
if(appJustRun){
}
}
*/


int8_t screenNum = 1;
bool editModeOn = false;
int8_t pageSettingsIndex = 1;

float Kp=0.1, Ki=0.5, Kd=0.1, Hz=10;
int output_bits = 8;
bool output_signed = false;

FastPID myPID(Kp, Ki, Kd, Hz, output_bits, output_signed);


void hotAirGun(){
     int16_t currentTemp = 34;



//toggle display
if(gestureType == longClick && (!editModeOn) ){screenNum++;if(screenNum > 2)screenNum = 1;
if(screenNum == 1){hotAirGunStaticDisplay_1();}
else if (screenNum == 2){hotAirGunStaticDisplay_2();}
}
//end of toggle display


// code to run once HERE
if(appJustRun){
     appJustRun = false;hotAirGunStaticDisplay_1();
     pinMode(Heater,OUTPUT);
     pinMode(Fan,OUTPUT);
     pinMode(AirGunNTC,INPUT);
     pinMode(acZeroRead,INPUT);
     pinMode(acDimPin,OUTPUT);
        
}
//end of code once 

//Closing app
if(appClosing){
//do whatever you want before closing app
screenNum = 1;



appClosing = false;
appRunning = false;
}
//end of app closing


//display screen one
if(screenNum == 1){
    dynamicDisplay_1(currentTemp,targetTemp);
    if(gestureType == doubleClick){
          if(editModeOn == false){editModeOn = true;}else{editModeOn = false;}
     }
     if(editModeOn){targetTemp = (controlPot-10)*0.2964;;}
}
//end of display screen one

//display screen two
else if(screenNum == 2){
     
     dynamicDisplay_2();
     if(gestureType == shortClick && (!editModeOn) ){pageSettingsIndex++; if(pageSettingsIndex > 3)pageSettingsIndex = 1;}

     if(pageSettingsIndex == 1){
          display.drawLine(1,60,127,60,BLACK);
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
          if(editModeOn){fanSpeed = (controlPot-10)*0.0988;if(fanSpeed > 100){fanSpeed = 100;}else if(fanSpeed < 0){fanSpeed = 0;}}
          
          }


else if(pageSettingsIndex == 3){
          display.drawLine(65,28,127,28,BLACK);
          display.drawLine(1,60,127,60,WHITE);
          display.display();
          if(gestureType == doubleClick){
               if(heatingElementOn == true){heatingElementOn = false;}else{heatingElementOn = true;}}
     }
}
// end of display sreen two

// I/O Functionality Code Block

     if(fanOn == true){
          uint8_t outputFanSpeed = 2.56 * fanSpeed;
          analogWrite(Fan,outputFanSpeed);}
          else{digitalWrite(Fan,LOW);}

    // int16_t setpoint = targetTemp; 
   //  int16_t feedback = currentTemp;
    // uint8_t output = myPID.step(setpoint, feedback);
   //  analogWrite(Heater, output);

     if(heatingElementOn == true){digitalWrite(acDimPin,HIGH);}
     else{digitalWrite(acDimPin,LOW);}
     if(digitalRead(acZeroRead) == LOW){Serial.println(noVar);}
     
}

#endif
