#include <Arduino.h>
#include "hotAirGun.h"

bool appJustRun = true;

#define AirGunNTCPin A2
#define Fan 10
#define Heater 11

const char  hotAirGuntxt [] PROGMEM = "--*  HOT AIR GUN  *--" ,
            firtMessagetxt [] PROGMEM = "Double Click To Start";


void hotAirGunDisplay(){
textBox BOX1 = textBox("",0,0),
        BOX2 = textBox("",0,0),
        BOX3 = textBox("",0,0),
        BOX4 = textBox("",0,0);

BOX1.text = firtMessagetxt;

                
        
        
display.clearDisplay();



}


void hotAirGun(){
hotAirGunDisplay();


}
