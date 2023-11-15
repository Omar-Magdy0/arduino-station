#ifndef PIN_DYNAMICS_H
#define PIN_DYNAMICS_H
#include <stdint.h>
#include <avr/io.h>
#include <math.h>
#include <avr/interrupt.h>
#include "gestures.h"



extern volatile int8_t PCINTMEM0;
extern volatile int8_t BTNCNTRL;


//GLOBAL TIMING VARIABLES
extern volatile uint16_t globalTimeMillis;
extern volatile uint8_t  allRemainingFract;

//DEFINITIONS FOR THE RETURN OFF potButtonComb()
#define NEXTPAGE  11
#define PREVPAGE  12
#define reserved1 13
#define IPGINDIC  21
#define IPGINDDC  22
#define IPGEDIT   23
#define reserved2 31
#define reserved3 32
#define APPCLOOP  33


//INLINE FUNCTIONS DEFINITIONS

//READ POTENTIOMETER VALUE
inline uint16_t readPot(){
  ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX3));
  ADCSRA |= (1<<ADSC);
  uint16_t ADCVAL;
  ADCVAL = (ADCL) + (ADCH<<8);
  return ADCVAL;
}

//FUNCTION TO READ POTENTIOMETER VALUE AND LAST BUTTON ACTION AND MAKE A COMBOOO!!
inline uint8_t potButtonComb(){
ADCSRA |= (1<<ADSC);
if((BTNCNTRL & (1<<CHGNUM0)) | (BTNCNTRL & (1<<CHGNUM1))){
uint8_t cont = floor(readPot()/342) + 1;
uint8_t numClicks = ((BTNCNTRL & (1<<CHGNUM0)) | (BTNCNTRL & (1<<CHGNUM1)));
BTNCNTRL &= ~((1<<CHGNUM0) | (1<<CHGNUM1));
return (numClicks + cont*10);
}
return 0;
}

//DEBOUNCE FUNCTION
inline void atomicDebounceReEnable(){
  if(!(PCMSK0 & (1 << PCINT5))){
    if(!(BTNCNTRL & (1 << DBNCPSD))){debounceStartTime = globalTimeMillis; BTNCNTRL |= ( 1 << DBNCPSD);}
    // IF BUTTON DEBOUNCED clear boolean flag and re-enable the interrup on button pins
    if((globalTimeMillis - debounceStartTime) >= debounceTime){
      BTNCNTRL &= ~(1 << DBNCPSD);
      PCMSK0 |= (1 << PCINT5);
      return;
    }
  }
  if(BTNCNTRL & (1<<CHANGE1)){
    if((globalTimeMillis - lastChangeTime) >= CHANGETMT){
      if(BTNCNTRL & (1<<CHANGE2)){BTNCNTRL |= (1<<CHGNUM1);}
      else{BTNCNTRL |= (1<<CHGNUM0);}
      BTNCNTRL &= ~((1 << CHANGE1) | (1 << CHANGE2));
    }
  }
}

#endif



