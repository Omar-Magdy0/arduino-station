#include <Arduino.h>
#include <display.h>
#include <applicationManager.h>

const unsigned char MGSLOGO [] PROGMEM = {
0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x06, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x07, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x07, 0x3f, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xc7, 0xff, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x01, 0xe7, 0xfe, 0x30, 0x01, 0xfe, 0x00, 0x3f, 0xc0, 0x1f, 0xff, 0x00, 0x3f, 0xfc, 0x00, 
	0x00, 0x00, 0xff, 0x00, 0x38, 0x01, 0xfe, 0x00, 0x3f, 0xc0, 0x7f, 0xff, 0xc0, 0xff, 0xff, 0x00, 
	0x00, 0x00, 0xfc, 0x00, 0x10, 0x01, 0xff, 0x00, 0x7f, 0xc0, 0xff, 0xff, 0xe3, 0xff, 0xff, 0x00, 
	0x00, 0x00, 0x70, 0x00, 0x00, 0x01, 0xff, 0x00, 0x7f, 0xc3, 0xff, 0xff, 0xe7, 0xff, 0xff, 0x00, 
	0x00, 0x0c, 0xe0, 0x00, 0x00, 0x01, 0xff, 0x80, 0x7f, 0xc3, 0xff, 0xff, 0xe7, 0xff, 0xff, 0x00, 
	0x00, 0x1f, 0xc0, 0x00, 0x02, 0x01, 0xff, 0x80, 0xff, 0xc7, 0xfc, 0x03, 0xef, 0xf0, 0x0f, 0x00, 
	0x00, 0x0f, 0x80, 0x00, 0x08, 0x01, 0xff, 0x80, 0xff, 0xcf, 0xf8, 0x00, 0xef, 0xe0, 0x03, 0x00, 
	0x00, 0x07, 0x00, 0x00, 0x10, 0x01, 0xff, 0xc1, 0xff, 0xcf, 0xf0, 0x00, 0x6f, 0xe0, 0x01, 0x00, 
	0x00, 0x07, 0x00, 0x00, 0x00, 0x81, 0xff, 0xc1, 0xff, 0xdf, 0xe0, 0x00, 0x0f, 0xe0, 0x00, 0x00, 
	0x00, 0x06, 0x00, 0x00, 0x20, 0x01, 0xff, 0xe3, 0xff, 0xdf, 0xc0, 0x00, 0x0f, 0xf8, 0x00, 0x00, 
	0x00, 0x3e, 0x00, 0x00, 0x40, 0x01, 0xfb, 0xe3, 0xef, 0xdf, 0xc0, 0x00, 0x0f, 0xff, 0x00, 0x00, 
	0x00, 0x7e, 0x00, 0x00, 0xc0, 0x01, 0xfb, 0xf7, 0xef, 0xdf, 0xc0, 0x00, 0x07, 0xff, 0xf0, 0x00, 
	0x00, 0x3c, 0x00, 0x40, 0x80, 0x01, 0xf9, 0xf7, 0xcf, 0xdf, 0xc1, 0xff, 0xe7, 0xff, 0xfc, 0x00, 
	0x00, 0x0c, 0x00, 0xe1, 0x80, 0x31, 0xf9, 0xff, 0xcf, 0xdf, 0xc1, 0xff, 0xe3, 0xff, 0xfe, 0x00, 
	0x00, 0x0c, 0x01, 0xf3, 0x00, 0x39, 0xf9, 0xff, 0x8f, 0xdf, 0xc1, 0xff, 0xe1, 0xff, 0xff, 0x00, 
	0x00, 0x0c, 0x01, 0x9e, 0x00, 0x19, 0xf8, 0xff, 0x8f, 0xdf, 0xc1, 0xff, 0xe0, 0x7f, 0xff, 0x80, 
	0x00, 0x7c, 0x03, 0x1e, 0x00, 0x0d, 0xf8, 0xff, 0x8f, 0xdf, 0xc1, 0xff, 0xe0, 0x0f, 0xff, 0x80, 
	0x00, 0x3e, 0x03, 0x0c, 0x00, 0x0d, 0xf8, 0x7f, 0x0f, 0xdf, 0xc0, 0x0f, 0xe0, 0x00, 0xff, 0x80, 
	0x00, 0x3e, 0x06, 0x04, 0x00, 0x7f, 0xf8, 0x7f, 0x0f, 0xdf, 0xe0, 0x0f, 0xe0, 0x00, 0x3f, 0x80, 
	0x00, 0x06, 0x04, 0x00, 0x00, 0x7f, 0xf8, 0x7e, 0x0f, 0xcf, 0xe0, 0x0f, 0xe8, 0x00, 0x3f, 0x80, 
	0x00, 0x07, 0x08, 0x00, 0x00, 0x7f, 0xf8, 0x3e, 0x0f, 0xcf, 0xf0, 0x0f, 0xec, 0x00, 0x3f, 0x80, 
	0x00, 0x07, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x0f, 0xc7, 0xfc, 0x0f, 0xef, 0x00, 0x3f, 0x80, 
	0x03, 0x1f, 0x90, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x0f, 0xc7, 0xff, 0x0f, 0xef, 0xe0, 0xff, 0x00, 
	0x03, 0x8f, 0x80, 0x00, 0x01, 0xff, 0xf8, 0x00, 0x0f, 0xc3, 0xff, 0xff, 0xef, 0xff, 0xff, 0x00, 
	0x07, 0xc8, 0xc0, 0x00, 0x03, 0xff, 0xf8, 0x00, 0x0f, 0xc1, 0xff, 0xff, 0xef, 0xff, 0xfe, 0x00, 
	0x07, 0xe0, 0x60, 0x00, 0x01, 0xff, 0xf8, 0x00, 0x0f, 0xc0, 0xff, 0xff, 0xef, 0xff, 0xfc, 0x00, 
	0x0f, 0xf0, 0xf8, 0x00, 0x11, 0xff, 0xf8, 0x00, 0x0f, 0xc0, 0x3f, 0xff, 0x83, 0xff, 0xf0, 0x00, 
	0x0f, 0xf9, 0xfe, 0x00, 0x3b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0x1f, 0xfe, 0xc7, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0x1f, 0xff, 0x07, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0x3f, 0xff, 0xc7, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0x3f, 0xff, 0xf6, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0x7f, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80
};


const unsigned char BIGANTLOGO [] PROGMEM = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xc0, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0x80, 0x00, 0x00, 0x1c, 0x00, 0x00, 
	0xfe, 0x08, 0x1f, 0x80, 0x7c, 0x40, 0x7f, 0x80, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x18, 0x00, 0x00, 
	0xfe, 0x08, 0x0f, 0x80, 0x78, 0x40, 0x3f, 0x81, 0xfc, 0x03, 0xf8, 0x00, 0x00, 0x30, 0x00, 0x00, 
	0xfe, 0x08, 0x07, 0x80, 0x70, 0x40, 0x1f, 0x83, 0xf0, 0x00, 0x3e, 0x00, 0x00, 0x30, 0x00, 0x00, 
	0xfe, 0x0f, 0x83, 0xc1, 0xf0, 0x7c, 0x1f, 0x8f, 0xe0, 0x00, 0x0f, 0x00, 0x00, 0x60, 0x00, 0x00, 
	0xfe, 0x0f, 0x83, 0xc1, 0xf0, 0x7f, 0xff, 0x8f, 0x80, 0x00, 0x03, 0xc0, 0x00, 0x60, 0x00, 0x00, 
	0xfe, 0x0f, 0x83, 0xc1, 0xf0, 0x7f, 0xff, 0x8f, 0x00, 0x00, 0x01, 0xe0, 0x00, 0xc0, 0x00, 0x00, 
	0xfe, 0x0f, 0x83, 0xc1, 0xf0, 0x7f, 0xff, 0x86, 0x00, 0x00, 0x01, 0xf0, 0x00, 0xc0, 0x00, 0x00, 
	0xfe, 0x08, 0x07, 0xc1, 0xf0, 0x70, 0x1f, 0x80, 0x00, 0x00, 0x00, 0xff, 0x9d, 0x80, 0x00, 0x00, 
	0xfe, 0x08, 0x07, 0xc1, 0xf0, 0x70, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x7b, 0x9f, 0x80, 0x00, 0x00, 
	0xfe, 0x0f, 0x83, 0xc1, 0xf0, 0x70, 0x1f, 0x80, 0x00, 0x00, 0x00, 0xbf, 0x9f, 0xc0, 0x00, 0x00, 
	0xfe, 0x0f, 0x83, 0xc1, 0xf0, 0x7e, 0x1f, 0x80, 0x00, 0x00, 0x03, 0xdd, 0x9f, 0xf0, 0x00, 0x00, 
	0xfe, 0x0f, 0x83, 0xc1, 0xf0, 0x7e, 0x1f, 0x80, 0x00, 0x00, 0x07, 0xef, 0x9f, 0xf8, 0x00, 0x00, 
	0xfe, 0x0f, 0x83, 0xc1, 0xf0, 0x7e, 0x1f, 0x80, 0x00, 0x00, 0x0f, 0xf7, 0x9f, 0xf8, 0x00, 0x00, 
	0xfe, 0x08, 0x07, 0x80, 0x78, 0x06, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x7b, 0x9f, 0xfc, 0x00, 0x00, 
	0xfe, 0x08, 0x0f, 0x80, 0x7c, 0x06, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x1f, 0x9f, 0x8e, 0x00, 0x00, 
	0xfe, 0x08, 0x1f, 0x80, 0x7e, 0x06, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x0f, 0x9f, 0x06, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x0f, 0x9e, 0x03, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x07, 0x9e, 0x01, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x07, 0x9c, 0x01, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x07, 0x9c, 0x01, 0x80, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x07, 0x9c, 0x00, 0x80, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x07, 0x9c, 0x00, 0x80, 0x00, 
	0xff, 0xc1, 0xfe, 0x07, 0xc3, 0x80, 0x03, 0x80, 0x00, 0x00, 0x00, 0x07, 0x9c, 0x00, 0x80, 0x00, 
	0xff, 0xc1, 0xff, 0x07, 0xc3, 0x80, 0x03, 0x80, 0x00, 0x00, 0x00, 0x07, 0x9c, 0x01, 0x80, 0x00, 
	0xff, 0x61, 0xff, 0x83, 0xc3, 0x80, 0x03, 0x80, 0x00, 0x00, 0x00, 0x07, 0x9c, 0x01, 0x80, 0x00, 
	0xff, 0x20, 0xfe, 0x83, 0xc3, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x0f, 0x9e, 0x01, 0x80, 0x00, 
	0xff, 0x30, 0xfe, 0xc1, 0xc3, 0xf8, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x0f, 0x9e, 0x03, 0x80, 0x00, 
	0xfe, 0x30, 0x7e, 0x60, 0xc3, 0xf8, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x1f, 0x9f, 0x03, 0x80, 0x00, 
	0xfe, 0x10, 0x7e, 0x20, 0xc3, 0xf8, 0x3f, 0x80, 0x00, 0x00, 0x10, 0x7f, 0x9f, 0x8f, 0x80, 0x00, 
	0xfe, 0x18, 0x7e, 0x30, 0x43, 0xf8, 0x3f, 0x80, 0x00, 0x00, 0x0f, 0xff, 0x9f, 0xff, 0x00, 0x00, 
	0xfc, 0x38, 0x3e, 0x10, 0x63, 0xf8, 0x3f, 0x80, 0x00, 0x00, 0x0f, 0xff, 0x9f, 0xff, 0x00, 0x00, 
	0xfc, 0x3c, 0x3e, 0x18, 0x33, 0xf8, 0x3f, 0x80, 0x00, 0x00, 0x0f, 0xff, 0x9f, 0xff, 0x00, 0x00, 
	0xf8, 0x3c, 0x1e, 0x1c, 0x13, 0xf8, 0x3f, 0x80, 0x00, 0x00, 0x07, 0xff, 0x9f, 0xfe, 0x00, 0x00, 
	0xf8, 0x20, 0x1e, 0x1c, 0x1b, 0xf8, 0x3f, 0x80, 0x00, 0x00, 0x07, 0xff, 0x9f, 0xfc, 0x00, 0x00, 
	0xf8, 0x60, 0x1e, 0x1e, 0x0b, 0xf8, 0x3f, 0x80, 0x00, 0x00, 0x03, 0xfc, 0x1f, 0xfc, 0x00, 0x00, 
	0xf0, 0x40, 0x0e, 0x1e, 0x0f, 0xf8, 0x3f, 0x80, 0x00, 0x00, 0x01, 0xff, 0x9f, 0xf8, 0x00, 0x00, 
	0xf0, 0x7f, 0x0e, 0x1f, 0x07, 0xf8, 0x3f, 0x80, 0x00, 0x00, 0x01, 0xff, 0x9f, 0xf0, 0x00, 0x00, 
	0xf0, 0xff, 0x06, 0x1f, 0x83, 0xf8, 0x3f, 0x80, 0x00, 0x00, 0x01, 0xef, 0x9f, 0xe0, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0xff, 0x1f, 0xc0, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0xfe, 0x1f, 0xc0, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x6e, 0x01, 0xc0, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x2f, 0x01, 0xc0, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x0f, 0x00, 0xc0, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x06, 0x00, 0x80, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x03, 0x01, 0x80, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char INTRODUCING [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x70, 0x00, 0x00, 0xf0, 0x00, 0x38, 
	0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x78, 0x00, 0x00, 0xf0, 0x00, 0x38, 0x00, 
	0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd0, 0x00, 0x00, 0xf1, 0xde, 0x7e, 0xf7, 0x1f, 
	0x03, 0xfc, 0xe7, 0x8f, 0x9e, 0x73, 0x87, 0xe0, 0x00, 0x00, 0xf3, 0xfe, 0x7c, 0xff, 0x3f, 0xcf, 
	0xbd, 0xe7, 0x9f, 0xde, 0x7f, 0xcf, 0xf0, 0x00, 0x00, 0xf3, 0xce, 0x38, 0xf7, 0x79, 0xef, 0x3d, 
	0xe7, 0xbc, 0xde, 0x7b, 0xde, 0xf0, 0x00, 0x00, 0xf3, 0xce, 0x38, 0xf2, 0x79, 0xef, 0x3d, 0xe7, 
	0xbc, 0x1e, 0x7b, 0xde, 0xf0, 0x00, 0x00, 0xf3, 0xce, 0x38, 0xf0, 0x79, 0xef, 0x3d, 0xe7, 0xbc, 
	0x1e, 0x7b, 0xcf, 0xe0, 0x00, 0x00, 0xf3, 0xce, 0x3c, 0xf0, 0x7b, 0xcf, 0xfc, 0xff, 0x9e, 0x1e, 
	0x7b, 0xcc, 0x00, 0x00, 0x00, 0xf3, 0xce, 0x3c, 0xf0, 0x1f, 0x87, 0xfc, 0xff, 0x8f, 0x9e, 0x7b, 
	0xcf, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 
	0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


const unsigned char ATSTATION [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x3f, 0x7b, 0xf3, 0x1f, 0xf3, 0xce, 0x60, 
	0x07, 0x1c, 0xe1, 0xe3, 0x8e, 0x77, 0x6f, 0x60, 0x07, 0x9c, 0xf8, 0xc3, 0x8e, 0x7e, 0x7f, 0xe0, 
	0x0f, 0x9c, 0x7c, 0xc7, 0xce, 0x76, 0x7f, 0xe0, 0x0f, 0xdc, 0x1c, 0xc7, 0xce, 0x77, 0x6d, 0xe0, 
	0x19, 0xdc, 0xf8, 0xcc, 0xee, 0x73, 0xec, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x33, 0x8c, 0xc0, 0x00, 0x00, 
	0x00, 0x00, 0x07, 0x33, 0x8c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x31, 0x8c, 0xe0, 0x00, 0x00, 
	0x00, 0x00, 0x07, 0x31, 0x8c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x31, 0x8c, 0xe0, 0x00, 0x00, 
	0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x00, 
	0x00, 0x01, 0xf8, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x1f, 0xc0, 0x00, 
	0x00, 0x01, 0xf8, 0x09, 0x90, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x18, 0x19, 0x98, 0x18, 0x00, 0x00, 
	0x00, 0x00, 0x18, 0x19, 0x98, 0x18, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x1f, 0xf8, 0x1f, 0xc0, 0x00, 
	0x00, 0x03, 0xf8, 0xff, 0xff, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x19, 0xf7, 0xef, 0x98, 0x00, 0x00, 
	0x00, 0x00, 0x18, 0x3f, 0xfc, 0x18, 0x1c, 0x00, 0x00, 0x00, 0x18, 0x3f, 0xfc, 0x18, 0xfe, 0x00, 
	0x00, 0x13, 0xf9, 0xff, 0xff, 0x9f, 0xfe, 0x00, 0x00, 0x7f, 0xf9, 0xff, 0xff, 0x9f, 0xc8, 0x00, 
	0x00, 0x7f, 0x18, 0x3f, 0xfc, 0x18, 0x00, 0x00, 0x00, 0x38, 0x18, 0x3f, 0xfc, 0x18, 0x00, 0x00, 
	0x00, 0x00, 0x19, 0xf7, 0xef, 0x98, 0x00, 0x00, 0x00, 0x03, 0xf8, 0xff, 0xff, 0x1f, 0xc0, 0x00, 
	0x00, 0x03, 0xf8, 0x1f, 0xf8, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x18, 0x19, 0x98, 0x18, 0x00, 0x00, 
	0x00, 0x00, 0x18, 0x19, 0x98, 0x18, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x09, 0x90, 0x1f, 0xc0, 0x00, 
	0x00, 0x03, 0xf8, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x1f, 0x80, 0x00, 
	0x00, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x07, 0x31, 0x8c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x31, 0x8c, 0xe0, 0x00, 0x00, 
	0x00, 0x00, 0x07, 0x31, 0x8c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x31, 0xcc, 0xe0, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0x31, 0xcc, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


void defaultBootLoader(){

pinMode(mainButton,INPUT_PULLUP); pinMode(mainPot,INPUT); 
 checkForScreen();
 Serial.begin(9600);


display.clearDisplay();
display.drawBitmap(1,10,MGSLOGO,126,44,WHITE);
display.display();
delay(3000);
display.clearDisplay();
display.drawBitmap(0,0,BIGANTLOGO,128,64,WHITE);
display.display();
delay(3000);
display.clearDisplay();
display.drawBitmap(5,27,INTRODUCING,118,17,WHITE);
display.display();
delay(1000);
display.clearDisplay();
display.drawBitmap(32,0,ATSTATION,64,64,WHITE);
display.display();
delay(3000);

}

