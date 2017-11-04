#pragma once

#include <Arduino.h>
#include <Print.h>

class Font3x5 : public Print {
    
  public:

    Font3x5(int16_t width, int16_t height);   

    virtual size_t write(uint8_t); // used by the Arduino Print class
    void printChar(const char c, const int16_t x, int16_t y);
    void setCursor(const int16_t x, const int16_t y);

    // int16_t getCursorX() const;
    // int16_t getCursorY() const;
    void setTextColor(const uint8_t color);
    void setHeight(const uint8_t color);
    

  private:

    // int16_t sWidth;
    // int16_t sHeight;

    int16_t _cursorX;    //!< Default is 0.
    int16_t _baseX;      //!< needed for linebreak.
    int16_t _cursorY;    //!< Default is 0.

    int16_t _textColor;  // BLACK == 0, everything else is WHITE. Default is WHITE.

    uint8_t _letterSpacing;  //!< letterSpacing controls the distance between letters. Default is 1.
    uint8_t _lineHeight;     //!< lineHeight controls the height between lines breakend by \n. Default is 6.

};
