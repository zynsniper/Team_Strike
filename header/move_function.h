#ifndef MOVE_FUNCTION_H
#define MOVE_FUNCTION_H
#include <stdio.h>
#include "tile.h"
#include "team.h"

void moveRight(Team* team, Tile gameMap [10][10], int character);
void moveLeft(Team* team, Tile gameMap [10][10], int character);
void moveUp(Team* team, Tile gameMap [10][10], int character);
void moveDown(Team* team, Tile gameMap [10][10], int character);

#endif