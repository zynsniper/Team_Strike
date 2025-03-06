#include <stdio.h>
#include "tile.h"
#include "team.h"

int MAX_ROWS = 10, MAX_COLS = 10; //Map currently hardcoded to 10x10

void saveGame(Tile gameWorld[MAX_ROWS][MAX_COLS], Character* team1, Character* team2, FILE* file) {
    if (file == NULL) {
        printf("Error locating file.\n");
        return;
    }

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            fwrite(&gameWorld[i][j], sizeof(Tile), 1, file);
        }
    }

    for (int i = 0; i < 4; i++) {
        fwrite(&team1[i], sizeof(Character), 1, file);
    }

    for (int i = 0; i < 4; i++) {
        fwrite(&team2[i], sizeof(Character), 1, file);
    }

    fclose(file);
}