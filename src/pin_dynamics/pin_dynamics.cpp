#include "pin_dynamics.h"
#include "gestures.h"



// PIN INTERRUPT VECTORS

//PCINT0-PCINT7 CHANGE VECTOR
ISR(PCINT0_vect){
    //CHECK FOR THE PINS STATES CHANGED BY USING XOR OPERATOR ON PINB(PINS'S CURRENT STATE) AND PCINTMEM0(PIN'S LAST STATE) 
    uint8_t PINCHANGED = PINB ^ PCINTMEM0;
    //STORE CURRENT PIN STATES FOR THE NEXT TIME;
    PCINTMEM0 = PORTB;
  //SWITCH CASE ACCORDING TO WHICH PIN CHANGED
    switch (PINCHANGED)
    {
        #ifdef PCINT0FUNCTION
        case (1<<PCINTM0):
            PCINT0FUNC();
        break;
        #endif
        #ifdef PCINT1FUNCTION
        case (1<<PCINTM1):
            PCINT1FUNC();
        break;
        #endif
        #ifdef PCINT2FUNCTION
        case (1<<PCINTM2):
            PCINT2FUNC();
        break;
        #endif
        #ifdef PCINT3FUNCTION
        case (1<<PCINTM3):
            PCINT3FUNC();
        break;
        #endif
        #ifdef PCINT4FUNCTION
        case (1<<PCINTM4):
            PCINT4FUNC();
        break;
        #endif
        #ifdef PCINT5FUNCTION
        case (1<<PCINTM5):
            PCINT5FUNC();
        break;
        #endif
        #ifdef PCINT6FUNCTION
        case (1<<PCINTM6):
            PCINT6FUNC();
        break;
        #endif
        #ifdef PCINT7FUNCTION
        case (1<<PCINTM7):
            PCINT7FUNC();
        break;
        #endif
  }
};