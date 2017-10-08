#include <Arduboy2.h>
#include "Level.h"
#include "Enums.h"
#include "MapData.h"
#include "Item.h"

Level::Level() {}

const uint32_t Level::getStartPos()                         { return _startPos; }
const uint32_t Level::getWidth()                            { return _width; }
const uint32_t Level::getHeight()                           { return _height; }

const uint8_t * Level::getLevel()                           { return _level; }
const uint8_t * const * Level::getMapTiles()                { return _map_tiles; }
const uint8_t * const * Level::getMapImages()               { return _map_images; }
const uint8_t * const * Level::getMapMasks()                { return _map_masks; }

char * Level::getTitleLine1()                               { return _titleLine1; }
char * Level::getTitleLine2()                               { return _titleLine2; }

void Level::setStartPos(const uint32_t value)               { _startPos = value; }
void Level::setWidth(const uint32_t value)                  { _width = value; }
void Level::setHeight(const uint32_t value)                 { _height = value; }

void Level::setLevel(const uint8_t *value)                  { _level = value; }
void Level::setMapTiles(const uint8_t * const *value)       { _map_tiles = value; }
void Level::setMapImages(const uint8_t * const *value)      { _map_images = value; }
void Level::setMapMasks(const uint8_t * const *value)       { _map_masks = value; }
  
const MapElement Level::getMapElement(uint32_t x, uint32_t y) {

  uint8_t tile = pgm_read_byte(&_level[_startPos + (x / MAP_TILE_WIDTH) + ((y / MAP_TILE_HEIGHT) * _width)]);
  const uint8_t *tileStart = _map_tiles[tile];
  uint16_t mapElement = pgm_read_byte(&tileStart[(x % MAP_TILE_WIDTH)  + ((y/8) * MAP_TILE_WIDTH)]) & (1 << (y % MAP_TILE_HEIGHT % 8));
  return (MapElement)mapElement;

}
