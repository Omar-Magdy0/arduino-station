#include <avr/interrupt.h>
#include <Arduino.h>




#ifdef OLDCLICK1
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
}
#endif

#ifdef OLDCLICK2
/* 
 BTNCNTRL DEFINITION
 lastButtonState set 1 for press or 0 for release
 lastShortFlag if after last release a short click was detected is set to 1 if not is set to 0
 last Four bit for click Type
                         | CLCKTYPE2 | CLCKTYPE1 | CLCKTYPE0 |
DEFAULT NOSTORED         |     0     |     0     |     0     |                                                  
TempSHORT CLICK          |     0     |     0     |     1     |                                            
LONG CLICK               |     0     |     1     |     0     |                                            
VERYLONG CLICK           |     0     |     1     |     1     |                                                
DVERYLONG CLICK          |     1     |     0     |     0     |                                              
DOUBLE CLICK             |     1     |     0     |     1     |
CMBSLV Shortclick        |     1     |     1     |     0     |


corresponding to  
DEFAULT NOSTORED
SHORT CLICK         b00100000
LONG CLICK          b01000000
VERYLONG CLICK      b01100000
DVERYLONG CLICK     b10000000
*/
 
extern uint16_t globalTimeMillis;
#define NOCLICK 0
#define SHORTCLICK 1
#define TEMPSHORTCLICK 1
#define LONGCLICK 2
#define VERYLONGCLICK 3
#define DVERYLONGCLICK 4
#define DOUBLECLICK 5
#define CMBSVSHORTCLICK 6

volatile byte BTNCNTRL;
  #define lastButtonState 0
  #define SHRTCLCK1  1
  #define SHRTCLCK2  2
  #define BTNCNTRLCG 4
  #define DBNCTMDEF  3 
  #define CLCKTYPE0  5
  #define CLCKTYPE1  6
  #define CLCKTYPE2  7


#define debounceTime 50
#define shortClickMax 400
#define longClickMax 2000
#define veryLongMax 3000
#define doubleClickTimeout 700
//Scale time value in milliseconds to value for clock at 1024 prescaler
#define timeToCounter(n) (n/(6.4e-2))

volatile int16_t timeOfPress;
ISR(PCINT0_vect){
  //FIRST CHECK BUTTON STATE PRESSED/RELEASED 
  //THEN DO OPERATIONS ACCORDINGLY  
  BTNCNTRL |= (1<<BTNCNTRLCG);
  if(PINB & ( 1 << PORTB5)){ // IF change then read HIGH then it is released
    PCMSK0 &= ~( 1 << PCINT5); //DISABLE INTERRUPT FOR DEBOUNCE
    BTNCNTRL &=  ~(1 << lastButtonState); //Store released
    // CHECK what click type was after release
    // **TCN1 clock/counter1 count register defined at 1024 prescaller in bootloader 
    uint16_t pressReleaseDiff = TCNT1 - timeOfPress;
    //Free the bits holding click types to store fresh ones
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
void atomicDebounceReEnable(){
    if(!(PCMSK0 & (1 << PCINT5))){
      if(!(BTNCNTRL & (1 << DBNCTMDEF))){debounceStartTime = TCNT1; BTNCNTRL |= ( 1 << DBNCTMDEF);}
      //check last button state and the time since that state
      if((TCNT1 - debounceStartTime) >= timeToCounter(debounceTime)){
       PCMSK0 |= (1 << PCINT5);
       BTNCNTRL &= ~(1 << DBNCTMDEF);
    }
    }}

uint16_t shortClickTime_1;
int8_t getClickType(bool detectDoubleClick){
//IF the detectDoubleClick is true we execute code block for managing it if not we skip to checking clickType  
 
  if(detectDoubleClick){
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


//Code block for checking ClickType
  
  byte clickType = 0;
  if(BTNCNTRL & (1<<BTNCNTRLCG)){
  clickType |= ((BTNCNTRL & (1<<CLCKTYPE0)) | (BTNCNTRL & (1<<CLCKTYPE1)) | (BTNCNTRL & (1<<CLCKTYPE2)));
  BTNCNTRL &= ~(( 1 << CLCKTYPE0) | ( 1 << CLCKTYPE1) | ( 1 << CLCKTYPE2));
  clickType = (clickType>>5);
  BTNCNTRL &= ~(1<<BTNCNTRLCG);
  }
  if(clickType>0)Serial.println(clickType);
  if(clickType == CMBSVSHORTCLICK){clickType = SHORTCLICK;}
  return clickType;
}
#endif


#ifdef OLDCLICK3
//APPROACH 3 for making MY control settings


/* 
 BTNCNTRL DEFINITION
 lastButtonState set 1 for press or 0 for release
 lastShortFlag if after last release a short click was detected is set to 1 if not is set to 0
 last Four bit for click Type
                           5         4         3         2         1         0
  BTNCNTRL  | ------- | ------- | RELESFG | PRESSFG | DBNCPSD | LONGCLK | SHRTCLK |
*/
volatile int8_t BTNCNTRL;
  #define SHRTCLK 0
  #define LONGCLK 1
  #define DBNCPSD 2
  #define PRESSFG 3
  #define RELESFG 4

#define debounceTime 200
#define shortClickMax 3000
#define longClickMax 6000




volatile uint16_t timeOfPress;
ISR(PCINT0_vect){
 
  //FIRST CHECK BUTTON STATE PRESSED/RELEASED 1
  //if press flag is true check for release (every press should have only 1 release)
  //THEN DO OPERATIONS ACCORDINGLY  
  if( (PINB & ( 1 << PINB5)) && (BTNCNTRL & (1 << PRESSFG))){ // IF change then read HIGH then it is released
    // CHECK what click type was after release
    // **TCN1 clock/counter1 count register defined at 1024 prescaller in bootloader
    //Free the bits holding click types to store fresh ones
    Serial.write('r');
    BTNCNTRL &=  ~( (1 << PRESSFG) | ( 1 << SHRTCLK) | ( 1 << LONGCLK)); 
    uint16_t pressReleaseDiff = globalTimeMillis - timeOfPress;
    PCMSK0 &= ~( 1 << PCINT5); //DISABLE INTERRUPT FOR DEBOUNCE
    if(pressReleaseDiff <= shortClickMax){BTNCNTRL |= ( 1 << SHRTCLK);Serial.write('s');}
    else if(pressReleaseDiff <= longClickMax){BTNCNTRL |= ( 1 << LONGCLK);Serial.write('l');}
  }

  else if( !(PINB & ( 1 << PINB5)) && !(BTNCNTRL & (1 << PRESSFG)) ){ // IF change then read LOW then it is pressed
    timeOfPress = globalTimeMillis;
    //press flag on
    Serial.write('p');
    BTNCNTRL |= (1 << PRESSFG);
    PCMSK0 &= ~( 1 << PCINT5); //DISABLE INTERRUPT FOR DEBOUNCE
  }
};

uint16_t debounceStartTime;
void atomicDebounceReEnable(){
    if(!(PCMSK0 & (1 << PCINT5))){
      if(!(BTNCNTRL & (1 << DBNCPSD))){debounceStartTime = globalTimeMillis; BTNCNTRL |= ( 1 << DBNCPSD);}
      //check last button state and the time since that state
      if((globalTimeMillis - debounceStartTime) >= debounceTime){
       Serial.write('d');
       Serial.write('$');
       BTNCNTRL &= ~(1 << DBNCPSD);
       PCMSK0 |= (1 << PCINT5);
    }
    }}
#endif



//APPROACH 4 for making MY control settings

volatile uint16_t lastChangeTime;

/*
            |    7    |     6   |    5    |    4    |    3    |    2    |    1    |    0    |
  PCINTMEM0 | PCINTM7 | PCINTM6 | PCINTM5 | PCINTM4 | PCINTM3 | PCINTM2 | PCINTM1 | PCINTM0 |
  ---PCINTMEM is used to store the last pinState before interrupt happened for PCINT0-PCINT7 pins 
*/
volatile int8_t PCINTMEM0;
  #define PCINTM0 0
  #define PCINTM1 1
  #define PCINTM2 2
  #define PCINTM3 3
  #define PCINTM4 4
  #define PCINTM5 5
  #define PCINTM6 6
  #define PCINTM7 7

/* 
 BTNCNTRL DEFINITION
 BTNCNTRL DEFINITION
-----CHGNUM(1:2) stores number of clicks before timeout was detected (3max)
-----CHANGE(1/2) for the first and second clicks detected respectively
-----DBNCPSD     flag that is set once debouncing starts and cleared when debounce is done 

            |    7    |     6   |    5    |    4    |    3    |    2    |    1    |    0    |
  BTNCNTRL  | DBNCPSD | ------- | ------- | ------- | CHANGE2 | CHANGE1 | CHGNUM1 | CHGNUM0 |
*/
volatile int8_t BTNCNTRL;
  #define CHGNUM0 0
  #define CHGNUM1 1
  #define CHANGE1 2
  #define CHANGE2 3
  #define POTRL0  4
  #define POTRL1  5 
  #define DBNCPSD 7

uint16_t debounceStartTime;