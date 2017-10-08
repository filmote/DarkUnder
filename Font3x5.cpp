#include <Arduino.h>
#include <Print.h>
#include <Sprites.h>
#include "Font3x5.h"

#define FONT3X5_WIDTH 3
#define FONT3X5_HEIGHT 6

const unsigned char PROGMEM FONT_MASK[] = {
0x7F, 0x7F, 0x7F, 0x7F,
};

const unsigned char PROGMEM FONT_A[] = {
4, 7,
0x1F, 0x05, 0x1F, 0x00,
};

const unsigned char PROGMEM FONT_B[] = {
4, 7,
0x1F, 0x15, 0x1B, 0x00,
};

const unsigned char PROGMEM FONT_C[] = {
4, 7,
0x1F, 0x11, 0x11, 0x00,
};

const unsigned char PROGMEM FONT_D[] = {
4, 7,
0x1F, 0x11, 0x0E, 0x00,
};

const unsigned char PROGMEM FONT_E[] = {
4, 7,
0x1F, 0x15, 0x11, 0x00,
};

const unsigned char PROGMEM FONT_F[] = {
4, 7,
0x1F, 0x05, 0x01, 0x00,
};

const unsigned char PROGMEM FONT_G[] = {
4, 7,
0x1F, 0x11, 0x1D, 0x00,
};

const unsigned char PROGMEM FONT_H[] = {
4, 7,
0x1F, 0x04, 0x1F, 0x00,
};

const unsigned char PROGMEM FONT_I[] = {
4, 7,
0x00, 0x1F, 0x00, 0x00,
};

const unsigned char PROGMEM FONT_J[] = {
4, 7,
0x10, 0x10, 0x1F, 0x00,
};

const unsigned char PROGMEM FONT_K[] = {
4, 7,
0x1F, 0x04, 0x1B, 0x00,
};

const unsigned char PROGMEM FONT_L[] = {
4, 7,
0x1F, 0x10, 0x10, 0x00,
};

const unsigned char PROGMEM FONT_M[] = {
4, 7,
0x1F, 0x06, 0x1F, 0x00,
};

const unsigned char PROGMEM FONT_N[] = {
4, 7,
0x1F, 0x01, 0x1F, 0x00,
};

const unsigned char PROGMEM FONT_O[] = {
4, 7,
0x1F, 0x11, 0x1F, 0x00,
};

const unsigned char PROGMEM FONT_P[] = {
4, 7,
0x1F, 0x05, 0x07, 0x00,
};

const unsigned char PROGMEM FONT_Q[] = {
4, 7,
0x1F, 0x31, 0x1F, 0x00,
};

const unsigned char PROGMEM FONT_R[] = {
4, 7,
0x1F, 0x05, 0x1B, 0x00, 
};

const unsigned char PROGMEM FONT_S[] = {
4, 7,
0x17, 0x15, 0x1D, 0x00, 
};

const unsigned char PROGMEM FONT_T[] = {
4, 7,
0x01, 0x1F, 0x01, 0x00, 
};

const unsigned char PROGMEM FONT_U[] = {
4, 7,
0x1F, 0x10, 0x1F, 0x00, 
};

const unsigned char PROGMEM FONT_V[] = {
4, 7,
0x0F, 0x10, 0x0F, 0x00, 
};

const unsigned char PROGMEM FONT_W[] = {
4, 7,
0x1F, 0x0C, 0x1F, 0x00, 
};

const unsigned char PROGMEM FONT_X[] = {
4, 7,
0x1B, 0x04, 0x1B, 0x00, 
};

const unsigned char PROGMEM FONT_Y[] = {
4, 7,
0x07, 0x1C, 0x07, 0x00, 
};

const unsigned char PROGMEM FONT_Z[] = {
4, 7,
0x19, 0x15, 0x13, 0x00,
};

const unsigned char PROGMEM FONT_0[] = {
4, 7,

0x1F, 0x11, 0x1F, 0x00, 
};

const unsigned char PROGMEM FONT_1[] = {
4, 7,
0x00, 0x1F, 0x00, 0x00, 
};

const unsigned char PROGMEM FONT_2[] = {
4, 7,
0x1D, 0x15, 0x17, 0x00, 
};

const unsigned char PROGMEM FONT_3[] = {
4, 7,
0x11, 0x15, 0x1F, 0x00, 
};

const unsigned char PROGMEM FONT_4[] = {
4, 7,
0x07, 0x04, 0x1F, 0x00, 
};

const unsigned char PROGMEM FONT_5[] = {
4, 7,
0x17, 0x15, 0x1D, 0x00, 
};

const unsigned char PROGMEM FONT_6[] = {
4, 7,
0x1F, 0x15, 0x1D, 0x00, 
};

const unsigned char PROGMEM FONT_7[] = {
4, 7,
0x01, 0x01, 0x1F, 0x00, 
};

const unsigned char PROGMEM FONT_8[] = {
4, 7,
0x1F, 0x15, 0x1F, 0x00, 
};

const unsigned char PROGMEM FONT_9[] = {
4, 7,
0x17, 0x15, 0x1F, 0x00,
};

const uint8_t * const font_letters[] PROGMEM = { FONT_A, FONT_B, FONT_C, FONT_D, FONT_E, FONT_F, FONT_G, FONT_H, FONT_I, FONT_J, FONT_K, FONT_L, FONT_M, 
                                                 FONT_N, FONT_O, FONT_P, FONT_Q, FONT_R, FONT_S, FONT_T, FONT_U, FONT_V, FONT_W, FONT_X, FONT_Y ,FONT_Z };
const uint8_t * const font_numbers[] PROGMEM = { FONT_0, FONT_1, FONT_2, FONT_3, FONT_4, FONT_5, FONT_6, FONT_7, FONT_8, FONT_9 };   

Font3x5::Font3x5(uint8_t *screenBuffer, int16_t width, int16_t height) {

  sBuffer = screenBuffer;
  sWidth = width;
  sHeight = height;

  // default values
  lineHeight = FONT3X5_HEIGHT + 1;
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

  // no need to draw at all of we're offscreen
  if (x + FONT3X5_WIDTH <= 0 || x > sWidth - 1 || y + FONT3X5_HEIGHT <= 0 || y > sHeight - 1) return;

  ++y;

  if (c >= 65 && c <= 90) {
    Sprites::drawExternalMask(x, y, pgm_read_word_near(&font_letters[c - 65]), FONT_MASK, 0, 0);
  }
  if (c >= 48 && c <= 57) {  
    Sprites::drawExternalMask(x, y, pgm_read_word_near(&font_numbers[c - 48]), FONT_MASK, 0, 0);
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