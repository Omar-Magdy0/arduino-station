#include <Arduino.h>
#include "applicationManager.h"
#include <lightDisplay.h>
#include "FunkyAnimations/FunkyObjects.h"


// 'BIGANT LOGO', 128x64px
const unsigned char BIGANT_LOGO [] PROGMEM = {

};


  


// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 1040)
lightDisplay dispS = lightDisplay(128,64,&Wire);
FUNKYSquare S1 = FUNKYSquare(15,12,40,40,&dispS);
FUNKYSquare S2 = FUNKYSquare(25,12,40,40,&dispS);




   void display1(){
    dispS.drawChar(62,28,37,WHITE,0);
   }

int main(){

    clk1CountMillis(START);
    defaultBootLoader();
    Serial.begin(115200);
    if(dispS.begin()){Serial.println("SCREEN INITIALIZED");}
      dispS.displayFunctionGroup(0,7,display1);
    while(1){
      S1.angle+= 0.05;
      S2.angle+= 0.1;
      dispS.displayFunctionGroup(0,7,display1);
      _delay_ms(200);



    
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










