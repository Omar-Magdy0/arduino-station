#ifndef MAINMENU_H
#define MAINMENU_H
#include <Arduino.h>
#include <display.h>
#include <pin_dynamics.h>
#include <FlashStringTable.h>



//Define HOW YOUR PINS HERE AND GIVE THEM PURPOSE ON BOOTLOADER OR INDIVIDUAL APPLICATION FILES
// (PIN 13 AND PIN 17 UNIQUE FOR BUTTON AND POT)
#define mainButton 13
#define mainPot 14
 
void maintenance();
extern bool mainMenuJustOpen,appRunning;

class application{
private:
void (*appLoopingFunction)();
const char* appname PROGMEM;
public:
const char* name(){return appname;}
application(const char* name,void (*function)()){appname = name;appLoopingFunction = function;}
void runApp(){appRunning = true;appLoopingFunction();}
void closeApp(){appRunning = false;}
};


extern bool appJustRun;
extern application menuApps[];
extern int8_t gestureType;
extern int16_t controlPot;
extern textBox Box1;
void applicationManager();
void defaultBootLoader();
#endif



