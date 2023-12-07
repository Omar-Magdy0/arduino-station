#include "applicationManager.h"
#include <lightDisplay.h>
#include <PeripheralsCustom/PeripheralsCustom.h>
#include "Arduino.h"


#pragma GCC optimize ("-O3")


int main(){
	  defaultBootLoader();
    while(1){
        atomicDebounceReEnable(); 
        if(APMNGCTRL & (1<<APRNNG)){
          appFunction();
        }
        else{
          applicationManager();
        } 
    }
return 0;
}










