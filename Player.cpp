#include <Arduboy2.h>
#include "Player.h"
#include "Enums.h"
#include "Level.h"

Player::Player() {}

const Direction Player::getDirection()             { return _direction; }
const uint16_t Player::getX()                      { return _x; }
const uint16_t Player::getY()                      { return _y; }
const Point Player::getPosition()                  { return Point {_x, _y}; }

void Player::setDirection(const Direction value)   { _direction = value; }
void Player::setX(const uint16_t value)            { _x = value; }
void Player::setY(const uint16_t value)            { _y = value; }

bool Player::moveLegal(Level *level, int x, int y) {

  return (level->getMapElement(x, y) == MapElement::Floor);

}

bool Player::move(Level *level, Button button) {

  bool movement = false;

  if (button == Button::Up) {

    switch (_direction) {

      case Direction::North:
        if (moveLegal(level, _x, _y - 1))   { --_y; movement = true; };   break;
      
      case Direction::East:
        if (moveLegal(level, _x + 1, _y))   { ++_x; movement = true; };   break;
        break;
                            
      case Direction::South:
        if (moveLegal(level, _x, _y + 1))   { ++_y; movement = true; };   break;
        break;
      
      case Direction::West:
        if (moveLegal(level, _x - 1, _y))   { --_x; movement = true; };   break;
        break;
      
    }

  }
  else {

    switch (button) {

      case Button::Down:   ++_direction; ++_direction;                    break;
      case Button::Left:   --_direction;                                  break;
      case Button::Right:  ++_direction;                                  break;
      
    }

  }

  return movement;

}
