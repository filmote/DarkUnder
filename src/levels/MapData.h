#pragma once

#define MAX_LEVEL_COUNT 3
#define START_HP 20
#define START_AP 2
#define START_DF 2
#define MAX_HP 50
#define LEVEL_UP 50

#define ENEMY_BEHOLDER_HP 15
#define ENEMY_BEHOLDER_AP 10
#define ENEMY_BEHOLDER_XP 20
#define ENEMY_BEHOLDER_MV true

#define ENEMY_SKELETON_HP 10
#define ENEMY_SKELETON_AP 5
#define ENEMY_SKELETON_XP 10
#define ENEMY_SKELETON_MV false

#define ENEMY_DISPLACER_HP 8
#define ENEMY_DISPLACER_AP 5
#define ENEMY_DISPLACER_XP 8
#define ENEMY_DISPLACER_MV true

#define ENEMY_WRAITH_HP 12
#define ENEMY_WRAITH_AP 6
#define ENEMY_WRAITH_XP 12
#define ENEMY_WRAITH_MV true

#define ENEMY_DRAGON_HP 25
#define ENEMY_DRAGON_AP 12
#define ENEMY_DRAGON_XP 50
#define ENEMY_DRAGON_MV false

#define ENEMY_RAT_HP 4
#define ENEMY_RAT_AP 2
#define ENEMY_RAT_XP 3
#define ENEMY_RAT_MV false

#define ENEMY_SLIME_HP 5
#define ENEMY_SLIME_AP 3
#define ENEMY_SLIME_XP 6
#define ENEMY_SLIME_MV false

const uint8_t PROGMEM tile_00[] = {
0xFF, 0x81, 0xED, 0x05, 0xF5, 0x95, 0xD5, 0x05, 0xDD, 0x85, 0xB1, 0xA5, 0xED, 0x01, 0x7F, 0x7F, 0x40, 0x5E, 0x52, 0x5A, 0x4A, 0x6A, 0x02, 0x6E, 0x42, 0x5E, 0x54, 0x55, 0x45, 0x7F, 
};
const uint8_t PROGMEM tile_01[] = {
0x7F, 0x55, 0x05, 0x7D, 0x41, 0x5D, 0x15, 0x54, 0x57, 0x51, 0xDD, 0x05, 0xFD, 0x01, 0x7F, 0x7F, 0x41, 0x5D, 0x57, 0x50, 0x55, 0x5D, 0x01, 0x7F, 0x40, 0x5F, 0x50, 0x5E, 0x42, 0x7F, 
};
const uint8_t PROGMEM tile_02[] = {
0xFF, 0x01, 0xDD, 0x51, 0x55, 0x15, 0x57, 0x54, 0xD5, 0x15, 0xF5, 0x85, 0xED, 0x21, 0xFF, 0x7F, 0x40, 0x56, 0x54, 0x54, 0x50, 0x54, 0x14, 0x56, 0x54, 0x56, 0x52, 0x56, 0x40, 0x7F, 
};
const uint8_t PROGMEM tile_03[] = {
0xFF, 0x09, 0xED, 0x21, 0xAD, 0xA5, 0xB7, 0xA0, 0xBF, 0xA5, 0x2D, 0xA5, 0xAD, 0x81, 0xFF, 0x7F, 0x40, 0x5F, 0x50, 0x5B, 0x40, 0x7E, 0x02, 0x6A, 0x4B, 0x58, 0x53, 0x5E, 0x40, 0x7F, 
};
const uint8_t PROGMEM tile_04[] = {
0x7F, 0x01, 0xFD, 0x41, 0x6D, 0x49, 0x6F, 0x21, 0xAD, 0xA5, 0x8F, 0xA5, 0xBD, 0x81, 0xFF, 0x7F, 0x41, 0x5D, 0x51, 0x5D, 0x44, 0x75, 0x15, 0x55, 0x54, 0x56, 0x52, 0x5A, 0x40, 0x7F, 
};
const uint8_t PROGMEM tile_05[] = {
0x7F, 0x45, 0x55, 0x51, 0xDD, 0x45, 0x75, 0x11, 0x75, 0x05, 0x75, 0x15, 0xFD, 0x01, 0x7F, 0x7F, 0x41, 0x5D, 0x50, 0x5B, 0x41, 0x6D, 0x01, 0x6D, 0x41, 0x5F, 0x40, 0x7B, 0x41, 0x7F, 
};
const uint8_t PROGMEM tile_06[] = {
0xFF, 0x01, 0xD7, 0x55, 0xDD, 0x01, 0xFF, 0x81, 0xBD, 0x25, 0xED, 0x81, 0x3D, 0xA1, 0xFF, 0x7F, 0x40, 0x5F, 0x42, 0x7A, 0x42, 0x6E, 0x08, 0x6B, 0x42, 0x48, 0x6F, 0x40, 0x4A, 0x7F, 
};
const uint8_t PROGMEM tile_07[] = {
0xFF, 0x01, 0xEF, 0x89, 0xB9, 0xA1, 0xA1, 0x81, 0xA1, 0xA1, 0xB9, 0x89, 0xEF, 0x01, 0xFF, 0x7F, 0x40, 0x5E, 0x42, 0x5A, 0x4A, 0x78, 0x03, 0x78, 0x4A, 0x5A, 0x42, 0x5E, 0x40, 0x7F, 
};
const uint8_t PROGMEM tile_08[] = {
0xFF, 0x81, 0xFD, 0x05, 0xED, 0xA9, 0xAB, 0xA0, 0xBF, 0x81, 0xED, 0x05, 0xFD, 0x01, 0xFF, 0x7F, 0x40, 0x5A, 0x52, 0x5A, 0x52, 0x7E, 0x02, 0x76, 0x52, 0x5A, 0x42, 0x5B, 0x48, 0x7F, 
};
const uint8_t PROGMEM tile_09[] = {
0x7F, 0x41, 0xDD, 0x45, 0x5D, 0x51, 0x17, 0x54, 0xD5, 0x95, 0xB5, 0xA5, 0xAD, 0x81, 0xFF, 0x7F, 0x40, 0x5F, 0x41, 0x5B, 0x49, 0x7B, 0x42, 0x5A, 0x52, 0x78, 0x52, 0x5E, 0x40, 0x7F, 
};
const uint8_t PROGMEM tile_10[] = {
0xFF, 0x41, 0x55, 0x75, 0x05, 0xD5, 0x7D, 0x04, 0xDF, 0x01, 0xF5, 0x15, 0xDD, 0x41, 0x7F, 0x7F, 0x44, 0x5F, 0x55, 0x50, 0x5B, 0x40, 0x7F, 0x41, 0x5C, 0x47, 0x50, 0x5F, 0x40, 0x7F, 
};
const uint8_t PROGMEM tile_11[] = {
0xFF, 0x01, 0xFD, 0x05, 0xDD, 0x55, 0x55, 0x04, 0xF7, 0x11, 0x51, 0x55, 0x15, 0x45, 0x7F, 0x7F, 0x40, 0x76, 0x44, 0x5D, 0x41, 0x7F, 0x04, 0x77, 0x44, 0x51, 0x55, 0x5C, 0x41, 0x7F, 
};
const uint8_t PROGMEM tile_12[] = {
0x7F, 0x41, 0x7D, 0x05, 0xDD, 0x51, 0x55, 0x55, 0x55, 0xD5, 0x55, 0x55, 0x75, 0x05, 0x7F, 0x7F, 0x40, 0x5F, 0x51, 0x5D, 0x40, 0x5F, 0x51, 0x5D, 0x45, 0x55, 0x51, 0x5F, 0x40, 0x7F, 
};
const uint8_t PROGMEM tile_13[] = {
0x7F, 0x21, 0xBD, 0x85, 0xB1, 0x85, 0xFD, 0x00, 0x77, 0xC5, 0x15, 0x55, 0xDD, 0x41, 0x7F, 0x7F, 0x41, 0x5F, 0x40, 0x5E, 0x52, 0x56, 0x50, 0x55, 0x45, 0x57, 0x54, 0x77, 0x40, 0x7F, 
};
const uint8_t PROGMEM tile_14[] = {};
const uint8_t PROGMEM tile_15[] = {};
const uint8_t PROGMEM tile_16[] = {};
const uint8_t PROGMEM tile_17[] = {};
const uint8_t PROGMEM tile_18[] = {};
const uint8_t PROGMEM tile_19[] = {};

const uint8_t PROGMEM level_00[] = {
72, 65, 76, 76, 87, 65, 89, 83, 32, 79, 70, 
84, 72, 69, 32, 68, 69, 65, 68, 32, 32, 32, 
7, 58,
0,
1, 4,
16,
5, 10, 52,
5, 1, 51,
5, 5, 56,
5, 8, 41,
5, 3, 36,
6, 13, 33,
6, 8, 38,
1, 5, 23,
6, 11, 16,
5, 11, 23,
5, 4, 18,
6, 3, 4,
6, 10, 9,
5, 12, 4,
5, 3, 8,
1, 7, 2,
19,
2, 1, 47,
2, 13, 42,
2, 3, 41,
2, 5, 36,
2, 1, 36,
2, 11, 33,
2, 11, 25,
3, 11, 21,
3, 13, 21,
2, 5, 16,
3, 9, 24,
2, 1, 2,
2, 11, 3,
4, 3, 11,
5, 12, 8,
3, 8, 8,
1, 7, 1,
2, 9, 1,
2, 11, 11,
1,
101, 7, 0,
3, 2, 8, 3, 
};

const uint8_t PROGMEM level_01[] = {
67, 82, 89, 80, 84, 32, 79, 70, 32, 32, 32, 
65, 78, 71, 85, 73, 83, 72, 32, 32, 32, 32, 
22, 43,
0,
3, 3,
30,
2, 19, 39,
6, 21, 35,
1, 22, 31,
2, 13, 42,
2, 33, 41,
6, 38, 40,
6, 8, 40,
5, 17, 35,
5, 38, 38,
1, 4, 31,
2, 24, 25,
1, 21, 21,
1, 22, 16,
1, 7, 16,
2, 3, 21,
2, 10, 23,
2, 36, 23,
5, 43, 21,
6, 37, 27,
6, 36, 11,
2, 37, 9,
5, 39, 6,
6, 37, 2,
2, 18, 10,
6, 23, 7,
6, 18, 5,
5, 24, 3,
3, 7, 1,
1, 9, 11,
1, 7, 5,
27,
1, 2, 35,
1, 21, 33,
1, 33, 33,
1, 17, 39,
2, 11, 33,
2, 43, 27,
2, 24, 18,
2, 11, 18,
2, 3, 26,
2, 26, 26,
2, 33, 18,
2, 41, 3,
2, 18, 11,
2, 5, 7,
5, 23, 23,
4, 5, 21,
5, 41, 1,
4, 16, 1,
3, 35, 21,
3, 41, 18,
3, 11, 11,
3, 1, 5,
3, 41, 41,
3, 3, 39,
3, 13, 27,
2, 31, 21,
1, 1, 13,
5,
101, 7, 0,
100, 7, 15,
100, 22, 15,
100, 37, 15,
100, 22, 40,
11, 8, 10, 5, 3, 1, 4, 8, 9, 
};

const uint8_t PROGMEM level_02[] = {
68, 82, 65, 71, 79, 78, 32, 32, 32, 32, 32, 
76, 65, 73, 82, 32, 32, 32, 32, 32, 32, 32, 
37, 58,
0,
5, 4,
30,
4, 37, 3,
0, 35, 23,
0, 50, 23,
3, 37, 55,
3, 30, 52,
1, 22, 51,
1, 26, 56,
3, 8, 56,
1, 4, 51,
3, 10, 41,
1, 10, 32,
3, 18, 37,
1, 24, 35,
3, 37, 31,
1, 33, 36,
3, 41, 19,
1, 52, 28,
1, 49, 28,
1, 51, 37,
1, 51, 50,
3, 58, 54,
3, 66, 51,
0, 65, 38,
1, 67, 26,
3, 52, 7,
3, 67, 9,
3, 5, 8,
3, 22, 9,
1, 7, 5,
1, 22, 4,
30,
1, 24, 46,
1, 1, 54,
1, 39, 31,
1, 28, 40,
1, 1, 43,
1, 54, 43,
1, 73, 36,
1, 37, 10,
2, 1, 6,
2, 11, 11,
2, 16, 17,
2, 27, 23,
2, 56, 21,
2, 46, 6,
2, 71, 3,
2, 69, 18,
2, 13, 31,
2, 41, 39,
2, 31, 46,
2, 16, 49,
2, 21, 33,
2, 39, 24,
2, 35, 12,
3, 39, 12,
3, 31, 1,
3, 43, 1,
5, 35, 16,
4, 38, 37,
5, 43, 21,
4, 1, 21,
8,
101, 37, 1,
100, 15, 52,
100, 7, 45,
100, 37, 30,
100, 22, 30,
100, 7, 30,
100, 52, 30,
100, 67, 30,
0, 8, 11, 10, 4, 3, 1, 13, 7, 2, 13, 5, 0, 2, 9, 12, 4, 3, 2, 9, 
};

const uint8_t PROGMEM level_03[] = {};

const uint8_t PROGMEM level_04[] = {};

const uint8_t PROGMEM level_05[] = {};

const uint8_t PROGMEM level_06[] = {};

const uint8_t PROGMEM level_07[] = {};

const uint8_t PROGMEM level_08[] = {};

const uint8_t PROGMEM level_09[] = {};
