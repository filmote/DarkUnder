#include "Item.h"

Item::Item() : Base() {}

ItemType Item::getItemType() const                { return _itemType; }
bool Item::getEnabled() const                     { return _enabled; }

void Item::setItemType(const ItemType value)      { _itemType = value; }
void Item::setEnabled(const bool value)           { _enabled = value; }