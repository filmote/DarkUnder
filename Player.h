#ifndef PLAYER_H
#define PLAYER_H

#include <Arduboy2.h>
#include "Enums.h"
#include "Level.h"

struct Player {
//    color playerColor = color(#FFFFFF);
    int playerSize = TILE_SIZE;
    int x;
    int y;

    Player (int initX, int initY) {
//      playerX = colX*TILE_SIZE;
//      playerY = rowY*TILE_SIZE;
      x = initX;
      y = initY;
//      pcolX=col;
//      prowY=row;
    }  
    void display(Arduboy2 *arduboy) {
    //  fill(#000000);
    //  noStroke();
      arduboy->fillRect(x, y, TILE_SIZE, TILE_SIZE, BLACK);
      arduboy->fillRect(x + 1, y + 1, TILE_SIZE/2, TILE_SIZE/2, WHITE);
    
      // rect(originX,originY, TILE_SIZE, TILE_SIZE);
      // fill(#FFFFFF);
      // rect(originX+1,originY+1, TILE_SIZE/2, TILE_SIZE/2);
      // stroke(0);
    }

    boolean moveLegal(Level *myLevel, int row, int col) {
      //println("Hero X= "+row+" Hero Y= "+col);
      if (myLevel->worldGrid[row][col] < 1) {
        return true;
      } else {
        return false;
      }
    }  

    void movePlayer(Level *myLevel, Direction direction) {
 Serial.println(myLevel->worldGrid[y][x]);  
      switch (direction) {
        case Direction::Up:
          if (moveLegal(myLevel, y - 1, x)) {
//            playerY = playerY-playerSize;
            --y;
            renderMaze(myLevel);
          };
          break;
        case Direction::Down:
          if (moveLegal(myLevel, y + 1, x)) {
//            playerY = playerY+playerSize;
            ++y;
            renderMaze(myLevel);
          };
          break;
        case Direction::Left:
          if (moveLegal(myLevel, y, x - 1)) {
//            playerX = playerX-playerSize;
            --x;
            renderMaze(myLevel);
          };
          break;
        case Direction::Right:
          if (moveLegal(myLevel, y, x + 1)) {
//            playerX = playerX+playerSize;
            ++x;
            renderMaze(myLevel);
          };
          break;
      }

//      pcolX=col;
//      prowY=row;
//      aiTurn=true;//player moved, turn to enemy
    }
  

void renderMaze(Level *myLevel) {


  Serial.print("After x :");
  Serial.print(x);
  Serial.print(", y :");
  Serial.println(y);
 

  Serial.print(myLevel->worldGrid[y - 2][x - 1]);
  Serial.print(" ");
  Serial.print(myLevel->worldGrid[y - 2][x]);
  Serial.print(" ");
  Serial.println(myLevel->worldGrid[y - 2][x + 1]);

  Serial.print(myLevel->worldGrid[y - 1][x - 1]);
  Serial.print(" ");
  Serial.print(myLevel->worldGrid[y - 1][x]);
  Serial.print(" ");
  Serial.println(myLevel->worldGrid[y - 1][x + 1]);

  Serial.print(myLevel->worldGrid[y][x - 1]);
  Serial.print(" ");
  Serial.print(myLevel->worldGrid[y][x]);
  Serial.print(" ");
  Serial.println(myLevel->worldGrid[y][x + 1]);



}

};

#endif
