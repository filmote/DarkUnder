#ifndef ENEMY_H
#define ENEMY_H

#include <Arduboy2.h>
#include "Enums.h"

struct Enemy {

  bool enabled;
  EnemyType enemyType;
  int x;
  int y;

};

#endif
