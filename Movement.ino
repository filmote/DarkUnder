    
bool movePlayer(Player *player, Enemy *enemies, Level *level, Button button) {

  bool movement = false;

  if (button == Button::Up) {

    switch (player->getDirection()) {

      case Direction::North:
        if (moveLegalPlayer(enemies, level, player->getX(), player->getY() - 1))    { player->setY(player->getY() - 1); movement = true; };   
        break;
      
      case Direction::East:
        if (moveLegalPlayer(enemies, level, player->getX() + 1, player->getY()))   { player->setX(player->getX() + 1); movement = true; };
        break;
                            
      case Direction::South:
        if (moveLegalPlayer(enemies, level, player->getX(), player->getY() + 1))   { player->setY(player->getY() + 1); movement = true; };
        break;
      
      case Direction::West:
        if (moveLegalPlayer(enemies, level, player->getX() - 1, player->getY()))   { player->setX(player->getX() - 1); movement = true; };
        break;
      
    }

  }
  else {

    Direction curDirection = player->getDirection();

    switch (button) {

      case Button::Down:   ++curDirection; ++curDirection;      break;
      case Button::Left:   --curDirection;                      break;
      case Button::Right:  ++curDirection;                      break;
      
    }

    player->setDirection(curDirection);

  }

  return movement;

}

bool moveLegalPlayer(Enemy *enemies, Level *level, int x, int y) {
  
  if (level->getMapElement(x, y) == MapElement::Floor) {


    // Is another enemy in the same position ?

    for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {
      
      if (enemies[i].getEnabled()) {

        if (enemies[i].getX() == x && enemies[i].getY() == y) { return false; }

      }

    }  

    return true;

  }
  else {

    return false;

  }
  
}

void moveEnemy(Enemy *enemy, Enemy *enemies, Player *player, Level *level) {
  
  if (!moveEnemyTowardsPlayer(enemy, enemies, player, level)) {

    while (true) {

      if (moveEnemyToVacantSquare(enemy, player, level, (Direction)random((uint8_t)Direction::North, (uint8_t)Direction::Count))) { break; }

    }

  }

}
  
boolean moveEnemyTowardsPlayer(Enemy *enemy, Enemy *enemies, Player *player, Level *level) {

  if (player->getY() < enemy->getY() && moveLegalEnemy(enemies, player, level, enemy->getX(), enemy->getY() - 1))                { enemy->setY(enemy->getY() - 1); } 
  else if (player->getY() > enemy->getY() && moveLegalEnemy(enemies, player, level, enemy->getX(), enemy->getY() + 1))           { enemy->setY(enemy->getY() + 1); } 
  else if (player->getX() > enemy->getX() && moveLegalEnemy(enemies, player, level, enemy->getX() + 1, enemy->getY()))           { enemy->setX(enemy->getX() + 1); }  
  else if (player->getX() < enemy->getX() && moveLegalEnemy(enemies, player, level, enemy->getX() - 1, enemy->getY()))           { enemy->setX(enemy->getX() - 1); } 
  else {

    return false;

  }

  return true;

}

boolean moveEnemyToVacantSquare(Enemy *enemy, Player *player, Level *level, Direction playerDirection) {

  bool moved = true;

  if (playerDirection == Direction::North && moveLegalEnemy(enemies, player, level, enemy->getX(), enemy->getY() - 1))         { enemy->setY(enemy->getY() - 1); } 
  else if (playerDirection == Direction::South && moveLegalEnemy(enemies, player, level, enemy->getX(), enemy->getY() + 1))    { enemy->setY(enemy->getY() + 1); } 
  else if (playerDirection == Direction::East && moveLegalEnemy(enemies, player, level, enemy->getX() + 1, enemy->getY()))     { enemy->setX(enemy->getX() + 1); } 
  else if (playerDirection == Direction::West && moveLegalEnemy(enemies, player, level, enemy->getX() - 1, enemy->getY()))     { enemy->setX(enemy->getX() - 1); } 
  else { moved = false; }

  return moved;

}
  
boolean moveLegalEnemy(Enemy *enemies, Player *player, Level *level, int x, int y) {

  if (level->getMapElement(x, y) == MapElement::Floor) {


    // Is another enemy in the same position ?

    for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {
      
      if (enemies[i].getEnabled()) {

        if (enemies[i].getX() == x && enemies[i].getY() == y)   { return false; }

      }

    }  

    // Position is already occupied by the player ?

    if (player->getX() == x && player->getY() == y)             { return false; }

    return true;

  }
  else {
    
    return false;

  }

}  