#ifndef PIN_DYNAMICS_H
#define PIN_DYNAMICS_H
#include <Arduino.h>

#define noClick 0
#define shortClick 1
#define longClick 2
#define veryLongClick 3
#define doubleClick 4



int8_t gestureHandler();
int16_t readPot();


#endif