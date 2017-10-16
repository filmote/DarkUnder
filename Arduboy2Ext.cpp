#include "Arduboy2Ext.h"

Arduboy2Ext::Arduboy2Ext() : Arduboy2Base() { }

const uint8_t Arduboy2Ext::justPressedButtons() {

  return (~previousButtonState & currentButtonState);

}



