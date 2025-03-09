#include "tile.h"
#include "team.h"
#include <stdio.h>

void saveGame(Tile gameWorld[10][10], Character* playerTeam, Character* teamAI, FILE* file) {
    if (file == NULL) {
        printf("Error locating file.\n");
        return;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fwrite(&gameWorld[i][j], sizeof(Tile), 1, file);
        }
    }

    for (int i = 0; i < 4; i++) {
        fwrite(&playerTeam[i], sizeof(Character), 1, file);
    }

    for (int i = 0; i < 4; i++) {
        fwrite(&teamAI[i], sizeof(Character), 1, file);
    }

    fclose(file);
    printf("Game has been saved.\n");
}