#include <Arduino.h>
#include "applicationManager.h"




extern volatile uint16_t globalTimeMillis;
extern void atomicDebounceReEnable();
extern void comboSlave();

int main(){
 defaultBootLoader();
 Serial.begin(115200); 
while(1){
 //applicationManager();
  //Serial.println(globalTime);
 atomicDebounceReEnable();
 comboSlave();
}
return 0;

}










