#include "display.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>


#define screenWidth 128
#define screenHeight 64
#define reset -1
Adafruit_SSD1306 disp(screenWidth, screenHeight, &Wire, reset);

void checkForScreen(){if(!disp.begin(SSD1306_SWITCHCAPVCC, 0x3c)){for(;;);}else{disp.clearDisplay();}}

