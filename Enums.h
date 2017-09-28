#ifndef VISION_H
#define VISION_H


#define TILE_SIZE     4
#define TILE_OFFSET   5
#define UNIT          TILE_SIZE / 4

enum class GameStates : uint8_t {
  Splash,
  About,
  Play
};

enum class SplashButtons : uint8_t {
  Play,
  About
};

enum class Buttons : uint8_t {
  Up,
  Left,
  Down,
  Right
};

enum class Direction : uint8_t {
  North,
  East,
  South,
  West
};

enum class MapElements : uint8_t {
  Floor,
  Wall
};

#endif
