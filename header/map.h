#ifndef MAP_H
#define MAP_H
#include "tile.h"

typedef struct Map{
    int MAX_ROWS;
    int MAX_COLS;
    Tile * gameWorld[][];
}Map;

#endif

//Obsolete header. DO NOT USE