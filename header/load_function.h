#ifndef LOAD_FUNCTION_H
#define LOAD_FUNCTION_H
#include <stdio.h>
#include "tile.h"
#include "team.h"

void loadGame(Tile gameWorld[10][10], Team* playerTeam, Team* teamAI, FILE* file);

#endif