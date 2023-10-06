#include <Arduino.h>
#include <applicationManager.h>



const unsigned char evilMotivation [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x1c, 0x7f, 0x10, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x33, 0x0c, 0x18, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x21, 0x08, 0x18, 0xc4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x20, 0x08, 0x2c, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x30, 0x08, 0x24, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x0e, 0x08, 0x24, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x08, 0x7e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x08, 0x42, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xf8, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x61, 0x08, 0xc2, 0x10, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xf8, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x3e, 0x08, 0x81, 0x10, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0xfc, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x7c, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x7e, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x3f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x3f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf0, 0x7f, 0x80, 0x00, 0x00, 
	0x00, 0xe3, 0xf9, 0xe0, 0x70, 0x01, 0x0f, 0x00, 0x38, 0x00, 0x0f, 0xf0, 0x7f, 0x00, 0x07, 0x00, 
	0x01, 0x10, 0x43, 0x11, 0x88, 0xc1, 0x19, 0x80, 0x1f, 0x00, 0x07, 0xf8, 0xfe, 0x00, 0x1e, 0x00, 
	0x02, 0x10, 0x43, 0x19, 0x04, 0xe1, 0x30, 0xc0, 0x0f, 0xc0, 0x03, 0xff, 0xfc, 0x00, 0x7c, 0x00, 
	0x02, 0x00, 0x43, 0x0a, 0x04, 0xb1, 0x20, 0x40, 0x07, 0xe0, 0x01, 0xff, 0xf8, 0x00, 0xf8, 0x00, 
	0x01, 0x80, 0x43, 0x1a, 0x06, 0x91, 0x20, 0x00, 0x03, 0xf8, 0x00, 0xff, 0xf8, 0x03, 0xf8, 0x00, 
	0x00, 0xe0, 0x43, 0xf2, 0x06, 0x89, 0x23, 0xc0, 0x03, 0xfe, 0x00, 0xff, 0xf0, 0x07, 0xf0, 0x00, 
	0x00, 0x10, 0x43, 0x22, 0x06, 0x8d, 0x20, 0x44, 0x01, 0xff, 0x00, 0x7f, 0xf0, 0x0f, 0xe0, 0x10, 
	0x00, 0x18, 0x43, 0x13, 0x04, 0x85, 0x20, 0x47, 0x00, 0xff, 0x80, 0x7f, 0xe0, 0x1f, 0xe0, 0x30, 
	0x02, 0x10, 0x43, 0x11, 0x0c, 0x83, 0x10, 0x83, 0x80, 0xff, 0xc0, 0x3f, 0xe0, 0x3f, 0xe0, 0xe0, 
	0x01, 0xf0, 0x43, 0x08, 0xf8, 0x81, 0x0f, 0x81, 0xe0, 0xff, 0xe0, 0x3f, 0xe0, 0x7f, 0xc1, 0xe0, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0xf0, 0x3f, 0xe0, 0xff, 0xc3, 0xc0, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x7f, 0xf0, 0x3f, 0xc0, 0xff, 0xc3, 0x80, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x7f, 0xe0, 0x3f, 0xc0, 0x7f, 0x87, 0x80, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x3f, 0xe0, 0x3f, 0xc0, 0x7f, 0x8f, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x3f, 0xe0, 0x3f, 0xe0, 0x7f, 0x9f, 0x00, 
	0x00, 0x00, 0x01, 0x24, 0x08, 0x70, 0x00, 0x00, 0x1f, 0x3f, 0xe0, 0x3f, 0xe0, 0x7f, 0x9e, 0x00, 
	0x00, 0x00, 0x23, 0x26, 0x08, 0xcc, 0x00, 0x00, 0x1f, 0xbf, 0xf0, 0x7f, 0xf0, 0xff, 0xbe, 0x00, 
	0x00, 0x00, 0x26, 0x27, 0x09, 0x04, 0x00, 0x00, 0x1f, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 
	0x00, 0x00, 0x24, 0x25, 0x09, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x00, 0x00, 0x28, 0x24, 0x89, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x00, 0x00, 0x38, 0x24, 0xc9, 0x1c, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xfc, 0x00, 
	0x00, 0x00, 0x2c, 0x24, 0x49, 0x02, 0x00, 0x00, 0x07, 0xdf, 0xff, 0xf0, 0x7f, 0xff, 0xfc, 0x00, 
	0x00, 0x00, 0x24, 0x24, 0x29, 0x06, 0x00, 0x00, 0x07, 0x9f, 0xc7, 0xf0, 0x3f, 0x1f, 0x38, 0x00, 
	0x00, 0x00, 0x22, 0x24, 0x19, 0x84, 0x00, 0x00, 0x07, 0xdf, 0xc3, 0xf0, 0x3f, 0x1f, 0x38, 0x00, 
	0x00, 0x00, 0x21, 0x24, 0x18, 0xf8, 0x00, 0x00, 0x07, 0xff, 0xe7, 0xf8, 0x7f, 0x3f, 0xf8, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xc0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char cuteMotivation [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x02, 0x10, 0x00, 0x12, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x02, 0x13, 0x22, 0x1b, 0xc6, 0x13, 0x92, 0x00, 0x00, 0x07, 0xfe, 0x00, 0x00, 0xff, 0xc0, 0x00, 
	0x02, 0x14, 0xb2, 0x13, 0x29, 0xa6, 0x52, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x07, 0xff, 0xf0, 0x00, 
	0x03, 0xf4, 0x54, 0x12, 0x28, 0xa4, 0x52, 0x00, 0x00, 0x7f, 0xff, 0xe0, 0x0f, 0xff, 0xfc, 0x00, 
	0x02, 0x17, 0x94, 0x12, 0x2f, 0xa7, 0xd2, 0x00, 0x00, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xfe, 0x00, 
	0x02, 0x14, 0x0c, 0x12, 0x28, 0x24, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff, 0x00, 
	0x02, 0x13, 0x88, 0x1a, 0x27, 0x23, 0x92, 0x00, 0x03, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0x80, 
	0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0x80, 
	0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xc0, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
	0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
	0x03, 0x86, 0x73, 0x04, 0xc0, 0xc0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
	0x02, 0x49, 0x44, 0x85, 0x21, 0x20, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
	0x02, 0x51, 0x48, 0x85, 0x00, 0x20, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
	0x02, 0x5f, 0x4f, 0x84, 0xe1, 0xe0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
	0x02, 0x50, 0x48, 0x04, 0x21, 0x20, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
	0x02, 0x4f, 0x47, 0x85, 0xe1, 0xe0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
	0x00, 0x00, 0x01, 0x00, 0x10, 0x00, 0x01, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
	0x03, 0x31, 0xd9, 0x18, 0xd3, 0x88, 0x39, 0x80, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
	0x02, 0x49, 0x25, 0x65, 0x34, 0x50, 0x45, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
	0x02, 0x45, 0x25, 0x45, 0x14, 0x50, 0x45, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
	0x02, 0x79, 0x25, 0x45, 0x17, 0xd0, 0x45, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
	0x02, 0x41, 0x25, 0x45, 0x14, 0x10, 0x45, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0x02, 0x79, 0x25, 0x44, 0xf3, 0x90, 0x39, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 
	0x02, 0x00, 0x00, 0x08, 0x00, 0x01, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x03, 0x86, 0x09, 0x09, 0x80, 0x31, 0x08, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
	0x02, 0x49, 0x49, 0x0a, 0x49, 0x49, 0x48, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
	0x02, 0x51, 0x5d, 0x0a, 0x29, 0x45, 0x48, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 
	0x02, 0x51, 0x76, 0x0a, 0x2a, 0x79, 0x70, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 
	0x02, 0x51, 0x36, 0x0a, 0x26, 0x41, 0x30, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
	0x02, 0x4e, 0x26, 0x09, 0xc4, 0x79, 0x30, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfc, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xf8, 0x00, 0x00, 
	0x04, 0x4c, 0x08, 0x31, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x00, 
	0x06, 0x52, 0x48, 0x49, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xc0, 0x00, 0x00, 
	0x02, 0x91, 0x48, 0x09, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0x80, 0x00, 0x00, 
	0x02, 0xa1, 0x48, 0x79, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 
	0x01, 0x92, 0x48, 0x49, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x00, 
	0x01, 0x1e, 0x78, 0x79, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00, 
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 
	0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


int8_t motivationType = 0;
void motivational(){
    if(gestureType == shortClick){
        if (motivationType == 0){motivationType = 1;}
        else{motivationType = 0;}
        }

if (motivationType == 0){
display.clearDisplay();
display.drawBitmap(0,0,cuteMotivation,128,64,WHITE);
display.display();
}
else {
display.clearDisplay();
display.drawBitmap(0,0,evilMotivation,128,64,WHITE);
display.display();
}

if(appClosing){
//do whatever you want before closing app
appClosing = false;
appRunning = false;
}
}