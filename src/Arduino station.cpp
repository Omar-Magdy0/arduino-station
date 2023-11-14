#include <Arduino.h>
#include "applicationManager.h"


int main(){
    clk1CountMillis(START);
    defaultBootLoader();
    Serial.begin(115200);
    while(1){
        //applicationManager();
        uint8_t clickType = potButtonComb();
        atomicDebounceReEnable(); 
      //  if(clickType > 0)Serial.println(clickType);
    }

return 0;
}










