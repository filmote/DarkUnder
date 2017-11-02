#include <Arduboy2.h>
#include "Enemy.h"
#include "../../Enums.h"

Enemy::Enemy() : Base() { }

EnemyType Enemy::getEnemyType()                           { return _enemyType; }
uint8_t Enemy::getHitPoints()                             { return _hitPoints; }
uint8_t Enemy::getHitPointsMax()                          { return _hitPointsMax; }
uint8_t Enemy::getAttackPower()                           { return _attackPower; }
uint8_t Enemy::getExperiencePoints()                      { return _experiencePoints; }
bool Enemy::getEnabled()                                  { return _enabled; }
bool Enemy::getMoving()                                   { return _moving; }

void Enemy::setEnemyType(const EnemyType value)           { _enemyType = value; }
void Enemy::setHitPoints(const uint8_t value)             { _hitPoints = value; }
void Enemy::setHitPointsMax(const uint8_t value)          { _hitPointsMax = value; }
void Enemy::setAttackPower(const uint8_t value)           { _attackPower = value; }
void Enemy::setExperiencePoints(const uint8_t value)      { _experiencePoints = value; }
void Enemy::setMoving(const bool value)                   { _moving = value; }
void Enemy::setEnabled(const bool value)                  { _enabled = value; }

