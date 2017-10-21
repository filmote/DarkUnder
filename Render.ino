

#define VISION_X_OFFSET   3
#define VISION_Y_OFFSET   4

const int8_t offsetXTable[] = { 0, 1, 0, -1 };
const int8_t offsetYTable[] = { -1, 0, 1, 0 };

void drawPlayerVision(Player *myHero, Level *myLevel) { //draw the walls by checking row and cols ahead of player

  bool horizon3Plus = false;
  bool horizon2Plus = false;

  int8_t farLeftX = 0;
  int8_t farFrontX = 0;
  int8_t farRightX = 0;

  int8_t farLeftY = 0;
  int8_t farFrontY = 0;
  int8_t farRightY = 0;
  
  int8_t middleLeftX = 0;
  int8_t middleFrontX = 0;
  int8_t middleRightX = 0;

  int8_t middleLeftY = 0;
  int8_t middleFrontY = 0;
  int8_t middleRightY = 0;

  int8_t closeLeftX = 0;
  int8_t closeFrontX = 0;
  int8_t closeRightX = 0;

  int8_t closeLeftY = 0;
  int8_t closeFrontY = 0;
  int8_t closeRightY = 0;

  switch (myHero->getDirection()) {

    case Direction::North:
    
      horizon3Plus = (myHero->getY() - 3 >= 0);
      horizon2Plus = (myHero->getY() - 2 >= 0);

      farFrontX = 0;      farFrontY = -3;
      farLeftX = -1;      farLeftY = -2;
      farRightX = 1;      farRightY = -2;

      middleFrontX = 0;   middleFrontY = -2;
      middleLeftX = -1;   middleLeftY = -1;
      middleRightX = 1;   middleRightY = -1;

      closeFrontX = 0;    closeFrontY = -1;
      closeLeftX = -1;    closeLeftY = 0;
      closeRightX = 1;    closeRightY = 0;

      break;
      
    case Direction::East:
    
      horizon3Plus = (myHero->getX() + 3 >= 0);
      horizon2Plus = (myHero->getX() + 2 >= 0);
      
      farFrontX = 3;      farFrontY = 0;
      farLeftX = 2;       farLeftY = -1;
      farRightX = 2;      farRightY = 1;

      middleFrontX = 2;   middleFrontY = 0;
      middleLeftX = 1;    middleLeftY = -1;
      middleRightX = 1;   middleRightY = 1;

      closeFrontX = 1;    closeFrontY = 0;
      closeLeftX = 0;     closeLeftY = -1;
      closeRightX = 0;    closeRightY = 1;

      break;

    case Direction::South:
    
      horizon3Plus = (myHero->getY() + 3 >= 0);
      horizon2Plus = (myHero->getY() + 2 >= 0);

      farFrontX = 0;      farFrontY = 3;
      farLeftX = 1;       farLeftY = 2;
      farRightX = -1;     farRightY = 2;

      middleFrontX = 0;   middleFrontY = 2;
      middleLeftX = 1;    middleLeftY = 1;
      middleRightX = -1;  middleRightY = 1;

      closeFrontX = 0;    closeFrontY = 1;
      closeLeftX = 1;     closeLeftY = 0;
      closeRightX = -1;   closeRightY = 0;

      break;
      
    case Direction::West:
    
      horizon3Plus = (myHero->getX() - 3 >= 0);
      horizon2Plus = (myHero->getX() - 2 >= 0);
      
      farFrontX = -3;     farFrontY = 0;
      farLeftX = -2;      farLeftY = 1;
      farRightX = -2;     farRightY = -1;

      middleFrontX = -2;  middleFrontY = 0;
      middleLeftX = -1;   middleLeftY = 1;
      middleRightX = -1;  middleRightY = -1;

      closeFrontX = -1;   closeFrontY = 0;
      closeLeftX = 0;     closeLeftY = 1;
      closeRightX = 0;    closeRightY = -1;

      break;    
    default: break;
      
  }

  
  arduboy.drawCompressed(0, 0, frames, WHITE);
  arduboy.drawCompressed(VISION_X_OFFSET + 1, VISION_Y_OFFSET, myLevel->getMapImages()[MAP_IMAGE_BACK], WHITE);

  
  // Far front wall ..
  
  if (horizon3Plus) {
    
    MapElement mapElement = (MapElement)myLevel->getMapElement(myHero->getX() + farFrontX, myHero->getY() + farFrontY);
    
    int8_t imageIndex = -1;
    int8_t xOffset = 29;
    int8_t yOffset = 25;

    if (mapElement > MapElement::Floor) {

      switch (mapElement) {

        case MapElement::LockedGate:
          imageIndex = MAP_IMAGE_FAR_GATE_LOCKED;
          xOffset = 27;
          yOffset = 26;
          break;

        case MapElement::LockedDoor:
          imageIndex = MAP_IMAGE_FAR_DOOR_LOCKED;
          break;
      
        case MapElement::UnlockedDoor:
          imageIndex = MAP_IMAGE_FAR_DOOR_UNLOCKED;
          break;
          
        default: break;
      
      }

      for (uint8_t i = VISION_X_OFFSET + 1; i < VISION_X_OFFSET + 62; ++i) {  
        arduboy.drawPixel(i, VISION_Y_OFFSET + 27 + (i %2), WHITE);
      }

      if (imageIndex > 0) {
        Sprites::drawOverwrite(VISION_X_OFFSET + xOffset, VISION_Y_OFFSET + yOffset, myLevel->getMapImages()[imageIndex], 0);
      }
      
    }
    
  }

 
  // Far left wall ..
  
  if (horizon2Plus) {
    if ((MapElement)myLevel->getMapElement(myHero->getX() + farLeftX, myHero->getY() + farLeftY) > MapElement::Floor) {
     Sprites::drawOverwrite(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 23, myLevel->getMapImages()[MAP_IMAGE_FAR_LEFT], 0);
    }
  }
 
  
  // Far right wall ..

  if (horizon2Plus) {
    if ((MapElement)myLevel->getMapElement(myHero->getX() + farRightX, myHero->getY() + farRightY) > MapElement::Floor) {
     Sprites::drawOverwrite(VISION_X_OFFSET + 35, VISION_Y_OFFSET + 23, myLevel->getMapImages()[MAP_IMAGE_FAR_RIGHT], 0);
    }
  }
 

  // Mid front wall ..
  
  if (horizon2Plus) {

    int8_t imageIndex = -1;
    int8_t xOffset = 24;
    int8_t yOffset = 23;

    MapElement mapElement = (MapElement)myLevel->getMapElement(myHero->getX() + middleFrontX, myHero->getY() + middleFrontY);
    
    if (mapElement > MapElement::Floor) {

      switch (mapElement) {

        case MapElement::LockedGate:
          imageIndex = MAP_IMAGE_MID_GATE_LOCKED;
          xOffset = 24;
          yOffset = 23;
          break;

        case MapElement::LockedDoor:
          imageIndex = MAP_IMAGE_MID_DOOR_LOCKED;
          xOffset = 27;
          yOffset = 25;
          break;
    
        case MapElement::UnlockedDoor:
          imageIndex = MAP_IMAGE_MID_DOOR_UNLOCKED;
          xOffset = 27;
          yOffset = 25;
          break;
        default: break;
      
      }
      
      Sprites::drawOverwrite(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 23, myLevel->getMapImages()[MAP_IMAGE_MID_FRONT], 0);

      if (imageIndex > 0) {
        Sprites::drawOverwrite(VISION_X_OFFSET + xOffset, VISION_Y_OFFSET + yOffset, myLevel->getMapImages()[imageIndex], 0);
      }
  
    } 

  }


  // Mid left wall ..
  
  MapElement mapElement = myLevel->getMapElement(myHero->getX() + middleLeftX, myHero->getY() + middleLeftY);
  if (mapElement == MapElement::Wall) {
    Sprites::drawOverwrite(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 14, myLevel->getMapImages()[MAP_IMAGE_MID_LEFT], 0);    
  }
  else if (mapElement == MapElement::LockedGate) {
    Sprites::drawOverwrite(VISION_X_OFFSET + 15, VISION_Y_OFFSET + 15, myLevel->getMapImages()[MAP_IMAGE_MID_GATE_LEFT], 0);    
  }

  // Mid right wall ..
  
  mapElement = myLevel->getMapElement(myHero->getX() + middleRightX, myHero->getY() + middleRightY);
  if (mapElement == MapElement::Wall) {
    Sprites::drawOverwrite(VISION_X_OFFSET + 39, VISION_Y_OFFSET + 14, myLevel->getMapImages()[MAP_IMAGE_MID_RIGHT], 0);    
  }
  else if (mapElement == MapElement::LockedGate) {
    Sprites::drawOverwrite(VISION_X_OFFSET + 39, VISION_Y_OFFSET + 15, myLevel->getMapImages()[MAP_IMAGE_MID_GATE_RIGHT], 0);    
  }
  

  // Close front wall ..
  
  mapElement = (MapElement)myLevel->getMapElement(myHero->getX() + closeFrontX, myHero->getY() + closeFrontY);
  
  if (mapElement > MapElement::Floor) {

    int8_t imageIndex = -1;
    int8_t xOffset = 0;
    int8_t yOffset = 0;
  
    switch (mapElement) {

      case MapElement::Wall:
        imageIndex = MAP_IMAGE_CLOSE_FRONT;
        xOffset = 0;
        yOffset = 14;
        break;

      case MapElement::LockedGate:
        imageIndex = MAP_IMAGE_CLOSE_GATE_LOCKED;
        xOffset = 15;
        yOffset = 14;
        break;

      case MapElement::LockedDoor:
        imageIndex = MAP_IMAGE_CLOSE_DOOR_LOCKED;
        xOffset = 22;
        yOffset = 21;
        break;

      case MapElement::UnlockedDoor:
        imageIndex = MAP_IMAGE_CLOSE_DOOR_UNLOCKED;
        xOffset = 22;
        yOffset = 21;
        break;
      default: break;
    
    }

    Sprites::drawOverwrite(VISION_X_OFFSET, VISION_Y_OFFSET + 14, closeWallFront, 0);
    if (imageIndex >= 0) {
      Sprites::drawOverwrite(VISION_X_OFFSET + xOffset, VISION_Y_OFFSET + yOffset, myLevel->getMapImages()[imageIndex], 0);
    }

  }


  // Close left wall ..

  mapElement = myLevel->getMapElement(myHero->getX() + closeLeftX, myHero->getY() + closeLeftY);
  if (mapElement == MapElement::Wall) {
    Sprites::drawOverwrite(VISION_X_OFFSET, VISION_Y_OFFSET, myLevel->getMapImages()[MAP_IMAGE_CLOSE_LEFT], 0);
  }
  else if (mapElement == MapElement::LockedGate) {
    Sprites::drawOverwrite(VISION_X_OFFSET, VISION_Y_OFFSET, myLevel->getMapImages()[MAP_IMAGE_CLOSE_GATE_LEFT], 0);
  }
  

  // Close right wall ..
  
  mapElement = myLevel->getMapElement(myHero->getX() + closeRightX, myHero->getY() + closeRightY);
  if (mapElement == MapElement::Wall) {
    Sprites::drawOverwrite(VISION_X_OFFSET + 48, VISION_Y_OFFSET, myLevel->getMapImages()[MAP_IMAGE_CLOSE_RIGHT], 0);
  }
  else if (mapElement == MapElement::LockedGate) {
    Sprites::drawOverwrite(VISION_X_OFFSET + 49, VISION_Y_OFFSET, myLevel->getMapImages()[MAP_IMAGE_CLOSE_GATE_RIGHT], 0);
  }


  // Render enemies ..

  bool renderEnemy = false;

  for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {  

    if (enemies[i].getEnabled()) {

      uint8_t selector = static_cast<uint8_t>(myHero->getDirection());

      int8_t offsetX = offsetXTable[selector];
      int8_t offsetY = offsetYTable[selector];

      if (enemies[i].getX() == myHero->getX() + offsetX && enemies[i].getY() == myHero->getY() + offsetY) {

        uint8_t enemyType = (uint8_t)enemies[i].getEnemyType();
        arduboy.drawCompressed(enemy_offset[enemyType].x, enemy_offset[enemyType].y, enemy_masks[enemyType], BLACK);
        arduboy.drawCompressed(enemy_offset[enemyType].x, enemy_offset[enemyType].y, enemy_images[enemyType], WHITE);
        if (gameState == GameState::Move) gameState = GameState::Battle_EnemyAttacks_Init;
        renderEnemy = true;
        break;

      }
            
    }
         
  }


  // Render items if no enemy has been rendered .. 

  if (!renderEnemy && (gameState == GameState::Move || gameState == GameState::ItemSelect)) {
    
    for (uint8_t i = 0; i < NUMBER_OF_ITEMS; ++i) {  

      if (items[i].getEnabled()) {

        uint8_t selector = static_cast<uint8_t>(myHero->getDirection());

        int8_t offsetX = offsetXTable[selector];
        int8_t offsetY = offsetYTable[selector];

        if (items[i].getX() == myHero->getX() + offsetX && items[i].getY() == myHero->getY() + offsetY) {

          arduboy.fillRect(14, 11, 41, 43, BLACK);
          arduboy.fillRect(15, 12, 39, 41, WHITE);
          arduboy.drawCompressed(item_offset[(uint8_t)items[i].getItemType()].x, item_offset[(uint8_t)items[i].getItemType()].y, item_images[(uint8_t)items[i].getItemType()], BLACK);

          font3x5.setTextColor(BLACK);
          font3x5.setCursor(17, 12);
          font3x5.print(F("YOU FOUND"));
          font3x5.setCursor(17, 46);
          
          switch (items[i].getItemType()) {
        
            case ItemType::Key:
              font3x5.print(F("SOME KEYS"));
              break;
        
            case ItemType::Potion:
              font3x5.print(F("HP POTION"));
              break;
        
            case ItemType::Scroll:
              font3x5.print(F("A SCROLL"));
              break;
            default: break;

          }

          font3x5.setTextColor(WHITE);
          renderEnemy = true;
          gameState = GameState::ItemSelect; 
          savedItem = i;
          break;

        }
              
      }
          
    }

  }

}


#define MAP_X_OFFSET   98
#define MAP_Y_OFFSET   6

void drawMapAndStatistics(Player *player, Level *myLevel) {

  uint8_t drawX = 0;
  uint8_t drawY = 0;

  bool renderMapElement = false;

  for (int16_t mapY = player->getY() - 3; mapY <= player->getY() + 3; ++mapY) {

    for (int16_t mapX = player->getX() - 2; mapX <= player->getX() + 2; ++mapX) {

      if (mapX >= 0 && mapX < ((int16_t)myLevel->getWidth() * MAP_TILE_WIDTH) && mapY >= 0 && mapY < ((int16_t)myLevel->getHeight() * MAP_TILE_HEIGHT) && !(drawX == 4 && drawY == 0) ) { 
        
        MapElement element = myLevel->getMapElement(mapX, mapY);

        if (element != MapElement::Wall) {
          
          
          // Is there an enemy standing here ?
          
          renderMapElement = true;
          
          for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {  
        
            if (enemies[i].getEnabled() && enemies[i].getX() == mapX && enemies[i].getY() == mapY) {

              Sprites::drawSelfMasked(MAP_X_OFFSET + (drawX * TILE_OFFSET), MAP_Y_OFFSET + (drawY * TILE_OFFSET), enemyMap, 0);
              renderMapElement = false;
              break;
                    
            }
                 
          }
          
          
          // Is there an item standing here ?
          
          if (renderMapElement) {

            for (uint8_t i = 0; i < NUMBER_OF_ITEMS; ++i) {  
          
              if (items[i].getEnabled() && items[i].getX() == mapX && items[i].getY() == mapY) {
          
                Sprites::drawSelfMasked(MAP_X_OFFSET + (drawX * TILE_OFFSET), MAP_Y_OFFSET + (drawY * TILE_OFFSET), itemMap, 0);
                renderMapElement = false;
                break;
                      
              }
                  
            }

          }

          if (renderMapElement) {
            
            switch (element) {

              case MapElement::Floor:
                arduboy.fillRect(MAP_X_OFFSET + (drawX * TILE_OFFSET), MAP_Y_OFFSET + (drawY * TILE_OFFSET), TILE_SIZE, TILE_SIZE, WHITE);
                break;

              case MapElement::LockedGate:
              case MapElement::LockedDoor:
                arduboy.fillRect(MAP_X_OFFSET + (drawX * TILE_OFFSET), MAP_Y_OFFSET + (drawY * TILE_OFFSET), TILE_SIZE, TILE_SIZE, WHITE);
                arduboy.drawLine(MAP_X_OFFSET + (drawX * TILE_OFFSET) + 1, MAP_Y_OFFSET + (drawY * TILE_OFFSET) + 1, MAP_X_OFFSET + (drawX * TILE_OFFSET) + 1, MAP_Y_OFFSET + (drawY * TILE_OFFSET) + 2, BLACK);
                break;

              case MapElement::UnlockedDoor:
                arduboy.fillRect(MAP_X_OFFSET + (drawX * TILE_OFFSET), MAP_Y_OFFSET + (drawY * TILE_OFFSET), TILE_SIZE, TILE_SIZE, WHITE);
                arduboy.drawLine(MAP_X_OFFSET + (drawX * TILE_OFFSET) + 2, MAP_Y_OFFSET + (drawY * TILE_OFFSET) + 1, MAP_X_OFFSET + (drawX * TILE_OFFSET) + 2, MAP_Y_OFFSET + (drawY * TILE_OFFSET) + 2, BLACK);
                break;
              default: break;
            
            }

          }
  
        }

      }

      drawX++;
      
    }

    drawX = 0;
    drawY++;

  }
  

  // Render player ..

  Sprites::drawExternalMask(MAP_X_OFFSET + 10, MAP_Y_OFFSET + 15, playerMap, playerMap_Mask, 0, 0);


  // Render statistics ..
  
  font3x5.setCursor(70, 8);
  font3x5.print("HP  ");
  if (player->getHitPoints() < 10) font3x5.print(" ");
  font3x5.print(player->getHitPoints());

  font3x5.print("\nDF  ");
  if (player->getDefence() < 10) font3x5.print(" ");
  font3x5.print(player->getDefence());

  font3x5.print("\nAP  ");
  if (player->getAttackPower() < 10) font3x5.print(" ");
  font3x5.print(player->getAttackPower());

  font3x5.print("\nMG  ");
  if (player->getMagic() < 10) font3x5.print(" ");
  font3x5.print(player->getMagic());

}


void drawDirectionIndicator(Player *myHero) {

  Sprites::drawSelfMasked(DIRECTION_X_OFFSET, DIRECTION_Y_OFFSET, direction_images[(uint8_t)myHero->getDirection()], 0);
  
}

void drawLevelDescription(Level *level) {

  font3x5.setCursor(80,44);
  font3x5.print(level->getTitleLine1());
  font3x5.setCursor(80,52);
  font3x5.print(level->getTitleLine2());

}

void drawEnemyHitPointsBar(uint8_t hitPoints) {

  arduboy.drawCompressed(3, 49, fight_HP_bar_Mask, BLACK);
  arduboy.drawCompressed(3, 49, fight_HP_bar, WHITE);
  arduboy.drawRect(17, 54, hitPoints, 2);  
  
}

void displaySplash() {
  
  Sprites::drawOverwrite(0, 0, splash, 0);
 
  if (splashStatus == SplashButtons::Play) {
    Sprites::drawSelfMasked(25, 54, hMarker, 0);
  }
  else {
    Sprites::drawSelfMasked(63, 54, hMarker, 0);
  }

  uint8_t buttons = arduboy.justPressedButtons();

  if (buttons & LEFT_BUTTON_MASK) {
    splashStatus = SplashButtons::Play;
  }

  if (buttons & RIGHT_BUTTON_MASK) {
    splashStatus = SplashButtons::About;
  }

  if (buttons & SELECT_BUTTON_MASK) {
    if(splashStatus == SplashButtons::Play) {
      gameState = GameState::InitGame;
    }
    if(splashStatus == SplashButtons::About) {
      gameState = GameState::About;
    }
  }

}

void displayLogo() {

  arduboy.drawCompressed(0, 0, garCol, WHITE);
  
  if (arduboy.justPressed(BACK_BUTTON)) {
    gameState = GameState::Splash;
  }

}
  
