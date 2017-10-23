#include <Arduboy2.h>
#include "Arduboy2Ext.h"
#include "Enums.h"
#include "Level.h"
#include "Images.h"
#include "Images_Dungeons.h"
#include "Images_Enemies.h"
#include "Images_Fight.h"
#include "Images_Map.h"
#include "Images_Inventory.h"
#include "Images_Items.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "MapData.h"
#include "PlayerController.h"
#include "EnemyController.h"
#include "Font3x5.h"
#include "Utils.h"
#include "EnemyNames.h"

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
const uint8_t *map_tiles[] = { tile_00, tile_01, tile_02 };

const uint8_t *map_images[] = { visionBack, closeWallFront, closeGateLocked, closeDoorLocked, closeDoorUnlocked, closeWallLeft, closeWallRight, closeGateLeft, closeGateRight,
                                midWallFront, midDoorLocked, midDoorLevelLocked, midDoorLevelUnlocked, midWallLeft, midWallRight, midGateLeft, midGateRight,
                                farGateLocked, farDoorLocked, farDoorUnlocked, farWallLeft, farWallRight };

const uint8_t *direction_images[] = { directionN, directionE, directionS, directionW };


// Inventory settings ..

const uint8_t *inventory_images[] = { NULL, inv_key, inv_potion, inv_scroll, inv_shield, inv_sword };
const Point inventory_Coords[] = { INVENTORY_POSITION_1, INVENTORY_POSITION_2, INVENTORY_POSITION_3, INVENTORY_POSITION_4, INVENTORY_POSITION_5 };
uint8_t inventory_selection = 0;
uint8_t inventory_action = 0;


// Enemy details ..

const uint8_t *enemy_images[] = { enemy_beholder, enemy_skeleton, enemy_displacer, enemy_wraith, enemy_dragon, enemy_rat, enemy_slime };
const uint8_t *enemy_masks[] = { enemy_beholder_Mask, enemy_skeleton_Mask, enemy_displacer_Mask, enemy_wraith_Mask, enemy_dragon_Mask, enemy_rat_Mask, enemy_slime_Mask };
const Point enemy_offset[] = { ENEMY_BEHOLDER_POSITION, ENEMY_SKELETON_POSITION, ENEMY_DISPLACER_POSITION, ENEMY_WRAITH_POSITION, ENEMY_DRAGON_POSITION, ENEMY_RAT_POSITION, ENEMY_SLIME_POSITION };


// Item details ..

const uint8_t *item_images[] = { NULL, item_key, item_potion, item_mascroll };
const Point item_offset[] = { Point{0, 0}, ITEM_KEY_POSITION, ITEM_HPPOTION_POSITION, ITEM_SCROLL_POSITION };
uint8_t item_action = 0;
uint8_t savedItem = 0;

GameState gameState = GameState::Splash; 
GameState savedState = GameState::Splash; 

Level myLevel;
Player myHero;

SplashButtons splashStatus = SplashButtons::Play;
FightButtons fightButton = FightButtons::Attack;


uint8_t level = 0;      // Current Level
#ifdef USE_DICE_ANIMATIONS
int16_t diceDelay = DICE_NO_ACTION;
#endif
uint8_t diceAttack = 0;


/* -----------------------------------------------------------------------------------------------------------------------------
 *  Setup ..
 * -----------------------------------------------------------------------------------------------------------------------------
 */
void setup() {

  #ifdef USE_BEGIN
  arduboy.begin()
  #else
  arduboy.boot();
  #endif

  #ifdef USE_FLASHLIGHT
  arduboy.flashlight();
  #endif

  #ifdef USE_SOUNDS
  arduboy.audio.begin();
  arduboy.initRandomSeed();  
  #endif
  
  myLevel.setMapTiles(map_tiles);

  myHero.setInventory(0, Inventory::Key);
//  myHero.setInventory(1, Inventory::Potion);
  myHero.setInventory(2, Inventory::Potion);
  myHero.setInventory(3, Inventory::Shield);
  myHero.setInventory(4, Inventory::Sword);
  
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
      inventoryLoop();
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
    case GameState::Battle_PlayerDies:
      delayLength = battleLoop();
      break;
      
    case GameState::NextLevel:
      displayNextLevel();
      break;
      
    case GameState::EndOfGame:
      displayEndOfGame();
      break;

  }

  arduboy.display();
  delay(delayLength);
  
}


/* -----------------------------------------------------------------------------------------------------------------------------
 *  Item loop.  
 *  
 *  Controls the selection or discarding of an item the player has stumbled over.  If a user choses to ignore an item found in 
 *  the maze, the GameState is updated to ItemIgnore which will allow them to progress beyond the item.  If th user returns to
 *  the same position in the maze, they will be re-prompted to collect / discard the same item.
 *  
 *  The player can press the BACK_BUTTON (as defined in Enums.h) to bring up the inventory management dialogue if they need to 
 *  delete an existing inventory item to make space for the new item.  The current GameState is retained in the 'savedState' 
 *  field allowing for control to return back to this action after the dialogue is dismissed.
 *  
 *  Returns delay in milliseconds to wait.
 *
 * -----------------------------------------------------------------------------------------------------------------------------
 */
uint16_t itemLoop() {

  drawPlayerVision(&myHero, &myLevel);

  if (item_action == INVENTORY_ACTION_USE)     arduboy.drawCompressed(71, 56, inv_select, WHITE);
  if (item_action == INVENTORY_ACTION_DELETE)  arduboy.drawCompressed(83, 56, inv_select, WHITE);

  arduboy.drawCompressed(70, 45, inv_hand, WHITE);
  arduboy.drawCompressed(81, 45, inv_trash, WHITE);

  uint8_t buttons = arduboy.justPressedButtons();
  
  if ((buttons & LEFT_BUTTON_MASK) && item_action > ITEM_ACTION_USE)         { --item_action; }
  if ((buttons & RIGHT_BUTTON_MASK) && item_action < ITEM_ACTION_DELETE)     { ++item_action; }


  // Return to the previous game state if the user presses the back button ..

  if (buttons & BACK_BUTTON) {
    savedState = gameState;
    gameState = GameState::InventorySelect;
  }

  
  // Handle the use of the selected item ..

  if (buttons & SELECT_BUTTON) {

    if (item_action == ITEM_ACTION_USE) {

      Inventory inventoryType = (Inventory)((uint8_t)items[savedItem].getItemType());
      // int8_t inventorySlot = -1;
      // bool item_no_slots = false;
      
      // switch (inventoryType) {

      //   case Inventory::Key:

      //     inventorySlot = myHero.getConsumableSlot();
      //     if (inventorySlot >= 0) {

      //       myHero.setInventory(inventorySlot, inventoryType);
      //       items[savedItem].setEnabled(false);
      //       gameState = GameState::Move;
            
      //     }
      //     else {
          
      //       item_no_slots = true;

      //     }
      //     break;
          
      //   case Inventory::Potion:
      //   case Inventory::Scroll:

      //     inventorySlot = myHero.getSlotNumber(inventoryType);
      //     if (inventorySlot < 0) { inventorySlot = myHero.getConsumableSlot(); }

      //     if (inventorySlot >= 0) {

      //       myHero.setInventory(inventorySlot, inventoryType);
      //       items[savedItem].setEnabled(false);
      //       gameState = GameState::Move;
            
      //     }
      //     else {
          
      //       item_no_slots = true;

      //     }

      //   default: break;

      // }

      int8_t inventorySlot = myHero.getConsumableSlot();
      if (inventorySlot >= 0) {

        myHero.setInventory(inventorySlot, inventoryType);
        items[savedItem].setEnabled(false);
        gameState = GameState::Move;
        
      }
      else {
      
        font3x5.setCursor(95, 44);
        font3x5.print(F("NO INV\nSLOTS!"));
        return ITEM_DELAY;

      }


      // // Diplay a message if there are no inventory slots to pickup the item ..

      // if (item_no_slots) {
        
      //   font3x5.setCursor(95, 44);
      //   font3x5.print(F("NO INV\nSLOTS!"));
      //   return ITEM_DELAY;

      // }
      
    }

    if (item_action == ITEM_ACTION_DELETE)  { 
      
      gameState = GameState::ItemIgnore;
    
    }

  }

  return 0;

}


/* -----------------------------------------------------------------------------------------------------------------------------
 *  Inventory loop.  
 *  
 *  Controls the management and use of the inventory panel.  As a player transitions to this panel, the current GameState is 
 *  saved in a variable named 'savedState' which allows the player to exit the panel and return to whence they came.
 *  
 *  GameStates:
 *  
 *  InventorySelect     - navigate through the five inventory slots.
 *  InventoryAction     - after selecting an item, the user can use or delete an item.
 *  
 * -----------------------------------------------------------------------------------------------------------------------------
 */
void inventoryLoop() {
 
  arduboy.drawCompressed(0, 0, frames_outside, WHITE);  
  arduboy.drawCompressed(66, 4, frames_inside, WHITE);

  #ifdef INV_STYLE_BONW
  arduboy.drawCompressed(4, 4, inv_background, WHITE);
  #endif
  #ifdef INV_STYLE_WONB
  Sprites::drawOverwrite(8, 32, inv_lhs_icons, 0);
  #endif
  
  drawMapAndStatistics(&myHero, &myLevel);

  // TODO: Attempted to roll the rendering below with the selector using an 'if (i == inventory_selection) ..' added 46 bytes.
  for (uint8_t i = 0; i < 5; ++i) {

    if (myHero.getInventory(i) != Inventory::None) {

      Point inventoryCoords = inventory_Coords[i];

      #ifdef INV_STYLE_BONW
      arduboy.fillRect(inventoryCoords.x, inventoryCoords.y, 14, 16, BLACK);
      arduboy.drawCompressed(inventoryCoords.x, inventoryCoords.y, inventory_images[(uint8_t)myHero.getInventory(i)], WHITE);
      #endif
      #ifdef INV_STYLE_WONB
      arduboy.drawRect(inventoryCoords.x - 1, inventoryCoords.y - 1, 16, 16);
      arduboy.drawCompressed(inventoryCoords.x, inventoryCoords.y, inventory_images[(uint8_t)myHero.getInventory(i)], WHITE);
      #endif
      
    }

  }


  // Render selector ..

  Point inventoryCoords = inventory_Coords[inventory_selection];
  #ifdef INV_STYLE_BONW
  arduboy.drawCompressed(inventoryCoords.x + 3, inventoryCoords.y + 11, inv_select, BLACK);
  #endif
  #ifdef INV_STYLE_WONB
  arduboy.drawCompressed(inventoryCoords.x + 3, inventoryCoords.y + 11, inv_select, WHITE);
  #endif
  uint8_t buttons = arduboy.justPressedButtons();

  switch (gameState) {

    case GameState::InventorySelect:
      if ((buttons & LEFT_BUTTON_MASK) && inventory_selection > 0)      { --inventory_selection; }
      if ((buttons & RIGHT_BUTTON_MASK) && inventory_selection < 4)     { ++inventory_selection; }
      if (buttons & BACK_BUTTON_MASK)                                   { gameState = savedState;}

      if (buttons & SELECT_BUTTON_MASK) { 
        if (myHero.getInventory(inventory_selection) != Inventory::None) {
          gameState = GameState::InventoryAction;
        }
      }

      break;

    case GameState::InventoryAction:

      if (inventory_action == INVENTORY_ACTION_USE)     arduboy.drawCompressed(71, 56, inv_select, WHITE);
      if (inventory_action == INVENTORY_ACTION_DELETE)  arduboy.drawCompressed(83, 56, inv_select, WHITE);

      arduboy.drawCompressed(70, 45, inv_hand, WHITE);
      arduboy.drawCompressed(81, 45, inv_trash, WHITE);
  
      if ((buttons & LEFT_BUTTON_MASK) && inventory_action > INVENTORY_ACTION_USE)         { --inventory_action; }
      if ((buttons & RIGHT_BUTTON_MASK) && inventory_action < INVENTORY_ACTION_DELETE)     { ++inventory_action; }
      if (buttons & BACK_BUTTON_MASK)                                                      { gameState = GameState::InventorySelect;}

      if (buttons & SELECT_BUTTON_MASK) { 
        
        if (inventory_action == INVENTORY_ACTION_USE) {
         
          switch (myHero.getInventory(inventory_selection)) {

            case Inventory::Key:
            
              for (uint8_t i = 0; i < NUMBER_OF_DOORS; ++i) {

                int16_t deltaX = doors[i].getX() - myHero.getX();
                int16_t deltaY = doors[i].getY() - myHero.getY();
                
                if (doors[i].getEnabled() && (doors[i].getItemType() == ItemType::LockedDoor || doors[i].getItemType() == ItemType::LockedGate) && 
                    absT(deltaX) <= 1 && absT(deltaY) <= 1) {

                  if (doors[i].getItemType() == ItemType::LockedGate)       doors[i].setEnabled(false);
                  if (doors[i].getItemType() == ItemType::LockedDoor)       doors[i].setItemType(ItemType::UnlockedDoor);
                      
                  myHero.setInventory(inventory_selection, Inventory::None);
                  inventory_action = INVENTORY_ACTION_USE;
                  gameState = GameState::InventorySelect;
            
                }

              }
              break;

            case Inventory::Potion:
              myHero.setHitPoints(myHero.getHitPoints() + INVENTORY_POTION_HP_INC);
//              myHero.decInventoryCount(Inventory::Potion);
              myHero.setInventory(inventory_selection, Inventory::None);
              inventory_action = INVENTORY_ACTION_USE;
              gameState = GameState::InventorySelect;
              break;

            default: break;

          }

        }

        if (inventory_action == INVENTORY_ACTION_DELETE) {

          myHero.setInventory(inventory_selection, Inventory::None);
          inventory_action = INVENTORY_ACTION_USE;
          gameState = GameState::InventorySelect;

        }

      }

      break;

    default: break;

  }

}


/* -----------------------------------------------------------------------------------------------------------------------------
 *  Dice control.  
 *  
 *  Transition the dice rolling to the final state.  The variable 'diceAttack' stores the final dice value.
 *  
 * -----------------------------------------------------------------------------------------------------------------------------
 */
#ifdef USE_DICE_ANIMATIONS
void diceDoOnce(uint8_t maxValue, uint8_t offset) {

  if (diceDelay >= DICE_DELAY_END) {  // Do once.

    diceAttack = random(0, maxValue) + offset;
    diceDelay = DICE_NO_ACTION;

  }

}
#endif


/* -----------------------------------------------------------------------------------------------------------------------------
 *  Battle Loop  
 *  
 *  GameStates:
 *  
 *  Battle_EnemyAttacks_Init -    Displays the initial '{enemy} attacks !' message and prepares for and enemy attck.
 *  Battle_EnemyAttacks -         Displays the dice animation and inflicts damage to the player.  
 *  Battle_PlayerDecides -        Presents the players battle options including attack, defend, cast a spell ..
 *  Battle_PlayerAttacks -        Throws the dice and inflicts damage on the enemy.
 *  Battle_PlayerDefends -        Inflicts 1 point of damage on the enemy and randomly gains player hit points.
 *  Battle_PlayerCastsSpell -     Inflicts 5 points of damage on the enemy.
 *  Battle_EnemyDies -            Handles and end of battel where the enemy dies.
 * 
 *  Returns delay in milliseconds to wait.
 *  
 * -----------------------------------------------------------------------------------------------------------------------------
 */
uint16_t battleLoop() {

  uint16_t delayLength = 0;
  
  drawPlayerVision(&myHero, &myLevel);
  Sprites::drawSelfMasked(DIRECTION_X_OFFSET, DIRECTION_Y_OFFSET, fight_icon, 0);

  font3x5.setCursor(80,44);

  switch (gameState) {

    case GameState::Battle_EnemyAttacks_Init:
      
      font3x5.print(getEnemyName(enemies[attackingEnemyIdx].getEnemyType()));
      font3x5.print(F("\nATTACKS!"));
      
      #ifdef USE_DICE_ANIMATIONS
      diceDelay = DICE_DELAY_START;
      #endif
      gameState = GameState::Battle_EnemyAttacks;
      delayLength = FIGHT_DELAY;
      break;

    case GameState::Battle_EnemyAttacks:
    
      arduboy.drawCompressed(12, 12, fight_scratch_Mask, BLACK);
      arduboy.drawCompressed(12, 12, fight_scratch, WHITE);

      #ifdef USE_DICE_ANIMATIONS
      if (diceDelay >= DICE_DELAY_START && diceDelay < DICE_DELAY_END) {

        rollDice(33, 26);
        
      }
      else {

        diceDoOnce(ENEMY_MAX_ATTACK, 0);

        font3x5.print(F("YOU TAKE\n"));
        font3x5.print(diceAttack);
        font3x5.print(F(" DAMAGE!"));
        font3x5.setCursor(33, 26);
        font3x5.print(diceAttack);

        myHero.setHitPoints(myHero.getHitPoints() - diceAttack);
        gameState = GameState::Battle_PlayerDecides;
        delayLength = FIGHT_DELAY;
        
      }
      #endif

      #ifndef USE_DICE_ANIMATIONS
      diceAttack = random(0, ENEMY_MAX_ATTACK);
      font3x5.print(F("YOU TAKE\n"));
      font3x5.print(diceAttack);
      font3x5.print(F(" DAMAGE!"));
      font3x5.setCursor(33, 26);
      font3x5.print(diceAttack);
      myHero.setHitPoints(myHero.getHitPoints() - diceAttack);
      gameState = GameState::Battle_PlayerDecides;
      delayLength = FIGHT_DELAY;
      #endif

      break;

    case GameState::Battle_EnemyDies:
      arduboy.drawCompressed(18, 12, enemy_defeated_Mask, BLACK);
      arduboy.drawCompressed(18, 12, enemy_defeated, WHITE);
      gameState = GameState::Move;
      delayLength = FIGHT_DELAY;
      break;

    case GameState::Battle_PlayerDecides:
      {
        bool fightButtons[4] = { true, false, false, false };

        uint8_t buttons = arduboy.justPressedButtons();
        fightButtons[(uint8_t)FightButtons::Shield] = true;
        fightButtons[(uint8_t)FightButtons::Magic] = (myHero.getMagic() > 0);
        fightButtons[(uint8_t)FightButtons::Potion] = (myHero.getInventoryCount(Inventory::Potion));

        arduboy.drawCompressed(80, 44, fight_actions_1, WHITE);
        if (fightButtons[(uint8_t)FightButtons::Shield])   { arduboy.drawCompressed(91, 44, fight_actions_2, WHITE); }
        if (fightButtons[(uint8_t)FightButtons::Magic])    { arduboy.drawCompressed(102, 44, fight_actions_3, WHITE); }
        if (fightButtons[(uint8_t)FightButtons::Potion])   { arduboy.drawCompressed(113, 44, fight_actions_4, WHITE); }
        Sprites::drawSelfMasked(81 + (((uint8_t)fightButton) * 11), 56, icnSelect, 0);
        
        if ((buttons & LEFT_BUTTON_MASK) && (uint8_t)fightButton > 0) { 
          
          for (uint8_t i = (uint8_t)fightButton - 1; i >= 0; --i) {
            if (fightButtons[i]) { 
              fightButton = (FightButtons)i;
              break;
            }
          }

        }

        if (buttons & RIGHT_BUTTON_MASK) {
          
          for (uint8_t i = (uint8_t)fightButton + 1; i < (uint8_t)FightButtons::Count; ++i) {
            if (fightButtons[i]) { 
              fightButton = (FightButtons)i;
              break;
            }
          }
          
        }

        if (buttons & BACK_BUTTON_MASK)  {
          savedState = gameState;
          gameState = GameState::InventorySelect;
        }
          
        if (buttons & SELECT_BUTTON_MASK)  {
          
          #ifdef USE_DICE_ANIMATIONS
          diceDelay = DICE_DELAY_START;
          #endif

          switch (fightButton) {

            case (FightButtons::Attack):
              gameState = GameState::Battle_PlayerAttacks;
              break;

            case (FightButtons::Shield):
              gameState = GameState::Battle_PlayerDefends;
              break;

            case (FightButtons::Magic):
              gameState = GameState::Battle_PlayerCastsSpell;
              fightButton = FightButtons::Attack;
              break;

            case (FightButtons::Potion):
              myHero.setHitPoints(myHero.getHitPoints() + INVENTORY_POTION_HP_INC);
              // myHero.decInventoryCount(Inventory::Potion);
              myHero.setInventory(myHero.getSlotNumber(Inventory::Potion), Inventory::None);
              fightButton = FightButtons::Attack;
              break;
          
          }
        
        }
        
      }
      break;

    case GameState::Battle_PlayerAttacks:
    
      arduboy.drawCompressed(19, 19, fight_hero_strike_Mask, BLACK);
      arduboy.drawCompressed(19, 19, fight_hero_strike, WHITE);

      #ifdef USE_DICE_ANIMATIONS
      if (diceDelay >= DICE_DELAY_START && diceDelay < DICE_DELAY_END) {

        rollDice(32, 24);

      }
      else {

        diceDoOnce(HUMAN_MAX_ATTACK, 1);

        font3x5.print(F("YOU DEAL\n"));
        font3x5.print(diceAttack);
        font3x5.print(F(" DAMAGE!\n"));
        font3x5.setCursor(32, 24);
        font3x5.print(diceAttack);
        enemies[attackingEnemyIdx].decHitPoints(diceAttack);
        
        if (enemies[attackingEnemyIdx].getHitPoints() > 0) {
          gameState = GameState::Battle_EnemyAttacks_Init;
        }
        else {
          gameState = GameState::Battle_EnemyDies;
        }

        delayLength = FIGHT_DELAY;

      }
      #endif

      #ifndef USE_DICE_ANIMATIONS
      diceAttack = random(1, HUMAN_MAX_ATTACK);
      font3x5.print(F("YOU DEAL\n"));
      font3x5.print(diceAttack);
      font3x5.print(F(" DAMAGE!\n"));
      font3x5.setCursor(32, 24);
      font3x5.print(diceAttack);
      enemies[attackingEnemyIdx].decHitPoints(diceAttack);

      if (enemies[attackingEnemyIdx].getHitPoints() > 0) {
        gameState = GameState::Battle_EnemyAttacks_Init;
      }
      else {
        gameState = GameState::Battle_EnemyDies;
      }

      delayLength = FIGHT_DELAY;
      #endif
      
      break; 

    case GameState::Battle_PlayerDefends:
    
      arduboy.drawCompressed(12, 15, fight_hero_shield_Mask, BLACK);
      arduboy.drawCompressed(12, 15, fight_hero_shield, WHITE);

      #ifdef USE_DICE_ANIMATIONS   
      if (diceDelay >= DICE_DELAY_START && diceDelay < DICE_DELAY_END) {

        rollDice(17, 35);

      }
      else {

        diceDoOnce(HUMAN_MAX_ATTACK, 1);

        font3x5.print(F("SAVE "));
        font3x5.print(diceAttack);
        font3x5.print(F(" HP\n"));
        font3x5.print(F("DEAL 1 DMG\n"));
        font3x5.setCursor(17, 35);
        font3x5.print(diceAttack);

        myHero.setHitPoints(myHero.getHitPoints() + diceAttack);
        enemies[attackingEnemyIdx].decHitPoints(1);
        
        if (enemies[attackingEnemyIdx].getHitPoints() > 0) {
          gameState = GameState::Battle_EnemyAttacks_Init;
        }
        else {
          gameState = GameState::Battle_EnemyDies;
        }

        delayLength = FIGHT_DELAY;

      }
      #endif

      #ifdef USE_DICE_ANIMATIONS   
      diceAttack = random(1, HUMAN_MAX_ATTACK);      
      font3x5.print(F("SAVE "));
      font3x5.print(diceAttack);
      font3x5.print(F(" HP\n"));
      font3x5.print(F("DEAL 1 DMG\n"));
      font3x5.setCursor(17, 35);
      font3x5.print(diceAttack);

      myHero.setHitPoints(myHero.getHitPoints() + diceAttack);
      enemies[attackingEnemyIdx].decHitPoints(1);
      
      if (enemies[attackingEnemyIdx].getHitPoints() > 0) {
        gameState = GameState::Battle_EnemyAttacks_Init;
      }
      else {
        gameState = GameState::Battle_EnemyDies;
      }

      delayLength = FIGHT_DELAY;
      #endif
      
      break;   

    case GameState::Battle_PlayerCastsSpell:
    
      arduboy.drawCompressed(12, 15, fight_hero_spell_Mask, BLACK);
      arduboy.drawCompressed(12, 15, fight_hero_spell, WHITE);

      enemies[attackingEnemyIdx].decHitPoints(diceAttack);
//    myHero.decInventoryCount(Inventory::Scroll);
      myHero.setInventory(myHero.getSlotNumber(Inventory::Scroll), Inventory::None);

      if (enemies[attackingEnemyIdx].getHitPoints() > 0) {
        gameState = GameState::Battle_EnemyAttacks_Init;
      }
      else {
        gameState = GameState::Battle_EnemyDies;
      }

      delayLength = FIGHT_DELAY;
      break;

    default: break;
      
  }

  drawEnemyHitPointsBar(enemies[attackingEnemyIdx].getHitPoints());
  return delayLength;

}

#ifdef USE_DICE_ANIMATIONS
void rollDice(uint8_t x, uint8_t y) {

  font3x5.setCursor(x, y);
  font3x5.print(diceAttack);

  if (diceDelay < 1) {

    diceAttack = random(0, 4);
    diceDelay++;

    #ifdef USE_SOUNDS
    sound.tone(NOTE_A1, 20);
    #endif
    
  }
  else {  

    if (arduboy.everyXFrames(diceDelay)) {

      #ifdef USE_SOUNDS
      sound.tone(NOTE_A1, 20);
      #endif
      
      diceAttack = random(0, 4);
      diceDelay = diceDelay * 2;

    }

  }

}
#endif


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
  
  if (buttons & UP_BUTTON_MASK)       { playerMoved = PlayerController::move(&myHero, enemies, &myLevel, Button::Up); }
  if (buttons & DOWN_BUTTON_MASK)     { PlayerController::move(&myHero, enemies, &myLevel, Button::Down); }
  if (buttons & LEFT_BUTTON_MASK)     { PlayerController::move(&myHero, enemies, &myLevel, Button::Left); }
  if (buttons & RIGHT_BUTTON_MASK)    { PlayerController::move(&myHero, enemies, &myLevel, Button::Right); }
  
  if (buttons & BACK_BUTTON_MASK)     { 
  
    savedState = gameState;
    gameState = GameState::InventorySelect; 
  
  }
  

  // If the player moved then so should the enemies ..

  if (playerMoved) {

    if (myLevel.getMapElement(myHero.getX(), myHero.getY()) == MapElement::UnlockedDoor) { 
    
      ++level;

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
      
      if (enemies[i].getEnabled()) {

        EnemyController::move(&enemies[i], enemies, &myHero, &myLevel);

      }

    }  

  }


  // If the player is 'touching' an enemy then enter battle mode ..

  for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {
    
    if (enemies[i].getEnabled()) {

      const int16_t deltaX = enemies[i].getX() - myHero.getX();
      const int16_t deltaY = enemies[i].getY() - myHero.getY();
      const uint16_t absDeltaX = absT(deltaX);
      const uint16_t absDeltaY = absT(deltaY);

      if ((absDeltaX <= 1) && (absDeltaY <= 1))  {


        // Rotate the player if the enemy is attacking from the side ..
        
        if (deltaX < 0) { myHero.setDirection(Direction::West); }
        else if (deltaX > 0) { myHero.setDirection(Direction::East); }
        else if (deltaY < 0) { myHero.setDirection(Direction::North); }
        else if (deltaY > 0) { myHero.setDirection(Direction::South); }

        attackingEnemyIdx = i;
        gameState = GameState::Battle_EnemyAttacks_Init;
        break;

      } 

    }

  }  

}


/* -----------------------------------------------------------------------------------------------------------------------------
 *  Initialise Level.  
 *  
 *  Initialise the player, level and enemy details based on the current level.
 *  
 * -----------------------------------------------------------------------------------------------------------------------------
 */
void initialiseLevel(Player *myHero, Level *myLevel, const uint8_t *level) {

  uint8_t idx = 0;

  
  // Read level title ..

  memcpy_P(myLevel->getTitleLine1(), &level[idx], sizeof(char) * 11);
  idx += 11;
  memcpy_P(myLevel->getTitleLine2(), &level[idx], sizeof(char) * 11);
  idx += 11;
              
  myHero->setX(pgm_read_byte(&level[idx++]));
  myHero->setY(pgm_read_byte(&level[idx++]));
  myHero->setDirection((Direction)pgm_read_byte(&level[idx++]));

  myLevel->setWidth(pgm_read_byte(&level[idx++]));
  myLevel->setHeight(pgm_read_byte(&level[idx++]));


  // Create all enemies ..
  
  idx = loadEnemies(level, enemies, idx, NUMBER_OF_ENEMIES);
  

  // Create all items and doors ..
  
  idx = loadItems(level, items, idx, NUMBER_OF_ITEMS);
  idx = loadItems(level, doors, idx, NUMBER_OF_DOORS);
  
  myLevel->setLevel(level);
  myLevel->setDoors(doors);
  myLevel->setStartPos(idx);

  gameState = GameState::Move;

}


/* -----------------------------------------------------------------------------------------------------------------------------
 *  Initialise Level - load items.  
 *  
 *  Initialise the item and door items from progmem using the 'idx' variable as an index reference.  
 * 
 *  Returns the 'idx' index reference so the next process can continue reading from that location onwards.
 *  
 * -----------------------------------------------------------------------------------------------------------------------------
 */
uint8_t loadItems(const uint8_t *level, Item * items, uint8_t idx, uint8_t max) {

  uint8_t numberOfItems = pgm_read_byte(&level[idx++]);

  for (uint8_t i = 0; i < max; ++i) {  

    items[i].setEnabled(false);

    if(i < numberOfItems) {
      items[i].setItemType((ItemType)pgm_read_byte(&level[idx++]));
      items[i].setX(pgm_read_byte(&level[idx++]));
      items[i].setY(pgm_read_byte(&level[idx++]));
      items[i].setEnabled(true);
    }

  }  
  
  return idx;
}


/* -----------------------------------------------------------------------------------------------------------------------------
 *  Initialise Level - load enemies.  
 *  
 *  Initialise the enemies items from progmem using the 'idx' variable as an index reference.  
 * 
 *  Returns the 'idx' index reference so the next process can continue reading from that location onwards.
 *  
 * -----------------------------------------------------------------------------------------------------------------------------
 */
uint8_t loadEnemies(const uint8_t * level, Enemy * enemies, uint8_t idx, uint8_t max) {

  uint8_t numberOfEnemies = pgm_read_byte(&level[idx++]);
  
  for (uint8_t i = 0; i < max; ++i) {  

    enemies[i].setEnabled(i < numberOfEnemies);
    if(enemies[i].getEnabled()) {	
      enemies[i].setHitPoints(ENEMY_MAX_HITPOINTS);
      enemies[i].setEnemyType((EnemyType)pgm_read_byte(&level[idx++]));
      enemies[i].setX(pgm_read_byte(&level[idx++]));
      enemies[i].setY(pgm_read_byte(&level[idx++]));
    }
    
  }
  
  return idx;

}


/* -----------------------------------------------------------------------------------------------------------------------------
 *  Next Level Handler
 * 
 *  Display the 'Level Up' graphic and initialise the next level ready for play. 
 * 
 * -----------------------------------------------------------------------------------------------------------------------------
 */
void displayNextLevel() {
  
  arduboy.drawCompressed(0, 0, frames_outside, WHITE);
  arduboy.drawCompressed(66, 4, frames_inside, WHITE);

  drawMapAndStatistics(&myHero, &myLevel);
  drawDirectionIndicator(&myHero);
  drawLevelDescription(&myLevel);

  arduboy.drawCompressed(23, 5, levelUp, WHITE);

  font3x5.setCursor(20, 40);
  font3x5.print(F("LEVEL "));
  font3x5.print(level);
  font3x5.setCursor(18, 47);
  font3x5.print(F("YOU GAIN"));
  font3x5.setCursor(26, 54);
  font3x5.print(F("1 DF"));
  
  uint8_t buttons = arduboy.justPressedButtons();
  
  if (buttons & SELECT_BUTTON_MASK) { 
  
    if (level <= MAX_LEVEL_COUNT) { level = 0; }

    gameState = GameState::Move; 
    initialiseLevel(&myHero, &myLevel, levels[level]);
  
  }

}


/* -----------------------------------------------------------------------------------------------------------------------------
 *  End of Game Handler
 * -----------------------------------------------------------------------------------------------------------------------------
 */
void displayEndOfGame() {
  
  arduboy.drawCompressed(0, 0, frames_outside, WHITE);
  arduboy.drawCompressed(43, 4, victory, WHITE);
  font3x5.setCursor(9, 8);
  font3x5.print(F("WELL DONE!\nTHE RICHES\nUNDER THE\nMOUNTAIN\nARE YOURS\nNOW!"));
  level = 0;

  uint8_t buttons = arduboy.justPressedButtons();
  
  if (buttons & SELECT_BUTTON_MASK) { 
  
    if (level <= MAX_LEVEL_COUNT) { level = 0; }

    gameState = GameState::Splash; 
  
  }

}