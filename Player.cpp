#include <Arduboy2.h>
#include "Player.h"
#include "Enums.h"
#include "Level.h"

Player::Player() : Base() { }

uint8_t Player::getHitPoints()                            { return _hitPoints; }
uint8_t Player::getDefence()                              { return _defence; }
uint8_t Player::getAttackPower()                          { return _attackPower; }
uint8_t Player::getMagic()                                { return Player::getInventoryCount(ItemType::Scroll); }
uint8_t Player::getExperiencePoints()                     { return _experiencePoints; }

Direction Player::getDirection()                          { return _direction; }
ItemType Player::getInventory(uint8_t slot)               { return _inventory[slot]; }

void Player::setHitPoints(const uint8_t value)            { _hitPoints = value; }
void Player::setDefence(const uint8_t value)              { _defence = value; }
void Player::setAttackPower(const uint8_t value)          { _attackPower = value; }
void Player::setExperiencePoints(const uint8_t value)     { _experiencePoints = value; }

void Player::setDirection(const Direction value)          { _direction = value; }

void Player::setInventory(const int8_t slot, const ItemType item) { 

  _inventory[slot] = item; 
  shuffleInventory();
     
}

int8_t Player::getConsumableSlot() { 

    if (_inventory[0] == ItemType::None) return 0;
    if (_inventory[1] == ItemType::None) return 1;
    if (_inventory[2] == ItemType::None) return 2;

    return -1;

}

int8_t Player::getSlotNumber(const ItemType item) {
    
    for (uint8_t i = 0; i < 3; ++i) {
        if (_inventory[i] == item) { return i; }
    }

    return -1;
        
}

int8_t Player::getInventoryCount(const ItemType item) {
    
    uint8_t itemCount = 0;

    if (_inventory[0] == item) itemCount++;
    if (_inventory[1] == item) itemCount++;
    if (_inventory[2] == item) itemCount++;

    return itemCount;
        
}

void Player::shuffleInventory() {

  if (_inventory[0] == ItemType::None) { _inventory[0] = _inventory[1]; _inventory[1] = _inventory[2]; _inventory[2] = ItemType::None; }
  if (_inventory[1] == ItemType::None) { _inventory[1] = _inventory[2]; _inventory[2] = ItemType::None; }
 
}

void Player::decHitPoints(const int8_t value) { 
    
  if (_hitPoints > value ) {
    _hitPoints = _hitPoints - value;
  }
  else {
    _hitPoints = 0; 
  }

}
