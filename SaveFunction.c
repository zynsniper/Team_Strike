#include <stdio.h>
#include "map.h"
#include "team.h"

void saveGame(tile gameWorld[MAX_ROWS][MAX_COLS], character* team1, character* team2, FILE* file) {
    if (file == NULL) {
        printf("Error locating file.\n");
        return;
    }

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            fwrite(&gameWorld[i][j], sizeof(tile), 1, file);
        }
    }

    int team1_size = sizeof(team1) / sizeof(team1[0]);
    fwrite(&team1_size, sizeof(int), 1, file);
    for (int i = 0; i < team1_size; i++) {
        fwrite(&team1[i], sizeof(character), 1, file);
    }

    int team2_size = sizeof(team2) / sizeof(team2[0]);
    fwrite(&team2_size, sizeof(int), 1, file);
    for (int i = 0; i < team2_size; i++) {
        fwrite(&team2[i], sizeof(character), 1, file);
    }

    fclose(file);
}