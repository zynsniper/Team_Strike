#include <stdio.h>
#include "tile.h"
#include <stdlib.h>

// Function definition
void printMap(Tile gameMap[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", gameMap[j][i].type);
        }
        printf("\n");
    }
}

void generateMap(Tile gameMap[10][10]){
    for(int i = 0; i < 10; i++){
        for(int b = 0; b < 10; b++){
            int randomVal = rand() % 2;
            gameMap[i][b].type = '.';
            
            if(randomVal == 0)
                gameMap[i][b].type = '.';
            else
                gameMap[i][b].type = 'O';        
        }

        //Placing Palace in center
        gameMap[5][5].type = 'P';
    }
}