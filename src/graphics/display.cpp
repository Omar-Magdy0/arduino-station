#include "display.h"
#include "applicationManager.h"


#define screenWidth 128
#define screenHeight 64
#define reset -1

lightDisplay Screen = lightDisplay(screenWidth,screenHeight,&Wire);
void screenInitialize(){
    if(Screen.begin(SSD1306_SWITCHCAPVCC,0x3C,true))
        return;
    else{
        Serial.println("screen Failed");
        while(1);
    }
}


