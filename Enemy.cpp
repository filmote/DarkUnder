#include <Arduboy2.h>
#include "Enemy.h"
#include "Enums.h"

Enemy::Enemy() : Base() { }

const EnemyType Enemy::getEnemyType()             { return _enemyType; }
const bool Enemy::getEnabled()                    { return _enabled; }
const int8_t Enemy::getHitPoints()                { return _hitPoints; }

void Enemy::setEnemyType(const EnemyType value)   { _enemyType = value; }
void Enemy::setHitPoints(const int8_t value)      { _hitPoints = value; }
void Enemy::setEnabled(const bool value)          { _enabled = value; }

void Enemy::decHitPoints(const int8_t value)      { 
    
  if (_hitPoints > value ) {
    _hitPoints = _hitPoints - value;
  }
  else {
    _hitPoints = 0; 
    _enabled = false;
  }

}
