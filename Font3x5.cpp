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
3, 7,
0x1F, 0x05, 0x1F,
};

const unsigned char PROGMEM FONT_B[] = {
3, 7,
0x1F, 0x15, 0x1B, 
};

const unsigned char PROGMEM FONT_C[] = {
3, 7,
0x1F, 0x11, 0x11, 
};

const unsigned char PROGMEM FONT_D[] = {
3, 7,
0x1F, 0x11, 0x0E, 
};

const unsigned char PROGMEM FONT_E[] = {
3, 7,
0x1F, 0x15, 0x11, 
};

const unsigned char PROGMEM FONT_F[] = {
3, 7,
0x1F, 0x05, 0x01, 
};

const unsigned char PROGMEM FONT_G[] = {
3, 7,
0x1F, 0x11, 0x1D, 
};

const unsigned char PROGMEM FONT_H[] = {
3, 7,
0x1F, 0x04, 0x1F, 
};

const unsigned char PROGMEM FONT_I[] = {
3, 7,
0x00, 0x1F, 0x00, 
};

const unsigned char PROGMEM FONT_J[] = {
3, 7,
0x10, 0x10, 0x1F, 
};

const unsigned char PROGMEM FONT_K[] = {
3, 7,
0x1F, 0x04, 0x1B, 
};

const unsigned char PROGMEM FONT_L[] = {
3, 7,
0x1F, 0x10, 0x10, 
};

const unsigned char PROGMEM FONT_M[] = {
3, 7,
0x1F, 0x06, 0x1F, 
};

const unsigned char PROGMEM FONT_N[] = {
3, 7,
0x1F, 0x01, 0x1F, 
};

const unsigned char PROGMEM FONT_O[] = {
3, 7,
0x1F, 0x11, 0x1F, 
};

const unsigned char PROGMEM FONT_P[] = {
3, 7,
0x1F, 0x05, 0x07, 
};

const unsigned char PROGMEM FONT_Q[] = {
3, 7,
0x1F, 0x31, 0x1F, 
};

const unsigned char PROGMEM FONT_R[] = {
3, 7,
0x1F, 0x05, 0x1B,  
};

const unsigned char PROGMEM FONT_S[] = {
3, 7,
0x17, 0x15, 0x1D,  
};

const unsigned char PROGMEM FONT_T[] = {
3, 7,
0x01, 0x1F, 0x01,  
};

const unsigned char PROGMEM FONT_U[] = {
3, 7,
0x1F, 0x10, 0x1F,  
};

const unsigned char PROGMEM FONT_V[] = {
3, 7,
0x0F, 0x10, 0x0F,  
};

const unsigned char PROGMEM FONT_W[] = {
3, 7,
0x1F, 0x0C, 0x1F,  
};

const unsigned char PROGMEM FONT_X[] = {
3, 7,
0x1B, 0x04, 0x1B,  
};

const unsigned char PROGMEM FONT_Y[] = {
3, 7,
0x07, 0x1C, 0x07,  
};

const unsigned char PROGMEM FONT_Z[] = {
3, 7,
0x19, 0x15, 0x13, 
};

const unsigned char PROGMEM FONT_0[] = {
3, 7,

0x1F, 0x11, 0x1F,  
};

const unsigned char PROGMEM FONT_1[] = {
3, 7,
0x00, 0x1F, 0x00,
};

const unsigned char PROGMEM FONT_2[] = {
3, 7,
0x1D, 0x15, 0x17,  
};

const unsigned char PROGMEM FONT_3[] = {
3, 7,
0x11, 0x15, 0x1F,  
};

const unsigned char PROGMEM FONT_4[] = {
3, 7,
0x07, 0x04, 0x1F,  
};

const unsigned char PROGMEM FONT_5[] = {
3, 7,
0x17, 0x15, 0x1D,  
};

const unsigned char PROGMEM FONT_6[] = {
3, 7,
0x1F, 0x15, 0x1D,  
};

const unsigned char PROGMEM FONT_7[] = {
3, 7,
0x01, 0x01, 0x1F,  
};

const unsigned char PROGMEM FONT_8[] = {
3, 7,
0x1F, 0x15, 0x1F,  
};

const unsigned char PROGMEM FONT_9[] = {
3, 7,
0x17, 0x15, 0x1F, 
};

const unsigned char PROGMEM FONT_EXCLAMATION[] = {
3, 7,
0x00, 0x17, 0x00, 
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

  if (textColor == WHITE) {
    if (c >= 65 && c <= 90) {
      Sprites::drawSelfMasked(x, y, pgm_read_word_near(&font_letters[c - 65]), 0);
    }
    if (c >= 48 && c <= 57) {  
      Sprites::drawSelfMasked(x, y, pgm_read_word_near(&font_numbers[c - 48]), 0);
    }
    if (c == 33) {  
      Sprites::drawSelfMasked(x, y, FONT_EXCLAMATION, 0);
    }
  }
  else {

    if (c >= 65 && c <= 90) {
      Sprites::drawErase(x, y, pgm_read_word_near(&font_letters[c - 65]), 0);
    }
    if (c >= 48 && c <= 57) {  
      Sprites::drawErase(x, y, pgm_read_word_near(&font_numbers[c - 48]), 0);
    }
    if (c == 33) {  
      Sprites::drawErase(x, y, FONT_EXCLAMATION, 0);
    }
    
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