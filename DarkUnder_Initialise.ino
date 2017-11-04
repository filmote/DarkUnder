#include <Arduboy2.h>

/* -----------------------------------------------------------------------------------------------------------------------------
 *  Initialise Game Play.  
 * -----------------------------------------------------------------------------------------------------------------------------
 */
void initialiseGame() {

  myHero.setHitPoints(10);
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

    if (enemies[i].getEnabled()) {	

      EnemyType enemyType = (EnemyType)pgm_read_byte(&level[idx++]);

      enemies[i].setEnemyType(enemyType);
      enemies[i].setX(pgm_read_byte(&level[idx++]));
      enemies[i].setY(pgm_read_byte(&level[idx++]));

      uint8_t hp = 0;
      uint8_t ap = 0;
      uint8_t xp = 0;
      boolean moving = false;
     
      if (enemyType == EnemyType::Beholder)       { hp = 20; ap = 12; xp = 4; moving = true;  }
      else if (enemyType == EnemyType::Skeleton)  { hp = 10; ap = 8;  xp = 3; moving = true;  }
      else if (enemyType == EnemyType::Displacer) { hp = 10; ap = 5;  xp = 2; moving = true;  }
      else if (enemyType == EnemyType::Wraith)    { hp = 12; ap = 10; xp = 4; moving = true;  }
      else if (enemyType == EnemyType::Dragon)    { hp = 30; ap = 20; xp = 6; moving = true;  }
      else if (enemyType == EnemyType::Rat)       { hp = 5;  ap = 2;  xp = 1; }
      else if (enemyType == EnemyType::Slime)     { hp = 8;  ap = 4;  xp = 6; }

      enemies[i].setHitPoints(hp);
      enemies[i].setHitPointsMax(hp);
      enemies[i].setAttackPower(ap);
      enemies[i].setExperiencePoints(xp);
      enemies[i].setMoving(moving);

    }
   
  }

 return idx;

}