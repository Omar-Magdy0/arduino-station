#ifndef MAINMENU_H
#define MAINMENU_H
#include <Arduino.h>
#include "display.h"
#include "pin_dynamics.h"
#include <avr/pgmspace.h>


class application{
private:
void (*appLoopingFunction)();
const char* appName;
public:
application(const char* name,void (*function)()){appName = name;appLoopingFunction = function;}
const char* getName(){
    return appName ;}
void(*getAppMainFunc())(){return appLoopingFunction;}
};
 

#define START 1
#define END 0
extern void clk1CountMillis(uint8_t command);
extern application menuApps[];
extern textBox Box1;
extern void(*appFunction)();
extern uint8_t APMNGCTRL;
    #define MNUI0 	0
    #define MNUI1 	1
    #define MNUI2 	2
    #define MNUI3 	3
    #define PGCHNG 	4
    #define APRNNG  5
    #define MMJO 	6  
void applicationManager();
void maintenance();
void defaultBootLoader();
#endif



