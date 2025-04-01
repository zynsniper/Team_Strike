#ifndef SAVE_FUNCTION_H
#define SAVE_FUNCTION_H
#include <stdio.h>
#include "tile.h"
#include "team.h"

void saveGame(Tile gameWorld[10][10], Team* playerTeam, Team* teamAI, FILE* file);

#endif