
#ifndef APPLICATIONMENUCONF_H
#define APPLICATIONMENUCONF_H

#include "applicationManager.h"


//extern void motivational();
extern void hotAirGun();



#define CUSTOMMAINMENU
#ifdef CUSTOMMAINMENU
#define appMenuSize 5
#define App1 application("AC DIMMER",maintenance)
#define App2 application("DC DIMMER",maintenance)
#define App3 application("Oscilloscope",maintenance)
#define App4 application("3DFilament",maintenance)
//#define App5 application("Motivation!!",motivational)
#define App5 application("Hot Air Gun",hotAirGun)

application menuApps[appMenuSize] = {
App1,
App2,
App3,
App4,
App5,
//App6,
};


#endif

#endif