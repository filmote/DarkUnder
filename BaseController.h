#pragma once

#include <Arduboy2.h>
#include "Enums.h"
#include "Level.h"
#include "Images.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "MapData.h"

class BaseController {

  public:

    BaseController();

    static boolean moveLegal(Enemy *allEnemies, Player *player, Level *level, uint16_t x, uint16_t y);

};
