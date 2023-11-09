#include <Arduino.h>
#include "applicationManager.h"




extern volatile uint16_t globalTimeMillis;
extern void atomicDebounceReEnable();
extern void comboSlave();
extern void clk2CountMillis(uint8_t command);

int main(){
 defaultBootLoader();
 Serial.begin(115200); 
 
while(1){
 //applicationManager();
 atomicDebounceReEnable();
 comboSlave();
 Serial.println(globalTimeMillis);
}
return 0;

}










