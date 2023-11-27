#include <Arduino.h>
#include "applicationManager.h"
#include <lightDisplay.h>
#include "FunkyAnimations/FunkyObjects.h"
#include "WString.h"

// 'BIGANT LOGO', 128x64px
const unsigned char BIGANT_LOGO [] PROGMEM = {
};

lightDisplay dispS = lightDisplay(128,64,&Wire);
FUNKYSquare S1 = FUNKYSquare(15,12,40,40,&dispS);
FUNKYSquare S2 = FUNKYSquare(25,12,40,40,&dispS);


    int16_t a,b;uint8_t c,d;
    int16_t x = 60,y = 8;




   void display1(){
    dispS.setCursor(x,y);
    dispS.drawFillRect(x - 1,y - d,c + 2,d + 2,WHITE);
        dispS.print(F("SAD"));
   }



int main(){
    clk1CountMillis(START);
    defaultBootLoader();
    Serial.begin(115200);
    if(dispS.begin()){Serial.println(F("SCREEN INITIALIZED"));}
    dispS.getTextBounds(F("SAD"),x,y,&a,&b,&c,&d);
    dispS.setWrap(true);
    Serial.println(a);
    Serial.println(b);
    Serial.println(c);
    Serial.println(d);
    dispS.setTextColor(BLACK);
    dispS.displayFunctionGroup(0,7,display1);
    while(1){
          _delay_ms(100);
            dispS.displayFunctionGroup(0,7,display1);
            y++;
  

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










