#ifndef ENEMY_H
#define ENEMY_H

#include <Arduboy2.h>
#include "Base.h"
#include "Level.h"
#include "Enums.h"

class Enemy : public Base {

  public:

    Enemy();

    const EnemyType getEnemyType();
    const bool getEnabled();
    const int8_t getHitPoints();

    void setEnemyType(const EnemyType value);
    void setEnabled(const bool value);    
    void setHitPoints(const int8_t value);   
    void decHitPoints(const int8_t value);   
    
  private:

    EnemyType _enemyType;
    int8_t _hitPoints;
    bool _enabled;

};

#endif
