#ifndef ENUMS_H
#define ENUMS_H

#define MAP_TILE_WIDTH            15
#define MAP_TILE_HEIGHT           15
#define MAP_TILE_PHYSICAL_WIDTH   16
#define MAP_TILE_PHYSICAL_HEIGHT  16

#define TILE_SIZE                 4
#define TILE_OFFSET               5
#define UNIT                      TILE_SIZE / 4

#define NUMBER_OF_ENEMIES         10
#define ENEMY_BEHOLDER_POSITION   Point {6, 5}
#define ENEMY_SKELETON_POSITION   Point {11, 5}
#define ENEMY_DISPLACER_POSITION  Point {8, 10}
#define ENEMY_WRAITH_POSITION     Point {16, 3}
#define ENEMY_DRAGON_POSITION     Point {3, 5}
#define ENEMY_RAT_POSITION        Point {23, 16}
#define ENEMY_SLIME_POSITION      Point {13, 22}

#define NUMBER_OF_ITEMS           10
#define ITEM_HPPOTION_POSITION    Point {20, 20}

#define MAP_IMAGE_BACK            0
#define MAP_IMAGE_CLOSE_FRONT     1
#define MAP_IMAGE_CLOSE_LEFT      2
#define MAP_IMAGE_CLOSE_RIGHT     3
#define MAP_IMAGE_MID_FRONT       4
#define MAP_IMAGE_MID_LEFT        5
#define MAP_IMAGE_MID_RIGHT       6
#define MAP_IMAGE_FAR_FRONT       7
#define MAP_IMAGE_FAR_LEFT        8
#define MAP_IMAGE_FAR_RIGHT       9

#define MAP_MASK_CLOSE_FRONT      0
#define MAP_MASK_CLOSE_LEFT       1
#define MAP_MASK_CLOSE_RIGHT      2
#define MAP_MASK_MID_FRONT        3 
#define MAP_MASK_MID_LEFT         4
#define MAP_MASK_MID_RIGHT        5
#define MAP_MASK_FAR_LEFT         6
#define MAP_MASK_FAR_RIGHT        7

//#define DICE_X_POS                103
//#define DICE_Y_POS                16
#define DICE_NO_ACTION            -15
#define DICE_DELAY_START          DICE_NO_ACTION + 1
#define DICE_DELAY_END            32
#define FIGHT_DELAY               1500

#define ENEMY_MAX_ATTACK          4
#define ENEMY_MAX_HITPOINTS       10

#define HUMAN_MAX_ATTACK          4

#define DIRECTION_X_OFFSET        66
#define DIRECTION_Y_OFFSET        43

enum class GameState : uint8_t {
  Splash,
  About,
  InitGame,
  InitLevel,
  Move,
  Battle_EnemyAttacks_Init,
  Battle_EnemyAttacks,
  Battle_EnemyDies,
  Battle_PlayerDecides,
  Battle_PlayerAttacks,
  Battle_PlayerDefends,
  Battle_PlayerDies,
};

enum class SplashButtons : uint8_t {
  Play,
  About
};

enum class FightButtons : uint8_t {
  Attack,
  Defend,
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
  Wall
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
  HPPotion,
  Key
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
  
  c = ( c == Direction::West ) ? Direction::North : static_cast<Direction>( static_cast<uint8_t>(c) + 1 );
  return c;

}

inline Direction operator++( Direction &c, int ) {

  Direction result = c;
  ++c;
  return result;

}

inline Direction &operator--( Direction & c ) {

  c = ( c == Direction::North ) ? Direction::West : static_cast<Direction>( static_cast<uint8_t>(c) - 1 );
  return c;

}

inline Direction operator--( Direction & c, int ) {

  Direction result = c;
  --c;
  return result;

}

#endif
