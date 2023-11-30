#include <Arduino.h>
#include "applicationManager.h"
#include <lightDisplay.h>
#include "FunkyAnimations/FunkyObjects.h"
#include "WString.h"


#pragma GCC optimize ("O3")

// 'BIGANT LOGO', 128x64px
const unsigned char BIGANT_LOGO [] PROGMEM = {
};

lightDisplay dispS = lightDisplay(128,64,&Wire);
FUNKYSquare S1 = FUNKYSquare(20,20,40,40,&dispS);
FUNKYSquare S2 = FUNKYSquare(25,12,40,40,&dispS);


    int16_t a,b;uint8_t c,d;
    int8_t x = 0,y = 6;




   void display1(){
    dispS.setCursor(x,y);
    //S1.DisplayFunction();
    dispS.print(F("TOHAMY"));
   }
  void display2(){
    dispS.setCursor(0,y);
    //S1.DisplayFunction();
    dispS.print(F("TOHAMY"));
   }



int main(){
    clk1CountMillis(START);
    defaultBootLoader();
    Serial.begin(115200);
    if(dispS.begin()){Serial.println(F("SCREEN INITIALIZED"));}
    dispS.getTextBounds(F("TOHAMY"),x,y,&a,&b,&c,&d);
    dispS.displayFunctionGroupOpt(display1);
    dispS.setWrap(true);
    dispS.setTextColor(WHITE);

    while(1){
/*      
        atomicDebounceReEnable(); 
        if(APMNGCTRL & (1<<APRNNG)){
          appFunction();
        }
        else{
          applicationManager();
        } */
    }

return 0;
}










