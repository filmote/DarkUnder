#ifndef ITEM_H
#define ITEM_H

#include <Arduboy2.h>
#include "Enums.h"

class Item {

  public:

    Item();

    const bool getEnabled();
    const ItemType getItemType();
    const uint16_t getX();
    const uint16_t getY();

    void setEnabled(const bool value);
    void setItemType(const ItemType value);
    void setX(const uint16_t value);
    void setY(const uint16_t value);

  private:
    
    bool _enabled;
    ItemType _itemType;
    int _x;
    int _y;

};

#endif
