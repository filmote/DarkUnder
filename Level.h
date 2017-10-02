#ifndef LEVEL_H
#define LEVEL_H

#include <Arduboy2.h>
#include "Enums.h"
#include "Player.h"

struct Level {

//  int originX=108;
//  int originY=18;
  String levelDescription="Hallway of \nthe dead";
//    int  worldGrid[10][10] = {   
//    {1,1,1,1,1,1,1,1,1,1},
//    {1,0,0,0,0,0,0,0,0,1},
//    {1,0,1,1,1,0,0,0,0,1},
//    {1,0,1,0,1,0,0,0,0,1},
//    {1,0,0,0,1,0,0,0,0,1},
//    {1,1,1,0,1,0,0,0,0,1},
//    {1,0,0,0,0,0,0,0,0,1},
//    {1,0,1,1,0,1,0,1,0,1},
//    {1,0,0,1,0,1,0,1,0,1},
//    {1,1,1,1,1,1,1,1,1,1}
//     };

  uint32_t startPos = 0;
  uint32_t width = 3;
  uint32_t height = 1;

  const uint8_t * const * map_tiles;
  const uint8_t * const * map_images;
  const uint8_t * const * map_masks;
  // Level(){
  //    row=8;
  //    col=4;
  //    myHero = new Player(row, col); 
  //   // myObjects.add(new Object(3, 3, 'P'));
  //    //myObjects.add(new Object(4, 6, 'P'));
  //   // myEnemies.add(new Stalker(2, 6));
  // };
  
    MapElements getMapElement(uint32_t x, uint32_t y) {

      uint8_t tile = pgm_read_byte(x / MAP_TILE_WIDTH) + ((y / MAP_TILE_HEIGHT) * width);
      const uint8_t *tileStart = map_tiles[tile];

      return (MapElements)(pgm_read_byte(tileStart + (x % MAP_TILE_WIDTH) + (((y % MAP_TILE_HEIGHT) / 8) * width)) & (1 << ((y % MAP_TILE_HEIGHT) % 8)));
      
    }

};

#endif
