#include "Base.h"

Base::Base() {}

const int16_t Base::getX() const                 { return _x; }
const int16_t Base::getY() const                 { return _y; }


void Base::setX(const int16_t value)             { _x = value; }
void Base::setY(const int16_t value)             { _y = value; }

