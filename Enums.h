#ifndef VISION_H
#define VISION_H

#define MAP_TILE_WIDTH            31
#define MAP_TILE_HEIGHT           31

#define TILE_SIZE                 4
#define TILE_OFFSET               5
#define UNIT                      TILE_SIZE / 4

#define NUMBER_OF_ENEMIES         10
#define ENEMY_BEHOLDER_POSITION   Point {6, 5}

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

enum class GameState : uint8_t {
  Splash,
  About,
  InitGame,
  InitLevel,
  Play
};

enum class SplashButtons : uint8_t {
  Play,
  About
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
  DisplacerBeast,
  Wraith,
  Dragon
};

enum class ItemType : uint8_t {
  HPPotion,
  Key
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
