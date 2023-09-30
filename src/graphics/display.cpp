#include "display.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>


#define screenWidth 128
#define screenHeight 64
#define reset -1
Adafruit_SSD1306 display(screenWidth, screenHeight, &Wire, reset);

void checkForScreen(){if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)){Serial.println("nooo");for(;;);}else{display.clearDisplay();}}

