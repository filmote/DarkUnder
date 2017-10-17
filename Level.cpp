#include <Arduboy2.h>
#include "Level.h"
#include "Enums.h"
#include "MapData.h"

#define reverseBits(b) (((b)&1?128:0)|((b)&2?64:0)|((b)&4?32:0)|((b)&8?16:0)|((b)&16?8:0)|((b)&32?4:0)|((b)&64?2:0)|((b)&128?1:0))

Level::Level() {_tileNumber = 255; }

const uint32_t Level::getStartPos()                         { return _startPos; }
const uint32_t Level::getWidth()                            { return _width; }
const uint32_t Level::getHeight()                           { return _height; }
const Item * Level::getDoors()                              { return _doors; }

const uint8_t * Level::getLevel()                           { return _level; }
const uint8_t * const * Level::getMapTiles()                { return _map_tiles; }
const uint8_t * const * Level::getMapImages()               { return _map_images; }

#ifdef WALL_STYLE_1
const uint8_t * const * Level::getMapMasks()                { return _map_masks; }
#endif

char * Level::getTitleLine1()                               { return _titleLine1; }
char * Level::getTitleLine2()                               { return _titleLine2; }

void Level::setDoors(const Item *value)                     { _doors = value; }
void Level::setStartPos(const uint32_t value)               { _startPos = value; }
void Level::setWidth(const uint32_t value)                  { _width = value; }
void Level::setHeight(const uint32_t value)                 { _height = value; }

void Level::setLevel(const uint8_t *value)                  { _level = value; }
void Level::setMapTiles(const uint8_t * const *value)       { _map_tiles = value; }
void Level::setMapImages(const uint8_t * const *value)      { _map_images = value; }

#ifdef WALL_STYLE_1
void Level::setMapMasks(const uint8_t * const *value)       { _map_masks = value; }
#endif
  
const MapElement Level::getMapElement(uint32_t x, uint32_t y) {

  for (uint8_t i = 0; i < NUMBER_OF_DOORS; ++i) {

    if (_doors[i].getEnabled() && _doors[i].getX() == x && _doors[i].getY() == y) {

      return (MapElement)((uint8_t)_doors[i].getItemType());

    }

  }

  uint8_t tileNumber = pgm_read_byte(&_level[_startPos + (x / MAP_TILE_WIDTH) + ((y / MAP_TILE_HEIGHT) * _width)]);

  loadTile((Rotation)(tileNumber & 0xC0), tileNumber, _map_tiles[(tileNumber & 0x3F)]);
  uint16_t mapElement = _tileData[(x % MAP_TILE_WIDTH) + (((y % MAP_TILE_HEIGHT) / 8) * MAP_TILE_PHYSICAL_WIDTH)] & (1 << (y % MAP_TILE_HEIGHT % 8));

  return (MapElement)mapElement;

}

void Level::rotate(bool ccw, const uint8_t *a) {

  memset(_tileData, 0, 32);

  uint16_t bit = (ccw ? 128 : 1);
  uint8_t outputIdx = (ccw ? 16 : 0);

  for (uint8_t inputIdx = 0; inputIdx < 16; ++inputIdx) {
  
    uint8_t y1 = (ccw ? pgm_read_byte(&a[inputIdx]) : reverseBits(pgm_read_byte(&a[inputIdx + 16])));
    uint8_t y2 = (ccw ? pgm_read_byte(&a[inputIdx + 16]) : reverseBits(pgm_read_byte(&a[inputIdx])));

    for (uint8_t x = 0, s = 1; x < 8; ++x, s <<= 1) {
      _tileData[outputIdx + x] = _tileData[outputIdx + x] | ((y1 & s) > 0 ? bit : 0);
      _tileData[outputIdx + 8 + x] = _tileData[outputIdx + 8 + x] | ((y2 & s) > 0 ? bit : 0);
    }

    if (ccw) {
    
      bit = bit >> 1;
      if (bit == 0) { 
        bit = 128;
        outputIdx = outputIdx - 16;
      }
    
    }
    else {
    
      bit = bit << 1;
      if (bit == 256) { 
        bit = 1;
        outputIdx = outputIdx + 16;
      }
    
    }

  }

  if (ccw) {
    
    for (uint8_t x = 0; x < 16; ++x) {
      
      _tileData[x] = (_tileData[x] >> 1) | ((_tileData[x + 16] & 1) << 7);
      _tileData[x + 16] = (_tileData[x + 16] >> 1);
      
    }

  }
  else {

    for (uint8_t x = 0; x < 15; ++x) {
      _tileData[x] = _tileData[x + 1];
      _tileData[x + 16] = _tileData[x + 17];
    }
   
  }

}

void Level::rotate180(const uint8_t *a) {

  for (uint8_t x = 0; x < 32; ++x) {
  
    _tileData[31 - x] = reverseBits(pgm_read_byte(&a[x]));

  }

  for (uint8_t x = 0; x < 15; ++x) {
    
    _tileData[x] = (_tileData[x + 1] >> 1) | ((_tileData[x + 17] & 1) << 7);
    _tileData[x + 16] = (_tileData[x + 17] >> 1);

  }

}

void Level::rotate0(const uint8_t *a) {
 
  for (uint8_t x = 0; x < 16; ++x) {

    _tileData[x] = pgm_read_byte(&a[x]);
    _tileData[x + 16] = pgm_read_byte(&a[x + 16]);
    
  }

}

void Level::loadTile(Rotation rotation, uint8_t tileNumber, const uint8_t *a) {

  if (tileNumber != _tileNumber) {
    
    switch (rotation) {

      case Rotation::Rotation_0:
        Level::rotate0(a);
        break;

      case Rotation::Rotation_90:
        Level::rotate(false, a);
        break;

      case Rotation::Rotation_180:
        Level::rotate180(a);
        break;

      case Rotation::Rotation_270:
        Level::rotate(true, a);
        break;

    }

  }

  _tileNumber = tileNumber;

}