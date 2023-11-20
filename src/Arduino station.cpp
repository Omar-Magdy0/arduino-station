#include <Arduino.h>
#include "applicationManager.h"
#include "lightDisplayLib/lightDisplay.h"



lightDisplay disp = lightDisplay(128,64,&Wire);
int main(){
    clk1CountMillis(START);
    defaultBootLoader();
    Serial.begin(115200);
    if(disp.begin()){Serial.println("SCREEN INITIALIZED");}


    for(uint8_t i = 0; i < NUMOFPAGES; i++){
        disp.pageSelect(i);
        disp.clearPage();
        disp.drawLine(0,0,127,63,WHITE);
        disp.drawLine(0,63,127,0,WHITE);
        disp.drawLine(63,0,63,64,WHITE);
        disp.drawLine(64,0,64,64,WHITE);
        disp.drawLine(0,31,127,31,WHITE);
        disp.drawLine(0,32,127,32,WHITE);
        disp.pageDisplay();
        }


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










