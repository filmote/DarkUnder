#include <Arduboy2.h>

#include "Enums.h"
#include "Images.h"
#include "Player.h"
#include "MapData.h"


//int row;
//int col;
//int pcolX;
//int prowY;

//ArrayList<Object>myObjects = new ArrayList<Object>();
//ArrayList<Enemy>myEnemies = new ArrayList<Enemy>();

const uint8_t *levels[] = { level_00, level_01 };
const uint8_t *map_tiles[] = { tile_00, tile_01 };
const uint8_t *direction_images[] = { directionN, directionE, directionS, directionW };

GameStates gameState = GameStates::Splash; 

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

uint8_t level = 0;      // Current Level

void setup() {

  myLevel.map_tiles = map_tiles;
  arduboy.begin();
  arduboy.setFrameRate(75);
  arduboy.initRandomSeed();  

}

void loop() {
  
  if (!(arduboy.nextFrame())) return;
  
  arduboy.clear();
  arduboy.pollButtons();
  
  switch (gameState){

    case GameStates::InitGame:
      level = 0;
      gameState = GameStates::InitLevel;
      break;

    case GameStates::InitLevel:
      initialiseLevel(&myHero, &myLevel, levels[level]);
      break;
    
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
  worldDrawGrid(&arduboy, &myHero, &myLevel);
  drawDirectionIndicator(&myHero);
  
  if (arduboy.justPressed(UP_BUTTON))       { myHero.movePlayer(&myLevel, Buttons::Up); }
  if (arduboy.justPressed(DOWN_BUTTON))     { myHero.movePlayer(&myLevel, Buttons::Down); }
  if (arduboy.justPressed(LEFT_BUTTON))     { myHero.movePlayer(&myLevel, Buttons::Left); }
  if (arduboy.justPressed(RIGHT_BUTTON))    { myHero.movePlayer(&myLevel, Buttons::Right); }
  if (arduboy.justPressed(A_BUTTON))        { /* myUI.activated = true; */ }
  if (arduboy.justPressed(B_BUTTON))        { /* myUI.back = true; */ }

}


#define VISION_X_OFFSET   3
#define VISION_Y_OFFSET   4

void playerVision (Player *myHero, Level *myLevel) { //draw the walls by checking row and cols ahead of player

  bool horizon3Plus = false;
  bool horizon2Plus = false;

  int8_t farLeftX = 0;
  int8_t farFrontX = 0;
  int8_t farRightX = 0;

  int8_t farLeftY = 0;
  int8_t farFrontY = 0;
  int8_t farRightY = 0;
  
  int8_t middleLeftX = 0;
  int8_t middleFrontX = 0;
  int8_t middleRightX = 0;

  int8_t middleLeftY = 0;
  int8_t middleFrontY = 0;
  int8_t middleRightY = 0;

  int8_t closeLeftX = 0;
  int8_t closeFrontX = 0;
  int8_t closeRightX = 0;

  int8_t closeLeftY = 0;
  int8_t closeFrontY = 0;
  int8_t closeRightY = 0;

  switch (myHero->direction) {

    case Direction::North:
    
      horizon3Plus = (myHero->y - 3 >= 0);
      horizon2Plus = (myHero->y - 2 >= 0);

      farFrontX = 0;      farFrontY = -3;
      farLeftX = -1;      farLeftY = -2;
      farRightX = 1;      farRightY = -2;

      middleFrontX = 0;   middleFrontY = -2;
      middleLeftX = -1;   middleLeftY = -1;
      middleRightX = 1;   middleRightY = -1;

      closeFrontX = 0;    closeFrontY = -1;
      closeLeftX = -1;    closeLeftY = 0;
      closeRightX = 1;    closeRightY = 0;

      break;
      
    case Direction::East:
    
      horizon3Plus = (myHero->x + 3 >= 0);
      horizon2Plus = (myHero->x + 2 >= 0);
      
      farFrontX = 3;      farFrontY = 0;
      farLeftX = 2;       farLeftY = -1;
      farRightX = 2;      farRightY = 1;

      middleFrontX = 2;   middleFrontY = 0;
      middleLeftX = 1;    middleLeftY = -1;
      middleRightX = 1;   middleRightY = 1;

      closeFrontX = 1;    closeFrontY = 0;
      closeLeftX = 0;     closeLeftY = -1;
      closeRightX = 0;    closeRightY = 1;

      break;

    case Direction::South:
    
      horizon3Plus = (myHero->y + 3 >= 0);
      horizon2Plus = (myHero->y + 2 >= 0);

      farFrontX = 0;      farFrontY = 3;
      farLeftX = 1;       farLeftY = 2;
      farRightX = -1;     farRightY = 2;

      middleFrontX = 0;   middleFrontY = 2;
      middleLeftX = 1;    middleLeftY = 1;
      middleRightX = -1;  middleRightY = 1;

      closeFrontX = 0;    closeFrontY = 1;
      closeLeftX = 1;     closeLeftY = 0;
      closeRightX = -1;   closeRightY = 0;

      break;
      
    case Direction::West:
    
      horizon3Plus = (myHero->x - 3 >= 0);
      horizon2Plus = (myHero->x - 2 >= 0);
      
      farFrontX = -3;     farFrontY = 0;
      farLeftX = -2;      farLeftY = 1;
      farRightX = -2;     farRightY = -1;

      middleFrontX = -2;  middleFrontY = 0;
      middleLeftX = -1;   middleLeftY = 1;
      middleRightX = -1;  middleRightY = -1;

      closeFrontX = -1;   closeFrontY = 0;
      closeLeftX = 0;     closeLeftY = 1;
      closeRightX = 0;    closeRightY = -1;

      break;    
      
  }

  
  Sprites::drawOverwrite(0, 0, frames, 0);
  Sprites::drawSelfMasked(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 1, visionBack, 0);

  // Far front wall ..
  
  if (horizon3Plus) {
    if ((MapElements)myLevel->getMapElement(myHero->x + farFrontX, myHero->y + farFrontY) > MapElements::Floor) {        //worldGrid[myHero->y + farFrontY][myHero->x + farFrontX] > MapElements::Floor) {
      Sprites::drawSelfMasked(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 27, farWallFront, 0);
    }
  }

 
  // Far left wall ..
  
  if (horizon2Plus) {
    if ((MapElements)myLevel->getMapElement(myHero->x + farLeftX, myHero->y + farLeftY) > MapElements::Floor) {        //worldGrid[myHero->y + farLeftY][myHero->x + farLeftX] > MapElements::Floor) {
      Sprites::drawExternalMask(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 23, farWallLeft, farWallLeft_Mask, 0, 0);
    }
  }
 
  
  // Far right wall ..

  if (horizon2Plus) {
    if ((MapElements)myLevel->getMapElement(myHero->x + farRightX, myHero->y + farRightY) > MapElements::Floor) {        //worldGrid[myHero->y + farRightY][myHero->x + farRightX] > MapElements::Floor) {
      Sprites::drawExternalMask(VISION_X_OFFSET + 34, VISION_Y_OFFSET + 23, farWallRight, farWallRight_Mask, 0, 0);
    }
  }

 
  // Mid front wall ..
  
  if (horizon2Plus) {
    if ((MapElements)myLevel->getMapElement(myHero->x + middleFrontX, myHero->y + middleFrontY) > MapElements::Floor) {        //worldGrid[myHero->y + middleFrontY][myHero->x + middleFrontX] > MapElements::Floor) {
      Sprites::drawExternalMask(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 23, midWallFront, midWallFront_Mask, 0, 0);
    }
  }


  // Mid left wall ..

  if ((MapElements)myLevel->getMapElement(myHero->x + middleLeftX, myHero->y + middleLeftY) > MapElements::Floor) {       //worldGrid[myHero->y + middleLeftY][myHero->x + middleLeftX] > MapElements::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 14, midWallLeft, midWallLeft_Mask, 0, 0);
  }


  // Mid right wall ..
  
  if ((MapElements)myLevel->getMapElement(myHero->x + middleRightX, myHero->y + middleRightY) > MapElements::Floor) {    //worldGrid[myHero->y + middleRightY][myHero->x + middleRightX] > MapElements::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET + 38, VISION_Y_OFFSET + 14, midWallRight, midWallRight_Mask, 0, 0);
  }


  // Close front wall ..
  
  if ((MapElements)myLevel->getMapElement(myHero->x + closeFrontX, myHero->y + closeFrontY) > MapElements::Floor) {  // worldGrid[myHero->y + closeFrontY][myHero->x + closeFrontX] > MapElements::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET, VISION_Y_OFFSET + 14, closeWallFront, closeWallFront_Mask, 0, 0);
  }


  // Close left wall ..

  if ((MapElements)myLevel->getMapElement(myHero->x + closeLeftX, myHero->y + closeLeftY) > MapElements::Floor) {   //worldGrid[myHero->y + closeLeftY][myHero->x + closeLeftX] > MapElements::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET, VISION_Y_OFFSET, closeWallLeft, closeWallLeft_Mask, 0, 0);
  }

  
  // Close right wall ..
  
  if (myLevel->getMapElement(myHero->x + closeRightX, myHero->y + closeRightY) > MapElements::Floor) {    //[myHero->y + closeRightY][myHero->x + closeRightX] > MapElements::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET + 48, VISION_Y_OFFSET, closeWallRight, closeWallRight_Mask, 0, 0);
  }

}


//#define offset



#define MAP_X_OFFSET   98
#define MAP_Y_OFFSET   6

void worldDrawGrid(Arduboy2 *arduboy, Player *myHero, Level *myLevel) {

  uint8_t drawX = 0;
  uint8_t drawY = 0;
  
  for (int16_t mapY = myHero->y - 3; mapY <= myHero->y + 3; mapY++) {

    for (int16_t mapX = myHero->x - 2; mapX <= myHero->x + 2; mapX++) {

      if (mapY >= 0 && mapY < (int16_t)myLevel->height && mapX >= 0 && mapX < (int16_t)myLevel->width && !(drawX == 4 && drawY == 0) ) { 
        
        switch (myLevel->getMapElement(mapX, mapY)) { // worldGrid[mapY][mapX]) {
  
          case MapElements::Floor:
            arduboy->fillRect(MAP_X_OFFSET + (drawX * TILE_OFFSET), MAP_Y_OFFSET + (drawY * TILE_OFFSET), TILE_SIZE, TILE_SIZE, WHITE);
            break;
  
          case MapElements::Wall:
            //arduboy->fillRect(MAP_X_OFFSET + (x * TILE_OFFSET), MAP_Y_OFFSET + (y * TILE_OFFSET), TILE_SIZE, TILE_SIZE, WHITE);
            break;
  
        }

      }

      drawX++;
      
    }

    drawX = 0;
    drawY++;

  }


  // Render enemies ..


  // Render player ..

  arduboy->fillRect(MAP_X_OFFSET + 11, MAP_Y_OFFSET + 16, 2, 2, BLACK);

}

#define DIRECTION_X_OFFSET 66
#define DIRECTION_Y_OFFSET 43

void drawDirectionIndicator(Player *myHero) {

  Sprites::drawSelfMasked(DIRECTION_X_OFFSET, DIRECTION_Y_OFFSET, direction_images[(uint8_t)myHero->direction], 0);
  
}


void initialiseLevel(Player *myHero, Level *myLevel, const uint8_t *level) {

  uint8_t idx = 0;

  myHero->x = pgm_read_byte(&level[idx++]);
  myHero->y = pgm_read_byte(&level[idx++]);
  myHero->direction = (Direction)pgm_read_byte(&level[idx++]);

  myLevel->width = pgm_read_byte(&level[idx++]);
  myLevel->height = pgm_read_byte(&level[idx++]);
  myLevel->startPos = idx;
  gameState = GameStates::Play;

}
