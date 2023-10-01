#include <Arduino.h>
#include "applicationManager.h"
 

void setup() {
 defaultBootLoader();
}


unsigned long currentTime;

void loop() {
  currentTime = millis();
  applicationManager();
}