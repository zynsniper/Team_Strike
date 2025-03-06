#include <stdlib.h>
#include <stdio.h>
#include "team.h"
#include "tile.h"


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
    while(num_char <4){
        if(num_char%2 ==0 ){
            teamAI.members[num_char].health = 28;
            teamAI.members[num_char].attack = 2;
        }
        else{
            teamAI.members[num_char].health = 15;
            teamAI.members[num_char].attack = 5;
        }
        teamAI.members[num_char].pos[0] = (num_char *2) ;
        teamAI.members[num_char].pos[1] = (num_char%2) +1;
        num_char++; 
    }
    printf("Welcome to Team Strike; Make your move !\n");
    int MAX_COLS =9 ;
    int MAX_ROWS = 9;
    
    Tile gameMap[MAX_COLS][MAX_COLS];
    Tile * gameMapPointer = malloc((MAX_COLS*MAX_ROWS) * sizeof(Tile));
    for(int i = 0; i< MAX_ROWS; i++){
        for(int b = 0; b< MAX_COLS; b++){
            if(i%2 ==0){
                gameMap[i][b].type = '.';
           
            }
            else{
                gameMap[i][b].type = 'o';
            }  
        }
    } 
    for(int i = 0; i< MAX_ROWS; i++){
        for(int b = 0; b< MAX_COLS; b++){
            printf("%c",gameMap[i][b].type);
        }
        printf("\n");
    } 


    Team team;
    printf("Welcome to Team Strike\nPlease enter your team name");
    scanf("%s", team.teamName);
    num_char = 0;
    while(num_char <4){
        printf("define character #%d in your team\n Enter health, attack power and position (x,y) respectively: ", num_char); 
        scanf("%d %d %d %d", team.members[num_char].health, team.members[num_char].attack, team.members[num_char].pos[0],team.members[num_char].pos[1] ); 
        num_char++; 
    }

}
    

