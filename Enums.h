#ifndef VISION_H
#define VISION_H


#define TILE_SIZE   4
#define UNIT        TILE_SIZE / 4

enum class GameStates {
    Splash,
    About,
    Play
};

enum class SplashButtons {
    Play,
    About
};

enum class Direction {
    Up,
    Left,
    Down,
    Right
};

#endif