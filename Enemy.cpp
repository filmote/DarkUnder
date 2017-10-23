#include <Arduboy2.h>
#include "Enemy.h"
#include "Enums.h"

Enemy::Enemy() : Base() { }

EnemyType Enemy::getEnemyType()               { return _enemyType; }
bool Enemy::getEnabled()                      { return _enabled; }
int8_t Enemy::getHitPoints()                  { return _hitPoints; }
int8_t Enemy::getAttackPoints()               { return _attackPoints; }
bool Enemy::getMoving()                       { return _moving; }

void Enemy::setEnemyType(const EnemyType value)     { _enemyType = value; }
void Enemy::setHitPoints(const int8_t value)        { _hitPoints = value; }
void Enemy::setAttackPoints(const int8_t value)     { _attackPoints = value; }
void Enemy::setMoving(const bool value)             { _moving = value; }
void Enemy::setEnabled(const bool value)            { _enabled = value; }

void Enemy::decHitPoints(const int8_t value) { 
    
  if (_hitPoints > value ) {
    _hitPoints = _hitPoints - value;
  }
  else {
    _hitPoints = 0; 
    _enabled = false;
  }

}
