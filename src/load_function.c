#include "load_function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void loadGame(Tile gameWorld[10][10], Team* playerTeam, Team* teamAI, FILE* file) {
    if (file == NULL) {
        printf("Error: Invalid file pointer\n");
        return;
    }

    char line[256];
    int i, j;

    // Skip to GAME WORLD section
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "GAME WORLD:")) break;
    }

    // Read game world tiles
    for (i = 0; i < 10; i++) {
        if (!fgets(line, sizeof(line), file)) {
            printf("Error reading map data\n");
            return;
        }
        
        for (j = 0; j < 10; j++) {
            // Each tile is followed by a space in the save file
            gameWorld[i][j].type = line[j*2];
        }
    }

    // Skip to PLAYER TEAM section
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "PLAYER TEAM:")) break;
    }

    // Read player team name
    if (!fgets(line, sizeof(line), file)) {
        printf("Error reading team name\n");
        return;
    }
    
    // Extract team name (skip "Team Name: ")
    char* nameStart = strchr(line, ':');
    if (!nameStart) {
        printf("Invalid team name format\n");
        return;
    }
    nameStart += 2; // Skip ": "
    
    // Remove trailing newline
    nameStart[strcspn(nameStart, "\n")] = '\0';
    
    // Allocate memory for team name
    if (playerTeam->teamName) free(playerTeam->teamName);
    playerTeam->teamName = strdup(nameStart);
    if (!playerTeam->teamName) {
        printf("Memory allocation failed for team name\n");
        return;
    }

    // Read player characters
    for (i = 0; i < 4; i++) {
        // Skip character header
        if (!fgets(line, sizeof(line), file)) {
            printf("Error reading character header\n");
            return;
        }
        
        // Read health
        if (!fgets(line, sizeof(line), file)) {
            printf("Error reading health\n");
            return;
        }
        sscanf(line, "  Health: %d", &playerTeam->members[i]->health);
        
        // Read attack
        if (!fgets(line, sizeof(line), file)) {
            printf("Error reading attack\n");
            return;
        }
        sscanf(line, "  Attack: %d", &playerTeam->members[i]->attack);
        
        // Read position
        if (!fgets(line, sizeof(line), file)) {
            printf("Error reading position\n");
            return;
        }
        sscanf(line, "  Position: (%d, %d)", 
              &playerTeam->members[i]->pos[0],
              &playerTeam->members[i]->pos[1]);
    }

    // Skip to AI TEAM section
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "AI TEAM:")) break;
    }

    // Read AI team name (we'll skip this as AI team name is constant)
    fgets(line, sizeof(line), file);

    // Read AI characters
    for (i = 0; i < 4; i++) {
        // Skip character header
        fgets(line, sizeof(line), file);
        
        // Read health
        fgets(line, sizeof(line), file);
        sscanf(line, "  Health: %d", &teamAI->members[i]->health);
        
        // Read attack
        fgets(line, sizeof(line), file);
        sscanf(line, "  Attack: %d", &teamAI->members[i]->attack);
        
        // Read position
        fgets(line, sizeof(line), file);
        sscanf(line, "  Position: (%d, %d)", 
              &teamAI->members[i]->pos[0],
              &teamAI->members[i]->pos[1]);
    }

    printf("Game loaded successfully\n");
}