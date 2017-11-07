#pragma once

#define MAX_LEVEL_COUNT                   1


#define ENEMY_BEHOLDER_HP 20
#define ENEMY_BEHOLDER_AP 12
#define ENEMY_BEHOLDER_XP 4
#define ENEMY_BEHOLDER_MV true

#define ENEMY_SKELETON_HP 10
#define ENEMY_SKELETON_AP 8
#define ENEMY_SKELETON_XP 3
#define ENEMY_SKELETON_MV true

#define ENEMY_DISPLACER_HP 10
#define ENEMY_DISPLACER_AP 5
#define ENEMY_DISPLACER_XP 2
#define ENEMY_DISPLACER_MV true

#define ENEMY_WRAITH_HP 12
#define ENEMY_WRAITH_AP 10
#define ENEMY_WRAITH_XP 4
#define ENEMY_WRAITH_MV true

#define ENEMY_DRAGON_HP 30
#define ENEMY_DRAGON_AP 20
#define ENEMY_DRAGON_XP 6
#define ENEMY_DRAGON_MV true

#define ENEMY_RAT_HP 5
#define ENEMY_RAT_AP 2
#define ENEMY_RAT_XP 1
#define ENEMY_RAT_MV false

#define ENEMY_SLIME_HP 8
#define ENEMY_SLIME_AP 4
#define ENEMY_SLIME_XP 6
#define ENEMY_SLIME_MV false


// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Tiles 
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//00    01    02    03    04    05    06    07    08    09    10    11    12    13    14   

const uint8_t PROGMEM tile_00[] = {  // Temporary
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0x7D, 0x7D, 0x01, 0x6D, 0x01, 0x7D, 0x7D, 0xFD, 0xC1, 0xD5,  
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x18, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x78, 0x7F, 0x7F, 0x7F,  
};

const uint8_t PROGMEM tile_01[] = { 
0xFF, 0x01, 0xDD, 0x51, 0x55, 0x15, 0x57, 0x54, 0xD5, 0x15, 0xF5, 0x85, 0xED, 0x21, 0xFF,  
0x7F, 0x40, 0x56, 0x54, 0x54, 0x50, 0x54, 0x14, 0x5E, 0x54, 0x56, 0x52, 0x56, 0x40, 0x7F,  
};

const uint8_t PROGMEM tile_02[] = {
0xFF, 0x09, 0xED, 0x21, 0xAD, 0xA5, 0xB7, 0xA0, 0xBF, 0xA5, 0x2D, 0xA5, 0xAD, 0x81, 0xFF, 
0x7F, 0x40, 0x5F, 0x50, 0x5B, 0x40, 0x7E, 0x02, 0x6A, 0x4B, 0x58, 0x53, 0x5E, 0x40, 0x7F,  
};

const uint8_t PROGMEM tile_03[] = {  // Temporary
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0x7D, 0x7D, 0x01, 0x6D, 0x01, 0x7D, 0x7D, 0xFD, 0xC1, 0xD5, 
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x18, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x78, 0x7F, 0x7F, 0x7F,  
};

const uint8_t PROGMEM tile_04[] = {  // Temporary
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0x7D, 0x7D, 0x01, 0x6D, 0x01, 0x7D, 0x7D, 0xFD, 0xC1, 0xD5,  
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x18, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x78, 0x7F, 0x7F, 0x7F,  
};

const uint8_t PROGMEM tile_05[] = {  // Temporary
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0x7D, 0x7D, 0x01, 0x6D, 0x01, 0x7D, 0x7D, 0xFD, 0xC1, 0xD5,  
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x18, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x78, 0x7F, 0x7F, 0x7F, 
};

const uint8_t PROGMEM tile_06[] = {  // Temporary
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0x7D, 0x7D, 0x01, 0x6D, 0x01, 0x7D, 0x7D, 0xFD, 0xC1, 0xD5, 
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x18, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x78, 0x7F, 0x7F, 0x7F, 
};

const uint8_t PROGMEM tile_07[] = {
0xFF, 0x81, 0xBD, 0xE5, 0x0D, 0xE9, 0xAB, 0xA0, 0xBF, 0x81, 0xED, 0x05, 0xFD, 0x01, 0xFF, 
0x7F, 0x40, 0x5A, 0x52, 0x5A, 0x52, 0x7E, 0x02, 0x76, 0x52, 0x5A, 0x42, 0x5B, 0x48, 0x7F, 
};

const uint8_t PROGMEM tile_08[] = {  // Temporary
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0x7D, 0x7D, 0x01, 0x6D, 0x01, 0x7D, 0x7D, 0xFD, 0xC1, 0xD5,  
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x18, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x78, 0x7F, 0x7F, 0x7F,
};

const uint8_t PROGMEM tile_09[] = {  // Temporary
0xFF, 0x01, 0xDD, 0x51, 0x55, 0x15, 0x57, 0x54, 0xD5, 0x15, 0xF5, 0x85, 0xED, 0x21, 0xFF,  
0x7F, 0x40, 0x56, 0x54, 0x54, 0x50, 0x54, 0x14, 0x5E, 0x54, 0x56, 0x52, 0x56, 0x40, 0x7F, 
};

const uint8_t PROGMEM tile_10[] = { // Temporary
0xFF, 0x09, 0xED, 0x21, 0xAD, 0xA5, 0xB7, 0xA0, 0xBF, 0xA5, 0x2D, 0xA5, 0xAD, 0x81, 0xFF,  
0x7F, 0x40, 0x5F, 0x50, 0x5B, 0x40, 0x7E, 0x02, 0x6A, 0x4B, 0x58, 0x53, 0x5E, 0x40, 0x7F,  
};

const uint8_t PROGMEM tile_11[] = {  // Temporary
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0x7D, 0x7D, 0x01, 0x6D, 0x01, 0x7D, 0x7D, 0xFD, 0xC1, 0xD5, 
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x18, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x78, 0x7F, 0x7F, 0x7F,  
};

const uint8_t PROGMEM tile_12[] = {  // Temporary
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0x7D, 0x7D, 0x01, 0x6D, 0x01, 0x7D, 0x7D, 0xFD, 0xC1, 0xD5,  
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x18, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x78, 0x7F, 0x7F, 0x7F,  
};

const uint8_t PROGMEM tile_13[] = {  // Temporary
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0x7D, 0x7D, 0x01, 0x6D, 0x01, 0x7D, 0x7D, 0xFD, 0xC1, 0xD5,  
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x18, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x78, 0x7F, 0x7F, 0x7F,  
};

const uint8_t PROGMEM tile_14[] = {  // Temporary
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0x7D, 0x7D, 0x01, 0x6D, 0x01, 0x7D, 0x7D, 0xFD, 0xC1, 0xD5,  
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x18, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x78, 0x7F, 0x7F, 0x7F, 
};

const uint8_t PROGMEM tile_15[] = { // Temporary
0xFF, 0x81, 0xBD, 0xE5, 0x0D, 0xE9, 0xAB, 0xA0, 0xBF, 0x81, 0xED, 0x05, 0xFD, 0x01, 0xFF,  
0x7F, 0x40, 0x5A, 0x52, 0x5A, 0x52, 0x7E, 0x02, 0x76, 0x52, 0x5A, 0x42, 0x5B, 0x48, 0x7F,  
};

const uint8_t PROGMEM tile_16[] = {  // Temporary
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0x7D, 0x7D, 0x01, 0x6D, 0x01, 0x7D, 0x7D, 0xFD, 0xC1, 0xD5,  
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x18, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x78, 0x7F, 0x7F, 0x7F,  
};

const uint8_t PROGMEM tile_17[] = {  // Temporary
0xFF, 0x01, 0xDD, 0x51, 0x55, 0x15, 0x57, 0x54, 0xD5, 0x15, 0xF5, 0x85, 0xED, 0x21, 0xFF,  
0x7F, 0x40, 0x56, 0x54, 0x54, 0x50, 0x54, 0x14, 0x5E, 0x54, 0x56, 0x52, 0x56, 0x40, 0x7F,  
};

const uint8_t PROGMEM tile_18[] = { // Temporary
0xFF, 0x09, 0xED, 0x21, 0xAD, 0xA5, 0xB7, 0xA0, 0xBF, 0xA5, 0x2D, 0xA5, 0xAD, 0x81, 0xFF,  
0x7F, 0x40, 0x5F, 0x50, 0x5B, 0x40, 0x7E, 0x02, 0x6A, 0x4B, 0x58, 0x53, 0x5E, 0x40, 0x7F,  
};

const uint8_t PROGMEM tile_19[] = {  // Temporary
0xFF, 0x01, 0xDD, 0xC1, 0xFD, 0x7D, 0x7D, 0x01, 0x6D, 0x01, 0x7D, 0x7D, 0xFD, 0xC1, 0xD5,  
0x7F, 0x00, 0x5F, 0x1F, 0x5F, 0x18, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x78, 0x7F, 0x7F, 0x7F,  
};



// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Levels 
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

const uint8_t PROGMEM level_00[] = {  
  
  // 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11      // Title, 22 characters
  72, 65, 76, 76, 87, 65, 89, 32, 79, 70, 32, 
  84, 72, 69, 32, 68, 69, 65, 68, 32, 32, 32,
  
  7, 58,                                             // Starting postion of player
  
  (uint8_t)Direction::North,                         // Starting direction of player
  1, 4,                                              // Dimension of level in tiles (a tile is a 15x15 map)
  
  14,                                                // Number of enemies
  (uint8_t)EnemyType::Skeleton, 7, 3,                // Enemy type, starting position
  //(uint8_t)EnemyType::Skeleton, 14, 55,                // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 9, 49,                    // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 4, 49,                    // Enemy type, starting position
  (uint8_t)EnemyType::Displacer, 4, 5,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 8,                   // Enemy type, starting position
  (uint8_t)EnemyType::Displacer, 1, 9,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 12,                  // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 13, 17,                 // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 5, 18,                    // Enemy type, starting position
  (uint8_t)EnemyType::Skeleton, 5, 22,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 13, 25,                 // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 1, 36,                  // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 1, 40,                    // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 41,                  // Enemy type, starting position
  
  13,                                                // Number of items
  (uint8_t)ItemType::Potion, 2, 6,                   // Item type, starting position
  (uint8_t)ItemType::Scroll, 6, 6,                   // Item type, starting position
  (uint8_t)ItemType::Potion, 5, 11,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 13, 12,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 9, 13,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 5, 16,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 13, 21,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 5, 25,                  // Item type, starting position
  (uint8_t)ItemType::Potion, 1, 28,                  // Item type, starting position
  (uint8_t)ItemType::Potion, 11, 41,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 2, 51,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 6, 51,                  // Item type, starting position
  (uint8_t)ItemType::Key, 6, 14,                     // Item type, starting position
  
  
  1,                                                 // Number of doors
  (uint8_t)ItemType::LockedDoor, 7, 0,               // Item type, starting position
  
                                                      // Map Data (refers to tiles above).  The number of elements needs to match the dimensions above.
  
  7,  
  1,
  2,
  7,
  
};


const uint8_t PROGMEM level_01[] = {  
  
  // 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11      // Title, 22 characters
  72, 65, 76, 76, 87, 65, 89, 32, 79, 70, 32, 
  84, 72, 69, 32, 68, 69, 65, 68, 32, 32, 32,
  
  7, 58,                                             // Starting postion of player
  
  (uint8_t)Direction::North,                         // Starting direction of player
  1, 4,                                              // Dimension of level in tiles (a tile is a 15x15 map)
  
  14,                                                // Number of enemies
  (uint8_t)EnemyType::Skeleton, 7, 3,                // Enemy type, starting position
  //(uint8_t)EnemyType::Skeleton, 14, 55,                // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 9, 49,                    // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 4, 49,                    // Enemy type, starting position
  (uint8_t)EnemyType::Displacer, 4, 5,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 8,                   // Enemy type, starting position
  (uint8_t)EnemyType::Displacer, 1, 9,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 12,                  // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 13, 17,                 // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 5, 18,                    // Enemy type, starting position
  (uint8_t)EnemyType::Skeleton, 5, 22,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 13, 25,                 // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 1, 36,                  // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 1, 40,                    // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 41,                  // Enemy type, starting position
  
  13,                                                // Number of items
  (uint8_t)ItemType::Potion, 2, 6,                   // Item type, starting position
  (uint8_t)ItemType::Scroll, 6, 6,                   // Item type, starting position
  (uint8_t)ItemType::Potion, 5, 11,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 13, 12,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 9, 13,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 5, 16,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 13, 21,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 5, 25,                  // Item type, starting position
  (uint8_t)ItemType::Potion, 1, 28,                  // Item type, starting position
  (uint8_t)ItemType::Potion, 11, 41,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 2, 51,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 6, 51,                  // Item type, starting position
  (uint8_t)ItemType::Key, 6, 14,                     // Item type, starting position
  
  
  1,                                                 // Number of doors
  (uint8_t)ItemType::LockedDoor, 7, 0,               // Item type, starting position
  
                                                      // Map Data (refers to tiles above).  The number of elements needs to match the dimensions above.
  
  7,  
  1,
  2,
  7,
  
};


const uint8_t PROGMEM level_02[] = {  
  
  // 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11      // Title, 22 characters
  72, 65, 76, 76, 87, 65, 89, 32, 79, 70, 32, 
  84, 72, 69, 32, 68, 69, 65, 68, 32, 32, 32,
  
  7, 58,                                             // Starting postion of player
  
  (uint8_t)Direction::North,                         // Starting direction of player
  1, 4,                                              // Dimension of level in tiles (a tile is a 15x15 map)
  
  14,                                                // Number of enemies
  (uint8_t)EnemyType::Skeleton, 7, 3,                // Enemy type, starting position
  //(uint8_t)EnemyType::Skeleton, 14, 55,                // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 9, 49,                    // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 4, 49,                    // Enemy type, starting position
  (uint8_t)EnemyType::Displacer, 4, 5,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 8,                   // Enemy type, starting position
  (uint8_t)EnemyType::Displacer, 1, 9,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 12,                  // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 13, 17,                 // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 5, 18,                    // Enemy type, starting position
  (uint8_t)EnemyType::Skeleton, 5, 22,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 13, 25,                 // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 1, 36,                  // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 1, 40,                    // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 41,                  // Enemy type, starting position
  
  13,                                                // Number of items
  (uint8_t)ItemType::Potion, 2, 6,                   // Item type, starting position
  (uint8_t)ItemType::Scroll, 6, 6,                   // Item type, starting position
  (uint8_t)ItemType::Potion, 5, 11,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 13, 12,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 9, 13,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 5, 16,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 13, 21,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 5, 25,                  // Item type, starting position
  (uint8_t)ItemType::Potion, 1, 28,                  // Item type, starting position
  (uint8_t)ItemType::Potion, 11, 41,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 2, 51,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 6, 51,                  // Item type, starting position
  (uint8_t)ItemType::Key, 6, 14,                     // Item type, starting position
  
  
  1,                                                 // Number of doors
  (uint8_t)ItemType::LockedDoor, 7, 0,               // Item type, starting position
  
                                                      // Map Data (refers to tiles above).  The number of elements needs to match the dimensions above.
  
  7,  
  1,
  2,
  7,
  
};


const uint8_t PROGMEM level_03[] = {  
  
  // 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11      // Title, 22 characters
  72, 65, 76, 76, 87, 65, 89, 32, 79, 70, 32, 
  84, 72, 69, 32, 68, 69, 65, 68, 32, 32, 32,
  
  7, 58,                                             // Starting postion of player
  
  (uint8_t)Direction::North,                         // Starting direction of player
  1, 4,                                              // Dimension of level in tiles (a tile is a 15x15 map)
  
  14,                                                // Number of enemies
  (uint8_t)EnemyType::Skeleton, 7, 3,                // Enemy type, starting position
  //(uint8_t)EnemyType::Skeleton, 14, 55,                // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 9, 49,                    // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 4, 49,                    // Enemy type, starting position
  (uint8_t)EnemyType::Displacer, 4, 5,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 8,                   // Enemy type, starting position
  (uint8_t)EnemyType::Displacer, 1, 9,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 12,                  // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 13, 17,                 // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 5, 18,                    // Enemy type, starting position
  (uint8_t)EnemyType::Skeleton, 5, 22,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 13, 25,                 // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 1, 36,                  // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 1, 40,                    // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 41,                  // Enemy type, starting position
  
  13,                                                // Number of items
  (uint8_t)ItemType::Potion, 2, 6,                   // Item type, starting position
  (uint8_t)ItemType::Scroll, 6, 6,                   // Item type, starting position
  (uint8_t)ItemType::Potion, 5, 11,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 13, 12,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 9, 13,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 5, 16,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 13, 21,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 5, 25,                  // Item type, starting position
  (uint8_t)ItemType::Potion, 1, 28,                  // Item type, starting position
  (uint8_t)ItemType::Potion, 11, 41,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 2, 51,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 6, 51,                  // Item type, starting position
  (uint8_t)ItemType::Key, 6, 14,                     // Item type, starting position
  
  
  1,                                                 // Number of doors
  (uint8_t)ItemType::LockedDoor, 7, 0,               // Item type, starting position
  
                                                      // Map Data (refers to tiles above).  The number of elements needs to match the dimensions above.
  
  7,  
  1,
  2,
  7,
  
};


const uint8_t PROGMEM level_04[] = {  
  
  // 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11      // Title, 22 characters
  72, 65, 76, 76, 87, 65, 89, 32, 79, 70, 32, 
  84, 72, 69, 32, 68, 69, 65, 68, 32, 32, 32,
  
  7, 58,                                             // Starting postion of player
  
  (uint8_t)Direction::North,                         // Starting direction of player
  1, 4,                                              // Dimension of level in tiles (a tile is a 15x15 map)
  
  14,                                                // Number of enemies
  (uint8_t)EnemyType::Skeleton, 7, 3,                // Enemy type, starting position
  //(uint8_t)EnemyType::Skeleton, 14, 55,                // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 9, 49,                    // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 4, 49,                    // Enemy type, starting position
  (uint8_t)EnemyType::Displacer, 4, 5,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 8,                   // Enemy type, starting position
  (uint8_t)EnemyType::Displacer, 1, 9,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 12,                  // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 13, 17,                 // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 5, 18,                    // Enemy type, starting position
  (uint8_t)EnemyType::Skeleton, 5, 22,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 13, 25,                 // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 1, 36,                  // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 1, 40,                    // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 41,                  // Enemy type, starting position
  
  13,                                                // Number of items
  (uint8_t)ItemType::Potion, 2, 6,                   // Item type, starting position
  (uint8_t)ItemType::Scroll, 6, 6,                   // Item type, starting position
  (uint8_t)ItemType::Potion, 5, 11,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 13, 12,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 9, 13,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 5, 16,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 13, 21,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 5, 25,                  // Item type, starting position
  (uint8_t)ItemType::Potion, 1, 28,                  // Item type, starting position
  (uint8_t)ItemType::Potion, 11, 41,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 2, 51,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 6, 51,                  // Item type, starting position
  (uint8_t)ItemType::Key, 6, 14,                     // Item type, starting position
  
  
  1,                                                 // Number of doors
  (uint8_t)ItemType::LockedDoor, 7, 0,               // Item type, starting position
  
                                                      // Map Data (refers to tiles above).  The number of elements needs to match the dimensions above.
  
  7,  
  1,
  2,
  7,
  
};


const uint8_t PROGMEM level_05[] = {  
  
  // 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11      // Title, 22 characters
  72, 65, 76, 76, 87, 65, 89, 32, 79, 70, 32, 
  84, 72, 69, 32, 68, 69, 65, 68, 32, 32, 32,
  
  7, 58,                                             // Starting postion of player
  
  (uint8_t)Direction::North,                         // Starting direction of player
  1, 4,                                              // Dimension of level in tiles (a tile is a 15x15 map)
  
  14,                                                // Number of enemies
  (uint8_t)EnemyType::Skeleton, 7, 3,                // Enemy type, starting position
  //(uint8_t)EnemyType::Skeleton, 14, 55,                // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 9, 49,                    // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 4, 49,                    // Enemy type, starting position
  (uint8_t)EnemyType::Displacer, 4, 5,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 8,                   // Enemy type, starting position
  (uint8_t)EnemyType::Displacer, 1, 9,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 12,                  // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 13, 17,                 // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 5, 18,                    // Enemy type, starting position
  (uint8_t)EnemyType::Skeleton, 5, 22,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 13, 25,                 // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 1, 36,                  // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 1, 40,                    // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 41,                  // Enemy type, starting position
  
  13,                                                // Number of items
  (uint8_t)ItemType::Potion, 2, 6,                   // Item type, starting position
  (uint8_t)ItemType::Scroll, 6, 6,                   // Item type, starting position
  (uint8_t)ItemType::Potion, 5, 11,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 13, 12,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 9, 13,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 5, 16,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 13, 21,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 5, 25,                  // Item type, starting position
  (uint8_t)ItemType::Potion, 1, 28,                  // Item type, starting position
  (uint8_t)ItemType::Potion, 11, 41,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 2, 51,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 6, 51,                  // Item type, starting position
  (uint8_t)ItemType::Key, 6, 14,                     // Item type, starting position
  
  
  1,                                                 // Number of doors
  (uint8_t)ItemType::LockedDoor, 7, 0,               // Item type, starting position
  
                                                      // Map Data (refers to tiles above).  The number of elements needs to match the dimensions above.
  
  7,  
  1,
  2,
  7,
  
};


const uint8_t PROGMEM level_06[] = {  
  
  // 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11      // Title, 22 characters
  72, 65, 76, 76, 87, 65, 89, 32, 79, 70, 32, 
  84, 72, 69, 32, 68, 69, 65, 68, 32, 32, 32,
  
  7, 58,                                             // Starting postion of player
  
  (uint8_t)Direction::North,                         // Starting direction of player
  1, 4,                                              // Dimension of level in tiles (a tile is a 15x15 map)
  
  14,                                                // Number of enemies
  (uint8_t)EnemyType::Skeleton, 7, 3,                // Enemy type, starting position
  //(uint8_t)EnemyType::Skeleton, 14, 55,                // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 9, 49,                    // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 4, 49,                    // Enemy type, starting position
  (uint8_t)EnemyType::Displacer, 4, 5,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 8,                   // Enemy type, starting position
  (uint8_t)EnemyType::Displacer, 1, 9,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 12,                  // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 13, 17,                 // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 5, 18,                    // Enemy type, starting position
  (uint8_t)EnemyType::Skeleton, 5, 22,               // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 13, 25,                 // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 1, 36,                  // Enemy type, starting position
  (uint8_t)EnemyType::Rat, 1, 40,                    // Enemy type, starting position
  (uint8_t)EnemyType::Slime, 7, 41,                  // Enemy type, starting position
  
  13,                                                // Number of items
  (uint8_t)ItemType::Potion, 2, 6,                   // Item type, starting position
  (uint8_t)ItemType::Scroll, 6, 6,                   // Item type, starting position
  (uint8_t)ItemType::Potion, 5, 11,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 13, 12,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 9, 13,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 5, 16,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 13, 21,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 5, 25,                  // Item type, starting position
  (uint8_t)ItemType::Potion, 1, 28,                  // Item type, starting position
  (uint8_t)ItemType::Potion, 11, 41,                 // Item type, starting position
  (uint8_t)ItemType::Potion, 2, 51,                  // Item type, starting position
  (uint8_t)ItemType::Scroll, 6, 51,                  // Item type, starting position
  (uint8_t)ItemType::Key, 6, 14,                     // Item type, starting position
  
  
  1,                                                 // Number of doors
  (uint8_t)ItemType::LockedDoor, 7, 0,               // Item type, starting position
  
                                                      // Map Data (refers to tiles above).  The number of elements needs to match the dimensions above.
  
  7,  
  1,
  2,
  7,
  
};

const uint8_t PROGMEM level_07[] = {};
const uint8_t PROGMEM level_08[] = {};
const uint8_t PROGMEM level_09[] = {};