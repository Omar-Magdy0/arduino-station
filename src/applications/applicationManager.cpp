#include <applicationManager.h>
#include <Configuration.h>
// Menu Grid is like that 
// 1st box 128x20px 
// 2nd box 128x20px (has white rectangle)
// 3rd box 128x20px 

//Menu Items 


#ifndef CUSTOMMAINMENU
#define App1 application("APP1",maintenance)
#define App2 application("APP2",maintenance)
#define App3 application("APP3",maintenance)
#define App4 application("APP4",maintenance)
#define App5 application("APP5",maintenance)
#define App6 application("APP6",maintenance)
#define appMenuSize 6
application menuApps[appMenuSize] = {
App1,
App2,
App3,
App4,
App5,
App6,
};
#endif

textBox Box1 = textBox("",0,0);


int8_t appMenuIndexer(int8_t num){
    if(num > (appMenuSize - 1)){num = 0;}
    else if(num < 0){num = (appMenuSize - 1);}    
    return num;

}

//optimisable lines below
int8_t menuIndex = 0;
bool mainMenuJustOpen = true,appRunning = false,appJustRun = false,appClosing = false;
int8_t gestureType;
int16_t controlPot;



inline void applicationManager(){

controlPot = readPot();
gestureType = gestureHandler();

if (appRunning){
	menuApps[menuIndex].runApp();
	if(gestureType == veryLongClick){appClosing = true;mainMenuJustOpen = true;
	}
return;
}


else if(!appRunning){
if (mainMenuJustOpen){

display.clearDisplay();

	Box1.text = menuApps[appMenuIndexer(menuIndex - 1)].name();
	Box1.textRectCenterer(0,2,128,20,1);
	Box1.textDisplaySans(WHITE,0);
	Box1.text = menuApps[appMenuIndexer(menuIndex)].name();
	Box1.textRectCenterer(0,22,128,20,1);
    Box1.textDisplaySans(WHITE,0);
	Box1.text = menuApps[appMenuIndexer(menuIndex + 1)].name();
	Box1.textRectCenterer(0,42,128,20,1);
    Box1.textDisplaySans(WHITE,0);
	display.drawRect(0,22,128,20,WHITE);
    display.drawRect(1,23,126,18,WHITE);
    display.display();
    mainMenuJustOpen = false;
}
 

if (gestureType == shortClick){
menuIndex++;if(menuIndex > (appMenuSize - 1)){menuIndex = 0;}
display.clearDisplay();
Box1.text = menuApps[appMenuIndexer(menuIndex - 1)].name();
Box1.textRectCenterer(0,2,128,20,1);
Box1.textDisplaySans(WHITE,0);
Box1.text = menuApps[appMenuIndexer(menuIndex)].name();
Box1.textRectCenterer(0,22,128,20,1);
Box1.textDisplaySans(WHITE,0);
Box1.text = menuApps[appMenuIndexer(menuIndex + 1)].name();
Box1.textRectCenterer(0,42,128,20,1);
Box1.textDisplaySans(WHITE,0);

    display.drawRect(0,22,128,20,WHITE);
    display.drawRect(1,23,126,18,WHITE);
display.display();
}


else if (gestureType == veryLongClick){
menuApps[menuIndex].runApp();appJustRun = true;Serial.print("appprunning");
}
}



/*
else if (gestureType == doubleClick){
menuIndex--;if(menuIndex < (0)){menuIndex = appMenuSize -1;}
display.clearDisplay();
Box1.text = menuApps[appMenuIndexer(menuIndex - 1)].name();
Box1.textRectCenterer(0,2,128,20,1);
Box1.textDisplaySans(WHITE,0);
Box1.text = menuApps[appMenuIndexer(menuIndex)].name();
Box1.textRectCenterer(0,22,128,20,1);
Box1.textDisplaySans(WHITE,0);
Box1.text = menuApps[appMenuIndexer(menuIndex + 1)].name();
Box1.textRectCenterer(0,42,128,20,1);
Box1.textDisplaySans(WHITE,0);
    display.drawRect(0,22,128,20,WHITE);
    display.drawRect(1,23,126,18,WHITE);
display.display();
}
*/
}




//maintenance Screen

const unsigned char maintenanceScreen [] PROGMEM = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xf1, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x01, 0xff, 0x81, 0xf0, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0xfe, 0x00, 0x70, 0x7f, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x7c, 0x00, 0x38, 0x7f, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0x80, 0x7c, 0x00, 0x1c, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xc0, 0x7e, 0x00, 0x0f, 0xff, 
	0xff, 0xff, 0xf3, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0x80, 0x3f, 0x00, 0x07, 0xff, 
	0xfb, 0x93, 0x20, 0xc1, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0x00, 0x3f, 0x80, 0x03, 0xff, 
	0xfb, 0x93, 0x26, 0x4f, 0x37, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xc0, 0x01, 0xff, 
	0xfb, 0x91, 0x26, 0x43, 0x27, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xc0, 0x00, 0xff, 
	0xfb, 0x94, 0x27, 0x41, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0x80, 0x00, 0x7f, 
	0xfb, 0xb6, 0x26, 0x4f, 0x27, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xc0, 0x00, 0x7f, 
	0xf9, 0x36, 0x26, 0x4f, 0x27, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x1f, 0xe0, 0x00, 0xff, 
	0xf8, 0x37, 0x20, 0xc1, 0x37, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x0e, 0x70, 0x01, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x1c, 0x38, 0x03, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x18, 0x38, 0x1c, 0x07, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x70, 0x1e, 0x0f, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xe0, 0x1f, 0x1f, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 
	0xf9, 0xff, 0xff, 0xff, 0xfe, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x01, 0xcf, 0xff, 0xff, 
	0xf8, 0x30, 0x9c, 0x86, 0xf8, 0x30, 0x4f, 0x20, 0x9d, 0x03, 0xff, 0xfc, 0x03, 0x87, 0xff, 0xff, 
	0xfb, 0xb7, 0xdd, 0xbe, 0xf3, 0x93, 0x06, 0x27, 0x8d, 0xcf, 0xff, 0xfe, 0x07, 0x00, 0x0f, 0xff, 
	0xfb, 0x90, 0xc9, 0x86, 0xf3, 0x93, 0x06, 0x27, 0x85, 0xcf, 0xff, 0xc7, 0x0e, 0x00, 0x03, 0xff, 
	0xfb, 0x90, 0xc9, 0x86, 0xf7, 0xd0, 0x48, 0x20, 0x95, 0xcf, 0xff, 0x83, 0x9e, 0x00, 0x01, 0xff, 
	0xfb, 0x97, 0xeb, 0xbe, 0xf3, 0x90, 0xc9, 0x27, 0x91, 0xcf, 0xff, 0x01, 0xff, 0x00, 0x01, 0xff, 
	0xfb, 0x37, 0xe3, 0x9e, 0x73, 0x93, 0xcf, 0x27, 0x99, 0xcf, 0xfe, 0x00, 0xff, 0x80, 0x00, 0xff, 
	0xf8, 0x70, 0xe3, 0x82, 0x08, 0x33, 0xcf, 0x20, 0x99, 0xcf, 0xf8, 0x00, 0xff, 0x80, 0x00, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0xff, 0x80, 0x00, 0x7f, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0xff, 0x00, 0x00, 0x7f, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x01, 0xff, 0x00, 0x30, 0x7f, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xff, 0x80, 0xf8, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x07, 0xff, 0x80, 0x7c, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0f, 0xff, 0x80, 0x3f, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xc0, 0x1f, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x7f, 0xff, 0xe0, 0x0f, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xf0, 0x0f, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xfc, 0x1f, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};


void maintenance(){
    display.clearDisplay();
    display.drawBitmap(0,0,maintenanceScreen,128,64,WHITE);
    display.display();
	if(appClosing){
//do whatever you want before closing app
appClosing = false;
appRunning = false;
}
}







