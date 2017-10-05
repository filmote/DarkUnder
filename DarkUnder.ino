#include <Arduboy2.h>

#include "Enums.h"
#include "Images.h"
#include "Player.h"
#include "Enemy.h"
#include "MapData.h"


Arduboy2 arduboy;

//ArrayList<Object>myObjects = new ArrayList<Object>();

Enemy enemies[NUMBER_OF_ENEMIES];

const uint8_t *levels[] = { level_00, level_01 };
const uint8_t *map_tiles[] = { tile_00, tile_01 };
const uint8_t *map_images_00[] = { visionBack, closeWallFront, closeWallLeft, closeWallRight, midWallFront, midWallLeft, midWallRight, farWallFront, farWallLeft, farWallRight };
const uint8_t *map_masks[] = { closeWallFront_Mask, closeWallLeft_Mask, closeWallRight_Mask, midWallFront_Mask, midWallLeft_Mask, midWallRight_Mask, farWallLeft_Mask, farWallRight_Mask };

const uint8_t *enemy_images[] = { Enemy_Beholder };
const uint8_t *enemy_masks[] = { Enemy_Beholder_Mask };
const Point enemy_offset[] = { ENEMY_BEHOLDER_POSITION };

const uint8_t *direction_images[] = { directionN, directionE, directionS, directionW };

GameState gameState = GameState::Splash; 

//boolean aiTurn =true;


Level myLevel;
Player myHero;

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

    case GameState::InitGame:
      level = 0;
      gameState = GameState::InitLevel;
      break;

    case GameState::InitLevel:
      initialiseLevel(&myHero, &myLevel, levels[level]);
      break;
    
    case GameState::Play: //running
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
    
    case GameState::Splash: 
      displaySplash();
      break;

    case GameState::About: 
      displayLogo();
      break;

  }

  arduboy.display();

}


void playLoop() {

  drawPlayerVision(&myHero, &myLevel);
  drawMap(&arduboy, &myHero, &myLevel);
  drawDirectionIndicator(&myHero);
  
  if (arduboy.justPressed(UP_BUTTON))       { myHero.movePlayer(&myLevel, Button::Up); }
  if (arduboy.justPressed(DOWN_BUTTON))     { myHero.movePlayer(&myLevel, Button::Down); }
  if (arduboy.justPressed(LEFT_BUTTON))     { myHero.movePlayer(&myLevel, Button::Left); }
  if (arduboy.justPressed(RIGHT_BUTTON))    { myHero.movePlayer(&myLevel, Button::Right); }
  if (arduboy.justPressed(A_BUTTON))        { /* myUI.activated = true; */ }
  if (arduboy.justPressed(B_BUTTON))        { /* myUI.back = true; */ }

}

void initialiseLevel(Player *myHero, Level *myLevel, const uint8_t *level) {

  uint8_t idx = 0;

  myHero->x = pgm_read_byte(&level[idx++]);
  myHero->y = pgm_read_byte(&level[idx++]);
  myHero->direction = (Direction)pgm_read_byte(&level[idx++]);

  myLevel->width = pgm_read_byte(&level[idx++]);
  myLevel->height = pgm_read_byte(&level[idx++]);


  // Set the image and mask arrays ..
    
  idx++;
  myLevel->level = level;
  myLevel->map_images = map_images_00;
  myLevel->map_masks = map_masks;


  // Disable all enemies ..
  
  for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {
    enemies[i].enabled = false;
  }  


  // Create all enemies ..
  
  uint8_t numberOfEnemies = pgm_read_byte(&level[idx++]);

  for (uint8_t i = 0; i < numberOfEnemies; ++i) {  

    enemies[i].enabled = true;
    enemies[i].enemyType = (EnemyType)pgm_read_byte(&level[idx++]);
    enemies[i].x = pgm_read_byte(&level[idx++]);
    enemies[i].y = pgm_read_byte(&level[idx++]);
     
  }
    
  myLevel->startPos = idx;
  gameState = GameState::Play;

}
