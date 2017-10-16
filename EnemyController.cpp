#include "EnemyController.h"
#include <Arduboy2.h>
#include "Enums.h"
#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include "Utils.h"


EnemyController::EnemyController() {}


void EnemyController::move(Enemy *thisEnemy, Enemy *allEnemies, Player *player, Level *level) {
    
  if (!EnemyController::moveTowardsPlayer(thisEnemy, allEnemies, player, level)) {

    while (true) {

      if (EnemyController::moveToVacantSquare(thisEnemy, allEnemies, player, level, (Direction)random((uint8_t)Direction::North, (uint8_t)Direction::Count))) { break; }

    }

  }

}
    
bool EnemyController::moveTowardsPlayer(Enemy *thisEnemy, Enemy *allEnemies, Player *player, Level *level) {


  // If the enemy is only one cell away from the player, do not move ..

  if ((absT(player->getX() - thisEnemy->getX()) == 1) ^ (absT(player->getY() - thisEnemy->getY()) == 1))                                   { return true; } 


  // Otherwise attempt to move close to the player ..

  else if (player->getY() < thisEnemy->getY() && EnemyController::moveLegal(allEnemies, player, level, thisEnemy->getX(), thisEnemy->getY() - 1))          { thisEnemy->setY(thisEnemy->getY() - 1); } 
  else if (player->getY() > thisEnemy->getY() && EnemyController::moveLegal(allEnemies, player, level, thisEnemy->getX(), thisEnemy->getY() + 1))          { thisEnemy->setY(thisEnemy->getY() + 1); } 
  else if (player->getX() > thisEnemy->getX() && EnemyController::moveLegal(allEnemies, player, level, thisEnemy->getX() + 1, thisEnemy->getY()))          { thisEnemy->setX(thisEnemy->getX() + 1); }  
  else if (player->getX() < thisEnemy->getX() && EnemyController::moveLegal(allEnemies, player, level, thisEnemy->getX() - 1, thisEnemy->getY()))          { thisEnemy->setX(thisEnemy->getX() - 1); } 
  else {

    return false;

  }

  return true;

}
  
bool EnemyController::moveToVacantSquare(Enemy *thisEnemy, Enemy *allEnemies, Player *player, Level *level, Direction playerDirection) {
  
  bool moved = true;

  if (playerDirection == Direction::North && EnemyController::moveLegal(allEnemies, player, level, thisEnemy->getX(), thisEnemy->getY() - 1))              { thisEnemy->setY(thisEnemy->getY() - 1); } 
  else if (playerDirection == Direction::South && EnemyController::moveLegal(allEnemies, player, level, thisEnemy->getX(), thisEnemy->getY() + 1))         { thisEnemy->setY(thisEnemy->getY() + 1); } 
  else if (playerDirection == Direction::East && EnemyController::moveLegal(allEnemies, player, level, thisEnemy->getX() + 1, thisEnemy->getY()))          { thisEnemy->setX(thisEnemy->getX() + 1); } 
  else if (playerDirection == Direction::West && EnemyController::moveLegal(allEnemies, player, level, thisEnemy->getX() - 1, thisEnemy->getY()))          { thisEnemy->setX(thisEnemy->getX() - 1); } 
  else { moved = false; }

  return moved;
  
}
    
bool EnemyController::moveLegal(Enemy *allEnemies, Player *player, Level *level, int x, int y) {
  
  if ((level->getMapElement(x, y) == MapElement::Floor) ||
      (level->getMapElement(x, y) == MapElement::UnlockedDoor)) {
      

    // Is another enemy in the same position ?

    for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {
      
      if (allEnemies[i].getEnabled()) {

        if (allEnemies[i].getX() == x && allEnemies[i].getY() == y)   { return false; }

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