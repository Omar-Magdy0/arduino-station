#include <Arduino.h>
#include "applicationManager.h"
#include <lightDisplay.h>
//#include "FunkyAnimations/FunkyObjects.h"
#include "WString.h"


#pragma GCC optimize ("O3")

    int16_t a,b;uint8_t c,d;
    int8_t x = 32,y = 30;



int main(){
    clk1CountMillis(START);
    defaultBootLoader();
    checkForScreen();
    Serial.begin(115200);
    while(1){
        atomicDebounceReEnable(); 
        if(APMNGCTRL & (1<<APRNNG)){
          appFunction();
        }
        else{
          applicationManager();
        } 
    }

return 0;
}










