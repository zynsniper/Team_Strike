#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "team.h"
#include "tile.h"
#include "SaveFunction.c"


int main(int argc, char ** argv){
    printf("Welcome to Team Strike!\nEnemy Stats\n");

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
         printf("Helath: %d Attack: %d Pos(x,y):(%d,%d)\n", teamAI.members[num_char].health,
            teamAI.members[num_char].attack, teamAI.members[num_char].pos[0], teamAI.members[num_char].pos[1]);
        num_char++; 
        printf("\n");
    }
    int MAX_COLS = 10; //map is always 10x10
    int MAX_ROWS = 10;
    Tile gameMap [MAX_ROWS][MAX_COLS];

    for(int i =0; i< MAX_ROWS; i++){
        if((num_char - i)>=0){
                    }
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
    //Print out Enemy Team represented by X
      int posX, posY;
    for(int i = 0; i<4; i++){
        posX = teamAI.members[i].pos[0]; 
        posY = teamAI.members[i].pos[1];
        gameMap[posX][posY].type = 'X';
    }
    Team team1;                                                      // User's team
    char  Name[50];
    printf("\nPlease enter your team name: \n");
    scanf("%s", Name);
    team1.teamName = Name;
    num_char = 0;                                                   //Number of characters
    printf("Generating Characters for Team %s\n", team1.teamName);  //1-based indexing for userFriendly UI
    while(num_char < 4){
        printf("Characters #%d Stats\n", num_char +1);              //1-based indexing for userFriendly UI
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
        printf("\nHelath: %dAttack: %d Pos(x,y):(%d,%d)\n", team1.members[num_char].health,
            team1.members[num_char].attack, team1.members[num_char].pos[0], team1.members[num_char].pos[1]);
        num_char++; 
    }
       for(int i = 0; i<4; i++){
        posX = team1.members[i].pos[0]; 
        posY = team1.members[i].pos[1];
        gameMap[posX][posY].type = 'Y';
    }
    //Print Out Game Map
    for(int i = 0; i < MAX_ROWS; i++){
        for(int j = 0; j < MAX_COLS; j++){
            printf("%c ", gameMap[i][j].type);
        }
        printf("\n");
    }
    int character;                                                  //Stores the character value to be moved
    char  ans[2];
    char move[2];                                                // character move and user answer
    while(strcmp(ans, "q") != 0){
        printf("Do you wish to (q)uit OR (s)ave OR (p)lay\n: ");
        scanf("%s", ans);
        if(strcmp(ans, "s") == 0){
            FILE * file = fopen("game_save.txt", "w");
            saveGame(gameMap, team1.members, team1.members, file);
        }
        else if(strcmp(ans, "p") == 0){
            printf("Enter a Character# in Team %s to manipulate: \n", team1.teamName);
            scanf("%d", &character);
            if(character == 1 || character== 2  || character ==3|| character == 4){
                posX = team1.members[character].pos[0]; 
                posY = team1.members[character].pos[1];
                printf("Now enter a command {w, a, s, d to move}: ");
                scanf("%s", move);
                if(strcmp(move, "w") && (posY += 1)< 10 && gameMap[posX][posY+1].type == '.' ){
                    team1.members[character].pos[1] += 1;                                                                     //Move UP
                }
                else if(strcmp(move, "a") && (posX -= 1)> 0 && gameMap[posX-1][posY].type == '.' ){
                    team1.members[character].pos[0] -= 1;                                                                     //Move Left       
                }                                                                                                            
                else if(strcmp(move, "s") && (posY -= 1)> 0 && gameMap[posX][posY -1].type == '.' ){
                    team1.members[character].pos[1] -= 1;                                                                     //Move Down
                }
                else if(strcmp(move, "d") && (posX += 1) < 10 && gameMap[posX+1][posY].type == '.' ){
                    team1.members[character].pos[0] += 1;                                                                     //Move Right 
                }
                else
                    printf("Invalid move\n");
                gameMap[posX][posY].type = 'Y';

            }
            //Print Out Game Map
            for(int i = 0; i < MAX_ROWS; i++){
                for(int j = 0; j < MAX_COLS; j++){
                    printf("%c ", gameMap[i][j].type);
                }
                printf("\n");
            }
        }
    }
}
    

