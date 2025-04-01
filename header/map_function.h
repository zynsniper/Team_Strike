#ifndef MAP_FUNCTION_H
#define MAP_FUNCTION_H
#include "tile.h"
#include "palace.h"

// Function definition
void printMap(Tile gameMap[10][10], Palace * palace);
void generateMap(Tile gameMap[10][10], Palace * palace);

#endif