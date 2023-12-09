#include "pin_dynamics.h"
#include "gestures.h"



uint8_t lastNumOfClicks = 0;
//UPDATES UI according to clicks or POT part change
void controlUI(uint16_t potReading){
  //PART TO GET THE CURRENT NUM OF CLICKS
	uint8_t numOfClicks = 0;
    if((BTNCNTRL & (1<<CHANGE1))){
        numOfClicks = (1<<CHANGE1);
    }
    else if(BTNCNTRL & (1<<CHANGE0)){
        numOfClicks = (1<<CHANGE0);
    }
    numOfClicks >>= 2;
  
    //PART TO GET THE CURRENT POT READING PART AND COMPARE TO LAST
    uint8_t currentPotReadPart = (potReading/342) + 1;
    //UPDATE LAST POT READING Part BITS
    uint8_t lastPotReadPart = (BTNCNTRL & (1<<POTRL0)) | (BTNCNTRL & (1<<POTRL1)) ;
    lastPotReadPart >>= 4;

  /*****************************************************************/
  // Lambda Functions Part
  //Pot part update function
    auto potReadPartSelect = [&currentPotReadPart,&numOfClicks](){
        Screen.clearPage(BLACK);
        Screen.drawRect((42*(currentPotReadPart - 1) + 1),0,42,8,WHITE);
        if(numOfClicks)
            Screen.drawFillRect((42*currentPotReadPart - 1) + 3,2,numOfClicks*19,4,WHITE);
  };

  //Button CLICK update function
    auto clickFeedback = [&numOfClicks,&lastPotReadPart](){
        Screen.clearPage(BLACK);
        Screen.drawRect((42*(lastPotReadPart - 1) + 1),0,42,8,WHITE);
        if(numOfClicks)
            Screen.drawFillRect((42*(lastPotReadPart - 1) + 3),2,numOfClicks*19,4,WHITE);
    };
    /*****************************************************************/

  //if POT part changes
    if(lastPotReadPart != currentPotReadPart){
        lastPotReadPart = currentPotReadPart;
        BTNCNTRL &= ~((1<<POTRL0) | (1<<POTRL1));
        BTNCNTRL |= (lastPotReadPart<<4); 
        Screen.displayFunctionGroup(0,1,potReadPartSelect);
    }  
  
    //if CLICK part changes

    if(lastNumOfClicks != numOfClicks){
        lastNumOfClicks = numOfClicks;
        Screen.displayFunctionGroup(0,1,clickFeedback);
    }
}






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