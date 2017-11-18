#include <Arduboy2.h>

/* -----------------------------------------------------------------------------------------------------------------------------
 *  Initialise Game Play.  
 * -----------------------------------------------------------------------------------------------------------------------------
 */
void initialiseGame() {

  myHero.setHitPoints(15);
  myHero.setDefence(2);
  myHero.setAttackPower(2);
  
  myHero.setInventory(0, ItemType::None);
  myHero.setInventory(1, ItemType::None);
  myHero.setInventory(2, ItemType::None);
  myHero.setInventory(3, ItemType::Shield);
  myHero.setInventory(4, ItemType::Sword);

  playerLevel = 1;
  level = 0;

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

    if (i < numberOfItems) {
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

    if (enemies[i].getEnabled()) {	

      EnemyType enemyType = (EnemyType)pgm_read_byte(&level[idx++]);

      enemies[i].setEnemyType(enemyType);
      enemies[i].setX(pgm_read_byte(&level[idx++]));
      enemies[i].setY(pgm_read_byte(&level[idx++]));

      uint8_t hp = 0;
      uint8_t ap = 0;
      uint8_t xp = 0;
      boolean moving = false;

      if (enemyType == EnemyType::Beholder)       { hp = ENEMY_BEHOLDER_HP; ap = ENEMY_BEHOLDER_AP; xp = ENEMY_BEHOLDER_XP; moving = ENEMY_BEHOLDER_MV;  }
      else if (enemyType == EnemyType::Skeleton)  { hp = ENEMY_SKELETON_HP; ap = ENEMY_SKELETON_AP; xp = ENEMY_SKELETON_XP; moving = ENEMY_SKELETON_MV;  }
      else if (enemyType == EnemyType::Displacer) { hp = ENEMY_DISPLACER_HP; ap = ENEMY_DISPLACER_AP; xp = ENEMY_DISPLACER_XP; moving = ENEMY_DISPLACER_MV;  }
      else if (enemyType == EnemyType::Wraith)    { hp = ENEMY_WRAITH_HP; ap = ENEMY_WRAITH_AP; xp = ENEMY_WRAITH_XP; moving = ENEMY_WRAITH_MV;  }
      else if (enemyType == EnemyType::Dragon)    { hp = ENEMY_DRAGON_HP; ap = ENEMY_DRAGON_AP; xp = ENEMY_DRAGON_XP; moving = ENEMY_DRAGON_MV;  }
      else if (enemyType == EnemyType::Rat)       { hp = ENEMY_RAT_HP; ap = ENEMY_RAT_AP; xp = ENEMY_RAT_XP; moving = ENEMY_RAT_MV; }
      else if (enemyType == EnemyType::Slime)     { hp = ENEMY_SLIME_HP; ap = ENEMY_SLIME_AP; xp = ENEMY_SLIME_XP; moving = ENEMY_SLIME_MV; }

      enemies[i].setHitPoints(hp);
      enemies[i].setHitPointsMax(hp);
      enemies[i].setAttackPower(ap);
      enemies[i].setExperiencePoints(xp);
      enemies[i].setMoving(moving);

    }
   
  }

 return idx;

}

#ifdef SAVE_GAME

#define EEPROM_START            EEPROM_STORAGE_SPACE_START 
#define EEPROM_START_C1         EEPROM_START
#define EEPROM_START_C2         EEPROM_START + 1
#define EEPROM_LEVEL_NO         EEPROM_START + 2
#define EEPROM_PLAYER_X         EEPROM_START + 3
#define EEPROM_PLAYER_Y         EEPROM_START + 4
#define EEPROM_PLAYER_ROT       EEPROM_START + 5
#define EEPROM_PLAYER_HP        EEPROM_START + 6
#define EEPROM_PLAYER_AP        EEPROM_START + 7
#define EEPROM_PLAYER_DF        EEPROM_START + 8
#define EEPROM_PLAYER_XP        EEPROM_START + 9
#define EEPROM_PLAYER_LEVEL     EEPROM_START + 10
#define EEPROM_PLAYER_INV_0     EEPROM_START + 11
#define EEPROM_PLAYER_INV_1     EEPROM_START + 12
#define EEPROM_PLAYER_INV_2     EEPROM_START + 13


/* ----------------------------------------------------------------------------
 *   Is the EEPROM initialised? 
 *   
 *   Looks for the characters 'D' and 'U' in the first two bytes of the EEPROM
 *   memory range starting from byte EEPROM_STORAGE_SPACE_START.  If not found,
 *   it resets the settings ..
 */
bool initEEPROM() {

  byte c1 = EEPROM.read(EEPROM_START_C1);
  byte c2 = EEPROM.read(EEPROM_START_C2);

  if (c1 != 68 || c2 != 85) { // RU 68 85
  
    EEPROM.update(EEPROM_START_C1, 68);
    EEPROM.update(EEPROM_START_C2, 85);
    EEPROM.update(EEPROM_LEVEL_NO, 255);
      
  }

}

uint8_t getLevel() {

  return EEPROM.read(EEPROM_LEVEL_NO);

}

void saveGame() {

  EEPROM.update(EEPROM_LEVEL_NO, level);
  EEPROM.update(EEPROM_PLAYER_X, myHero.getX());
  EEPROM.update(EEPROM_PLAYER_Y, myHero.getY());
  EEPROM.update(EEPROM_PLAYER_ROT, (uint8_t)myHero.getDirection());

  EEPROM.update(EEPROM_PLAYER_HP, myHero.getHitPoints());
  EEPROM.update(EEPROM_PLAYER_AP, myHero.getAttackPower());
  EEPROM.update(EEPROM_PLAYER_DF, myHero.getDefence());
  EEPROM.update(EEPROM_PLAYER_XP, myHero.getExperiencePoints());
  EEPROM.update(EEPROM_PLAYER_LEVEL, playerLevel);
  
  EEPROM.update(EEPROM_PLAYER_INV_0, (uint8_t)myHero.getInventory(0));
  EEPROM.update(EEPROM_PLAYER_INV_1, (uint8_t)myHero.getInventory(1));
  EEPROM.update(EEPROM_PLAYER_INV_2, (uint8_t)myHero.getInventory(2));

  uint16_t loc = EEPROM_PLAYER_INV_2 + 1;

  for (int i = 0; i < NUMBER_OF_ENEMIES; i++) {
    EEPROM.update(loc, (uint8_t)enemies[i].getEnemyType());
    EEPROM.update(loc + 1, enemies[i].getX());
    EEPROM.update(loc + 2, enemies[i].getY());
    EEPROM.update(loc + 3, (enemies[i].getEnabled() ? 1 : 0));
    loc = loc + 4;
  }

  for (int i = 0; i < NUMBER_OF_ITEMS; i++) {
    EEPROM.update(loc, (uint8_t)items[i].getItemType());
    EEPROM.update(loc + 1, items[i].getX());
    EEPROM.update(loc + 2, items[i].getY());
    EEPROM.update(loc + 3, (items[i].getEnabled() ? 1 : 0));
    loc = loc + 4;
  }

}


void restoreGame() {

  level = EEPROM.read(EEPROM_LEVEL_NO);

  initialiseLevel(&myHero, &myLevel, levels[level]);

  myHero.setX(EEPROM.read(EEPROM_PLAYER_X));
  myHero.setY(EEPROM.read(EEPROM_PLAYER_Y));
  myHero.setDirection((Direction)EEPROM.read(EEPROM_PLAYER_ROT));

  myHero.setHitPoints(EEPROM.read(EEPROM_PLAYER_HP));
  myHero.setAttackPower(EEPROM.read(EEPROM_PLAYER_AP));
  myHero.setDefence(EEPROM.read(EEPROM_PLAYER_DF));
  myHero.setExperiencePoints(EEPROM.read(EEPROM_PLAYER_XP));
  playerLevel = EEPROM.read(EEPROM_PLAYER_LEVEL);
  
  myHero.setInventory(0, (ItemType)EEPROM.read(EEPROM_PLAYER_INV_0));
  myHero.setInventory(1, (ItemType)EEPROM.read(EEPROM_PLAYER_INV_1));
  myHero.setInventory(2, (ItemType)EEPROM.read(EEPROM_PLAYER_INV_2));

  uint16_t loc = EEPROM_PLAYER_INV_2 + 1;

  for (int i = 0; i < NUMBER_OF_ENEMIES; i++) {
    enemies[i].setEnemyType((EnemyType)EEPROM.read(loc));
    enemies[i].setX(EEPROM.read(loc + 1));
    enemies[i].setY(EEPROM.read(loc + 2));
    enemies[i].setEnabled(EEPROM.read(loc + 3) == 1);
    loc = loc + 4;
  }

  for (int i = 0; i < NUMBER_OF_ITEMS; i++) {
    items[i].setItemType((ItemType)EEPROM.read(loc));
    items[i].setX(EEPROM.read(loc + 1));
    items[i].setY(EEPROM.read(loc + 2));
    items[i].setEnabled(EEPROM.read(loc + 3) == 1);
    loc = loc + 4;
  }

}
#endif