#include <Arduboy2.h>

#include "Enums.h"
#include "Level.h"
#include "Images.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "MapData.h"
#include "PlayerController.h"
#include "EnemyController.h"


Arduboy2Base arduboy;

//ArrayList<Object>myObjects = new ArrayList<Object>();

Item items[NUMBER_OF_ITEMS];
Enemy enemies[NUMBER_OF_ENEMIES];

const uint8_t *levels[] = { level_00, level_01 };
const uint8_t *map_tiles[] = { tile_00, tile_01 };
const uint8_t *map_images_00[] = { visionBack, closeWallFront, closeWallLeft, closeWallRight, midWallFront, midWallLeft, midWallRight, farWallFront, farWallLeft, farWallRight };
const uint8_t *map_masks[] = { closeWallFront_Mask, closeWallLeft_Mask, closeWallRight_Mask, midWallFront_Mask, midWallLeft_Mask, midWallRight_Mask, farWallLeft_Mask, farWallRight_Mask };
const uint8_t *direction_images[] = { directionN, directionE, directionS, directionW };


// Enemy details ..

const uint8_t *enemy_images[] = { Enemy_Beholder };
const uint8_t *enemy_masks[] = { Enemy_Beholder_Mask };
const Point enemy_offset[] = { ENEMY_BEHOLDER_POSITION };


// Item details ..

const uint8_t *item_images[] = { icnHPPotion };
const uint8_t *item_masks[] = { icnHPPotion };
const Point item_offset[] = { ITEM_HPPOTION_POSITION };


GameState gameState = GameState::Splash; 

//boolean aiTurn =true;


Level myLevel;
Player myHero;

uint8_t level = 0;      // Current Level

void setup() {

  arduboy.boot();
  arduboy.flashlight(); 
  arduboy.audio.begin();
  arduboy.initRandomSeed();  

  myLevel.setMapTiles(map_tiles);
  
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

  bool playerMoved = false ;

  drawPlayerVision(&myHero, &myLevel);
  drawMap(&myHero, &myLevel);
  drawDirectionIndicator(&myHero);

  if (arduboy.justPressed(UP_BUTTON))       { playerMoved = PlayerController::move(&myHero, enemies, &myLevel, Button::Up); }
  if (arduboy.justPressed(DOWN_BUTTON))     { PlayerController::move(&myHero, enemies, &myLevel, Button::Down); }
  if (arduboy.justPressed(LEFT_BUTTON))     { PlayerController::move(&myHero, enemies, &myLevel, Button::Left); }
  if (arduboy.justPressed(RIGHT_BUTTON))    { PlayerController::move(&myHero, enemies, &myLevel, Button::Right); }
  if (arduboy.justPressed(A_BUTTON))        { /* myUI.activated = true; */ }
  if (arduboy.justPressed(B_BUTTON))        { /* myUI.back = true; */ }


  // If the player moved then so should the enemies ..

  if (playerMoved) {

    for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {
      
      if (enemies[i].getEnabled()) {

        EnemyController::move(&enemies[i], enemies, &myHero, &myLevel);

      }

    }  

  }

}

void initialiseLevel(Player *myHero, Level *myLevel, const uint8_t *level) {

  uint8_t idx = 0;

  myHero->setX(pgm_read_byte(&level[idx++]));
  myHero->setY(pgm_read_byte(&level[idx++]));
  myHero->setDirection((Direction)pgm_read_byte(&level[idx++]));

  myLevel->setWidth(pgm_read_byte(&level[idx++]));
  myLevel->setHeight(pgm_read_byte(&level[idx++]));


  // Set the image and mask arrays ..
    
  idx++;
  myLevel->setLevel(level);
  myLevel->setMapImages(map_images_00);
  myLevel->setMapMasks(map_masks);


  // Disable all enemies ..
  
  for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {
    enemies[i].setEnabled(false);
  }  


  // Create all enemies ..
  
  uint8_t numberOfEnemies = pgm_read_byte(&level[idx++]);

  for (uint8_t i = 0; i < numberOfEnemies; ++i) {  

    enemies[i].setEnabled(true);
    enemies[i].setEnemyType((EnemyType)pgm_read_byte(&level[idx++]));
    enemies[i].setX(pgm_read_byte(&level[idx++]));
    enemies[i].setY(pgm_read_byte(&level[idx++]));
     
  }
  

  // Disable all items ..
  
  for (uint8_t i = 0; i < NUMBER_OF_ITEMS; ++i) {
    items[i].setEnabled(false);
  }  


  // Create all items ..
  
  uint8_t numberOfItems = pgm_read_byte(&level[idx++]);

  for (uint8_t i = 0; i < numberOfItems; ++i) {  
Serial.println("sdfsd0");
    items[i].setEnabled(true);
    items[i].setItemType((ItemType)pgm_read_byte(&level[idx++]));
    items[i].setX(pgm_read_byte(&level[idx++]));
    items[i].setY(pgm_read_byte(&level[idx++]));
     
  }  

  myLevel->setStartPos(idx);
  gameState = GameState::Play;

}
