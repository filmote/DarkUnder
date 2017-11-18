#pragma once

// ----  Memory saving and other decision switches ----------------------------------------------------------------------------------

        // 834 bytes
#undef  USE_SOUNDS

        // Saves 290 bytes
#undef  USE_LARGE_MAP

        // Should a level up include HP
#define LEVEL_UP_INC_HP 

        // Saves 482 bytes of not used.
#define USE_DISPLACER_SLIME

#define XP_LEVEL_UP                       4

#define LEVEL_UP_SELECT_PRIZE

#define USE_SHIELD_ITEM

#define SAVE_GAME

//#define USE_2_WALL_IMAGES     This has been moved to the MapData.h file.  It can be added in manually **if** there is enough room

// ----------------------------------------------------------------------------------------------------------------------------------


#define UP_BUTTON_MASK                    128
#define DOWN_BUTTON_MASK                  16
#define LEFT_BUTTON_MASK                  32
#define RIGHT_BUTTON_MASK                 64
#define A_BUTTON_MASK                     8
#define B_BUTTON_MASK                     4

#define SELECT_BUTTON_MASK                A_BUTTON_MASK
#define BACK_BUTTON_MASK                  B_BUTTON_MASK

#define MAP_TILE_WIDTH                    15
#define MAP_TILE_HEIGHT                   15
#define MAP_TILE_PHYSICAL_WIDTH           15
#define MAP_TILE_PHYSICAL_HEIGHT          15

#define MAP_TILE_SIZE                     4
#define MAP_TILE_OFFSET                   5

#define NUMBER_OF_ENEMIES                 30
#define NUMBER_OF_DOORS                   7
#define NUMBER_OF_ITEMS                   NUMBER_OF_ENEMIES

#define MAP_IMAGE_BACK                    0
#define MAP_IMAGE_CLOSE_FRONT             1
#define MAP_IMAGE_CLOSE_GATE_LOCKED       2
#define MAP_IMAGE_CLOSE_DOOR_LOCKED       3
#define MAP_IMAGE_CLOSE_DOOR_UNLOCKED     4
#define MAP_IMAGE_CLOSE_LEFT              5
#define MAP_IMAGE_CLOSE_RIGHT             6
#define MAP_IMAGE_CLOSE_GATE_LEFT         7
#define MAP_IMAGE_CLOSE_GATE_RIGHT        8

#define MAP_IMAGE_MID_FRONT               9
#define MAP_IMAGE_MID_GATE_LOCKED         10
#define MAP_IMAGE_MID_DOOR_LOCKED         11
#define MAP_IMAGE_MID_DOOR_UNLOCKED       12
#define MAP_IMAGE_MID_LEFT                13
#define MAP_IMAGE_MID_RIGHT               14
#define MAP_IMAGE_MID_GATE_LEFT           15
#define MAP_IMAGE_MID_GATE_RIGHT          16

#define MAP_IMAGE_FAR_GATE_LOCKED         17
#define MAP_IMAGE_FAR_DOOR_LOCKED         18
#define MAP_IMAGE_FAR_DOOR_UNLOCKED       19
#define MAP_IMAGE_FAR_LEFT                20
#define MAP_IMAGE_FAR_RIGHT               21

#define DICE_NO_ACTION                    -15
#define DICE_DELAY_START                  DICE_NO_ACTION + 1
#define DICE_DELAY_END                    32
#define FIGHT_DELAY                       1500
#define LEVEL_UP_DELAY                    3000

#define ENEMY_MAX_ATTACK                  4
#define ENEMY_MAX_HITPOINTS               10

#define HUMAN_MAX_ATTACK                  5
#define PLAYER_CASTS_SPELL                5

#define DIRECTION_X_OFFSET                66
#define DIRECTION_Y_OFFSET                43

#define INVENTORY_ACTION_USE              0
#define INVENTORY_ACTION_DROP             1
#define INVENTORY_POSITION_1              Point{11, 8}
#define INVENTORY_POSITION_2              Point{28, 8}
#define INVENTORY_POSITION_3              Point{45, 8}
#define INVENTORY_POSITION_4              Point{28, 35}
#define INVENTORY_POSITION_5              Point{45, 35}
#define INVENTORY_POTION_HP_INC           5

#define ITEM_DELAY                        1500
#define ITEM_ACTION_USE                   0
#define ITEM_ACTION_DROP                  1

enum class GameState : uint8_t {
  Splash,   
  About,
  InitGame,
  InitLevel,
  Move,
  InventorySelect,
  InventoryAction,
  ItemSelect,
  ItemIgnore,
  Battle_EnemyAttacks_Init,
  Battle_EnemyAttacks,          
  Battle_EnemyDies,
  Battle_PlayerDecides,
  Battle_PlayerAttacks,
  Battle_PlayerDefends,
  Battle_PlayerCastsSpell,
  Battle_PlayerDies,
  LevelUp,
  NextLevel,
  EndOfGame,
  #ifdef USE_LARGE_MAP
  DisplayLargeMap
  #endif
};

#ifdef LEVEL_UP_SELECT_PRIZE
enum class LevelUpButtons : uint8_t {
  None,
  AP,
  DF
};
#endif

enum class SplashButtons : uint8_t {
  Play,
  About
};

enum class FightButtons : uint8_t {
  Attack,
  Shield,
  Magic,
  Potion,
  Count
};

enum class Button : uint8_t {
  Up,
  Left,
  Down,
  Right
};

enum class MapElement : uint8_t {
  Floor,
  Wall,
  LockedGate = 100,
  LockedDoor,
  UnlockedDoor,
};

enum class EnemyType : uint8_t {
  Beholder,
  Skeleton,
  Displacer,
  Wraith,
  Dragon,
  Rat,
  Slime
};

enum class ItemType : uint8_t {
  None, 
  Key,
  Potion,
  Scroll,
  Shield,
  Sword,
  LockedGate = 100,
  LockedDoor,
  UnlockedDoor,
};

enum class Direction : uint8_t {
  North,
  East,
  South,
  West,
  Count
};

inline Direction &operator++( Direction &c ) { 
  
  c = static_cast<Direction>( (static_cast<uint8_t>(c) + 1) & 0x03 );
  return c;

}

inline Direction operator++( Direction &c, int ) {

  Direction result = c;
  ++c;
  return result;

}

inline Direction &operator--( Direction & c ) {

  c = static_cast<Direction>( (static_cast<uint8_t>(c) - 1) & 0x03 );
  return c;

}

inline Direction operator--( Direction & c, int ) {

  Direction result = c;
  --c;
  return result;

}
