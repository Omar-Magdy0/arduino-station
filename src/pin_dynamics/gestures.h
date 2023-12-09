#ifndef GESTURES_H
#define GESTURES_H

#include "pin_dynamics.h"

extern volatile int8_t PCINTMEM0;
  #define PCINTM0 0
  #define PCINTM1 1
  #define PCINTM2 2
  #define PCINTM3 3
  #define PCINTM4 4
  #define PCINTM5 5
  #define PCINTM6 6
  #define PCINTM7 7

extern volatile int8_t BTNCNTRL;
  #define CHGNUM0 0
  #define CHGNUM1 1
  #define CHANGE0 2
  #define CHANGE1 3 
  #define POTRL0  4
  #define POTRL1  5
  #define DBNCPSD 7

extern uint16_t debounceStartTime;
extern volatile uint16_t globalTimeMillis;
extern volatile uint16_t lastChangeTime;

#define debounceTime 200
#define CHANGETMT 800


//PIN CHANGE INTERRUPT VECTOR FUNCTIONS
//INLINE FUNCTION
#define PCINT5FUNCTION
inline void PCINT5FUNC(){
      if(!(BTNCNTRL & (1<<CHANGE0))){
        PCMSK0 &= ~(1 << PCINT5);
        BTNCNTRL |= ( 1 << CHANGE0 );
        lastChangeTime = globalTimeMillis;
        return;
      }  
      else if(!(BTNCNTRL & (1<<CHANGE1))){
        PCMSK0 &= ~(1 << PCINT5);
        BTNCNTRL |= ( 1 << CHANGE1 );
        lastChangeTime = globalTimeMillis;
        return;
      }
      else{
        PCMSK0 &= ~(1 << PCINT5);
        BTNCNTRL &= ~((1<<CHANGE0) | (1<<CHANGE1));
        BTNCNTRL |= ((1<<CHGNUM1) | (1<<CHGNUM0));
        return;
      }
}


#endif