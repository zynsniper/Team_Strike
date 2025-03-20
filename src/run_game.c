#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "team.h"
#include "tile.h"
#include "save_function.h"
#include "load_function.h"
#include "move_function.h"
#include "map_function.h"


int main(int argc, char ** argv){
    printf("Welcome to Team Strike!\nEnemy Stats:\n");

    //Generate Enemy Team(AI)
    //================================================================================================================//
    Team * teamAI = malloc(sizeof(Team));
    teamAI->teamName = "AI";
    int num_char = 0;
    while(num_char < 4 ){
        printf("Character #%d\n", num_char+ 1);
        if(num_char%2 == 0 ){
            teamAI->members[num_char].health = 28;
            teamAI->members[num_char].attack = 2;
        }
        else{
            teamAI->members[num_char].health = 15;
            teamAI->members[num_char].attack = 5;
        }
        teamAI->members[num_char].pos[0] = (num_char *2) ;
        teamAI->members[num_char].pos[1] = (num_char %2) + 1;

        //Dont print enemy coordinate
        printf("HP: %d AD: %d\n", teamAI->members[num_char].health, teamAI->members[num_char].attack);
        
        num_char++;
    }

    int MAX_COLS = 10; //map is always 10x10
    int MAX_ROWS = 10;
    Tile gameMap [MAX_ROWS][MAX_COLS];
    generateMap(gameMap);

    //Print out Enemy Team represented by X
    int posX, posY;
    for(int i = 0; i < 4; i++){
        posX = teamAI->members[i].pos[0]; 
        posY = teamAI->members[i].pos[1];
        gameMap[posX][posY].type = 'X';
    }

    // Players's team
    //================================================================================================================//
    Team * team1 = malloc(sizeof(Team));                   
    char Name[50];
    printf("\nPlease enter your team name: ");
    scanf("%s", Name);
    team1->teamName = Name;
    num_char = 0; //Number of characters
    printf("Generating Characters for <Team %s>\n", team1->teamName); 
    while(num_char < 4){
        printf("Character #%d\n", num_char +1); //1-based indexing for userFriendly UI
         if(num_char%2 == 0 ){
            team1->members[num_char].health = 28;
            team1->members[num_char].attack = 2;
        }
        else{
            team1->members[num_char].health = 15;
            team1->members[num_char].attack = 5;
        }
        team1->members[num_char].pos[0] = (num_char %2) ;
        team1->members[num_char].pos[1] = (num_char *2) + 1;
        //Dont print out character coord, just show on map
        printf("HP: %d AD: %d\n", team1->members[num_char].health, team1->members[num_char].attack);
        num_char++; 
    }

    //Placing player's characters on the map
    for(int i = 0; i < 4; i++){
        posX = team1->members[i].pos[0]; 
        posY = team1->members[i].pos[1];
        gameMap[posX][posY].type = '1' + i;
    }
    //================================================================================================================//

    printMap(gameMap);

    //User Inputs
    //================================================================================================================//                                             
    char userInput[2];
    bool inMovementMode = false;

    while(1){
        if(!inMovementMode){
            printf("(p)lay, (s)ave, (l)oad or (q)uit?: \n");
            scanf(" %c", &userInput[0]);
        
            if(userInput[0] == 'p'){
                inMovementMode = true;
            }
            else if(userInput[0] == 'q'){
                printf("Exiting game.\n");
                return 0;
            }
            else if(userInput[0] == 's'){
                char saveName[100];
                printf("Enter save name: ");
                scanf("%99s", &saveName[0]);
                FILE * file = fopen(saveName, "w");
                saveGame(gameMap, team1, teamAI, file); 
            }
            else if(userInput[0] == 'l'){
                char saveName[100];
                printf("Enter save name: ");
                scanf("%99s", &saveName[0]);
                FILE * file = fopen(saveName, "r");
                loadGame(gameMap, team1, teamAI, file);
                printMap(gameMap);
            }
        }
        else{
            printf("Select which character to move (or q to return): ");
            scanf(" %c", &userInput[0]);
            getchar();

            if(userInput[0] == 'q'){
                inMovementMode = false;
                continue;
            }

            if(userInput[0] >= '1' && userInput[0] <= '4'){
                char character = userInput[0] - '0';

                printf("Now enter a command {w, a, s, d to move}: ");
                scanf(" %c", &userInput[0]);

                if(userInput[0] == 'q'){
                    inMovementMode = false;
                    continue;
                }

                //move logic
                switch(userInput[0]){
                    case 'w':
                        moveUp(team1, teamAI, gameMap, character);
                        printMap(gameMap);
                        break;

                    case 'a':
                        moveLeft(team1, teamAI, gameMap, character);
                        printMap(gameMap);
                        break;

                    case 's':
                        moveDown(team1, teamAI, gameMap, character);
                        printMap(gameMap);
                        break;

                    case 'd':
                        moveRight(team1, teamAI, gameMap, character);
                        printMap(gameMap);
                        break;

                    default:
                        printf("Invalid movement command\n");
                        break;
                }
            }
            else{
                printf("Invalid character selected.\n");
            }
        }   
    }
}
    

