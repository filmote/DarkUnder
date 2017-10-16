#include <Arduino.h>
#include <Print.h>
#include <Sprites.h>
#include "Font3x5.h"

#define FONT3X5_WIDTH 3
#define FONT3X5_HEIGHT 6

//const unsigned char PROGMEM Font_Mask[] = {
//0x7F, 0x7F, 0x7F, 0x7F,
//};

const unsigned char PROGMEM font_images[] = {
3, 7,
0x1F, 0x05, 0x1F, // A
0x1F, 0x15, 0x1B, 
0x1F, 0x11, 0x11, 
0x1F, 0x11, 0x0E, 
0x1F, 0x15, 0x11, 
0x1F, 0x05, 0x01, 
0x1F, 0x11, 0x1D, 
0x1F, 0x04, 0x1F, 
0x00, 0x1F, 0x00, 
0x10, 0x10, 0x1F, 
0x1F, 0x04, 0x1B, 
0x1F, 0x10, 0x10, 
0x1F, 0x06, 0x1F, 
0x1F, 0x01, 0x1F, 
0x1F, 0x11, 0x1F, 
0x1F, 0x05, 0x07, 
0x1F, 0x31, 0x1F, 
0x1F, 0x05, 0x1B,  
0x17, 0x15, 0x1D,  
0x01, 0x1F, 0x01,  
0x1F, 0x10, 0x1F,  
0x0F, 0x10, 0x0F,  
0x1F, 0x0C, 0x1F,  
0x1B, 0x04, 0x1B,  
0x07, 0x1C, 0x07,  
0x19, 0x15, 0x13, // Z
0x1F, 0x11, 0x1F, // 0  
0x00, 0x1F, 0x00,
0x1D, 0x15, 0x17,  
0x11, 0x15, 0x1F,  
0x07, 0x04, 0x1F,  
0x17, 0x15, 0x1D,  
0x1F, 0x15, 0x1D,  
0x01, 0x01, 0x1F,  
0x1F, 0x15, 0x1F,  
0x17, 0x15, 0x1F, // 9
0x00, 0x17, 0x00, // !
};
  
Font3x5::Font3x5(int16_t width, int16_t height) {

  sWidth = width;
  sHeight = height;

  // default values
  lineHeight = FONT3X5_HEIGHT + 2;
  letterSpacing = 1;

  cursorX = cursorY = baseX = 0;
  textColor = 1;

}

size_t Font3x5::write(uint8_t c) {

  if (c == '\n')      { cursorX = baseX; cursorY += lineHeight; }
  else if(c == '\t')  { cursorX += FONT3X5_WIDTH + 5; }
  else {

    printChar(c, cursorX, cursorY);
    cursorX += FONT3X5_WIDTH + letterSpacing;

  }

  return 1;

}

void Font3x5::printChar(char c, int16_t x, int16_t y) {

  uint8_t idx = 0;

  // no need to draw at all of we're offscreen
  if (x + FONT3X5_WIDTH <= 0 || x > sWidth - 1 || y + FONT3X5_HEIGHT <= 0 || y > sHeight - 1) return;

  ++y;

//  const uint8_t * glyph = nullptr;
  if (c >= 65 && c <= 90) {
//    glyph = reinterpret_cast<const uint8_t *>(pgm_read_word_near(&font_letters[c - 65]));
    idx = c - 65;
  }
  if (c >= 48 && c <= 57) {  
//    glyph = reinterpret_cast<const uint8_t *>(pgm_read_word_near(&font_numbers[c - 48]));
    idx = c - 48 + 26;
  }
  if (c == 33) {  
//    glyph = FONT_EXCLAMATION;
    idx = 36;
  }
  if (textColor == WHITE) {
    Sprites::drawSelfMasked(x, y, font_images, idx);
  }
  else {
    Sprites::drawErase(x, y, font_images, idx);
  }

}

void Font3x5::setCursor(int16_t x, int16_t y) {
  cursorX = baseX = x;
  cursorY = y;
}

const int16_t Font3x5::getCursorX(){
  return cursorX;
}

const int16_t Font3x5::getCursorY(){
  return cursorY;
}

void Font3x5::setTextColor(uint8_t color){
  textColor = color;
}
