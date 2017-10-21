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
bool item_no_slots = false;

GameState gameState = GameState::Splash; 
GameState savedState = GameState::Splash; 

Level myLevel;
Player myHero;

SplashButtons splashStatus = SplashButtons::Play;
FightButtons fightButton = FightButtons::Attack;


uint8_t level = 0;      // Current Level
int16_t diceDelay = DICE_NO_ACTION;
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
  myHero.setInventory(1, Inventory::Potion);
  myHero.setInventory(2, Inventory::Scroll);
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
      itemLoop();
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
 * -----------------------------------------------------------------------------------------------------------------------------
 */
void itemLoop() {

  drawPlayerVision(&myHero, &myLevel);
  drawMapAndStatistics(&myHero, &myLevel);

  if (item_action == INVENTORY_ACTION_USE)     arduboy.drawCompressed(71, 56, inv_select, WHITE);
  if (item_action == INVENTORY_ACTION_DELETE)  arduboy.drawCompressed(83, 56, inv_select, WHITE);

  arduboy.drawCompressed(70, 45, inv_hand, WHITE);
  arduboy.drawCompressed(81, 45, inv_trash, WHITE);

  if (item_no_slots) {
  }

  uint8_t buttons = arduboy.justPressedButtons();
  
  if ((buttons & LEFT_BUTTON_MASK) && item_action > ITEM_ACTION_USE)         { --item_action; item_no_slots = false; }
  if ((buttons & RIGHT_BUTTON_MASK) && item_action < ITEM_ACTION_DELETE)     { ++item_action; item_no_slots = false; }

  if (buttons & BACK_BUTTON) {
    savedState = gameState;
    gameState = GameState::InventorySelect;
  }
 
  if (buttons & SELECT_BUTTON) {

    if (item_action == ITEM_ACTION_USE) {

      switch (items[savedItem].getItemType()) {

        case ItemType::Key:
        case ItemType::HPPotion:
        case ItemType::Scroll:

          if (myHero.getConsumableSlot() >= 0) {

            myHero.setInventory(myHero.getConsumableSlot(), (Inventory)((uint8_t)items[savedItem].getItemType()));
            items[savedItem].setEnabled(false);
            item_no_slots = false;

          }
          else {
          
            item_no_slots = true;
    font3x5.setCursor(95, 44);
    font3x5.print(F("NO INV\nSLOTS!"));

          }
        default: break;

      }

    }

    if (item_action == ITEM_ACTION_DELETE)  { 
      
      gameState = GameState::ItemIgnore;
      item_no_slots = false;
    
    }

  }

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
 
  arduboy.drawCompressed(0, 0, frames, WHITE);  
  #ifdef INV_STYLE_BONW
  arduboy.drawCompressed(4, 4, inv_background, WHITE);
  #endif
  #ifdef INV_STYLE_WONB
  Sprites::drawOverwrite(8, 32, inv_lhs_icons, 0);
  #endif
  
  drawMapAndStatistics(&myHero, &myLevel);

  for (uint8_t i = 0; i < 5; ++i) {

    if (myHero.getInventory(i) != Inventory::None) {

      #ifdef INV_STYLE_BONW
      arduboy.fillRect(inventory_Coords[i].x, inventory_Coords[i].y, 14, 16, BLACK);
      arduboy.drawCompressed(inventory_Coords[i].x, inventory_Coords[i].y, inventory_images[(uint8_t)myHero.getInventory(i)], WHITE);
      #endif
      #ifdef INV_STYLE_WONB
      arduboy.drawRect(inventory_Coords[i].x - 1, inventory_Coords[i].y - 1, 16, 16);
      arduboy.drawCompressed(inventory_Coords[i].x, inventory_Coords[i].y, inventory_images[(uint8_t)myHero.getInventory(i)], WHITE);
      #endif
      
    }

  }

  #ifdef INV_STYLE_BONW
  arduboy.drawCompressed(inventory_Coords[inventory_selection].x + 3, inventory_Coords[inventory_selection].y + 11, inv_select, BLACK);
  #endif
  #ifdef INV_STYLE_WONB
  arduboy.drawCompressed(inventory_Coords[inventory_selection].x + 3, inventory_Coords[inventory_selection].y + 11, inv_select, WHITE);
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
            default: break;
          }

        }

        if (inventory_action == INVENTORY_ACTION_DELETE) {

          myHero.setInventory(inventory_selection, Inventory::None);
          inventory_action = INVENTORY_ACTION_USE;
          gameState = GameState::InventorySelect;
          item_no_slots = false;

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
void diceDoOnce(uint8_t maxValue, uint8_t offset) {

  if (diceDelay >= DICE_DELAY_END) {  // Do once.

    diceAttack = random(0, maxValue) + offset;
    diceDelay = DICE_NO_ACTION;

  }

}


/* -----------------------------------------------------------------------------------------------------------------------------
 *  Battle Loop  
 *  
 *  GameStates:
 *  
 *  Battle_EnemyAttacks_Init -    Displays the initial '{enemy} attacks !' message and prepares for and enemy attck.
 *  Battle_EnemyAttacks -         Displays the dice animation and inflicts damage to the player.  
 *  Battle_PlayerDecides -        Presents the players battle options including attack, defend, cast a spell ..
 *  Battle_PlayerAttacks -        Throws the dice and inflicts damage on the enemy.
 *  Battle_PlayerDefends -        Inflicts 1 point of damage on the user and randomly gains player hit points.
 *  Battle_EnemyDies -            Handles and end of battel where the enemy dies.
 *  
 * -----------------------------------------------------------------------------------------------------------------------------
 */
uint16_t battleLoop() {

  uint16_t delayLength = 0;

  drawPlayerVision(&myHero, &myLevel);
  drawMapAndStatistics(&myHero, &myLevel);  
  Sprites::drawSelfMasked(DIRECTION_X_OFFSET, DIRECTION_Y_OFFSET, fight_icon, 0);

  font3x5.setCursor(80,44);
  uint8_t buttons = arduboy.justPressedButtons();

  switch (gameState) {

    case GameState::Battle_EnemyAttacks_Init:
      
      font3x5.print(getEnemyName(enemies[attackingEnemyIdx].getEnemyType()));
      font3x5.print(F("\nATTACKS!"));
      
      diceDelay = DICE_DELAY_START;
      gameState = GameState::Battle_EnemyAttacks;
      delayLength = FIGHT_DELAY;
      break;

    case GameState::Battle_EnemyAttacks:
    
      arduboy.drawCompressed(12, 12, fight_scratch_Mask, BLACK);
      arduboy.drawCompressed(12, 12, fight_scratch, WHITE);
    
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
      break;

    case GameState::Battle_EnemyDies:
      arduboy.drawCompressed(18, 12, enemy_defeated_Mask, BLACK);
      arduboy.drawCompressed(18, 12, enemy_defeated, WHITE);
      gameState = GameState::Move;
      delayLength = FIGHT_DELAY;
      break;

    case GameState::Battle_PlayerDecides:

      arduboy.drawCompressed(80, 44, fight_actions, WHITE);
      Sprites::drawSelfMasked(80 + (((uint8_t)fightButton) * 12), 56, icnSelect, 0);

      if ((buttons & LEFT_BUTTON_MASK) && (uint8_t)fightButton > 0)                                 { fightButton = (FightButtons)((uint8_t)fightButton - 1); }
      if ((buttons & RIGHT_BUTTON_MASK) && (uint8_t)fightButton < (uint8_t)FightButtons::Defend)    { fightButton = (FightButtons)((uint8_t)fightButton + 1); }

      if (buttons & BACK_BUTTON_MASK)  {
        savedState = gameState;
        gameState = GameState::InventorySelect;
      }
        
      if (buttons & SELECT_BUTTON_MASK)  {
        
        diceDelay = DICE_DELAY_START; 
        gameState = (fightButton == FightButtons::Attack ? GameState::Battle_PlayerAttacks : GameState::Battle_PlayerDefends); 
      
      }

      break;

    case GameState::Battle_PlayerAttacks:
    
      arduboy.drawCompressed(19, 19, fight_hero_strike_Mask, BLACK);
      arduboy.drawCompressed(19, 19, fight_hero_strike, WHITE);
    
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

      break; 

    case GameState::Battle_PlayerDefends:
    
      arduboy.drawCompressed(12, 15, fight_hero_shield_Mask, BLACK);
      arduboy.drawCompressed(12, 15, fight_hero_shield, WHITE);
    
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

      break;   
    default: break;


    case GameState::Battle_PlayerCastsSpell:
    
      arduboy.drawCompressed(12, 15, fight_hero_spell_Mask, BLACK);
      arduboy.drawCompressed(12, 15, fight_hero_spell, WHITE);

      break;

  }

  drawEnemyHitPointsBar(enemies[attackingEnemyIdx].getHitPoints());
  return delayLength;

}

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

void playLoop() {

  bool playerMoved = false ;

  drawPlayerVision(&myHero, &myLevel);
  drawMapAndStatistics(&myHero, &myLevel);
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

        if (deltaY < 0) { myHero.setDirection(Direction::North); }
        else if (deltaY > 0) { myHero.setDirection(Direction::South); }

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
  
  // Create all items ..
  
  idx = loadItems(level, items, idx, NUMBER_OF_ITEMS);
  idx = loadItems(level, doors, idx, NUMBER_OF_DOORS);
  
  myLevel->setLevel(level);
  myLevel->setMapImages(map_images);  

  #ifdef WALL_STYLE_1
  myLevel->setMapMasks(map_masks);
  #endif

  myLevel->setDoors(doors);
  myLevel->setStartPos(idx);
  gameState = GameState::Move;

}

uint8_t loadItems(const uint8_t *level, Item * items, uint8_t idx, uint8_t max)
{
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

uint8_t loadEnemies(const uint8_t * level, Enemy * enemies, uint8_t idx, uint8_t max)
{
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