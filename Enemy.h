#pragma once

#include <Arduboy2.h>
#include "Base.h"
#include "Level.h"
#include "Enums.h"

class Enemy : public Base {

  public:

    Enemy();

    EnemyType getEnemyType();
    bool getEnabled();
    int8_t getHitPoints();
    int8_t getAttackPower();
    bool getMoving();
    
    void setEnemyType(const EnemyType value);
    void setEnabled(const bool value);    
    void setHitPoints(const int8_t value);   
    void setAttackPower(const int8_t value);   
    void setMoving(const bool value);    
    void decHitPoints(const int8_t value);   
    
  private:

    EnemyType _enemyType;
    int8_t _hitPoints;
    int8_t _attackPower;
    bool _moving;
    bool _enabled;
    
};
