#ifndef ITEM_H
#define ITEM_H

#include <Arduboy2.h>
#include "Item.h"
#include "Base.h"
#include "Enums.h"

class Item : public Base {

  public:

    Item();

    const ItemType getItemType();
    const bool getEnabled();

    void setItemType(const ItemType value);
    void setEnabled(const bool value);

  private:
    
    ItemType _itemType;
    bool _enabled;

};

#endif
