#include <Arduboy2.h>

/* -----------------------------------------------------------------------------------------------------------------------------
 *  Play loop.  
 *  
 *  Handles the players moves around the dungeon.  If the player has moved (as opposed to simply turned), the enemies can then
 *  also move.  If the player and an enemy collide, the gameState is chaged to 'Battle_EnemyAttacks_Init'.
 *  
 * -----------------------------------------------------------------------------------------------------------------------------
 */
void playLoop() {
    
  bool playerMoved = false ;

  drawPlayerVision(&myHero, &myLevel);
  drawDirectionIndicator(&myHero);
  drawLevelDescription(&myLevel);

  uint8_t buttons = arduboy.justPressedButtons();

  if (buttons & UP_BUTTON_MASK)            { playerMoved = PlayerController::move(&myHero, enemies, &myLevel, Button::Up); }
  else if (buttons & DOWN_BUTTON_MASK)     { PlayerController::move(&myHero, enemies, &myLevel, Button::Down); }
  else if (buttons & LEFT_BUTTON_MASK)     { PlayerController::move(&myHero, enemies, &myLevel, Button::Left); }
  else if (buttons & RIGHT_BUTTON_MASK)    { PlayerController::move(&myHero, enemies, &myLevel, Button::Right); }

  #ifdef USE_LARGE_MAP
  else if (buttons & SELECT_BUTTON_MASK)     { 
    
    savedState = gameState;
    gameState = GameState::DisplayLargeMap; 
    
  }
  #endif
  
  else  if (buttons & BACK_BUTTON_MASK)     { 

    savedState = gameState;
    gameState = GameState::InventorySelect; 

  }
  

  // If the player moved then so should the enemies ..

  if (playerMoved) {
  
    if (myLevel.getMapElement(myHero.getX(), myHero.getY()) == MapElement::UnlockedDoor) { 
  
      if (level < MAX_LEVEL_COUNT) {
        gameState = GameState::NextLevel; 
      }
      else {
        gameState = GameState::EndOfGame;
      }
  
      return;
  
    }
  
    gameState = GameState::Move;        // Play could be at game state ItemIgnore, in which case we only want to ignore this first item only. 
  
    for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {
  
      if (enemies[i].getEnabled() && enemies[i].getMoving()) {
  
        EnemyController::move(&enemies[i], enemies, &myHero, &myLevel);
  
      }
  
    }  

  }

}
