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

    int8_t deltaX = 0;
    int8_t deltaY = 0;
    
    switch (player->getDirection()) {
      
      case Direction::North:      deltaY = -1;    break;
      case Direction::East:       deltaX = 1;     break;
      case Direction::South:      deltaY = 1;     break;
      case Direction::West:       deltaX = -1;    break;
      
    }

    if (PlayerController::moveLegal(allEnemies, player, level, player->getX() + deltaX, player->getY() + deltaY))    { 
    
      player->setX(player->getX() + deltaX); 
      player->setY(player->getY() + deltaY); 
      movement = true; 
    
    };
    
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
