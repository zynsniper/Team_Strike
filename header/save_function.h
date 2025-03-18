#ifndef SAVE_FUNCTION_H
#define SAVE_FUNCTION_H
#include <stdio.h>
#include "tile.h"
#include "team.h"

void save(Tile gameWorld[10][10], Team* playerTeam, Team* teamAI, FILE* file);

#endif