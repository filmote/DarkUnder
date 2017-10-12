#include <Arduboy2.h>
#include "Player.h"
#include "Enums.h"
#include "Level.h"

Player::Player() : Base() {

    _hitPoints = 15;
    _defence = 10;
    _attackPower = 0;
    _magic = 0;
    
}

const Direction Player::getDirection()              { return _direction; }
const int8_t Player::getHitPoints()                 { return _hitPoints; }
const int8_t Player::getDefence()                   { return _defence; }
const int8_t Player::getAttackPower()               { return _attackPower; }
const int8_t Player::getMagic()                     { return _magic; }

void Player::setDirection(const Direction value)    { _direction = value; }
void Player::setHitPoints(const int8_t value)       { _hitPoints = value; }
void Player::setDefence(const int8_t value)         { _defence = value; }
void Player::setAttackPower(const int8_t value)     { _attackPower = value; }
void Player::setMagic(const int8_t value)           { _magic = value; }