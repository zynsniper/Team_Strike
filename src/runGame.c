#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "team.h"
#include "tile.h"
#include "SaveFunction.h"
#include "LoadFunction.h"
#include "MoveFunction.h"
#include "printMap.h"

int main(int argc, char ** argv){
    printf("Welcome to Team Strike!\nEnemy Stats:\n");

    //Generate Enemy Team*******************************
    Team teamAI;
    teamAI.teamName = "AI";
    int num_char = 0;
    while(num_char < 4 ){
        printf("Character #%d\n", num_char+ 1);
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

        //(Dont show enemy position for now) teamAI.members[num_char].health
        printf("HP: %d AD: %d\n", teamAI.members[num_char].health, teamAI.members[num_char].attack);
        
        num_char++;
    }

    int MAX_COLS = 10; //map is always 10x10
    int MAX_ROWS = 10;
    Tile gameMap [MAX_ROWS][MAX_COLS];

    for(int i =0; i< MAX_ROWS; i++){
        if((num_char - i)>=0){
            for(int b =0; b< MAX_ROWS; b++){
                int randomVal = rand() % 2;

                if(randomVal == 0)
                    gameMap[i][b].type = '.';
                else
                    gameMap[i][b].type = 'O';
            }

            //Placing Palace
            int centerRow = MAX_ROWS/2;
            int centerCol = MAX_COLS/2;
            gameMap[centerRow][centerCol].type = 'P';
        }
    }

    //Print out Enemy Team represented by X
    int posX, posY;
    for(int i = 0; i < 4; i++){
        posX = teamAI.members[i].pos[0]; 
        posY = teamAI.members[i].pos[1];
        gameMap[posX][posY].type = 'X';
    }

    // Players's team
    //================================================================================================================//
    Team team1;                    
    char Name[50];
    printf("\nPlease enter your team name: ");
    scanf("%s", Name);
    team1.teamName = Name;
    num_char = 0; //Number of characters
    printf("Generating Characters for <Team %s>\n", team1.teamName); 
    while(num_char < 4){
        printf("Character #%d\n", num_char +1); //1-based indexing for userFriendly UI
         if(num_char%2 == 0 ){
            team1.members[num_char].health = 28;
            team1.members[num_char].attack = 2;
        }
        else{
            team1.members[num_char].health = 15;
            team1.members[num_char].attack = 5;
        }
        team1.members[num_char].pos[0] = (num_char %2) ;
        team1.members[num_char].pos[1] = (num_char *2) + 1;
        //Dont print out character coord, just show on map
        printf("HP: %d AD: %d\n", team1.members[num_char].health, team1.members[num_char].attack);
        num_char++; 
    }

    //Placing player's characters on the map
    for(int i = 0; i < 4; i++){
        posX = team1.members[i].pos[0]; 
        posY = team1.members[i].pos[1];
        gameMap[posX][posY].type = 'Y';
    }
    //================================================================================================================//

    printMap(gameMap);

    //User Inputs
    //================================================================================================================//
    int character;                                                
    char userInput[2];                                             
    while(1){
        printf("(p)lay, (s)ave, (l)oad or (q)uit?\n: ");
        fgets(userInput, sizeof(userInput), stdin);

        switch(userInput[0]){
            case 's':
                FILE * file = fopen("game_save", "w");
                saveGame(gameMap, team1.members, team1.members, file);
                break;

            case 'p':
                printf("Enter a Character# in Team %s to manipulate: \n", team1.teamName);
                scanf("%d", &character);
                int characterNum = character;
                if(characterNum >= 1 || characterNum <= 4){
                    printf("Now enter a command {w, a, s, d to move}: ");
                    scanf("%s", userInput);

                    //move logic
                    switch(userInput[0]){
                        case 'w':
                            moveUp(&team1, gameMap, characterNum);
                            printMap(gameMap);
                            break;

                        case 'a':
                            moveLeft(&team1, gameMap, characterNum);
                            printMap(gameMap);
                            break;

                        case 's':
                            moveDown(&team1, gameMap, characterNum);
                            printMap(gameMap);
                            break;

                        case 'd':
                            moveRight(&team1, gameMap, characterNum);
                            printMap(gameMap);
                            break;

                        default:
                            printf("Invalid command\n");
                            break;
                    }
                }
        }   
    }
}
    

