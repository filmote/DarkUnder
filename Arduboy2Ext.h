#ifndef ARDUBOY2EXT_H
#define ARDUBOY2EXT_H

#include "Arduboy2.h"

#define DEFAULT_VERT_SPACING 12 

class Arduboy2Ext : public Arduboy2Base {
  
   public:
     Arduboy2Ext();
   
     const uint8_t justPressedButtons();            
  
};
#endif
