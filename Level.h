#ifndef LEVEL_H
#define LEVEL_H

#include <Arduboy2.h>
#include "Enums.h"
#include "Player.h"
#include "MapData.h"

struct Level {

  String levelDescription="Hallway of \nthe dead";

  uint32_t startPos = 0;
  uint32_t width = 3;
  uint32_t height = 1;

  const uint8_t * level;
  const uint8_t * const * map_tiles;
  const uint8_t * const * map_images;
  const uint8_t * const * map_masks;
  
  MapElement getMapElement(uint32_t x, uint32_t y) {

    uint8_t tile = pgm_read_byte(&level[startPos + (x / MAP_TILE_WIDTH) + ((y / MAP_TILE_HEIGHT) * width)]);
    const uint8_t *tileStart = map_tiles[tile];
    uint16_t mapElement = pgm_read_byte(&tileStart[(x % MAP_TILE_WIDTH)  + ((y/8) * MAP_TILE_WIDTH)]) & (1 << (y % MAP_TILE_HEIGHT % 8));
    return (MapElement)mapElement;

  }

};

#endif
