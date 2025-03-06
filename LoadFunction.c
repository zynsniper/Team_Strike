#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "team.h"

void loadGame(tile gameWorld[MAX_ROWS][MAX_COLS], character* team1, character* team2, FILE* file) {
    if (file == NULL) {
        printf("Error locating file.\n");
        return;
    }

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            fread(&gameWorld[i][j], sizeof(tile), 1, file);
        }
    }

    int team1Size, team2Size;
    fread(&team1Size, sizeof(int), 1, file);
    fread(&team2Size, sizeof(int), 1, file);

    for (int i = 0; i < team1Size; i++) {
        fread(&team1[i], sizeof(character), 1, file);
    }

    for (int i = 0; i < team2Size; i++) {
        fread(&team2[i], sizeof(character), 1, file);
    }

    fclose(file); 
}

