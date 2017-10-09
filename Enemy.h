#ifndef ENEMY_H
#define ENEMY_H

#include <Arduboy2.h>
#include "Level.h"
#include "Enums.h"

class Enemy {

  public:

    Enemy();

    const bool getEnabled();
    const EnemyType getEnemyType();
    const int16_t getX();
    const int16_t getY();

    void setEnabled(const bool value);
    void setEnemyType(const EnemyType value);
    void setX(const int16_t value);
    void setY(const int16_t value);
    
  private:

    bool _enabled;
    EnemyType _enemyType;
    int16_t _x;
    int16_t _y;

};

#endif
