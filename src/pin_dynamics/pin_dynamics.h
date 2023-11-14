#ifndef PIN_DYNAMICS_H
#define PIN_DYNAMICS_H
#include <stdint.h>
#include <avr/io.h>
#include <math.h>


#define S1 11
#define S2 21
#define S3 31
#define L1 12
#define L2 22
#define L3 32
extern volatile int8_t BTNCNTRL;
  #define SHRTCLK 0
  #define LONGCLK 1
  #define DBNCPSD 2

extern volatile uint16_t globalTimeMillis;
extern volatile uint8_t  allRemainingFract;
void atomicDebounceReEnable();


//INLINE FUNCTIONS DEFINITIONS

inline uint16_t readPot(){
  ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX3));
  ADCSRA |= (1<<ADSC);
  uint16_t ADCVAL;
  ADCVAL = (ADCL) + (ADCH<<8);
  return ADCVAL;
}

inline uint8_t potButtonComb(){
uint8_t cont = floor(readPot()/340);
  if(BTNCNTRL&(1<<SHRTCLK)){
    if(cont == 0){cont = S1;}
      else if(cont == 1){cont = S2;}
      else{cont = S3;}
    }
  else if(BTNCNTRL&(1<<LONGCLK)){
    if(cont == 0){cont = L1;}
      else if(cont == 1){cont = L2;}
      else{cont = L3;}
    }
        BTNCNTRL &= ~(( 1 << SHRTCLK) | ( 1 << LONGCLK));
  return cont;
}

#endif



