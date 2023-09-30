#include <pin_dynamics.h>
#include <Arduino.h>
#include <applicationManager.h>



 enum State{
idle,
releaseWatchDog,
debounceTime,
};


State currentState = idle;
extern unsigned long currentTime;
unsigned long startTime;
uint8_t debounceWait = 50;


#define maxShortClickTime 400
#define maxLongClickTime 2000


int8_t gesture(){
switch (currentState)
{
case idle:
if(digitalRead(mainButton)==LOW){startTime = millis();currentState = releaseWatchDog;};
break;

case releaseWatchDog:
unsigned long timeOfClick;
if((digitalRead(mainButton)==HIGH)){
    int8_t clickytype;
    timeOfClick = currentTime - startTime;
    if (timeOfClick < maxShortClickTime){clickytype = shortClick;}
    else if ((timeOfClick >= maxShortClickTime)&&(timeOfClick <= maxLongClickTime)){clickytype = longClick;}
    else if (timeOfClick > maxLongClickTime){clickytype = veryLongClick;}
startTime = millis();currentState = debounceTime;Serial.println(clickytype);return clickytype;
}
break;

case debounceTime:
if((currentTime - startTime) >= debounceWait)currentState  = idle;

break;



}

return 0;
}







