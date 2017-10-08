#ifndef LEVEL_H
#define LEVEL_H

#include <Arduboy2.h>
#include "Enums.h"
#include "MapData.h"
#include "Item.h"

class Level {

  public:

    Level();
    const MapElement getMapElement(uint32_t x, uint32_t y);

    const uint32_t getStartPos();
    const uint32_t getWidth();
    const uint32_t getHeight();

    const uint8_t * getLevel();
    const uint8_t * const * getMapTiles();
    const uint8_t * const * getMapImages();
    const uint8_t * const * getMapMasks();
    char * getTitleLine1();
    char * getTitleLine2();
    
    void setStartPos(const uint32_t value);
    void setWidth(const uint32_t value);
    void setHeight(const uint32_t value);

    void setLevel(const uint8_t *value);
    void setMapTiles(const uint8_t * const *value);
    void setMapImages(const uint8_t * const *value);
    void setMapMasks(const uint8_t * const *value);

  private:

    uint32_t _startPos;
    uint32_t _width;
    uint32_t _height;
    char _titleLine1[12];
    char _titleLine2[12];
    
    const uint8_t * _level;
    const uint8_t * const * _map_tiles;
    const uint8_t * const * _map_images;
    const uint8_t * const * _map_masks;

};

#endif
