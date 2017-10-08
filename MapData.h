#ifndef MAPDATA_H
#define MAPDATA_H


// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Tiles 
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

const uint8_t PROGMEM tile_00[] = { 
//00    01    02    03    04    05    06    07    08    09    10    11    12    13    14    15    16    17    18    19    20    21    22    23    24    25    26    27    28    29    30
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFD, 0x00, 0xFD, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
0xEB, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xEB,
0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x1F, 0x5F, 0x00, 0x5F, 0x1F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
};

const uint8_t PROGMEM tile_01[] = {
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFD, 0x00, 0xFD, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 
0xEB, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xEB, 
0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x1F, 0x5F, 0x00, 0x5F, 0x1F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 
};


// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Levels 
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

const uint8_t PROGMEM level_00[] = {  

// 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11      // Title, 22 characters
   72, 65, 76, 76, 87, 65, 89, 32, 79, 70, 32, 
   84, 72, 69, 32, 68, 69, 65, 68, 32, 32, 32,

27, 15,                                            // Starting postion of player
(uint8_t)Direction::East,                          // Starting direction of player
3, 1,                                              // Dimension of level in tiles (a tile is a 31x31 map)
0,                                                 // Wall texture of this level
2,                                                 // Number of enemies

                                                   // Enemy 1
(uint8_t)EnemyType::Beholder,                      // Enemy type
24, 15,                                            // Starting position

                                                   // Enemy 2
(uint8_t)EnemyType::Beholder,                      // Enemy type
15, 15,                                            // Starting position

1,                                                 // Number of items
                                                   // Item 1
(uint8_t)ItemType::HPPotion,                       // Item type
31, 15,                                            // Starting position



0, 0, 0,                                           // Map Data (refers to tiles above).  The number of elements needs to match the dimensions above.

};

// ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    

const uint8_t PROGMEM level_01[] = {

// 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11      // Title, 22 characters
   72, 65, 76, 76, 87, 65, 89, 32, 79, 70, 32, 
   84, 72, 69, 32, 68, 69, 65, 68, 32, 32, 32,

27, 15,                                            // Starting postion of player
(uint8_t)Direction::East,                          // Starting direction of player
3, 1,                                              // Dimension of level in tiles (a tile is a 31x31 map)
0,                                                 // Wall texture of this level
2,                                                 // Number of enemies

                                                   // Enemy 1
(uint8_t)EnemyType::Beholder,                      // Enemy type
24, 15,                                            // Starting position

                                                   // Enemy 2
(uint8_t)EnemyType::Beholder,                      // Enemy type
15, 15,                                            // Starting position

0, 0, 0,                                           // Map Data (refers to tiles above).  The number of elements needs to match the dimensions above.

};

// ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    

#endif
