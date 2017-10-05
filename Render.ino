

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

  switch (myHero->direction) {

    case Direction::North:
    
      horizon3Plus = (myHero->y - 3 >= 0);
      horizon2Plus = (myHero->y - 2 >= 0);

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
    
      horizon3Plus = (myHero->x + 3 >= 0);
      horizon2Plus = (myHero->x + 2 >= 0);
      
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
    
      horizon3Plus = (myHero->y + 3 >= 0);
      horizon2Plus = (myHero->y + 2 >= 0);

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
    
      horizon3Plus = (myHero->x - 3 >= 0);
      horizon2Plus = (myHero->x - 2 >= 0);
      
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
  Sprites::drawSelfMasked(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 1, myLevel->map_images[MAP_IMAGE_BACK], 0);

 
  // Far front wall ..
  
  if (horizon3Plus) {
    if ((MapElement)myLevel->getMapElement(myHero->x + farFrontX, myHero->y + farFrontY) > MapElement::Floor) {
      Sprites::drawSelfMasked(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 27, myLevel->map_images[MAP_IMAGE_FAR_FRONT], 0);
    }
  }

 
  // Far left wall ..
  
  if (horizon2Plus) {
    if ((MapElement)myLevel->getMapElement(myHero->x + farLeftX, myHero->y + farLeftY) > MapElement::Floor) {
      Sprites::drawExternalMask(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 23, myLevel->map_images[MAP_IMAGE_FAR_LEFT], myLevel->map_masks[MAP_MASK_FAR_LEFT], 0, 0);
    }
  }
 
  
  // Far right wall ..

  if (horizon2Plus) {
    if ((MapElement)myLevel->getMapElement(myHero->x + farRightX, myHero->y + farRightY) > MapElement::Floor) {
      Sprites::drawExternalMask(VISION_X_OFFSET + 34, VISION_Y_OFFSET + 23, myLevel->map_images[MAP_IMAGE_FAR_RIGHT], myLevel->map_masks[MAP_MASK_FAR_RIGHT], 0, 0);
    }
  }
 

  // Mid front wall ..
  
  if (horizon2Plus) {
    if ((MapElement)myLevel->getMapElement(myHero->x + middleFrontX, myHero->y + middleFrontY) > MapElement::Floor) {
      Sprites::drawExternalMask(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 23, myLevel->map_images[MAP_IMAGE_MID_FRONT], myLevel->map_masks[MAP_MASK_MID_FRONT], 0, 0);
    }
  }


  // Mid left wall ..

  if ((MapElement)myLevel->getMapElement(myHero->x + middleLeftX, myHero->y + middleLeftY) > MapElement::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET + 1, VISION_Y_OFFSET + 14, myLevel->map_images[MAP_IMAGE_MID_LEFT], myLevel->map_masks[MAP_MASK_MID_LEFT], 0, 0);
  }


  // Mid right wall ..
  
  if ((MapElement)myLevel->getMapElement(myHero->x + middleRightX, myHero->y + middleRightY) > MapElement::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET + 38, VISION_Y_OFFSET + 14, myLevel->map_images[MAP_IMAGE_MID_RIGHT], myLevel->map_masks[MAP_MASK_MID_RIGHT], 0, 0);
  }
  

  // Close front wall ..
  
  if ((MapElement)myLevel->getMapElement(myHero->x + closeFrontX, myHero->y + closeFrontY) > MapElement::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET, VISION_Y_OFFSET + 14, myLevel->map_images[MAP_IMAGE_CLOSE_FRONT], myLevel->map_masks[MAP_MASK_CLOSE_FRONT], 0, 0);
  }


  // Close left wall ..

  if ((MapElement)myLevel->getMapElement(myHero->x + closeLeftX, myHero->y + closeLeftY) > MapElement::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET, VISION_Y_OFFSET, myLevel->map_images[MAP_IMAGE_CLOSE_LEFT], myLevel->map_masks[MAP_MASK_CLOSE_LEFT], 0, 0);
  }

  
  // Close right wall ..
  
  if (myLevel->getMapElement(myHero->x + closeRightX, myHero->y + closeRightY) > MapElement::Floor) {
    Sprites::drawExternalMask(VISION_X_OFFSET + 48, VISION_Y_OFFSET, myLevel->map_images[MAP_IMAGE_CLOSE_RIGHT], myLevel->map_masks[MAP_MASK_CLOSE_RIGHT], 0, 0);
  }


  // Render enemies ..

  for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {  

    if (enemies[i].enabled) {

      int8_t offsetX = 0;
      int8_t offsetY = 0;
      
      switch (myHero->direction) {

        case Direction::North:    offsetX =  0;  offsetY = -1;  break;
        case Direction::East:     offsetX =  1;  offsetY =  0;  break;
        case Direction::South:    offsetX =  0;  offsetY =  1;  break;
        case Direction::West:     offsetX = -1;  offsetY =  0;  break;
        
      }

      if (enemies[i].x == myHero->x + offsetX && enemies[i].y == myHero->y + offsetY) {

        uint8_t enemyType = (uint8_t)enemies[i].enemyType;
        Sprites::drawExternalMask(enemy_offset[enemyType].x, enemy_offset[enemyType].y, enemy_images[enemyType], enemy_masks[enemyType], 0, 0);
      
      }
            
    }
         
  }
  
}




#define MAP_X_OFFSET   98
#define MAP_Y_OFFSET   6

void drawMap(Arduboy2 *arduboy, Player *myHero, Level *myLevel) {

  uint8_t drawX = 0;
  uint8_t drawY = 0;
  bool enemyFound = false;
  
  for (int16_t mapY = myHero->y - 3; mapY <= myHero->y + 3; mapY++) {

    for (int16_t mapX = myHero->x - 2; mapX <= myHero->x + 2; mapX++) {

      if (mapX >= 0 && mapX < ((int16_t)myLevel->width * MAP_TILE_WIDTH) && mapY >= 0 && mapY < ((int16_t)myLevel->height * MAP_TILE_HEIGHT) && !(drawX == 4 && drawY == 0) ) { 
        
        if (myLevel->getMapElement(mapX, mapY) == MapElement::Floor) {
          
          // Is there an enemy standing here ?
          
          enemyFound = false;
          
          for (uint8_t i = 0; i < NUMBER_OF_ENEMIES; ++i) {  
        
            if (enemies[i].enabled && enemies[i].x == mapX && enemies[i].y == mapY) {
        
              Sprites::drawSelfMasked(MAP_X_OFFSET + (drawX * TILE_OFFSET), MAP_Y_OFFSET + (drawY * TILE_OFFSET), enemyMap, 0);
              enemyFound = true;
              break;
                    
            }
                 
          }

          if (!enemyFound) {
            
            arduboy->fillRect(MAP_X_OFFSET + (drawX * TILE_OFFSET), MAP_Y_OFFSET + (drawY * TILE_OFFSET), TILE_SIZE, TILE_SIZE, WHITE);
            
          }
  
        }

      }

      drawX++;
      
    }

    drawX = 0;
    drawY++;

  }
  

  // Render player ..

  arduboy->fillRect(MAP_X_OFFSET + 11, MAP_Y_OFFSET + 16, 2, 2, BLACK);

}

#define DIRECTION_X_OFFSET 66
#define DIRECTION_Y_OFFSET 43

void drawDirectionIndicator(Player *myHero) {

  Sprites::drawSelfMasked(DIRECTION_X_OFFSET, DIRECTION_Y_OFFSET, direction_images[(uint8_t)myHero->direction], 0);
  
}
