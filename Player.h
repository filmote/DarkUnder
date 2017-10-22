#ifndef PLAYER_H
#define PLAYER_H

#include <Arduboy2.h>
#include "Base.h"
#include "Enums.h"
#include "Level.h"

class Player : public Base {

  public:

    Player();

    Direction getDirection();
    int8_t getHitPoints();
    int8_t getDefence();
    int8_t getAttackPower();
    int8_t getMagic();
    Inventory getInventory(uint8_t slot);
    int8_t getConsumableSlot();
    int8_t getSlotNumber(const Inventory item);
    int8_t getInventoryCount(const Inventory item);
    
    void setDirection(const Direction value);
    void setHitPoints(const int8_t value);   
    void setDefence(const int8_t value);   
    void setAttackPower(const int8_t value);   
    void setInventory(const int8_t slot, const Inventory item);   
    void decInventoryCount(const Inventory item);
    
  private:

    void shuffleInventory();

    Direction _direction;
    int8_t _hitPoints;
    int8_t _defence;
    int8_t _attackPower;
    Inventory _inventory[5];
    uint8_t _inventoryCount[5];
    
  };

#endif
