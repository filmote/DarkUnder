

#define VISION_X_OFFSET   3
#define VISION_Y_OFFSET   4

void drawPlayerVision (Player *myHero, Level *myLevel) { //draw the walls by checking row and cols ahead of player

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
      
  }

  
  Sprites::drawOverwrite(0, 0, frames, 0);
  Sprites::drawSelfMasked(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 1, myLevel->getMapImages()[MAP_IMAGE_BACK], 0);

 
  // Far front wall ..
  
  if (horizon3Plus) {
    if ((MapElement)myLevel->getMapElement(myHero->getX() + farFrontX, myHero->getY() + farFrontY) > MapElement::Floor) {
      Sprites::drawSelfMasked(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 27, myLevel->getMapImages()[MAP_IMAGE_FAR_FRONT], 0);
    }
  }

 
  // Far left wall ..
  
  if (horizon2Plus) {
    if ((MapElement)myLevel->getMapElement(myHero->getX() + farLeftX, myHero->getY() + farLeftY) > MapElement::Floor) {
      Sprites::drawExternalMask(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 23, myLevel->getMapImages()[MAP_IMAGE_FAR_LEFT], myLevel->getMapMasks()[MAP_MASK_FAR_LEFT], 0, 0);
    }
  }
 
  
  // Far right wall ..

  if (horizon2Plus) {
    if ((MapElement)myLevel->getMapElement(myHero->getX() + farRightX, myHero->getY() + farRightY) > MapElement::Floor) {
      Sprites::drawExternalMask(VISION_X_OFFSET + 34, VISION_Y_OFFSET + 23, myLevel->getMapImages()[MAP_IMAGE_FAR_RIGHT], myLevel->getMapMasks()[MAP_MASK_FAR_RIGHT], 0, 0);
    }
  }
 

  // Mid front wall ..
  
  if (horizon2Plus) {
    if ((MapElement)myLevel->getMapElement(myHero->getX() + middleFrontX, myHero->getY() + middleFrontY) > MapElement::Floor) {
      Sprites::drawExternalMask(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 23, myLevel->getMapImages()[MAP_IMAGE_MID_FRONT], myLevel->getMapMasks()[MAP_MASK_MID_FRONT], 0, 0);
    }
  }


  // Mid left wall ..

  if ((MapElement)myLevel->getMapElement(myHero->getX() + middleLeftX, myHero->getY() + middleLeftY) > MapElement::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 14, myLevel->getMapImages()[MAP_IMAGE_MID_LEFT], myLevel->getMapMasks()[MAP_MASK_MID_LEFT], 0, 0);
  }


  // Mid right wall ..
  
  if ((MapElement)myLevel->getMapElement(myHero->getX() + middleRightX, myHero->getY() + middleRightY) > MapElement::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET + 38, VISION_Y_OFFSET + 14, myLevel->getMapImages()[MAP_IMAGE_MID_RIGHT], myLevel->getMapMasks()[MAP_MASK_MID_RIGHT], 0, 0);
  }
  

  // Close front wall ..
  
  if ((MapElement)myLevel->getMapElement(myHero->getX() + closeFrontX, myHero->getY() + closeFrontY) > MapElement::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET, VISION_Y_OFFSET + 14, myLevel->getMapImages()[MAP_IMAGE_CLOSE_FRONT], myLevel->getMapMasks()[MAP_MASK_CLOSE_FRONT], 0, 0);
  }


  // Close left wall ..

  if ((MapElement)myLevel->getMapElement(myHero->getX() + closeLeftX, myHero->getY() + closeLeftY) > MapElement::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET, VISION_Y_OFFSET, myLevel->getMapImages()[MAP_IMAGE_CLOSE_LEFT], myLevel->getMapMasks()[MAP_MASK_CLOSE_LEFT], 0, 0);
  }

  
  // Close right wall ..
  
  if (myLevel->getMapElement(myHero->getX() + closeRightX, myHero->getY() + closeRightY) > MapElement::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET + 48, VISION_Y_OFFSET, myLevel->getMapImages()[MAP_IMAGE_CLOSE_RIGHT], myLevel->getMapMasks()[MAP_MASK_CLOSE_RIGHT], 0, 0);
  }


  // Render enemies ..

  bool renderEnemy = false;

  for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {  

    if (enemies[i].getEnabled()) {

      int8_t offsetX = 0;
      int8_t offsetY = 0;
      
      switch (myHero->getDirection()) {

        case Direction::North:    offsetX =  0;  offsetY = -1;  break;
        case Direction::East:     offsetX =  1;  offsetY =  0;  break;
        case Direction::South:    offsetX =  0;  offsetY =  1;  break;
        case Direction::West:     offsetX = -1;  offsetY =  0;  break;
        
      }

      if (enemies[i].getX() == myHero->getX() + offsetX && enemies[i].getY() == myHero->getY() + offsetY) {

        uint8_t enemyType = (uint8_t)enemies[i].getEnemyType();
        Sprites::drawExternalMask(enemy_offset[enemyType].x, enemy_offset[enemyType].y, enemy_images[enemyType], enemy_masks[enemyType], 0, 0);
        renderEnemy = true;
        break;

      }
            
    }
         
  }


  // Render items if no enemy has been rendered .. 

  if (!renderEnemy) {
    
    for (uint8_t i = 0; i < NUMBER_OF_ITEMS; ++i) {  

      if (items[i].getEnabled()) {

        int8_t offsetX = 0;
        int8_t offsetY = 0;
        
        switch (myHero->getDirection()) {

          case Direction::North:    offsetX =  0;  offsetY = -1;  break;
          case Direction::East:     offsetX =  1;  offsetY =  0;  break;
          case Direction::South:    offsetX =  0;  offsetY =  1;  break;
          case Direction::West:     offsetX = -1;  offsetY =  0;  break;
          
        }

        if (items[i].getX() == myHero->getX() + offsetX && items[i].getY() == myHero->getY() + offsetY) {

          uint8_t itemType = (uint8_t)items[i].getItemType();
          arduboy.fillRect(16, 16, 32, 32, WHITE);
          Sprites::drawErase(item_offset[itemType].x, item_offset[itemType].y, item_images[itemType], 0);
          renderEnemy = true;
          break;

        }
              
      }
          
    }

  }

}




#define MAP_X_OFFSET   98
#define MAP_Y_OFFSET   6

void drawMap(Player *myHero, Level *myLevel) {

  uint8_t drawX = 0;
  uint8_t drawY = 0;

  bool renderFloor = false;

  for (int16_t mapY = myHero->getY() - 3; mapY <= myHero->getY() + 3; ++mapY) {

    for (int16_t mapX = myHero->getX() - 2; mapX <= myHero->getX() + 2; ++mapX) {

      if (mapX >= 0 && mapX < ((int16_t)myLevel->getWidth() * MAP_TILE_WIDTH) && mapY >= 0 && mapY < ((int16_t)myLevel->getHeight() * MAP_TILE_HEIGHT) && !(drawX == 4 && drawY == 0) ) { 
        
        if (myLevel->getMapElement(mapX, mapY) == MapElement::Floor) {
          
          
          // Is there an enemy standing here ?
          
          renderFloor = true;
          
          for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {  
        
            if (enemies[i].getEnabled() && enemies[i].getX() == mapX && enemies[i].getY() == mapY) {
        
              Sprites::drawSelfMasked(MAP_X_OFFSET + (drawX * TILE_OFFSET), MAP_Y_OFFSET + (drawY * TILE_OFFSET), enemyMap, 0);
              renderFloor = false;
              break;
                    
            }
                 
          }
          
          
          // Is there an item standing here ?
          
          if (renderFloor) {

            for (uint8_t i = 0; i < NUMBER_OF_ITEMS; ++i) {  
          
              if (items[i].getEnabled() && items[i].getX() == mapX && items[i].getY() == mapY) {
          
                Sprites::drawSelfMasked(MAP_X_OFFSET + (drawX * TILE_OFFSET), MAP_Y_OFFSET + (drawY * TILE_OFFSET), itemMap, 0);
                renderFloor = false;
                break;
                      
              }
                  
            }

          }

          if (renderFloor) {
            
            arduboy.fillRect(MAP_X_OFFSET + (drawX * TILE_OFFSET), MAP_Y_OFFSET + (drawY * TILE_OFFSET), TILE_SIZE, TILE_SIZE, WHITE);
            
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

void drawStatistics(Player *player) {

  font3x5.setCursor(70, 8);
  font3x5.print("HP  ");
  font3x5.print(player->getHitPoints());
  font3x5.print("\nDF  ");
  font3x5.print(player->getDefence());
  font3x5.print("\nAP  ");
  font3x5.print(player->getAttackPower());
  font3x5.print("\nMG  ");
  font3x5.print(player->getMagic());

}

void drawEnemyHitPointsBar(uint8_t hitPoints) {

  arduboy.fillRect(5, 48, 40, 12, BLACK);
  Sprites::drawSelfMasked(5, 48, fight_HP_bar, 0);
  arduboy.drawRect(19, 53, hitPoints, 2);  
  
}
