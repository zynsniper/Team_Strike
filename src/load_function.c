#include "load_function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void loadGame(Tile gameWorld[10][10], Team* playerTeam, Team* teamAI, FILE* file) {
    if(file == NULL){
        printf("Error: Invalid file pointer\n");
        return;
    }

    char line[256];
    int i, j;

    while(fgets(line, sizeof(line), file)){
        if(strstr(line, "GAME WORLD:")) break;
    }

    for(i = 0; i < 10; i++){
        if(!fgets(line, sizeof(line), file)){
            printf("Error reading map data\n");
            return;
        }
        
        for(j = 0; j < 10; j++){
            gameWorld[i][j].type = line[j*2];
        }
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "PLAYER TEAM:")) break;
    }

    if (!fgets(line, sizeof(line), file)) {
        printf("Error reading team name\n");
        return;
    }
    
    char* nameStart = strchr(line, ':');
    nameStart += 2;
    
    nameStart[strcspn(nameStart, "\n")] = '\0';
    
    if(playerTeam->teamName){
        free(playerTeam->teamName);
    }
    
    playerTeam->teamName = strdup(nameStart);
    if(!playerTeam->teamName){
        printf("Memory allocation failed for team name\n");
        return;
    }

    for(i = 0; i < 4; i++){
        if(!fgets(line, sizeof(line), file)){
            printf("Error reading character header\n");
            return;
        }
        
        // Read health
        if (!fgets(line, sizeof(line), file)){
            printf("Error reading health\n");
            return;
        }
        sscanf(line, "  Health: %d", &playerTeam->members[i]->health);
        
        // Read attack
        if (!fgets(line, sizeof(line), file)){
            printf("Error reading attack\n");
            return;
        }
        sscanf(line, "  Attack: %d", &playerTeam->members[i]->attack);
        
        // Read position
        if (!fgets(line, sizeof(line), file)){
            printf("Error reading position\n");
            return;
        }
        sscanf(line, "  Position: (%d, %d)",  &playerTeam->members[i]->pos[0], &playerTeam->members[i]->pos[1]);
    }

    while(fgets(line, sizeof(line), file)){
        if(strstr(line, "AI TEAM:")){
            break;
        }
    }

    fgets(line, sizeof(line), file);

    for (i = 0; i < 4; i++){
        fgets(line, sizeof(line), file);
        fgets(line, sizeof(line), file);
        sscanf(line, "  Health: %d", &teamAI->members[i]->health);
        fgets(line, sizeof(line), file);
        sscanf(line, "  Attack: %d", &teamAI->members[i]->attack);
        
        // Read position
        fgets(line, sizeof(line), file);
        sscanf(line, "  Position: (%d, %d)", &teamAI->members[i]->pos[0], &teamAI->members[i]->pos[1]);
    }

    printf("Game loaded successfully\n");
}