#include "Item.h"
#include "Enums.h"

Item::Item() {}

const bool Item::getEnabled()                     { return _enabled; }
const ItemType Item::getItemType()                { return _itemType; }
const uint16_t Item::getX()                       { return _x; }
const uint16_t Item::getY()                       { return _y; }

void Item::setEnabled(const bool value)           { _enabled = value; }
void Item::setItemType(const ItemType value)      { _itemType = value; }
void Item::setX(const uint16_t value)             { _x = value; }
void Item::setY(const uint16_t value)             { _y = value; }