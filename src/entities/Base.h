#pragma once

#include <Arduboy2.h>

class Base {

  public:

    Base();

    int16_t getX() const;
    int16_t getY() const;
    
    void setX(const int16_t value);
    void setY(const int16_t value);

  private:

    int16_t _x;
    int16_t _y;
    
};

