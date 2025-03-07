#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "team.h"
#include "tile.h"
#include "SaveFunction.c"


/*void saveGame(Tile gameWorld[MAX_ROWS][MAX_COLS], Character*
team1, Character* team2, FILE* file){

}

void loadGame(Tile gameWorld[MAX_ROWS][MAX_COLS], Character*
team1, Character* team2, FILE* file){

}*/

int main(int argc, char ** argv){
    Team teamAI;
    teamAI.teamName = "AI";
    int num_char = 0;
    while(num_char < 4 ){
        if(num_char%2 == 0 ){
            teamAI.members[num_char].health = 28;
            teamAI.members[num_char].attack = 2;
        }
        else{
            teamAI.members[num_char].health = 15;
            teamAI.members[num_char].attack = 5;
        }
        teamAI.members[num_char].pos[0] = (num_char *2) ;
        teamAI.members[num_char].pos[1] = (num_char %2) + 1;
        num_char++; 
    }

    printf("Welcome to Team Strike!\n");
    int MAX_COLS = 10; //map is always 10x10
    int MAX_ROWS = 10;
    
    Tile gameMap[MAX_ROWS][MAX_COLS];
    Tile * gameMapPointer = malloc((MAX_COLS*MAX_ROWS) * sizeof(Tile));


    for(int i = 0; i < MAX_ROWS; i++){
        for(int j = 0; j < MAX_COLS; j++){
            int randomVal = rand() % 2;

            if(randomVal == 0){
                gameMap[i][j].type = '.';
            }
            else{
                gameMap[i][j].type = 'O';
            }

            //Placing Palace
            int centerRow = MAX_ROWS/2;
            int centerCol = MAX_COLS/2;
            gameMap[centerRow][centerCol].type = 'P';
        }
    }

    for(int i = 0; i < MAX_ROWS; i++){
        for(int j = 0; j < MAX_COLS; j++){
            printf("%c ", gameMap[i][j].type);
        }
        printf("\n");
    }

    Team team1;
    printf("Please enter your team name: ");
    scanf("%s", team1.teamName);
    num_char = 0;
    while(num_char < 4){
        printf("Create character #%d in your team\n", num_char + 1); //1-based indexing for userFriendly UI
        printf("Enter HitPoints, Attack Damage and position respectively(a b c d): "); 

        scanf("%d %d %d %d", &team1.members[num_char].health, &team1.members[num_char].attack, &team1.members[num_char].pos[0], &team1.members[num_char].pos[1]); 
        num_char++; 
    }

    char input[10];
    while(1){
        printf("Enter a command {wasd to move}, save to save the game, quit to exit: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if(strcmp(input, "save") == 0){
            FILE * file = fopen("game_save.txt", "w");
            saveGame(gameMap, team1.members, team1.members, file);
        }
        else if(strcmp(input, "quit") == 0){
            printf("Exiting the game.\n");
            break;
        }
    }
}
    

