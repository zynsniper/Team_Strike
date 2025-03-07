#include <stdio.h>
#include <stdlib.h>
#include "tile.h"
#include "SaveFunction.h"

int MAX_ROWS = 10, MAX_COLS = 10; //Map currently hardcoded to 10x10

void loadGame(Tile gameWorld[MAX_ROWS][MAX_COLS], Character* team1, Character* team2, FILE* file) {
    if (file == NULL) {
        printf("Error locating file.\n");
        return;
    }

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            fread(&gameWorld[i][j], sizeof(Tile), 1, file);
        }
    }

    for (int i = 0; i < 4; i++) {
        fread(&team1[i], sizeof(Character), 1, file);
    }

    for (int i = 0; i < 4; i++) {
        fread(&team2[i], sizeof(Character), 1, file);
    }

    fclose(file);
}

