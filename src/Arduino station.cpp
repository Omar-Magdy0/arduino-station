#include <Arduino.h>
#include <applicationManager.h>
 

void setup() {
 bootLoader();
}


unsigned long currentTime;

void loop() {
  currentTime = millis();
  applicationManager();
}