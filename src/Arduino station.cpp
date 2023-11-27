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
FUNKYSquare S3 = FUNKYSquare(35,12,40,40,&dispS);
FUNKYSquare S4 = FUNKYSquare(45,12,40,40,&dispS);
FUNKYSquare S5 = FUNKYSquare(55,12,40,40,&dispS);
FUNKYSquare S6 = FUNKYSquare(65,12,40,40,&dispS);
FUNKYSquare S7 = FUNKYSquare(75,12,40,40,&dispS);






   void display1(){
      S1.DisplayFunction();
      S2.DisplayFunction();
      S3.DisplayFunction();
      S4.DisplayFunction();
      S5.DisplayFunction();
      S6.DisplayFunction();
      S7.DisplayFunction();

   }

int main(){
    clk1CountMillis(START);
    defaultBootLoader();
    Serial.begin(115200);
    if(dispS.begin()){Serial.println("SCREEN INITIALIZED");}
    dispS.setCursor(32,12);
    while(1){
      S1.angle+= 0.05;
      S2.angle+= 0.15;
      S3.angle+= 0.2;
      S4.angle+= 0.25;
      S5.angle+= 0.3;
      S6.angle+= 0.35;
      S7.angle+= 0.4;

            dispS.displayFunctionGroup(0,7,display1);


    
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










