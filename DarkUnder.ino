#include <Arduboy2.h>
#include "src/utils/Arduboy2Ext.h"
#include "Enums.h"
#include "src/levels/Level.h"
#include "images/Images.h"
#include "src/entities/Player.h"
#include "src/entities/Enemy.h"
#include "src/entities/Item.h"
#include "src/levels/MapData.h"
#include "src/controllers/PlayerController.h"
#include "src/controllers/EnemyController.h"
#include "src/fonts/Font3x5.h"
#include "src/utils/Utils.h"
#include "src/utils/EnemyNames.h"
#include "FixedPoints.h"
#include "FixedPointsCommon.h"

#ifdef USE_SOUNDS
#include <ArduboyTones.h>
#endif

Arduboy2Ext arduboy;
#ifdef USE_SOUNDS
ArduboyTones sound(arduboy.audio.enabled);
#endif

Font3x5 font3x5 = Font3x5(Arduboy2::width(), Arduboy2::height());

Item items[NUMBER_OF_ITEMS];
Item doors[NUMBER_OF_DOORS];
Enemy enemies[NUMBER_OF_ENEMIES];

uint8_t attackingEnemyIdx = 0;

const uint8_t *levels[] = { level_00, level_01, level_02 };
const uint8_t *map_tiles[] = { tile_00, tile_01, tile_02, tile_03, tile_04, tile_05, tile_06, tile_07 };

const uint8_t *map_images[] = { visionBack, closeWallFront, closeGateLocked, closeDoorLocked, closeDoorUnlocked, closeWallLeft, closeWallRight, closeGateLeft, closeGateRight,
                                midWallFront, midDoorLocked, midDoorLevelLocked, midDoorLevelUnlocked, midWallLeft, midWallRight, midGateLeft, midGateRight,
                                farGateLocked, farDoorLocked, farDoorUnlocked, farWallLeft, farWallRight };

const uint8_t *direction_images[] = { directionN, directionE, directionS, directionW };

const EnemyStatistics enemyStats[] = { EnemyStatistics { 20, 12, 4, true },    // Beholder HP, AP, XP, MOVING
                                       EnemyStatistics { 10, 8, 3, true },     // Skeleton
                                       EnemyStatistics { 10, 5, 2, true },     // Displacer
                                       EnemyStatistics { 12, 10, 4, true },    // Wraith
                                       EnemyStatistics { 30, 20, 6, true },    // Dragon
                                       EnemyStatistics { 5, 2, 1, false },     // Rat
                                       EnemyStatistics { 8, 4, 6, false },     // Slime
                                     };


// Inventory settings ..

const uint8_t *inventory_images[] = { NULL, inv_key, inv_potion, inv_scroll, inv_shield, inv_sword };
const Point inventory_Coords[] = { INVENTORY_POSITION_1, INVENTORY_POSITION_2, INVENTORY_POSITION_3, INVENTORY_POSITION_4, INVENTORY_POSITION_5 };
uint8_t inventory_selection = 0;
uint8_t inventory_action = 0;


// Enemy details ..

const uint8_t *enemy_images[] = { enemy_beholder, enemy_skeleton, enemy_displacer, enemy_wraith, enemy_dragon, enemy_rat, enemy_slime };
const uint8_t *enemy_masks[] = { enemy_beholder_Mask, enemy_skeleton_Mask, enemy_displacer_Mask, enemy_wraith_Mask, enemy_dragon_Mask, enemy_rat_Mask, enemy_slime_Mask };
const Point enemy_offset[] = { ENEMY_BEHOLDER_POSITION, ENEMY_SKELETON_POSITION, ENEMY_DISPLACER_POSITION, ENEMY_WRAITH_POSITION, ENEMY_DRAGON_POSITION, ENEMY_RAT_POSITION, ENEMY_SLIME_POSITION };

#ifdef  USE_SMALL_IMAGES_1
const uint8_t *enemy_images_small[] = { enemy_beholder_small, enemy_skeleton_small, enemy_displacer_small, enemy_wraith_small, enemy_dragon_small, enemy_rat_small, enemy_slime_small };
const uint8_t *enemy_masks_small[] = { enemy_beholder_small_Mask, enemy_skeleton_small_Mask, enemy_displacer_small_Mask, enemy_wraith_small_Mask, enemy_dragon_small_Mask, enemy_rat_small_Mask, enemy_slime_small_Mask };
const Point enemy_offset_small[] = { ENEMY_BEHOLDER_POS_SMALL, ENEMY_SKELETON_POS_SMALL, ENEMY_DISPLACER_POS_SMALL, ENEMY_WRAITH_POS_SMALL, ENEMY_DRAGON_POS_SMALL, ENEMY_RAT_POS_SMALL, ENEMY_SLIME_POS_SMALL };
#endif


// Item details ..

const uint8_t *item_images[] = { NULL, item_key, item_potion, item_mascroll };
const Point item_offset[] = { Point{0, 0}, ITEM_KEY_POSITION, ITEM_HPPOTION_POSITION, ITEM_SCROLL_POSITION };
uint8_t itemAction = 0;
uint8_t savedItem = 0;

GameState gameState = GameState::Splash; 
GameState savedState = GameState::Splash; 

Level myLevel;
Player myHero;

SplashButtons splashStatus = SplashButtons::Play;
FightButtons fightButton = FightButtons::Attack;

uint8_t level = 0;          // Current map
uint8_t playerLevel = 1;    // Levelup level
#ifdef USE_DICE_ANIMATIONS
int16_t diceDelay = DICE_NO_ACTION;
#endif
uint8_t diceAttack = 0;


/* -----------------------------------------------------------------------------------------------------------------------------
 *  Setup ..
 * -----------------------------------------------------------------------------------------------------------------------------
 */
void setup() {

  arduboy.boot();
  arduboy.flashlight();

  #ifdef USE_SOUNDS
  arduboy.audio.begin();
  #endif
  
  arduboy.initRandomSeed();  
  myLevel.setMapTiles(map_tiles);

  initialiseGame();
  
}


/* -----------------------------------------------------------------------------------------------------------------------------
 *  Main loop ..
 * -----------------------------------------------------------------------------------------------------------------------------
 */
void loop() {
  
  uint16_t delayLength = 0;
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
    case GameState::ItemIgnore: 
      playLoop();
      break;

    case GameState::InventorySelect: 
    case GameState::InventoryAction: 
      delayLength = inventoryLoop();
      break;

    case GameState::ItemSelect: 
      delayLength = itemLoop();
      break;
      
    case GameState::Splash: 
      displaySplash();
      break;

    case GameState::About: 
      displayLogo();
      break;
    
    case GameState::Battle_EnemyAttacks_Init:
    case GameState::Battle_EnemyAttacks:
    case GameState::Battle_EnemyDies:
    case GameState::Battle_PlayerDecides:
    case GameState::Battle_PlayerAttacks:
    case GameState::Battle_PlayerDefends:
    case GameState::Battle_PlayerCastsSpell:
      delayLength = battleLoop();
      break;

    case GameState::Battle_PlayerDies:
      displayEndOfGame(true);
      break;
    
    case GameState::LevelUp:
      delayLength = displayLevelUp();
      break;
    
    case GameState::NextLevel:
      displayNextLevel();
      break;
      
    case GameState::EndOfGame:
      displayEndOfGame(false);
      break;

    #ifdef USE_LARGE_MAP
    case GameState::DisplayLargeMap:
      displayLargeMap();
      break;
    #endif
      
    default:
      break;

  }

  arduboy.display();
  delay(delayLength);
  
}



/* -----------------------------------------------------------------------------------------------------------------------------
 *  Level Up Handler
 * 
 *  Display the 'Level Up' graphic and award a point. 
 * 
 * -----------------------------------------------------------------------------------------------------------------------------
 */
uint16_t displayLevelUp() {
  
  arduboy.drawCompressed(0, 0, frames_outside, WHITE);
  arduboy.drawCompressed(66, 4, frames_inside, WHITE);

  #ifdef USE_LARGE_MAP
  drawMapAndStatistics(&myHero, &myLevel, true);
  #endif
  #ifndef USE_LARGE_MAP
  drawMapAndStatistics(&myHero, &myLevel);
  #endif
  drawDirectionIndicator(&myHero);
  drawLevelDescription(&myLevel);

  arduboy.drawCompressed(23, 5, levelUp, WHITE);

  font3x5.setCursor(20, 40);
  font3x5.print(F("LEVEL "));
  font3x5.print(playerLevel);
  font3x5.setCursor(18, 47);
  font3x5.print(F("YOU GAIN"));
  font3x5.setCursor(26, 54);

  playerLevel++;

  #ifdef LEVEL_UP_INC_HP
  switch (random(0, 3)) {

    case 0:
      font3x5.print(F("1 HP"));
      myHero.setHitPoints(myHero.getHitPoints() + 1);
      break;

    case 1:
      font3x5.print(F("1 AP"));
      myHero.setAttackPower(myHero.getAttackPower() + 1);
      break;

    case 2:
      font3x5.print(F("1 DF"));
      myHero.setDefence(myHero.getDefence() + 1);
      break;

    
  }
  #endif
  #ifndef LEVEL_UP_INC_HP
  switch (random(0, 2)) {

    case 0:
      font3x5.print(F("1 AP"));
      myHero.setAttackPower(myHero.getAttackPower() + 1);
      break;

    case 1:
      font3x5.print(F("1 DF"));
      myHero.setDefence(myHero.getDefence() + 1);
      break;

    
  }
  #endif
  
  gameState = GameState::Move; 
  return LEVEL_UP_DELAY;

}


/* -----------------------------------------------------------------------------------------------------------------------------
 *  Next Level Handler
 * 
 *  Display the 'Next Level' graphic and initialise the next level ready for play. 
 * 
 * -----------------------------------------------------------------------------------------------------------------------------
 */
void displayNextLevel() {
  
  //TODO Image?
  arduboy.drawCompressed(0, 0, frames_outside, WHITE);  
  arduboy.drawCompressed(8, 8, endOfLevel, WHITE);  

  font3x5.setCursor(64, 8);
  font3x5.print(F("WELL DONE!\nDONT STOP NOW\nTHE RICHES ARE\nIN YOUR GRASP\n\nPRESS A BUTTON"));

  uint8_t buttons = arduboy.justPressedButtons();
  
  if (buttons) { 
  
    level++;
    gameState = GameState::Move; 
    initialiseLevel(&myHero, &myLevel, levels[level]);
  
  }

}


/* -----------------------------------------------------------------------------------------------------------------------------
 *  End of Game Handler
 * -----------------------------------------------------------------------------------------------------------------------------
 */
void displayEndOfGame(bool playerDead) {

  arduboy.drawCompressed(0, 0, frames_outside, WHITE);

  if (playerDead) {

    arduboy.drawCompressed(66, 4, frames_inside, WHITE);
    Sprites::drawSelfMasked(DIRECTION_X_OFFSET, DIRECTION_Y_OFFSET, fight_icon, 0);
    #ifdef USE_LARGE_MAP
    drawMapAndStatistics(&myHero, &myLevel, true);
    #endif
    #ifndef USE_LARGE_MAP
    drawMapAndStatistics(&myHero, &myLevel);
    #endif
    
    arduboy.drawCompressed(16, 6, gameOver, WHITE);
    
  }
  else {

    arduboy.drawCompressed(43, 4, victory, WHITE);
    font3x5.setCursor(9, 8);
    font3x5.print(F("WELL DONE!\nTHE RICHES\nUNDER THE\nMOUNTAIN\nARE YOURS\nNOW!"));

  }

  uint8_t buttons = arduboy.justPressedButtons();
  
  if (buttons & SELECT_BUTTON_MASK) { 

    initialiseGame();
    gameState = GameState::Splash; 
  
  }

}
