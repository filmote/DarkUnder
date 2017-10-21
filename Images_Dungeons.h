#ifndef IMAGES_DUNGEONS_H
#define IMAGES_DUNGEONS_H

#include "Enums.h"

const unsigned char PROGMEM closeWallFront[] = {
63, 32,
0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 
0x00, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x80, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x80, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x3f, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x80, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x80, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 
0x00, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x1f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x00, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x1f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xc0, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x1f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x00, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x1f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x00, 
0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x5f, 0x8f, 0x0f, 0x8f, 0x0f, 0x8f, 0x0f, 0x8f, 0x0f, 0xa0, 0x4f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 
};

const unsigned char PROGMEM closeGateLocked[] = {
33, 32,
0x00, 0xd6, 0x06, 0xf6, 0xe6, 0x06, 0xd6, 0x06, 0x06, 0x06, 0x06, 0xd6, 0x06, 0x26, 0x16, 0x06, 0xd6, 0x06, 0x06, 0x06, 0x06, 0xd6, 0x06, 0x06, 0x06, 0x06, 0xd6, 0x06, 0xe6, 0xf6, 0x06, 0xd6, 0x00, 
0x00, 0xff, 0x00, 0xbd, 0x83, 0x00, 0xff, 0x00, 0xae, 0xac, 0x00, 0xff, 0x00, 0x00, 0xf8, 0x4c, 0x05, 0x4c, 0xf8, 0x00, 0x00, 0xff, 0x00, 0xac, 0xae, 0x00, 0xff, 0x00, 0x83, 0xbd, 0x00, 0xff, 0x00, 
0x00, 0xff, 0x00, 0xf7, 0x7b, 0x00, 0xff, 0x00, 0x46, 0x02, 0x00, 0xff, 0x00, 0x00, 0x4f, 0x08, 0xe8, 0x08, 0x4f, 0x00, 0x00, 0xff, 0x00, 0x82, 0x06, 0x00, 0xff, 0x00, 0x7b, 0xf7, 0x00, 0xff, 0x00, 
0x00, 0x07, 0x06, 0x06, 0x06, 0x06, 0x07, 0x06, 0x06, 0x06, 0x06, 0x07, 0x06, 0x06, 0x06, 0x06, 0x57, 0x86, 0x06, 0x86, 0x06, 0x87, 0x06, 0x86, 0x06, 0xa6, 0x47, 0x06, 0x06, 0x06, 0x06, 0x07, 0x00, 
};

const unsigned char PROGMEM closeDoorLocked[] = {
20, 24,
0x0e, 0x00, 0xe6, 0x12, 0xc8, 0x08, 0xe4, 0x04, 0x74, 0x04, 0x04, 0xf4, 0x04, 0xe4, 0x08, 0xc8, 0x12, 0xe6, 0x00, 0x0e, 
0x00, 0x00, 0xff, 0x00, 0xbd, 0x00, 0xf7, 0x00, 0x7f, 0x00, 0x00, 0xfe, 0xf6, 0x82, 0x82, 0xf6, 0xfe, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x1f, 0x10, 0x17, 0x10, 0x17, 0x10, 0x17, 0xb0, 0x10, 0x16, 0x10, 0x16, 0x10, 0x16, 0x10, 0x1e, 0x40, 0x80, 
};

const unsigned char PROGMEM closeDoorUnlocked[] = {
20, 24,
0x0e, 0x00, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x82, 0x86, 0x00, 0x0e, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x30, 0xb0, 0x34, 0xb2, 0x34, 0xb2, 0x34, 0xb2, 0x34, 0x00, 0x00, 
0x00, 0x00, 0x10, 0x0c, 0x1c, 0x0d, 0x0c, 0x0d, 0x0c, 0xad, 0x0c, 0x0d, 0x0c, 0x0d, 0x1c, 0x0d, 0x0c, 0x0d, 0x40, 0x80, 
};

// const unsigned char PROGMEM closeGatelocked[] = {
// 20, 24,
// 0x0e, 0x00, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x00, 0x0e, 
// 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x00, 0x00, 0x10, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x40, 0x80, 
// };

const unsigned char PROGMEM closeWallLeft[] = {
15, 56,
0x0d, 0xf2, 0xfb, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x20, 0x00, 0x22, 0x00, 0x22, 0x00, 0x22, 
0x00, 0xbf, 0xbf, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0x00, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 
0x00, 0xff, 0xff, 0xff, 0x00, 0xfe, 0xfe, 0xfd, 0xfc, 0xfb, 0xf7, 0x07, 0xef, 0xef, 0xdf, 
0x00, 0xef, 0xef, 0xef, 0xe0, 0xef, 0xef, 0xef, 0x0f, 0xef, 0xef, 0xe0, 0xef, 0xef, 0xef, 
0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0xbf, 0xdf, 0x1f, 0xef, 0xef, 0xf7, 
0x00, 0xfb, 0xfb, 0xfd, 0x01, 0xfe, 0xfe, 0xff, 0xff, 0x7f, 0x3f, 0x00, 0x0f, 0x07, 0x03, 
0xb0, 0x4f, 0xdf, 0x1f, 0x00, 0x07, 0x03, 0x01, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 
};

const unsigned char PROGMEM closeWallRight[] = {
15, 56,
0x88, 0x00, 0x00, 0x00, 0x80, 0x00, 0x08, 0x80, 0xc8, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0x00, 
0xc0, 0xe0, 0xf0, 0xf9, 0xfc, 0xfe, 0x00, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0xbf, 0xbf, 0x00, 
0xdf, 0xef, 0xef, 0x07, 0xf7, 0xfb, 0xfc, 0xfd, 0xfe, 0xfe, 0x00, 0xff, 0xff, 0xff, 0x00, 
0xef, 0xef, 0xef, 0xe0, 0xef, 0xef, 0x0f, 0xef, 0xef, 0xef, 0xe0, 0xef, 0xef, 0xef, 0x00, 
0xf7, 0xef, 0xef, 0x1f, 0xdf, 0xbf, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
0x03, 0x07, 0x0f, 0x00, 0x3f, 0x7f, 0xff, 0xff, 0xfe, 0xfe, 0x01, 0xfd, 0xfb, 0xfb, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x00, 0x1f, 0x3f, 0x7f, 0x00, 
};

const unsigned char PROGMEM closeGateLeft[] = {
14, 56,
0x0d, 0x02, 0x5b, 0x38, 0x70, 0xe0, 0xc0, 0x80, 0x20, 0x00, 0x22, 0x00, 0x22, 0x40, 
0x00, 0x00, 0xfd, 0x00, 0x00, 0xea, 0x01, 0x03, 0x57, 0x0e, 0x1c, 0xb8, 0x70, 0xe0, 
0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xfa, 0x00, 0xef, 
0x00, 0x00, 0xff, 0xfc, 0xfc, 0x27, 0x48, 0xf8, 0xff, 0x00, 0x00, 0xff, 0x00, 0xef, 
0x00, 0x00, 0xff, 0x0f, 0x0f, 0xe8, 0x04, 0x07, 0xf7, 0x00, 0x00, 0xff, 0x00, 0xef, 
0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x1f, 0x00, 0x07, 
0xb0, 0x40, 0xdf, 0x00, 0x00, 0x07, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 
};

const unsigned char PROGMEM closeGateRight[] = {
14, 55,
0x00, 0x00, 0x00, 0x80, 0x00, 0x08, 0x80, 0xc8, 0xe0, 0x70, 0x38, 0x5c, 0x0e, 0x00, 
0xe0, 0x70, 0xb9, 0x1c, 0x0e, 0x57, 0x03, 0x01, 0xea, 0x00, 0x00, 0xfd, 0x00, 0x00, 
0xef, 0x00, 0xfa, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 
0xef, 0x00, 0xff, 0x00, 0x00, 0xff, 0xf8, 0x48, 0x27, 0xfc, 0xfc, 0xff, 0x00, 0x00, 
0xef, 0x00, 0xff, 0x00, 0x00, 0xf7, 0x07, 0x04, 0xe8, 0x0f, 0x0f, 0xff, 0x00, 0x00, 
0x07, 0x00, 0x1f, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x3f, 0x00, 0x00, 
};

const unsigned char PROGMEM midWallFront[] = {
61, 16,
0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x00, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x00, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x00, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x00, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0x46, 0x56, 0x56, 
0x2b, 0x03, 0x08, 0x13, 0x0b, 0x03, 0x8b, 0x43, 0x0b, 0x00, 0x2b, 0x13, 0x2b, 0x03, 0x2b, 0x03, 0x20, 0x03, 0x23, 0x03, 0x23, 0x03, 0x23, 0x00, 0x23, 0x03, 0x23, 0x03, 0x23, 0x03, 0xa8, 0x03, 0x23, 0x03, 0x23, 0x03, 0x23, 0x40, 0x03, 0x03, 0x03, 0x03, 0x23, 0x03, 0x20, 0x03, 0x2b, 0x03, 0x2b, 0x13, 0x2b, 0x00, 0x0b, 0x43, 0x8b, 0x03, 0x0b, 0x13, 0x08, 0x03, 0x2b, 
};

const unsigned char PROGMEM midDoorLevelLocked[] = {
9, 8,
0x04, 0x01, 0xf1, 0x09, 0x09, 0x49, 0xf1, 0x01, 0x04, 
};

const unsigned char PROGMEM midDoorLocked[] = {
15, 16,
0x00, 0xf5, 0x01, 0x01, 0xf5, 0x01, 0x71, 0x55, 0x71, 0x01, 0xf5, 0x01, 0x01, 0xf5, 0x00, 
0x00, 0x23, 0x02, 0x22, 0x03, 0x22, 0x02, 0xab, 0x02, 0x22, 0x03, 0x22, 0x02, 0x23, 0x40, 
};

const unsigned char PROGMEM midDoorLevelUnlocked[] = {
9, 8,
0x04, 0x01, 0xf1, 0x89, 0xc9, 0xe9, 0xf1, 0x01, 0x04, 
};

// const unsigned char PROGMEM midDoorUnlocked[] = {
// 9, 8,
// 0x04, 0x01, 0xf1, 0x09, 0x09, 0x09, 0xf1, 0x01, 0x04, 
// };

const unsigned char PROGMEM midWallLeft[] = {
23, 32,
0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0xfc, 0x00, 0xf0, 0xe0, 0xc0, 0x84, 0x00, 0x00, 
0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x80, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x3f, 0xbe, 0xbe, 0xbd, 0x83, 0x3b, 0xb7, 0xb0, 0xae, 
0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x1f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xc0, 0xef, 0x0f, 0xf7, 0x7b, 0x38, 0x5d, 0x01, 0x46, 
0x0f, 0x8f, 0x0f, 0x8f, 0x0f, 0x8f, 0x0f, 0x80, 0x0f, 0x8f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x0b, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 
};

const unsigned char PROGMEM midWallRight[] = {
23, 32,
0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0x00, 0xfc, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
0xae, 0xb0, 0xb7, 0x3b, 0x83, 0xbd, 0xbe, 0xbe, 0x3f, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x80, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 
0x06, 0x01, 0x1d, 0x38, 0x7b, 0xf7, 0x0f, 0xef, 0xc0, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x1f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 
0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x0b, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x8f, 0x0f, 0x80, 0x0f, 0x8f, 0x0f, 0x8f, 0x0f, 0x8f, 0x0f, 
};

const unsigned char PROGMEM midGateLeft[] = {
9, 32,
0xbf, 0x7e, 0x00, 0x18, 0xb0, 0x60, 0xc2, 0x80, 0x00, 
0x1f, 0xdf, 0x00, 0xf0, 0x5e, 0x00, 0xfa, 0x01, 0x57, 
0xe0, 0xf7, 0x00, 0x03, 0x3e, 0x00, 0x2f, 0x00, 0x23, 
0x03, 0x05, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 
};

const unsigned char PROGMEM midGateRight[] = {
9, 32,
0x00, 0x80, 0xc0, 0x60, 0xb0, 0x18, 0x00, 0x7e, 0xbf, 
0x57, 0x01, 0xfa, 0x00, 0x5e, 0xf0, 0x00, 0xdf, 0x1f, 
0x03, 0x00, 0x0f, 0x00, 0x3e, 0x03, 0x00, 0xf7, 0xe0, 
0x02, 0x54, 0x20, 0x04, 0x00, 0x04, 0x00, 0x05, 0x03, 
};

const unsigned char PROGMEM farWallLeft[] = {
27, 16,
0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x00, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0xac, 0x58, 0x00, 
0x2b, 0x03, 0x08, 0x13, 0x0b, 0x03, 0x8b, 0x43, 0x0b, 0x00, 0x2b, 0x13, 0x2b, 0x03, 0x2b, 0x03, 0x20, 0x03, 0x23, 0x03, 0x23, 0x03, 0x23, 0x01, 0x22, 0x00, 0x22, 
};

const unsigned char PROGMEM farWallRight[] = {
27, 16,
0x00, 0x58, 0xac, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x00, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0x46, 0x56, 0x56, 
0x02, 0x00, 0x02, 0x01, 0x03, 0x03, 0x03, 0x03, 0x23, 0x03, 0x20, 0x03, 0x2b, 0x03, 0x0b, 0x13, 0x0b, 0x00, 0x0b, 0x43, 0x8b, 0x03, 0x0b, 0x13, 0x08, 0x03, 0x2b, 
};

const unsigned char PROGMEM farDoorLocked[] = {
5, 2,
0x00, 0x18, 0x18, 0x18, 0x00, 
};

const unsigned char PROGMEM farGateLocked[] = {
9, 8,
0x40, 0x0d, 0x41, 0x0d, 0x41, 0x0d, 0x41, 0x0d, 0x40, 
};

const unsigned char PROGMEM farDoorUnlocked[] = {
5, 2,
0x18, 0x00, 0x00, 0x00, 0x18, 
};
    
#endif
