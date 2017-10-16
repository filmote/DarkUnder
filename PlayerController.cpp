#include "PlayerController.h"
#include <Arduboy2.h>
#include "Enums.h"
#include "Level.h"
#include "Player.h"
#include "Enemy.h"


PlayerController::PlayerController() : BaseController() {}
    
bool PlayerController::move(Player *player, Enemy *allEnemies, Level *level, Button button) {

  bool movement = false;

  if (button == Button::Up) {

    switch (player->getDirection()) {

      case Direction::North:
        if (PlayerController::moveLegal(allEnemies, nullptr, level, player->getX(), player->getY() - 1))    { player->setY(player->getY() - 1); movement = true; };   
        break;
      
      case Direction::East:
        if (PlayerController::moveLegal(allEnemies, nullptr, level, player->getX() + 1, player->getY()))   { player->setX(player->getX() + 1); movement = true; };
        break;
                            
      case Direction::South:
        if (PlayerController::moveLegal(allEnemies, nullptr, level, player->getX(), player->getY() + 1))   { player->setY(player->getY() + 1); movement = true; };
        break;
      
      case Direction::West:
        if (PlayerController::moveLegal(allEnemies, nullptr, level, player->getX() - 1, player->getY()))   { player->setX(player->getX() - 1); movement = true; };
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
