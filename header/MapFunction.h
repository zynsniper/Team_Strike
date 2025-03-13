#include <stdio.h>
#include <time.h>
#include "tile.h"
#include <stdlib.h>

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

    int obstacleCount = 20;
    for(int i = 0; i < obstacleCount; i++){
        int X = rand() % 10;
        int Y = rand() % 10;

        if(X == 5 && Y == 5){
            continue;
        }
        else{
            gameMap[X][Y].type = 'O';
        }
    }
    //Placing Palace in center
    gameMap[5][5].type = 'P';
}