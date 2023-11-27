#include <Arduino.h>
#include "applicationManager.h"
#include <lightDisplay.h>
#include "FunkyAnimations/FunkyObjects.h"


// 'BIGANT LOGO', 128x64px
const unsigned char BIGANT_LOGO [] PROGMEM = {
};


  

lightDisplay dispS = lightDisplay(128,64,&Wire);
FUNKYSquare S1 = FUNKYSquare(15,12,40,40,&dispS);
FUNKYSquare S2 = FUNKYSquare(25,12,40,40,&dispS);




   void display1(){
    dispS.drawFillRect(0,0,128,64,WHITE);
    dispS.setCursor(10,40);
    dispS.println(F("SADISTIC SLAYER"));
   }

int main(){
    clk1CountMillis(START);
    defaultBootLoader();
    Serial.begin(115200);
    if(dispS.begin()){Serial.println(F("SCREEN INITIALIZED"));}
    dispS.setWrap(true);
    dispS.setTextColor(BLACK);
    dispS.displayFunctionGroup(0,7,display1);
    while(1){
          _delay_ms(100);
  

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










