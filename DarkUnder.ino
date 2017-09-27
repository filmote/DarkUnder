#include <Arduboy2.h>

#include "Enums.h"
#include "Images.h"
#include "Player.h"
#include "Level.h"


//int row;
//int col;
//int pcolX;
//int prowY;

//ArrayList<Object>myObjects = new ArrayList<Object>();
//ArrayList<Enemy>myEnemies = new ArrayList<Enemy>();

GameStates gameStatus = GameStates::Splash; 

//UI myUI;
//Level myLevel;
//Player myHero;
//Vision myVision;
boolean aiTurn =true;


  //    myHero = new Player(row, col); 
  //   // myObjects.add(new Object(3, 3, 'P'));
  //    //myObjects.add(new Object(4, 6, 'P'));
  //   // myEnemies.add(new Stalker(2, 6));

  typedef struct Player hero;  

Arduboy2 arduboy;
Level myLevel;
Player myHero(3, 5);


void setup() {

  arduboy.begin();
  arduboy.setFrameRate(75);
  arduboy.initRandomSeed();  

}

void loop() {
  
  if (!(arduboy.nextFrame())) return;
  
  arduboy.clear();
  arduboy.pollButtons();
  
  switch (gameStatus){

    case GameStates::Play: //running
//      worldDrawGrid(&arduboy, &myHero, &myLevel);
//      myHero.display(&arduboy);
      //-- display/remove objects
          // for (int i=0; i<myObjects.size (); i++) {
          //   Object o=myObjects.get(i);
          //   o.display();
          // }
          //-- display/remove enemies
          // for (int i=0; i<myEnemies.size (); i++) {
          //   Enemy e=myEnemies.get(i);
          //   e.display();
          //   if (aiTurn) {
          //     e.moveEnemy();
          //     aiTurn=false;//enemy moved, wait for player's turn
          //   }
          // }
//      playerVision(&myHero, &myLevel);
//      displayGame();
        playLoop();
      break;
    
    case GameStates::Splash: 
      displaySplash();
      break;

    case GameStates::About: 
      displayLogo();
      break;

  }

  arduboy.display();

}


void playLoop() {

  playerVision(&myHero, &myLevel);

  if (arduboy.justPressed(UP_BUTTON))       { myHero.movePlayer(&myLevel, Direction::Up); }
  if (arduboy.justPressed(DOWN_BUTTON))     { myHero.movePlayer(&myLevel, Direction::Down); }
  if (arduboy.justPressed(LEFT_BUTTON))     { myHero.movePlayer(&myLevel, Direction::Left); }
  if (arduboy.justPressed(RIGHT_BUTTON))    { myHero.movePlayer(&myLevel, Direction::Right); }
  if (arduboy.justPressed(A_BUTTON))        { /* myUI.activated = true; */ }
  if (arduboy.justPressed(B_BUTTON))        { /* myUI.back = true; */ }

}


#define VISION_X_OFFSET   3
#define VISION_Y_OFFSET   4

void playerVision (Player *myHero, Level *myLevel) { //draw the walls by checking row and cols ahead of player
  
  Sprites::drawOverwrite(0, 0, frames, 0);
  Sprites::drawOverwrite(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 1, visionBack, 0);

  //far front wall
  if (myHero->y-3>=0){//make sure we don't check row out of bound in the array
    if (myLevel->worldGrid[myHero->y - 3][myHero->x]>0) {
      Sprites::drawSelfMasked(VISION_X_OFFSET, VISION_Y_OFFSET + 27, farWallFront, 0);
    }
  }

 
  //far left wall
  if (myHero->y-2>=0){
    if (myLevel->worldGrid[myHero->y-2][myHero->x-1]>0) {
      Sprites::drawExternalMask(VISION_X_OFFSET, VISION_Y_OFFSET + 23, farWallLeft, farWallLeft_Mask, 0, 0);
    }
  }
 
  
  //far right wall
  if (myHero->y-2>=0){
    if (myLevel->worldGrid[myHero->y-2][myHero->x+1]>0) {
      Sprites::drawExternalMask(VISION_X_OFFSET + 34, VISION_Y_OFFSET + 23, farWallRight, farWallRight_Mask, 0, 0);
    }
  }
 
  //mid front wall
  if (myHero->y-2>=0){
    if (myLevel->worldGrid[myHero->y-2][myHero->x]>0) {
      Sprites::drawExternalMask(VISION_X_OFFSET, VISION_Y_OFFSET + 23, midWallFront, midWallFront_Mask, 0, 0);
    }
  }

  //mid left wall
  if (myLevel->worldGrid[myHero->y-1][myHero->x-1]>0) {
    Sprites::drawExternalMask(VISION_X_OFFSET, VISION_Y_OFFSET + 14, midWallLeft, midWallLeft_Mask, 0, 0);
  }

  //mid right wall
  if (myLevel->worldGrid[myHero->y-1][myHero->x+1]>0) {
    Sprites::drawExternalMask(VISION_X_OFFSET + 38, VISION_Y_OFFSET + 14, midWallRight, midWallRight_Mask, 0, 0);
  }


  //close front wall
  if (myLevel->worldGrid[myHero->y-1][myHero->x]>0) {
    Sprites::drawExternalMask(VISION_X_OFFSET, VISION_Y_OFFSET + 14, closeWallFront, closeWallFront_Mask, 0, 0);
  }

  //close left wall
  if (myLevel->worldGrid[myHero->y][myHero->x-1]>0) {
    Sprites::drawExternalMask(VISION_X_OFFSET, VISION_Y_OFFSET, closeWallLeft, closeWallLeft_Mask, 0, 0);
  }
  //close right wall
  if (myLevel->worldGrid[myHero->y][myHero->x+1]>0) {
    Sprites::drawExternalMask(VISION_X_OFFSET + 48, VISION_Y_OFFSET, closeWallRight, closeWallRight_Mask, 0, 0);
  }

}



void worldDrawGrid(Arduboy2 *arduboy, Player *myHero, Level *myLevel) {
  
      uint8_t color = WHITE;
      //    rectMode(CORNER);
      for (int row=0; row<myLevel->xDim; row++) {
  
        for ( int col=0; col<myLevel->yDim; col++) {
  
          switch(myLevel->worldGrid[row][col]) {
  
            case 0: //floor
              color = BLACK;
              break;
  
            case 1: //wall
              color = WHITE;
              break;
  
          }
  
          arduboy->fillRect((col*TILE_SIZE + myHero->x) - ((myHero->x*TILE_SIZE)), (row*TILE_SIZE + myHero->y) - ((myHero->y *TILE_SIZE)), TILE_SIZE, TILE_SIZE, color);
  
        }
  
      }
  
    }
