#include <Arduboy2.h>

/* -----------------------------------------------------------------------------------------------------------------------------
 *  Dice control.  
 *  
 *  Transition the dice rolling to the final state.  The variable 'diceAttack' stores the final dice value.
 *  
 * -----------------------------------------------------------------------------------------------------------------------------
 */
#ifdef USE_DICE_ANIMATIONS
void diceDoOnce(uint8_t maxValue, uint8_t offset) {

  if (diceDelay >= DICE_DELAY_END) {  // Do once.

    diceAttack = random(0, maxValue) + offset;
    diceDelay = DICE_NO_ACTION;

  }

}
#endif


#ifdef USE_DICE_ANIMATIONS
void rollDice(uint8_t x, uint8_t y) {

  font3x5.setCursor(x, y);
  font3x5.print(diceAttack);

  if (diceDelay < 1) {

    diceAttack = random(0, 4);
    diceDelay++;

    #ifdef USE_SOUNDS
    sound.tone(NOTE_A1, 20);
    #endif
    
  }
  else {  

    if (arduboy.everyXFrames(diceDelay)) {

      #ifdef USE_SOUNDS
      sound.tone(NOTE_A1, 20);
      #endif
      
      diceAttack = random(0, 4);
      diceDelay = diceDelay * 2;

    }

  }

}
#endif
