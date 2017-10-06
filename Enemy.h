#ifndef ENEMY_H
#define ENEMY_H

#include <Arduboy2.h>
#include "Level.h"
#include "Enums.h"

class Enemy {

  public:

    Enemy();
    void move(Level *level, Point playerPosition);
    boolean canMoveTowardsPlayer(Level *level, Point playerPosition);
    boolean moveToVacantSquare(Level *level, Direction playerDirection);    
    boolean moveLegal(Level *level, int x, int y);

    const bool getEnabled();
    const EnemyType getEnemyType();
    const uint16_t getX();
    const uint16_t getY();

    void setEnabled(const bool value);
    void setEnemyType(const EnemyType value);
    void setX(const uint16_t value);
    void setY(const uint16_t value);
    
  private:

    bool _enabled;
    EnemyType _enemyType;
    uint16_t _x;
    uint16_t _y;

};

#endif
