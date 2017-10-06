#include <Arduboy2.h>
#include "Player.h"
#include "Enums.h"
#include "Level.h"

Player::Player() {}

const Direction Player::getDirection()             { return _direction; }
const uint16_t Player::getX()                      { return _x; }
const uint16_t Player::getY()                      { return _y; }

void Player::setDirection(const Direction value)   { _direction = value; }
void Player::setX(const uint16_t value)            { _x = value; }
void Player::setY(const uint16_t value)            { _y = value; }


