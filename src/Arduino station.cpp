#include <Arduino.h>
#include "applicationManager.h"


int main(){
    clk1CountMillis(START);
    defaultBootLoader();
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










