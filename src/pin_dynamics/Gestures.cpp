#include <pin_dynamics.h>
#include <Arduino.h>
#include <applicationManager.h>


/*
 enum State{
idle,
releaseWatchDog,
debounceTime,
};


State currentState = idle;
extern unsigned long currentTime;
unsigned long startTime;


uint8_t debounceWait = 100;


#define maxShortClickTime 300
#define maxLongClickTime 3000




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
startTime = millis();currentState = debounceTime;return clickytype;
}
break;

case debounceTime:
if((currentTime - startTime) >= debounceWait)currentState  = idle;
break;
}

return 0;
}


unsigned long click1Time,click2Time = 0;

uint16_t doubleClickTimeout = 700;

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
}*/


extern uint16_t globalTimeMillis;

volatile byte BTNCNTRL; 
// lastButtonState set 1 for press or 0 for release
  
// lastShortFlag if after last release a short click was detected is set to 1 if not is set to 0
  
//last Four bit for click Type
/*               | CLCKTYPE2 | CLCKTYPE1 | CLCKTYPE0 |
DEFAULT NOSTORED |     0     |     0     |     0     |                                                  
TempSHORT CLICK  |     0     |     0     |     1     |                                            
LONG CLICK       |     0     |     1     |     0     |                                            
VERYLONG CLICK   |     0     |     1     |     1     |                                                
DVERYLONG CLICK  |     1     |     0     |     0     |                                              
DOUBLE CLICK     |     1     |     0     |     1     |
CMBSLV Shortclick|     1     |     1     |     0     |


corresponding to  
DEFAULT NOSTORED
SHORT CLICK         b00100000
LONG CLICK          b01000000
VERYLONG CLICK      b01100000
DVERYLONG CLICK     b10000000
*/

  #define lastButtonState 0
  #define SHRTCLCK1 1
  #define SHRTCLCK2 2
  #define DBNCTMDEF 3 
  #define CLCKTYPE0 5
  #define CLCKTYPE1 6
  #define CLCKTYPE2 7


#define debounceTime 50
#define shortClickMax 250
#define longClickMax 2000
#define veryLongMax 4000
#define doubleClickTimeout 700
//Scale time value in milliseconds to value for clock at 1024 prescaler
#define timeToCounter(n) (n/(6.4e-2))

volatile int16_t timeOfPress;
ISR(PCINT0_vect){
  //FIRST CHECK BUTTON STATE PRESSED/RELEASED 
  //THEN DO OPERATIONS ACCORDINGLY  
  if(PINB & ( 1 << PORTB5)){ // IF change then read HIGH then it is released
    PCMSK0 &= ~( 1 << PCINT5); //DISABLE INTERRUPT FOR DEBOUNCE
    BTNCNTRL &=  ~(1 << lastButtonState); //Store released
    // CHECK what click type was after release
    // **TCN1 clock/counter1 count register defined at 1024 prescaller in bootloader 
    uint16_t pressReleaseDiff = TCNT1 - timeOfPress;
    //Free the bytes holding click types to store fresh ones
    BTNCNTRL &= ~(( 1 << CLCKTYPE0) | ( 1 << CLCKTYPE1) | ( 1 << CLCKTYPE2));
    if(pressReleaseDiff <= timeToCounter(shortClickMax)){BTNCNTRL |= ( 1 << CLCKTYPE0);return;}
    else if(pressReleaseDiff <= timeToCounter(longClickMax)){BTNCNTRL |= ( 1 << CLCKTYPE1);return;}
    else if(pressReleaseDiff <= timeToCounter(veryLongMax)){BTNCNTRL |= ( 1 << CLCKTYPE0) | ( 1 << CLCKTYPE1);return;}
    else if(pressReleaseDiff >= timeToCounter(veryLongMax)){BTNCNTRL |= ( 1 << CLCKTYPE2);return;}
  }
  else{ // IF change then read LOW then it is pressed
    timeOfPress = TCNT1;
    PCMSK0 &= ~( 1 << PCINT5);  //DISABLE INTERRUPT FOR DEBOUNCE
    BTNCNTRL |= (1 << lastButtonState); //Store pressed
  }
};


uint16_t debounceStartTime;
inline void atomicDebounceReEnable(){
    if(!(PCMSK0 & (1 << PCINT5))){
      if(!(BTNCNTRL & (1 << DBNCTMDEF))){debounceStartTime = TCNT1; BTNCNTRL |= ( 1 << DBNCTMDEF);}
      //check last button state and the time since that state
      if((TCNT1 - debounceStartTime) >= timeToCounter(debounceTime)){
       PCMSK0 |= (1 << PCINT5);
       BTNCNTRL &= ~(1 << DBNCTMDEF);
    }
    }}

 uint16_t shortClickTime_1;
void comboSlave(){
  /* CHECK FOR SHORT CLICK 
  | CLCKTYPE2 | CLCKTYPE1 | CLCKTYPE0 |
  |     0     |     0     |     1     |
  */
  // if shortClick detected
  if ( !(BTNCNTRL & (1<<CLCKTYPE1)) && !(BTNCNTRL & (1<<CLCKTYPE2)) && (BTNCNTRL & ( 1 << CLCKTYPE0))) {
    //CHECK for the first click
    Serial.println('d');
    if(!(BTNCNTRL & (1<<SHRTCLCK1))){
    //Set SHRTCLCK1 flag and the time of that click 
    BTNCNTRL |= (1<<SHRTCLCK1); shortClickTime_1 = TCNT1;
    //WE then ABSORB OR consume the shortCLICK state by clearing clicktype register
    BTNCNTRL &= ~((1<<(CLCKTYPE0)) | (1<<(CLCKTYPE1)) | (1<<(CLCKTYPE2)));
    }
    //if first shortCLick was detected 
    else {
      //WE then ABSORB OR consume the shortCLICK state by clearing clicktype register
      BTNCNTRL &= ~((1<<(CLCKTYPE0)) | (1<<(CLCKTYPE1)) | (1<<(CLCKTYPE2)));
      // WE set Short click 2 flag as 1
      BTNCNTRL |= (1<<SHRTCLCK2);
    }
  }
//IF SHORT CLICK2 was detected check for time difference and act
  if(((TCNT1 - shortClickTime_1) <= timeToCounter(doubleClickTimeout)) && (BTNCNTRL & (1<<SHRTCLCK1)) && (BTNCNTRL & (1<<SHRTCLCK2))){
  //IF timeout haven't passed yes store double click
    BTNCNTRL |= ((1<<(CLCKTYPE0)) | (1<<(CLCKTYPE2)));
    BTNCNTRL &= ~((1<<SHRTCLCK1) | (1<<SHRTCLCK2));
      }
  else if(((TCNT1 - shortClickTime_1) >= timeToCounter(doubleClickTimeout)) && (BTNCNTRL & (1<<SHRTCLCK1)) && !(BTNCNTRL & (1<<SHRTCLCK2))){
    BTNCNTRL |= (1<<(CLCKTYPE1)) | (1<<(CLCKTYPE2)) ;
    BTNCNTRL &= ~(1<<SHRTCLCK1);
  }
}



readPot(){

}








