#ifndef ENUMS_H
#define ENUMS_H

// ----  Memory saving switches -------

#undef  USE_BEGIN

        // 558 bytes
#undef  USE_DICE_ANIMATIONS

        // 46 bytes
#define USE_FLASHLIGHT

        // 834 bytes
#undef  USE_SOUNDS

        // 180 bytes in favour of WONB
#define INV_STYLE_BONW
#undef  INV_STYLE_WONB


// ------------------------------------

#define MAX_LEVEL_COUNT                   1

#define UP_BUTTON_MASK                    128
#define DOWN_BUTTON_MASK                  16
#define LEFT_BUTTON_MASK                  32
#define RIGHT_BUTTON_MASK                 64
#define A_BUTTON_MASK                     8
#define B_BUTTON_MASK                     4

#define SELECT_BUTTON_MASK                A_BUTTON_MASK
#define BACK_BUTTON_MASK                  B_BUTTON_MASK
#define SELECT_BUTTON                     A_BUTTON_MASK
#define BACK_BUTTON                       B_BUTTON_MASK

#define MAP_TILE_WIDTH                    15
#define MAP_TILE_HEIGHT                   15
#define MAP_TILE_PHYSICAL_WIDTH           16
#define MAP_TILE_PHYSICAL_HEIGHT          16

#define TILE_SIZE                         4
#define TILE_OFFSET                       5
#define UNIT                              TILE_SIZE / 4

#define NUMBER_OF_ENEMIES                 18
#define ENEMY_BEHOLDER_POSITION           Point {6, 5}
#define ENEMY_SKELETON_POSITION           Point {11, 5}
#define ENEMY_DISPLACER_POSITION          Point {8, 10}
#define ENEMY_WRAITH_POSITION             Point {16, 3}
#define ENEMY_DRAGON_POSITION             Point {3, 5}
#define ENEMY_RAT_POSITION                Point {23, 16}
#define ENEMY_SLIME_POSITION              Point {13, 22}

#define NUMBER_OF_DOORS                   3
#define NUMBER_OF_ITEMS                   18
#define ITEM_HPPOTION_POSITION            Point {23, 19}
#define ITEM_KEY_POSITION                 Point {20, 20}
#define ITEM_SCROLL_POSITION              Point {20, 18}

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

#define ENEMY_MAX_ATTACK                  4
#define ENEMY_MAX_HITPOINTS               10

#ifdef USE_DICE_ANIMATIONS
#define HUMAN_MAX_ATTACK                  4
#endif

#ifndef USE_DICE_ANIMATIONS
#define HUMAN_MAX_ATTACK                  5
#endif

#define DIRECTION_X_OFFSET                66
#define DIRECTION_Y_OFFSET                43

#define INVENTORY_ACTION_USE              0
#define INVENTORY_ACTION_DELETE           1
#define INVENTORY_POSITION_1              Point{11, 8}
#define INVENTORY_POSITION_2              Point{28, 8}
#define INVENTORY_POSITION_3              Point{45, 8}
#define INVENTORY_POSITION_4              Point{28, 35}
#define INVENTORY_POSITION_5              Point{45, 35}
#define INVENTORY_POTION_HP_INC           5

#define ITEM_DELAY                        1500
#define ITEM_ACTION_USE                   0
#define ITEM_ACTION_DELETE                1

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
  NextLevel,
  EndOfGame
};

enum class Inventory: uint8_t {
  None,
  Key,
  Potion,
  Scroll,
  Shield,
  Sword
};

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

enum class Rotation : uint8_t {
  Rotation_0 = 0,
  Rotation_90 = 64,
  Rotation_180 = 128,
  Rotation_270 = 192,
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

#endif
