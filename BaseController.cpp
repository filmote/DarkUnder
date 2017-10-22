#include "EnemyController.h"
#include <Arduboy2.h>
#include "Enums.h"
#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include "Utils.h"


BaseController::BaseController() {}

bool BaseController::moveLegal(Enemy *allEnemies, Player *player, Level *level, int x, int y) {

  if ((level->getMapElement(x, y) == MapElement::Floor) ||
      (player != nullptr && level->getMapElement(x, y) == MapElement::UnlockedDoor)) {
       

    // Is there a locked door in the way ?

    for (uint8_t i = 0; i < NUMBER_OF_DOORS; ++i) {
      
      Item door = level->getDoors()[i];

      if ((door.getItemType() == ItemType::LockedDoor || door.getItemType() == ItemType::LockedGate) && door.getEnabled() && door.getX() == x && door.getY() == y)     { return false; }
  
    }


    // Is another enemy in the same position ?

    for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {

      if (allEnemies[i].getEnabled()) {

        if (allEnemies[i].getX() == x && allEnemies[i].getY() == y)           { return false; }

      }

    }
    
  
    // Position is already occupied by the player ?

    if (player != nullptr && player->getX() == x && player->getY() == y)      { return false; }

    return true;

  }
  else {

    return false;

  }

} 

 