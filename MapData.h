#ifndef MAPDATA_H
#define MAPDATA_H


// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Tiles 
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

const uint8_t PROGMEM tile_00[] = { 
//00    01    02    03    04    05    06    07    08    09    10    11    12    13    14   Unused
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0x7D, 0x7D, 0x01, 0x6D, 0x01, 0x7D, 0x7D, 0xFD, 0xC1, 0xD5,  0x00,
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x18, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x78, 0x7F, 0x7F,	0x7F,  0x00,
};

const uint8_t PROGMEM tile_01[] = {
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xC1, 0xD5,  0x00,
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x1F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,  0x00,
};

const uint8_t PROGMEM tile_02[] = {
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xC1, 0xD5,  0x00,
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x1F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,  0x00,
};

// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Levels 
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

const uint8_t PROGMEM level_00[] = {  

// 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11      // Title, 22 characters
   72, 65, 76, 76, 87, 65, 89, 32, 79, 70, 32, 
   84, 72, 69, 32, 68, 69, 65, 68, 32, 32, 32,

1, 1,                                              // Starting postion of player
(uint8_t)Direction::East,                          // Starting direction of player
2, 2,                                              // Dimension of level in tiles (a tile is a 15x15 map)
0,                                                 // Wall texture of this level

2,                                                 // Number of enemies
(uint8_t)EnemyType::Wraith, 3, 1,                     // Enemy type, starting position
(uint8_t)EnemyType::Slime, 13, 1,                  // Enemy type, starting position

1,                                                 // Number of items
(uint8_t)ItemType::HPPotion, 10, 1,                // Item type, starting position

                                                   // Map Data (refers to tiles above).  The number of elements needs to match the dimensions above.

(uint8_t)Rotation::Rotation_0   | 0,  (uint8_t)Rotation::Rotation_90  | 0,
(uint8_t)Rotation::Rotation_270 | 0,  (uint8_t)Rotation::Rotation_180 | 0,
                                                   
};

// ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    

const uint8_t PROGMEM level_01[] = {

// 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11      // Title, 22 characters
   72, 65, 76, 76, 87, 65, 89, 32, 79, 70, 32, 
   84, 72, 69, 32, 68, 69, 65, 68, 32, 32, 32,

1, 1,                                              // Starting postion of player
(uint8_t)Direction::East,                          // Starting direction of player
2, 2,                                              // Dimension of level in tiles (a tile is a 15x15 map)
0,                                                 // Wall texture of this level

2,                                                 // Number of enemies
(uint8_t)EnemyType::Beholder, 3, 1,                // Enemy type, starting position
(uint8_t)EnemyType::Beholder, 5, 1,                // Enemy type, starting position

1,                                                 // Number of items
(uint8_t)ItemType::HPPotion, 10, 1,                // Item type, starting position

                                                   // Map Data (refers to tiles above).  The number of elements needs to match the dimensions above.

(uint8_t)Rotation::Rotation_0   | 0,  (uint8_t)Rotation::Rotation_90  | 0,
(uint8_t)Rotation::Rotation_270 | 0,  (uint8_t)Rotation::Rotation_180 | 0,
                                                
};

// ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    

const uint8_t PROGMEM level_02[] = {  
    
// 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11      // Title, 22 characters
   72, 65, 76, 76, 87, 65, 89, 32, 79, 70, 32, 
   84, 72, 69, 32, 68, 69, 65, 68, 32, 32, 32,

1, 1,                                              // Starting postion of player
(uint8_t)Direction::East,                          // Starting direction of player
2, 2,                                              // Dimension of level in tiles (a tile is a 15x15 map)
0,                                                 // Wall texture of this level

2,                                                 // Number of enemies
(uint8_t)EnemyType::Dragon, 3, 1,                  // Enemy type, starting position
(uint8_t)EnemyType::Displacer, 5, 1,               // Enemy type, starting position

1,                                                 // Number of items
(uint8_t)ItemType::HPPotion, 10, 1,                // Item type, starting position

                                                   // Map Data (refers to tiles above).  The number of elements needs to match the dimensions above.

(uint8_t)Rotation::Rotation_0   | 0,  (uint8_t)Rotation::Rotation_90  | 0,
(uint8_t)Rotation::Rotation_270 | 0,  (uint8_t)Rotation::Rotation_180 | 0,

};

#endif
