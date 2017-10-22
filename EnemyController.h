#pragma once

#include <Arduboy2.h>
#include "BaseController.h"
#include "Enums.h"
#include "Level.h"
#include "Images.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "MapData.h"

class EnemyController : public BaseController {

  public:

    EnemyController();

    static void move(Enemy *thisEnemy, Enemy *allEnemies, Player *player, Level *level); 
    static boolean moveTowardsPlayer(Enemy *thisEnemy, Enemy *allEnemies, Player *player, Level *level);
    static boolean moveToVacantSquare(Enemy *thisEnemy, Enemy *allEnemies, Player *player, Level *level, Direction playerDirection);

};