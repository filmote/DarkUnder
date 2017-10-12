#include "Item.h"

Item::Item() : Base() {}

const ItemType Item::getItemType()                { return _itemType; }
const bool Item::getEnabled()                     { return _enabled; }

void Item::setItemType(const ItemType value)      { _itemType = value; }
void Item::setEnabled(const bool value)           { _enabled = value; }