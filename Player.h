#ifndef PLAYER_H
#define PLAYER_H

#include <Arduboy2.h>
#include "Enums.h"
#include "Level.h"

class Player {

  public:

    Player();

    const Direction getDirection();
    const uint16_t getX();
    const uint16_t getY();
    
    void setDirection(const Direction value);
    void setX(const uint16_t value);
    void setY(const uint16_t value);

  private:

    int _x;
    int _y;
    Direction _direction;

};

#endif
