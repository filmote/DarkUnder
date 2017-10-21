#include <Arduboy2.h>
#include "Player.h"
#include "Enums.h"
#include "Level.h"

Player::Player() : Base() {

    _hitPoints = 15;
    _defence = 10;
    _attackPower = 0;
//    _magic = 0;
    
}

Direction Player::getDirection()                    { return _direction; }
int8_t Player::getHitPoints()                       { return _hitPoints; }
int8_t Player::getDefence()                         { return _defence; }
int8_t Player::getAttackPower()                     { return _attackPower; }
int8_t Player::getMagic()                           { return Player::getInventoryCount(Inventory::Scroll); }
Inventory Player::getInventory(uint8_t slot)        { return _inventory[slot]; }

void Player::setDirection(const Direction value)    { _direction = value; }
void Player::setHitPoints(const int8_t value)       { _hitPoints = value; }
void Player::setDefence(const int8_t value)         { _defence = value; }
void Player::setAttackPower(const int8_t value)     { _attackPower = value; }
//void Player::setMagic(const int8_t value)           { _magic = value; }

void Player::setInventory(const int8_t slot, const Inventory item) { 

    if (item != Inventory::None) {
        _inventory[slot] = item; 
        ++_inventoryCount[slot];
    }
    else {
        _inventory[slot] = item; 
        _inventoryCount[slot] = 0;
    }

    shuffleInventory();
     
}

int8_t Player::getConsumableSlot() { 

    if (_inventory[0] == Inventory::None) return 0;
    if (_inventory[1] == Inventory::None) return 1;
    if (_inventory[2] == Inventory::None) return 2;

    return -1;

}

int8_t Player::getSlotNumber(const Inventory item) {
    
    for (uint8_t i = 0; i < 3; ++i) {
        if (_inventory[i] == item) { return i; }
    }

    return -1;
        
}

int8_t Player::getInventoryCount(const Inventory item) {
    
    int8_t slotNumber = Player::getSlotNumber(item);

    if (slotNumber >= 0)    return _inventoryCount[slotNumber];

    return 0;
        
}

void Player::decInventoryCount(const Inventory item) {
    
    int8_t slotNumber = Player::getSlotNumber(item);

    if (slotNumber >= 0)                    --_inventoryCount[slotNumber];
    if (_inventoryCount[slotNumber] == 0)   _inventory[slotNumber] = Inventory::None;
    
    shuffleInventory();
        
}

void Player::shuffleInventory() {

    if (_inventory[0] == Inventory::None) { _inventory[0] = _inventory[1]; _inventory[1] = _inventory[2]; _inventory[2] = Inventory::None; 
                                            _inventoryCount[0] = _inventoryCount[1]; _inventoryCount[1] = _inventoryCount[2]; _inventoryCount[2] = 0; }
    if (_inventory[1] == Inventory::None) { _inventory[1] = _inventory[2]; _inventory[2] = Inventory::None; 
                                            _inventoryCount[1] = _inventoryCount[2]; _inventoryCount[2] = 0; }
    if (_inventory[2] == Inventory::None) { _inventoryCount[2] = 0; }

}