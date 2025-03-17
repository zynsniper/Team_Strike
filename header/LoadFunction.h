#include <stdio.h>
#include "tile.h"
#include "team.h"

void loadGame(Tile gameWorld[10][10], Team* playerTeam, Team* teamAI, FILE* file) {
    if (file == NULL) {
        printf("Error locating file.\n");
        return;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fread(&gameWorld[i][j], sizeof(Tile), 1, file);
        }
    }

    playerTeam->teamName = malloc(50 * sizeof(char));
    fread(playerTeam->teamName, sizeof(char), 50, file);

    fread(playerTeam->members, sizeof(Character), 4, file);
    fread(teamAI->members, sizeof(Character), 4, file);

    printf("Save loaded successfully. Team: %s\n", playerTeam->teamName);
    fclose(file);
}

