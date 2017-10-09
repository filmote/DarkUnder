#include <Arduboy2.h>
#include "Enemy.h"
#include "Level.h"
#include "Enums.h"


Enemy::Enemy() {}

const bool Enemy::getEnabled()                    { return _enabled; }
const EnemyType Enemy::getEnemyType()             { return _enemyType; }
const int16_t Enemy::getX()                       { return _x; }
const int16_t Enemy::getY()                       { return _y; }

void Enemy::setEnabled(const bool value)          { _enabled = value; }
void Enemy::setEnemyType(const EnemyType value)   { _enemyType = value; }
void Enemy::setX(const int16_t value)             { _x = value; }
void Enemy::setY(const int16_t value)             { _y = value; }

