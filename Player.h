#ifndef PLAYER_H
#define PLAYER_H

#include <Arduboy2.h>
#include "Enums.h"
#include "Level.h"

struct Player {

  int x;
  int y;
  Direction direction;

  Player () { }

  boolean moveLegal(Level *myLevel, int row, int col) {

    if (myLevel->getMapElement(col, row) == MapElement::Floor) {
      return true;
    } 
    else {
      return false;
    }

  }  

  void movePlayer(Level *myLevel, Button button) {

    switch (direction) {

      case Direction::North:
      
        switch (button) {

          case Button::Up:
            if (moveLegal(myLevel, y - 1, x)) { --y; }; direction = Direction::North; break;
/*
          case Button::Down:
            if (moveLegal(myLevel, y + 1, x)) { ++y; }; break;

          case Button::Left:
            if (moveLegal(myLevel, y, x - 1)) { --x; }; direction = Direction::West; break;

          case Button::Right:
            if (moveLegal(myLevel, y, x + 1)) { ++x; }; direction = Direction::East; break;
*/
          case Button::Down:
            direction = Direction::South; break;

          case Button::Left:
            direction = Direction::West; break;

          case Button::Right:
            direction = Direction::East; break;
            
        }
        break;

      case Direction::East:
      
        switch (button) {

          case Button::Up:
            if (moveLegal(myLevel, y, x + 1)) { ++x; }; direction = Direction::East; break;
/*
          case Button::Down:
            if (moveLegal(myLevel, y, x - 1)) { --x; }; break;

          case Button::Left:
            if (moveLegal(myLevel, y - 1, x)) { --y; }; direction = Direction::North; break;

          case Button::Right:
            if (moveLegal(myLevel, y + 1, x)) { ++y; }; direction = Direction::South; break;
*/
          case Button::Down:
            direction = Direction::West; break;

          case Button::Left:
            direction = Direction::North; break;

          case Button::Right:
            direction = Direction::South; break;
            
        }
        break;
                        
      case Direction::South:

        switch (button) {

          case Button::Up:
            if (moveLegal(myLevel, y + 1, x)) { ++y; }; direction = Direction::South; break;
/*
          case Button::Down:
            if (moveLegal(myLevel, y - 1, x)) { --y; }; break;

          case Button::Left:
            if (moveLegal(myLevel, y, x + 1)) { ++x; }; direction = Direction::East; break;

          case Button::Right:
            if (moveLegal(myLevel, y, x - 1)) { --x; }; direction = Direction::West; break;
*/
          case Button::Down:
            direction = Direction::North; break;

          case Button::Left:
            direction = Direction::East; break;

          case Button::Right:
            direction = Direction::West; break;

        }
        break;

      case Direction::West:
      
        switch (button) {

          case Button::Up:
            if (moveLegal(myLevel, y, x - 1)) { --x; }; direction = Direction::West; break;
/*
          case Button::Down:
            if (moveLegal(myLevel, y, x + 1)) { ++x; }; break;

          case Button::Left:
            if (moveLegal(myLevel, y + 1, x)) { ++y; }; direction = Direction::South; break;

          case Button::Right:
            if (moveLegal(myLevel, y - 1, x)) { --y; }; direction = Direction::North; break;
*/
          case Button::Down:
            direction = Direction::East; break;

          case Button::Left:
            direction = Direction::South; break;

          case Button::Right:
            direction = Direction::North; break;

        }
        break;

    }

  }

};

#endif
