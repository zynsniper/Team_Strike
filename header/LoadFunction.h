#include <stdio.h>
#include "tile.h"
#include "team.h"

void loadGame(Tile gameWorld[10][10], Character* team1, Character* team2, FILE* file) {
    if (file == NULL) {
        printf("Error locating file.\n");
        return;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
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

