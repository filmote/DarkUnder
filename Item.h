#ifndef ITEM_H
#define ITEM_H

#include <Arduboy2.h>
#include "Enums.h"

class Item {

  public:

    Item();

    const bool getEnabled();
    const ItemType getItemType();
    const int16_t getX();
    const int16_t getY();

    void setEnabled(const bool value);
    void setItemType(const ItemType value);
    void setX(const int16_t value);
    void setY(const int16_t value);

  private:
    
    bool _enabled;
    ItemType _itemType;
    int16_t _x;
    int16_t _y;

};

#endif
