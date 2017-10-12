#include <Arduboy2.h>
#include <ArduboyTones.h>

#include "Enums.h"
#include "Level.h"
#include "Images.h"
#include "Images_Dungeons.h"
#include "Images_Enemies.h"
#include "Images_Fight.h"
#include "Images_Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "MapData.h"
#include "PlayerController.h"
#include "EnemyController.h"
#include "Font3x5.h"


Arduboy2Base arduboy;
ArduboyTones sound(arduboy.audio.enabled);

Font3x5 font3x5 = Font3x5(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());

Item items[NUMBER_OF_ITEMS];
Enemy enemies[NUMBER_OF_ENEMIES];

uint8_t attackingEnemyIdx = 0;

const uint8_t *levels[] = { level_00, level_01, level_02 };
const uint8_t *map_tiles[] = { tile_00, tile_01, tile_02 };
const uint8_t *map_images_00[] = { visionBack, closeWallFront_00, closeWallLeft_00, closeWallRight_00, midWallFront_00, midWallLeft_00, midWallRight_00, farWallFront_00, farWallLeft_00, farWallRight_00 };
const uint8_t *map_images_01[] = { visionBack, closeWallFront_01, closeWallLeft_01, closeWallRight_01, midWallFront_01, midWallLeft_01, midWallRight_01, farWallFront_01, farWallLeft_01, farWallRight_01 };
const uint8_t *map_images_02[] = { visionBack, closeWallFront_02, closeWallLeft_02, closeWallRight_02, midWallFront_02, midWallLeft_02, midWallRight_02, farWallFront_02, farWallLeft_02, farWallRight_02 };
const uint8_t *map_masks[] = { closeWallFront_Mask, closeWallLeft_Mask, closeWallRight_Mask, midWallFront_Mask, midWallLeft_Mask, midWallRight_Mask, farWallLeft_Mask, farWallRight_Mask };
const uint8_t *direction_images[] = { directionN, directionE, directionS, directionW };


// Enemy details ..

const uint8_t *enemy_images[] = { enemy_beholder, enemy_skeleton, enemy_displacer, enemy_wraith, enemy_dragon, enemy_rat, enemy_slime };
const uint8_t *enemy_masks[] = { enemy_beholder_Mask, enemy_skeleton_Mask, enemy_displacer_Mask, enemy_wraith_Mask, enemy_dragon_Mask, enemy_rat_Mask, enemy_slime_Mask };
const Point enemy_offset[] = { ENEMY_BEHOLDER_POSITION, ENEMY_SKELETON_POSITION, ENEMY_DISPLACER_POSITION, ENEMY_WRAITH_POSITION, ENEMY_DRAGON_POSITION, ENEMY_RAT_POSITION, ENEMY_SLIME_POSITION };


// Item details ..

const uint8_t *item_images[] = { icnHPPotion };
const uint8_t *item_masks[] = { icnHPPotion };
const Point item_offset[] = { ITEM_HPPOTION_POSITION };


GameState gameState = GameState::Splash; 

Level myLevel;
Player myHero;

SplashButtons splashStatus = SplashButtons::Play;
FightButtons fightButton = FightButtons::Attack;


uint8_t level = 0;      // Current Level
int16_t diceDelay = DICE_NO_ACTION;
uint8_t diceNumber = 0;

void setup() {

  arduboy.boot();
  arduboy.flashlight(); 
  arduboy.audio.begin();
  arduboy.initRandomSeed();  

  myLevel.setMapTiles(map_tiles);
  
}

void loop() {
  
  uint16_t delayLength;

  if (!(arduboy.nextFrame())) return;
  
  arduboy.clear();
  arduboy.pollButtons();
  
  switch (gameState) {

    case GameState::InitGame:
      level = 0;
      gameState = GameState::InitLevel;
      break;

    case GameState::InitLevel:
      initialiseLevel(&myHero, &myLevel, levels[level]);
      break;
    
    case GameState::Move: 
      playLoop();
      break;
    
    case GameState::Battle_EnemyAttacks_Init:
    case GameState::Battle_EnemyAttacks:
    case GameState::Battle_EnemyDies:
    case GameState::Battle_PlayerDecides:
    case GameState::Battle_PlayerAttacks:
    case GameState::Battle_PlayerShields:
    case GameState::Battle_PlayerDies:
      delayLength = battleLoop();
      break;
    
    case GameState::Splash: 
      displaySplash();
      break;

    case GameState::About: 
      displayLogo();
      break;
      
  }

  arduboy.display();
  delay(delayLength);
  
}


uint16_t battleLoop() {

  uint16_t delayLength = 0;

  drawPlayerVision(&myHero, &myLevel);
  drawStatistics(&myHero);
  Sprites::drawSelfMasked(DIRECTION_X_OFFSET, DIRECTION_Y_OFFSET, fight_icon, 0);

  font3x5.setCursor(80,44);

  switch (gameState) {

    case GameState::Battle_EnemyAttacks_Init:
      
      switch (enemies[attackingEnemyIdx].getEnemyType()) {
      
        case EnemyType::Beholder:
          font3x5.print(F("A BEHOLDER"));
          break;

        case EnemyType::Displacer:
          font3x5.print(F("A DISPLACER"));
          break;

        case EnemyType::Dragon:
          font3x5.print(F("A DRAGON"));
          break;

        case EnemyType::Skeleton:
          font3x5.print(F("A SKELETON"));
          break;

        case EnemyType::Wraith:
          font3x5.print(F("A WRAITH"));
          break;

        case EnemyType::Rat:
          font3x5.print(F("A RAT"));
          break;

        case EnemyType::Slime:
          font3x5.print(F("A SLIME"));
          break;

      }

      font3x5.print(F("\nATTACKS!"));
      
      diceDelay = DICE_DELAY_START;
      gameState = GameState::Battle_EnemyAttacks;
      delayLength = FIGHT_DELAY;
      break;

    case GameState::Battle_EnemyAttacks:

      //Sprites::drawExternalMask(12, 12, fight_scratch, fight_scratch_Mask, 0, 0);
      arduboy.drawCompressed(12, 12, fight_scratch_Mask1, BLACK);
      arduboy.drawCompressed(12, 12, fight_scratch1, WHITE);
    
      if (diceDelay >= DICE_DELAY_START && diceDelay < DICE_DELAY_END) {

        rollDice(33, 26);
        
      }
      else {

        if (diceDelay >= DICE_DELAY_END) {  // Do once.
  
          diceNumber = random(0, ENEMY_MAX_ATTACK);
          diceDelay = DICE_NO_ACTION;

        }

        font3x5.print(F("YOU TAKE\n"));
        font3x5.print(diceNumber);
        font3x5.print(F(" DAMAGE!"));
        font3x5.setCursor(33, 26);
        font3x5.print(diceNumber);

        myHero.setHitPoints(myHero.getHitPoints() - diceNumber);
        gameState = GameState::Battle_PlayerDecides;
        delayLength = FIGHT_DELAY;
        break;
        
      }
      break;

    case GameState::Battle_PlayerDecides:

//      Sprites::drawOverwrite(80, 44, fight_actions, 0);
      arduboy.drawCompressed(80, 44, fight_actions, WHITE);
      Sprites::drawSelfMasked(80 + (((uint8_t)fightButton) * 12), 56, icnSelect, 0);

      if (arduboy.justPressed(LEFT_BUTTON) && (uint8_t)fightButton > 0)                                 { fightButton = (FightButtons)((uint8_t)fightButton - 1); }
      if (arduboy.justPressed(RIGHT_BUTTON) && (uint8_t)fightButton < (uint8_t)FightButtons::Defend)    { fightButton = (FightButtons)((uint8_t)fightButton + 1); }
      if (arduboy.justPressed(A_BUTTON))  {
        
        diceDelay = DICE_DELAY_START; 
        gameState = GameState::Battle_PlayerAttacks; 
      
      }

      break;

    case GameState::Battle_PlayerAttacks:
    case GameState::Battle_PlayerShields:
    
      switch (gameState) {

        case GameState::Battle_PlayerAttacks:
//          Sprites::drawExternalMask(18, 19, fight_hero_strike, fight_hero_strike_Mask, 0, 0);
        arduboy.drawCompressed(18, 19, fight_hero_strike_Mask, BLACK);
        arduboy.drawCompressed(18, 19, fight_hero_strike, WHITE);
        break;

        case GameState::Battle_PlayerShields:
          Sprites::drawExternalMask(18, 19, fight_hero_strike, fight_hero_strike_Mask, 0, 0);
          break;
        
      }
    
      if (diceDelay >= DICE_DELAY_START && diceDelay < DICE_DELAY_END) {

        rollDice(31, 24);
        
      }
      else {

        if (diceDelay >= DICE_DELAY_END) {  // Do once.

          diceNumber = random(0, HUMAN_MAX_ATTACK) + 1;
          diceDelay = DICE_NO_ACTION;

        }

        font3x5.print(F("YOU DEAL\n"));
        font3x5.print(diceNumber);
        font3x5.print(F(" DAMAGE!"));
        font3x5.setCursor(31, 24);
        font3x5.print(diceNumber);
        
        enemies[attackingEnemyIdx].decHitPoints(diceNumber);

        if (enemies[attackingEnemyIdx].getHitPoints() > 0) {
          gameState = GameState::Battle_EnemyAttacks_Init;
        }
        else {
          gameState = GameState::Battle_EnemyDies;
        }

        delayLength = FIGHT_DELAY;

      }

      break;   

    case GameState::Battle_EnemyDies:
      arduboy.drawCompressed(18, 19, fight_hero_strike_Mask, BLACK);
      arduboy.drawCompressed(18, 19, fight_hero_strike, WHITE);
      gameState = GameState::Move;
      delayLength = FIGHT_DELAY;
      break;

  }

  drawEnemyHitPointsBar(enemies[attackingEnemyIdx].getHitPoints());
  return delayLength;

}

void rollDice(uint8_t x, uint8_t y) {

  font3x5.setCursor(x, y);
  font3x5.print(diceNumber);

  if (diceDelay < 1) {

    diceNumber = random(0, 4);
    diceDelay++;

    sound.tone(NOTE_A1, 20);
    
  }
  else {  

    if (arduboy.everyXFrames(diceDelay)) {

      sound.tone(NOTE_A1, 20);
      
      diceNumber = random(0, 4);
      diceDelay = diceDelay * 2;

    }

  }

}

void playLoop() {

  bool playerMoved = false ;

  drawPlayerVision(&myHero, &myLevel);
  drawMap(&myHero, &myLevel);
  drawDirectionIndicator(&myHero);
  drawLevelDescription(&myLevel);
  drawStatistics(&myHero);
  
  if (arduboy.justPressed(UP_BUTTON))       { playerMoved = PlayerController::move(&myHero, enemies, &myLevel, Button::Up); }
  if (arduboy.justPressed(DOWN_BUTTON))     { PlayerController::move(&myHero, enemies, &myLevel, Button::Down); }
  if (arduboy.justPressed(LEFT_BUTTON))     { PlayerController::move(&myHero, enemies, &myLevel, Button::Left); }
  if (arduboy.justPressed(RIGHT_BUTTON))    { PlayerController::move(&myHero, enemies, &myLevel, Button::Right); }


  // If the player moved then so should the enemies ..

  if (playerMoved) {

    for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {
      
      if (enemies[i].getEnabled()) {

        EnemyController::move(&enemies[i], enemies, &myHero, &myLevel);

      }

    }  

  }


  // If the player is 'touching' an enemy then enter battle mode ..

  for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {
    
    if (enemies[i].getEnabled()) {

      if ((abs(myHero.getX() - enemies[i].getX()) == 1) ^ (abs(myHero.getY() - enemies[i].getY()) == 1))  {

        attackingEnemyIdx = i;
        gameState = GameState::Battle_EnemyAttacks_Init;
        break;

      } 

    }

  }  

}


void initialiseLevel(Player *myHero, Level *myLevel, const uint8_t *level) {

  uint8_t idx = 0;

  // Read level title ..

  for (uint8_t i = 0; i < 11; ++i) {
    
    myLevel->getTitleLine1()[i] = pgm_read_byte(&level[idx++]);

  }

  for (uint8_t i = 0; i < 11; ++i) {
    
    myLevel->getTitleLine2()[i] = pgm_read_byte(&level[idx++]);
    
  }
            
  myHero->setX(pgm_read_byte(&level[idx++]));
  myHero->setY(pgm_read_byte(&level[idx++]));
  myHero->setDirection((Direction)pgm_read_byte(&level[idx++]));

  myLevel->setWidth(pgm_read_byte(&level[idx++]));
  myLevel->setHeight(pgm_read_byte(&level[idx++]));


  // Set the image and mask arrays ..
    
  myLevel->setLevel(level);
  uint8_t dungeonStyle = pgm_read_byte(&level[idx++]);
  if (dungeonStyle == 0) { myLevel->setMapImages(map_images_00); }
  if (dungeonStyle == 1) { myLevel->setMapImages(map_images_01); }
  if (dungeonStyle == 2) { myLevel->setMapImages(map_images_02); }
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
    enemies[i].setHitPoints(ENEMY_MAX_HITPOINTS);
    
  }
  

  // Disable all items ..
  
  for (uint8_t i = 0; i < NUMBER_OF_ITEMS; ++i) {
    items[i].setEnabled(false);
  }  


  // Create all items ..
  
  uint8_t numberOfItems = pgm_read_byte(&level[idx++]);

  for (uint8_t i = 0; i < numberOfItems; ++i) {  

    items[i].setEnabled(true);
    items[i].setItemType((ItemType)pgm_read_byte(&level[idx++]));
    items[i].setX(pgm_read_byte(&level[idx++]));
    items[i].setY(pgm_read_byte(&level[idx++]));
     
  }  

  myLevel->setStartPos(idx);
  gameState = GameState::Move;

}
