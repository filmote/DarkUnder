#ifndef PLAYER_H
#define PLAYER_H

#include <Arduboy2.h>
#include "Enums.h"
#include "Level.h"

class Player {

  public:

    Player();
    bool moveLegal(Level *level, int row, int col);
    bool move(Level *level, Button button);

    const Direction getDirection();
    const uint16_t getX();
    const uint16_t getY();
    const Point getPosition();
    
    void setDirection(const Direction value);
    void setX(const uint16_t value);
    void setY(const uint16_t value);

  private:

    int _x;
    int _y;
    Direction _direction;

};

#endif
