#ifndef BASE_H
#define BASE_H

#include <Arduboy2.h>

class Base {

  public:

    Base();

    const int16_t getX() const;
    const int16_t getY() const;
    
    void setX(const int16_t value);
    void setY(const int16_t value);

  private:

    int16_t _x;
    int16_t _y;
    
};

#endif
