#include <SPI.h>
#include <Wire.h>
#include "graphics/display.h"
#include <Arduino.h>
#include "pin_dynamics/pin_dynamics.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "applications/applicationManager.h"
 

void setup() {
 bootLoader();
}


unsigned long currentTime;

void loop() {
  currentTime = millis();
  applicationManager();
}