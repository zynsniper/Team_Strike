#include "map_function.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function definition
void printMap(Tile gameMap[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", gameMap[i][j].type);
        }
        printf("\n");
    }
}

void generateMap(Tile gameMap[10][10]){
    srand(time(NULL));

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            gameMap[i][j].type = '.'; 
        }
    }

    //Placing Palace in center
    gameMap[5][5].type = 'P';

    int obstacleCount = 1;
    int placedObstacles = 0;
    while(placedObstacles <= obstacleCount){
        int X = rand() % 10;
        int Y = rand() % 10;

        if(gameMap[X][Y].type == '.' && gameMap[X][Y].type != 'P'){
            gameMap[X][Y].type = 'O';
            placedObstacles++;
        }
    }
}