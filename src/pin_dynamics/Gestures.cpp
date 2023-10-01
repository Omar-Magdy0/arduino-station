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


int8_t clickHandler(){
switch (currentState)
{

    
case idle:
if(digitalRead(mainButton)==LOW){startTime = millis();currentState = releaseWatchDog;};
break;

case releaseWatchDog:
int8_t clickytype;
unsigned long timeOfClick;
if((digitalRead(mainButton)==HIGH)){
    timeOfClick = currentTime - startTime;
    if (timeOfClick < maxShortClickTime){clickytype = shortClick;}
    else if ((timeOfClick >= maxShortClickTime)&&(timeOfClick <= maxLongClickTime)){clickytype = longClick;}
    else if (timeOfClick > maxLongClickTime){clickytype = veryLongClick;}
startTime = millis();currentState = debounceTime;/*Serial.println(clickytype)*/;return clickytype;
}
break;

case debounceTime:
if((currentTime - startTime) >= debounceWait)currentState  = idle;
break;
}

return 0;
}


unsigned long click1Time,click2Time = 0;

uint16_t doubleClickTimeout = 300;

int8_t gestureHandler(){
int8_t clickType = clickHandler();

if(clickType == shortClick){
if(click1Time == 0){click1Time = currentTime;}
else if (click2Time == 0){click2Time = currentTime;}
}
if (((currentTime - click1Time) >= doubleClickTimeout)&&(click1Time != 0)){Serial.print(shortClick);click1Time = 0;click2Time = 0;return shortClick;}
else if (((click2Time - click1Time) < doubleClickTimeout)&&(click2Time != 0)){Serial.print(doubleClick);click1Time = 0;click2Time = 0;return doubleClick;}

if(clickType == longClick){return longClick;}
if(clickType == veryLongClick){return veryLongClick;}



return 0;
}









