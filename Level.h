#ifndef LEVEL_H
#define LEVEL_H

#include <Arduboy2.h>
#include "Enums.h"
#include "MapData.h"

class Level {

  public:

    Level();
    const MapElement getMapElement(uint32_t x, uint32_t y);
    void loadTile(Rotation rotation, uint8_t tileNumber, const uint8_t *a);

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

    void rotate180(const uint8_t *a);
    void rotate0(const uint8_t *a);
    void rotate(bool ccw, const uint8_t *a);
    
    uint32_t _startPos;
    uint32_t _width;
    uint32_t _height;

    uint32_t _tileNumber;
    uint8_t _tileData[32];

    char _titleLine1[12];
    char _titleLine2[12];
    
    const uint8_t * _level;
    const uint8_t * const * _map_tiles;
    const uint8_t * const * _map_images;
    const uint8_t * const * _map_masks;

};

#endif
