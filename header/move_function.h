#ifndef MOVE_FUNCTION_H
#define MOVE_FUNCTION_H
#include <stdio.h>
#include <stdbool.h>
#include "tile.h"
#include "team.h"

bool moveRight(Team* team, Team* enemyTeam, Tile gameMap [10][10], int character);
bool moveLeft(Team* team, Team* enemyTeam, Tile gameMap [10][10], int character);
bool moveUp(Team* team, Team* enemyTeam, Tile gameMap [10][10], int character);
bool moveDown(Team* team, Team* enemyTeam, Tile gameMap [10][10], int character);
void attack(Character * attacker, Character * defender);

#endif