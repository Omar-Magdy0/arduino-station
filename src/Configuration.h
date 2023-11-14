
#ifndef APPLICATIONMENUCONF_H
#define APPLICATIONMENUCONF_H

#include "applicationManager.h"


//extern void motivational();
//extern void hotAirGun();



#define CUSTOMMAINMENU
#ifdef CUSTOMMAINMENU

const char appName1[] PROGMEM = "AC DIM";
const char appName2[] PROGMEM = "DC DIM";
const char appName3[] PROGMEM = "Oscilloscope";
const char appName4[] PROGMEM = "3DFilament";
const char appName5[] PROGMEM = "Hot Air Gun";


const char *appNameslist[4] = {appName1,appName2,appName3,appName4};
#define appMenuSize 4
#define App1 application(appNameslist[0],maintenance)
#define App2 application(appNameslist[1],maintenance)
#define App3 application(appNameslist[2],maintenance)
#define App4 application(appNameslist[3],maintenance)
//#define App5 application("Motivation!!",motivational)
//#define App5 application("Hot Air Gun",hotAirGun)

application menuApps[appMenuSize] = {
App1,
App2,
App3,
App4,
//App5,
//App6,
};


#endif

#endif