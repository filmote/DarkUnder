#ifndef PLAYER_H
#define PLAYER_H

#include <Arduboy2.h>
#include "Enums.h"
#include "Level.h"

class Player {

  public:

    Player();

    const Direction getDirection();
    const int16_t getX();
    const int16_t getY();
    
    void setDirection(const Direction value);
    void setX(const int16_t value);
    void setY(const int16_t value);

  private:

    int16_t _x;
    int16_t _y;
    Direction _direction;

};

#endif
