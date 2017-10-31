#ifdef USE_LARGE_MAP
#include <Arduboy2.h>

/* -----------------------------------------------------------------------------------------------------------------------------
 *  Display Large Map.  
 *  
 *  Controls the selection or discarding of an item the player has stumbled over.  If a user choses to ignore an item found in 
 *  the maze, the GameState is updated to ItemIgnore which will allow them to progress beyond the item.  If th user returns to
 *  the same position in the maze, they will be re-prompted to collect / discard the same item.
 *  
 *  The player can press the BACK_BUTTON (as defined in Enums.h) to bring up the inventory management dialogue if they need to 
 *  delete an existing inventory item to make space for the new item.  The current GameState is retained in the 'savedState' 
 *  field allowing for control to return back to this action after the dialogue is dismissed.
 *  
 *  Returns delay in milliseconds to wait.
 *
 * -----------------------------------------------------------------------------------------------------------------------------
 */
void displayLargeMap() {

  arduboy.drawCompressed(0, 0, frames_outside, WHITE);  
  drawMapAndStatistics(&myHero, &myLevel, false);
  uint8_t buttons = arduboy.justPressedButtons();

  if (buttons & BACK_BUTTON_MASK) { gameState = savedState; } 

}
#endif
