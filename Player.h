#ifndef PLAYER_H
#define PLAYER_H

#include <Arduboy2.h>
#include "Enums.h"
#include "Level.h"

struct Player {

  int x;
  int y;
  Direction direction;

  Player (int initX, int initY) {

    x = initX;
    y = initY;
    direction = Direction::North;

  }

  boolean moveLegal(Level *myLevel, int row, int col) {

    if (myLevel->worldGrid[row][col] < 1) {
      return true;
    } 
    else {
      return false;
    }

  }  

  void movePlayer(Level *myLevel, Buttons button) {

    switch (direction) {

      case Direction::North:
      
        switch (button) {

          case Buttons::Up:
            if (moveLegal(myLevel, y - 1, x)) { --y; }; direction = Direction::North; break;

          case Buttons::Down:
            if (moveLegal(myLevel, y + 1, x)) { ++y; }; break;

          case Buttons::Left:
            if (moveLegal(myLevel, y, x - 1)) { --x; }; direction = Direction::West; break;

          case Buttons::Right:
            if (moveLegal(myLevel, y, x + 1)) { ++x; }; direction = Direction::East; break;

        }
        break;

      case Direction::East:
      
        switch (button) {

          case Buttons::Up:
            if (moveLegal(myLevel, y, x + 1)) { ++x; }; direction = Direction::East; break;

          case Buttons::Down:
            if (moveLegal(myLevel, y, x - 1)) { --x; }; break;

          case Buttons::Left:
            if (moveLegal(myLevel, y - 1, x)) { --y; }; direction = Direction::North; break;

          case Buttons::Right:
            if (moveLegal(myLevel, y + 1, x)) { ++y; }; direction = Direction::South; break;

        }
        break;
                        
      case Direction::South:

        switch (button) {

          case Buttons::Up:
            if (moveLegal(myLevel, y + 1, x)) { ++y; }; direction = Direction::South; break;

          case Buttons::Down:
            if (moveLegal(myLevel, y - 1, x)) { --y; }; break;

          case Buttons::Left:
            if (moveLegal(myLevel, y, x + 1)) { ++x; }; direction = Direction::East; break;

          case Buttons::Right:
            if (moveLegal(myLevel, y, x - 1)) { --x; }; direction = Direction::West; break;

        }
        break;

      case Direction::West:
      
        switch (button) {

          case Buttons::Up:
            if (moveLegal(myLevel, y, x - 1)) { --x; }; direction = Direction::West; break;

          case Buttons::Down:
            if (moveLegal(myLevel, y, x + 1)) { ++x; }; break;

          case Buttons::Left:
            if (moveLegal(myLevel, y + 1, x)) { ++y; }; direction = Direction::South; break;

          case Buttons::Right:
            if (moveLegal(myLevel, y - 1, x)) { --y; }; direction = Direction::North; break;

        }
        break;

    }

  }

};

#endif
