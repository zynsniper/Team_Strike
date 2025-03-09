#include <stdio.h>
#include "tile.h"

// Function definition
void printMap(Tile gameMap[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", gameMap[i][j].type);
        }
        printf("\n");
    }
}