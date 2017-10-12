#ifndef PLAYER_H
#define PLAYER_H

#include <Arduboy2.h>
#include "Base.h"
#include "Enums.h"
#include "Level.h"

class Player : public Base {

  public:

    Player();

    const Direction getDirection();
    const int8_t getHitPoints();
    const int8_t getDefence();
    const int8_t getAttackPower();
    const int8_t getMagic();
    
    void setDirection(const Direction value);
    void setHitPoints(const int8_t value);   
    void setDefence(const int8_t value);   
    void setAttackPower(const int8_t value);   
    void setMagic(const int8_t value);   
    
  private:

    Direction _direction;
    int8_t _hitPoints;
    int8_t _defence;
    int8_t _attackPower;
    int8_t _magic;
    
  };

#endif
