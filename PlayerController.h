#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <Arduboy2.h>
#include "Enums.h"
#include "Level.h"
#include "Images.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "MapData.h"

class PlayerController {

  public:

    PlayerController();

    static bool move(Player *player, Enemy *allEnemies, Level *level, Button button);
    static bool moveLegal(Enemy *allEnemies, Level *level, int x, int y);

};

#endif