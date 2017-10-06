#include <Arduboy2.h>
#include "Enemy.h"
#include "Level.h"
#include "Enums.h"


Enemy::Enemy() {}

const bool Enemy::getEnabled()                    { return _enabled; }
const EnemyType Enemy::getEnemyType()             { return _enemyType; }
const uint16_t Enemy::getX()                      { return _x; }
const uint16_t Enemy::getY()                      { return _y; }

void Enemy::setEnabled(const bool value)          { _enabled = value; }
void Enemy::setEnemyType(const EnemyType value)   { _enemyType = value; }
void Enemy::setX(const uint16_t value)            { _x = value; }
void Enemy::setY(const uint16_t value)            { _y = value; }

void Enemy::move(Level *level, Point playerPosition) {
    
  if (!Enemy::canMoveTowardsPlayer(level, playerPosition)) {

    while (true) {

      if (Enemy::moveToVacantSquare(level, (Direction)random(0, 4))) { break; }

    }

  }

}
    
boolean Enemy::canMoveTowardsPlayer(Level *level, Point playerPosition) {
  
  if (playerPosition.y < _y && Enemy::moveLegal(level, _x, _y - 1))                     { --_y; } 
  else if (playerPosition.y > _y && Enemy::moveLegal(level, _x, _y + 1))                { ++_y; } 
  else if (playerPosition.x > _x && Enemy::moveLegal(level, _x + 1, _y))                { ++_x; } 
  else if (playerPosition.x < _x && Enemy::moveLegal(level, _x - 1, _y))                { --_x; } 
  else {
  
    return false;

  }

  return true;

}

boolean Enemy::moveToVacantSquare(Level *level, Direction playerDirection) {
  
  bool moved = true;

  if (playerDirection == Direction::North && Enemy::moveLegal(level, _x, _y - 1))       { --_y; } 
  else if (playerDirection == Direction::South && Enemy::moveLegal(level, _x, _y + 1))  { ++_y; } 
  else if (playerDirection == Direction::East && Enemy::moveLegal(level, _x + 1, _y))   { ++_x; } 
  else if (playerDirection == Direction::West && Enemy::moveLegal(level, _x - 1, _y))   { --_x; } 
  else                                                                                  { moved = false; }

  return moved;

}
    
boolean Enemy::moveLegal(Level *level, int x, int y) {
  
  return (level->getMapElement(x, y) == MapElement::Floor);
  
}  
