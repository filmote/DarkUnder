#ifndef IMAGES_MAP_H
#define IMAGES_MAP_H

const unsigned char PROGMEM enemyMap[] = {
4, 4,
0x06, 0x09, 0x09, 0x06,
};

const unsigned char PROGMEM itemMap[] = {
4, 4,
0x09, 0x06, 0x06, 0x09,
};

const unsigned char PROGMEM playerMap[] = {
4, 4,
0x0F, 0x09, 0x09, 0x0F,
};

const unsigned char PROGMEM playerMap_Mask[] = {
0x0F, 0x0F, 0x0F, 0x0F,
};

#endif