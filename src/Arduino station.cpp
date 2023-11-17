#include <Arduino.h>
#include "applicationManager.h"
#include "lightDisplayLib/lightDisplay.h"

lightDisplay disp = lightDisplay(128,64);
int main(){
    clk1CountMillis(START);
    //defaultBootLoader();
    SREG |= ( 1 << SREG_I);
    Serial.begin(115200);
    if(disp.begin()){Serial.println("SCREEN INITIALIZED");}
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










