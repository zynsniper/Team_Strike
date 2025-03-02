#ifndef MAP_H
#define MAP_H
#include "tile.h"

typedef struct Map{
    tile tile;
    int rows;
    int cols;
}Map;

#endif
