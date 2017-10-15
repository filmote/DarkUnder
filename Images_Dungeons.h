#ifndef IMAGES_DUNGEONS_H
#define IMAGES_DUNGEONS_H



// Level 1 Scenery ------------------------------------------------------------------------------------------------------------------------------------------------

const unsigned char PROGMEM closeWallFront[] = {
62, 28,
0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x80, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x80, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x3f, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x80, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x80, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf,  
0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x1f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x00, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x1f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xc0, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x1f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x00, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x1f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 
0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,  
};

const unsigned char PROGMEM closeDoorLocked[] = {
0x13, 0x17, 0x52, 0x64, 0xaf, 0xea, 0x6c, 0xaf, 0xb2, 0xad, 0x4e, 0x97, 0x52, 0xe9, 0x74, 0xb9, 
0xd3, 0xad, 0x54, 0xba, 0xaf, 0x73, 0xaf, 0x88, 0x14, 0xa7, 0xf7, 0xe5, 0xca, 0xab, 0x9c, 0xd7, 
0x8c, 0xba, 0x73, 0x25, 0x2b, 0x59, 0xe7, 0xd2, 0x78, 0x92, 0x3a, 0xa5, 0x4a, 0xa7, 0x54, 0xe9, 
0x94, 0x2a, 0x9d, 0xce, 0x5d, 0x3a, 0x77, 0xe9, 0xdc, 0xa5, 0x73, 0x8e, 0x12
};

const unsigned char PROGMEM closeDoorLevelLocked[] = {
0x13, 0x17, 0x52, 0x64, 0xaf, 0xea, 0x6c, 0xaf, 0xb2, 0xad, 0x4e, 0x97, 0x52, 0xe9, 0x74, 0xb9, 
0xd3, 0xad, 0x54, 0xba, 0xaf, 0x73, 0xaf, 0x88, 0x14, 0xa7, 0xf7, 0xe5, 0xca, 0xab, 0x9c, 0xd7, 
0x8c, 0xba, 0x73, 0x25, 0x2b, 0x59, 0xe7, 0xd2, 0x78, 0x92, 0x3a, 0xa5, 0x4a, 0xa7, 0x54, 0xe9, 
0x94, 0x2a, 0x9d, 0xce, 0x5d, 0x3a, 0x77, 0xe9, 0xdc, 0xa5, 0x73, 0x8e, 0x12
};
            
const unsigned char PROGMEM closeDoorLevelUnlocked[] = {
0x13, 0x17, 0x52, 0x64, 0xdb, 0x90, 0x9a, 0x4e, 0x57, 0xb2, 0x76, 0x11, 0x29, 0xd4, 0x45, 0x97, 
0xdb, 0x5e, 0xd7, 0xaa, 0xaf, 0x6b, 0xd5, 0xd7, 0xb5, 0xea, 0xeb, 0x1a, 0x57, 0xdb, 0x5d, 0x6d, 
0x77, 0xb5, 0xdd, 0xd5, 0x76, 0x57, 0xdb, 0x5d, 0x6d, 0x77, 0xb5, 0xdd, 0xd5, 0x9c
};

const uint8_t PROGMEM closeDoorUnlocked[] = {
0x13, 0x17, 0x52, 0x64, 0xdb, 0xd0, 0x9c, 0x9e, 0x4d, 0xc1, 0xa1
};

const unsigned char PROGMEM closeWallLeft[] = {
15, 56,
0x00, 0xf0, 0xf8, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xbf, 0xbf, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0x00, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 
0x00, 0xff, 0xff, 0xff, 0x00, 0xfe, 0xfe, 0xfd, 0xfc, 0xfb, 0xf7, 0x07, 0xef, 0xef, 0xdf, 
0x00, 0xef, 0xef, 0xef, 0xe0, 0xef, 0xef, 0xef, 0x0f, 0xef, 0xef, 0xe0, 0xef, 0xef, 0xef, 
0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0xbf, 0xdf, 0x1f, 0xef, 0xef, 0xf7, 
0x00, 0xfb, 0xfb, 0xfd, 0x01, 0xfe, 0xfe, 0xff, 0xff, 0x7f, 0x3f, 0x00, 0x0f, 0x07, 0x03, 
0x00, 0x0f, 0x1f, 0x1f, 0x00, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const unsigned char PROGMEM closeWallRight[] = {
15, 56,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0x00, 
0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0x00, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0xbf, 0xbf, 0x00, 
0xdf, 0xef, 0xef, 0x07, 0xf7, 0xfb, 0xfc, 0xfd, 0xfe, 0xfe, 0x00, 0xff, 0xff, 0xff, 0x00, 
0xef, 0xef, 0xef, 0xe0, 0xef, 0xef, 0x0f, 0xef, 0xef, 0xef, 0xe0, 0xef, 0xef, 0xef, 0x00, 
0xf7, 0xef, 0xef, 0x1f, 0xdf, 0xbf, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
0x03, 0x07, 0x0f, 0x00, 0x3f, 0x7f, 0xff, 0xff, 0xfe, 0xfe, 0x01, 0xfd, 0xfb, 0xfb, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x00, 0x1f, 0x3f, 0x7f, 0x00, 
};

const unsigned char PROGMEM midWallFront[] = {
61, 10,
0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x00, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x00, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x00, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x00, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0x46, 0x56, 0x56, 
0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 
};

const unsigned char PROGMEM midDoorLocked[] = {
9, 8,
0x04, 0x01, 0xf1, 0x09, 0x09, 0x49, 0xf1, 0x01, 0x04, 
};
    
const unsigned char PROGMEM midDoorLevelLocked[] = {
9, 8,
0x04, 0x01, 0xf1, 0x09, 0x09, 0x49, 0xf1, 0x01, 0x04, 
};
            
const uint8_t PROGMEM midDoorUnlocked[] = {
9, 8,
0x04, 0x01, 0xf1, 0x09, 0x09, 0x09, 0xf1, 0x01, 0x04, 
};

const unsigned char PROGMEM midDoorLevelUnlocked[] = {
9, 8,
0x04, 0x01, 0xf1, 0x89, 0xc9, 0xe9, 0xf1, 0x01, 0x04, 
};

const unsigned char PROGMEM midWallLeft[] = {
23, 28,
0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0xfc, 0x00, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 
0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x80, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x3f, 0xbe, 0xbe, 0xbd, 0x83, 0x3b, 0xb7, 0xb0, 0xae, 
0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x1f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xc0, 0xef, 0x0f, 0xf7, 0x7b, 0x38, 0x1d, 0x01, 0x06, 
0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const unsigned char PROGMEM midWallRight[] = {
24, 28,
0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0x00, 0xfc, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
0xae, 0xb0, 0xb7, 0x3b, 0x83, 0xbd, 0xbe, 0xbe, 0x3f, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x80, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 
0x06, 0x01, 0x1d, 0x38, 0x7b, 0xf7, 0x0f, 0xef, 0xc0, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x1f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
};

const unsigned char PROGMEM farWallFront[] = {
62, 2,
0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02,
};

const unsigned char PROGMEM farWallFrontDoorLocked[] = {
4, 2,
0x00, 0x03, 0x03, 0x00, 
};

const unsigned char PROGMEM farWallFrontDoorUnlocked[] = {
4, 2,
0x03, 0x00, 0x00, 0x03, 
};


const unsigned char PROGMEM farWallLeft[] = {
27, 10,
0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x00, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0xac, 0x58, 0x00, 
0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 
};

const unsigned char PROGMEM farWallRight[] = {
28, 10,
0x00, 0x58, 0xac, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 0x10, 0x56, 0x56, 0x00, 0x56, 0x56, 0x10, 0x56, 0x56, 0x56, 0x46, 0x56, 0x56, 0x56, 
0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 
};



// Common masks -------------------------------------------------------------------------------------------------------------------------------------------------------

const unsigned char PROGMEM closeWallFront_Mask[] = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,  
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,  
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,  
0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,  
};

const unsigned char PROGMEM closeDoor_Mask[] = {
0x13, 0x17, 0x21, 0x51, 0x25, 0x95, 0x54, 0x52, 0x49, 0x25, 0x95, 0x54, 0x52, 0x49, 0x25, 0x95, 
0x54, 0x52, 0x49, 0x25, 0x95, 0x54, 0x52, 0x49, 0x25, 0x95, 0x54, 0x52, 0x01
};

const unsigned char PROGMEM closeWallLeft_Mask[] = {
0x00, 0xf0, 0xf8, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 
0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 
0x00, 0x0f, 0x1f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const unsigned char PROGMEM closeWallRight_Mask[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 
0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 
};

const unsigned char PROGMEM midWallFront_Mask[] = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
};

const unsigned char PROGMEM midWallFrontDoor_Mask[] = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
};

const unsigned char PROGMEM midWallLeft_Mask[] = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 
0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const unsigned char PROGMEM midWallRight_Mask[] = {
0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
};

const unsigned char PROGMEM farWallLeft_Mask[] = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0x78, 
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 
};

const unsigned char PROGMEM farWallRight_Mask[] = {
0x78, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
};

const unsigned char PROGMEM farWallFrontDoor_Mask[] = {
0x03, 0x03, 0x03, 0x03, 
};

#endif