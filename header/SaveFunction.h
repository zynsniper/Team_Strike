#include "tile.h"
#include "team.h"
#include <stdio.h>

void saveGame(Tile gameWorld[10][10], Team* playerTeam, Team* teamAI, FILE* file) {
    if (file == NULL) {
        printf("Error locating file.\n");
        return;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fwrite(&gameWorld[i][j], sizeof(Tile), 1, file);
        }
    }

    fwrite(playerTeam->teamName, sizeof(char), 50, file);
    fwrite(teamAI->teamName, sizeof(char), 50, file);

    fwrite(playerTeam->teamName, sizeof(Character), 4, file);
    fwrite(teamAI->teamName, sizeof(Character), 4, file);

    fclose(file);
    printf("Game has been saved.\n");
}