#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <Arduboy2.h>
#include "BaseController.h"
#include "Enums.h"
#include "Level.h"
#include "Images.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "MapData.h"

class PlayerController : public BaseController {

  public:

    PlayerController();

    static bool move(Player *player, Enemy *allEnemies, Level *level, Button button);

};

#endif