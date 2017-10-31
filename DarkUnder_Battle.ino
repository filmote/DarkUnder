#include <Arduboy2.h>

/* -----------------------------------------------------------------------------------------------------------------------------
 *  Battle Loop  
 *  
 *  GameStates:
 *  
 *  Battle_EnemyAttacks_Init -    Displays the initial '{enemy} attacks !' message and prepares for and enemy attck.
 *  Battle_EnemyAttacks -         Displays the dice animation and inflicts damage to the player.  
 *  Battle_PlayerDecides -        Presents the players battle options including attack, defend, cast a spell ..
 *  Battle_PlayerAttacks -        Throws the dice and inflicts damage on the enemy.
 *  Battle_PlayerDefends -        Inflicts 1 point of damage on the enemy and randomly gains player hit points.
 *  Battle_PlayerCastsSpell -     Inflicts 5 points of damage on the enemy.
 *  Battle_EnemyDies -            Handles and end of battel where the enemy dies.
 * 
 *  Returns delay in milliseconds to wait.
 *  
 * -----------------------------------------------------------------------------------------------------------------------------
 */
uint16_t battleLoop() {
  
  uint16_t delayLength = 0;
  
  drawPlayerVision(&myHero, &myLevel);
  Sprites::drawSelfMasked(DIRECTION_X_OFFSET, DIRECTION_Y_OFFSET, fight_icon, 0);

  Enemy enemy = enemies[attackingEnemyIdx];

  font3x5.setCursor(80,44);

  switch (gameState) {

    
    case GameState::Battle_EnemyAttacks_Init:  // ----------------------------------------------------------------------------------------------------------------------------------
      
      font3x5.print(getEnemyName(enemy.getEnemyType()));
      font3x5.print(F("\nATTACKS!"));
      
      #ifdef USE_DICE_ANIMATIONS
      diceDelay = DICE_DELAY_START;
      #endif
      gameState = GameState::Battle_EnemyAttacks;
      delayLength = FIGHT_DELAY;
      break;


    case GameState::Battle_EnemyAttacks:  // ---------------------------------------------------------------------------------------------------------------------------------------
    
      arduboy.drawCompressed(12, 12, fight_scratch_Mask, BLACK);
      arduboy.drawCompressed(12, 12, fight_scratch, WHITE);

      #ifdef USE_DICE_ANIMATIONS
      if (diceDelay >= DICE_DELAY_START && diceDelay < DICE_DELAY_END) {

        rollDice(33, 26);
        
      }
      else {

        diceDoOnce(ENEMY_MAX_ATTACK, 0);

        font3x5.print(F("YOU TAKE\n"));
        font3x5.print(diceAttack);
        font3x5.print(F(" DAMAGE!"));
        font3x5.setCursor(33, 26);
        font3x5.print(diceAttack);

        myHero.decHitPoints(diceAttack);
        gameState = GameState::Battle_PlayerDecides;
        delayLength = FIGHT_DELAY;
        
      }
      #endif

      #ifndef USE_DICE_ANIMATIONS
      diceAttack = random(0, ENEMY_MAX_ATTACK);
      font3x5.print(F("YOU TAKE\n"));
      font3x5.print(diceAttack);
      font3x5.print(F(" DAMAGE!"));
      font3x5.setCursor(33, 26);
      font3x5.print(diceAttack);
      myHero.decHitPoints(diceAttack);
      gameState = GameState::Battle_PlayerDecides;
      delayLength = FIGHT_DELAY;
      #endif

      if (myHero.getHitPoints() == 0)  gameState = GameState::Battle_PlayerDies;

      break;


    case GameState::Battle_EnemyDies:  // ---------------------------------------------------------------------------------------------------------------------------------------
      {
        uint8_t xp = enemy.getExperiencePoints();

        arduboy.drawCompressed(18, 14, enemy_defeated_Mask, BLACK);
        arduboy.drawCompressed(18, 14, enemy_defeated, WHITE);

        font3x5.setCursor(34, 26);
        font3x5.print(xp);
        myHero.setExperiencePoints(myHero.getExperiencePoints() + xp);

        if (myHero.getExperiencePoints() >= XP_LEVEL_UP) {
          myHero.setExperiencePoints(0);
          gameState = GameState::LevelUp;
        }
        else {
          gameState = GameState::Move;
        }

        delayLength = FIGHT_DELAY;

      }
      break;


    case GameState::Battle_PlayerDecides:  // -----------------------------------------------------------------------------------------------------------------------------------
      {
        bool fightButtons[4] = { true, false, false, false };

        uint8_t buttons = arduboy.justPressedButtons();
        fightButtons[(uint8_t)FightButtons::Shield] = true;
        fightButtons[(uint8_t)FightButtons::Magic] = (myHero.getMagic() > 0);
        fightButtons[(uint8_t)FightButtons::Potion] = (myHero.getInventoryCount(ItemType::Potion));

        arduboy.drawCompressed(80, 44, fight_actions_1, WHITE);
        if (fightButtons[(uint8_t)FightButtons::Shield])   { arduboy.drawCompressed(91, 44, fight_actions_2, WHITE); }
        if (fightButtons[(uint8_t)FightButtons::Magic])    { arduboy.drawCompressed(102, 44, fight_actions_3, WHITE); }
        if (fightButtons[(uint8_t)FightButtons::Potion])   { arduboy.drawCompressed(113, 44, fight_actions_4, WHITE); }
        Sprites::drawSelfMasked(81 + (((uint8_t)fightButton) * 11), 56, icnSelect, 0);
        
        if ((buttons & LEFT_BUTTON_MASK) && (uint8_t)fightButton > 0) { 
          
          for (uint8_t i = (uint8_t)fightButton - 1; i >= 0; --i) {
            if (fightButtons[i]) { 
              fightButton = (FightButtons)i;
              break;
            }
          }

        }

        if (buttons & RIGHT_BUTTON_MASK) {
          
          for (uint8_t i = (uint8_t)fightButton + 1; i < (uint8_t)FightButtons::Count; ++i) {
            if (fightButtons[i]) { 
              fightButton = (FightButtons)i;
              break;
            }
          }
          
        }

        if (buttons & BACK_BUTTON_MASK)  {
          savedState = gameState;
          gameState = GameState::InventorySelect;
        }
          
        if (buttons & SELECT_BUTTON_MASK)  {
          
          #ifdef USE_DICE_ANIMATIONS
          diceDelay = DICE_DELAY_START;
          #endif

          switch (fightButton) {

            case (FightButtons::Attack):
              gameState = GameState::Battle_PlayerAttacks;
              break;

            case (FightButtons::Shield):
              gameState = GameState::Battle_PlayerDefends;
              break;

            case (FightButtons::Magic):
              gameState = GameState::Battle_PlayerCastsSpell;
              fightButton = FightButtons::Attack;
              break;

            case (FightButtons::Potion):
              myHero.setHitPoints(myHero.getHitPoints() + INVENTORY_POTION_HP_INC);
              myHero.setInventory(myHero.getSlotNumber(ItemType::Potion), ItemType::None);
              fightButton = FightButtons::Attack;
              break;

            default:
              break;
          
          }
        
        }
        
      }
      break;


    case GameState::Battle_PlayerAttacks:  // ---------------------------------------------------------------------------------------------------------------------------------------
    
      arduboy.drawCompressed(19, 19, fight_hero_strike_Mask, BLACK);
      arduboy.drawCompressed(19, 19, fight_hero_strike, WHITE);

      #ifdef USE_DICE_ANIMATIONS
      if (diceDelay >= DICE_DELAY_START && diceDelay < DICE_DELAY_END) {

        rollDice(32, 24);

      }
      else {

        diceDoOnce(myHero.getAttackPower(), 1);

        font3x5.print(F("YOU DEAL\n"));
        font3x5.print(diceAttack);
        font3x5.print(F(" DAMAGE!\n"));
        font3x5.setCursor(32, 24);
        font3x5.print(diceAttack);
        enemy.decHitPoints(diceAttack);
        
        if (enemy.getHitPoints() > 0) {
          gameState = GameState::Battle_EnemyAttacks_Init;
        }
        else {
          gameState = GameState::Battle_EnemyDies;
        }

        delayLength = FIGHT_DELAY;

      }
      #endif

      #ifndef USE_DICE_ANIMATIONS
      diceAttack = random(1, myHero.getAttackPower() + 1);
      font3x5.print(F("YOU DEAL\n"));
      font3x5.print(diceAttack);
      font3x5.print(F(" DAMAGE!\n"));
      font3x5.setCursor(32, 24);
      font3x5.print(diceAttack);
      enemy.decHitPoints(diceAttack);

      if (enemy.getHitPoints() > 0) {
        gameState = GameState::Battle_EnemyAttacks_Init;
      }
      else {
        gameState = GameState::Battle_EnemyDies;
      }

      delayLength = FIGHT_DELAY;
      #endif
      
      break; 


    case GameState::Battle_PlayerDefends:  // ---------------------------------------------------------------------------------------------------------------------------------------
    
      arduboy.drawCompressed(12, 15, fight_hero_shield_Mask, BLACK);
      arduboy.drawCompressed(12, 15, fight_hero_shield, WHITE);

      #ifdef USE_DICE_ANIMATIONS   
      if (diceDelay >= DICE_DELAY_START && diceDelay < DICE_DELAY_END) {

        rollDice(17, 35);

      }
      else {

        diceDoOnce(HUMAN_MAX_ATTACK, 1);

        font3x5.print(F("TAKE "));
        font3x5.print(diceAttack);
        font3x5.print(F(" DMG\n"));
        font3x5.print(F("DEAL 1 DMG\n"));
        font3x5.setCursor(17, 35);
        font3x5.print(diceAttack);

        myHero.setHitPoints(myHero.getHitPoints() - diceAttack);
        enemy.decHitPoints(1);
        
        if (enemy.getHitPoints() > 0) {
          gameState = GameState::Battle_PlayerDecides;
        }
        else {
          gameState = GameState::Battle_EnemyDies;
        }

        delayLength = FIGHT_DELAY;

      }
      #endif

      #ifndef USE_DICE_ANIMATIONS   
      {
        uint8_t maxHP = enemy.getAttackPower() - myHero.getDefence();
        if (maxHP < 0) maxHP = 1;
        if (maxHP > 9) maxHP = 9;
        diceAttack = random(0, maxHP);   
      }   

      font3x5.print(F("TAKE "));
      font3x5.print(diceAttack);
      font3x5.print(F(" DMG\n"));
      font3x5.print(F("DEAL 1 DMG\n"));
      font3x5.setCursor(17, 35);
      font3x5.print(diceAttack);

      myHero.setHitPoints(myHero.getHitPoints() + diceAttack);
      enemy.decHitPoints(1);
      
      if (enemy.getHitPoints() > 0) {
        gameState = GameState::Battle_EnemyAttacks_Init;
      }
      else {
        gameState = GameState::Battle_EnemyDies;
      }

      delayLength = FIGHT_DELAY;
      #endif
      
      break;   


    case GameState::Battle_PlayerCastsSpell:  // ---------------------------------------------------------------------------------------------------------------------------------------
    
      arduboy.drawCompressed(12, 15, fight_hero_spell_Mask, BLACK);
      arduboy.drawCompressed(12, 15, fight_hero_spell, WHITE);

      enemy.decHitPoints(diceAttack);
      myHero.setInventory(myHero.getSlotNumber(ItemType::Scroll), ItemType::None);

      if (enemy.getHitPoints() > 0) {
        gameState = GameState::Battle_EnemyAttacks_Init;
      }
      else {
        gameState = GameState::Battle_EnemyDies;
      }

      delayLength = FIGHT_DELAY;
      break;

    default: break;
      
  }

  drawEnemyHitPointsBar(enemy.getHitPoints(), enemy.getHitPointsMax());
  return delayLength;

}