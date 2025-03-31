#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tile.h"
#include "team.h"

void attack(Character * attacker, Character * defender, Tile gameMap[10][10]){
    char attackerType = gameMap[attacker->pos[1]][attacker->pos[0]].type;
    
    if(attacker == NULL || defender == NULL){
        printf("Error: no attacker/defender found.\n");
        return;
    }

    defender -> health -= attacker -> attack;

    printf("%d damage dealt!\n", attacker->attack);

    if(defender -> health <= 0){
        printf("******************\nCHARACTER DEFEATED!\n****************\n");
        //Once target hp < 0, move onto its tile
        gameMap[attacker->pos[1]][attacker->pos[0]].type = '.';
        attacker->pos[0] = defender->pos[0];
        attacker->pos[1] = defender->pos[1];
        gameMap[defender->pos[1]][defender->pos[0]].type = attackerType;
        defender->pos[0] = 999;
        defender->pos[1] = 999;
    }
}

bool moveRight(Team* team, Team* enemyTeam, Tile gameMap [10][10], int characterIndex){
    int posX = team->members[characterIndex]->pos[0];
    int posY = team->members[characterIndex]->pos[1];
    int newX = posX + 1;
    int newY = posY;
    char moverType = gameMap[posY][posX].type;

    if(newX >= 10){
        printf("Invalid move: Out of bounds.\n");
        return false;
    }

    for(int i = 0; i < 4; i++){
        if(enemyTeam->members[i]->pos[0] == newX && enemyTeam->members[i]->pos[1] == newY){
            printf("Enemy detected! Attacking...\n");
            attack(team->members[characterIndex], enemyTeam->members[i], gameMap);
            return true;
        }
    }

    if(gameMap[newY][newX].type == '.'){
        team->members[characterIndex]->pos[0] = newX;  
        gameMap[posY][posX].type = '.'; 
        gameMap[newY][newX].type = moverType;
        return true;
    }
    else{
        printf("Can't move due to '%c' blocking\n", gameMap[newY][newX].type); 
    }

    return false;
}

bool moveLeft(Team* team, Team* enemyTeam, Tile gameMap [10][10], int characterIndex){
    int posX = team->members[characterIndex]->pos[0];
    int posY = team->members[characterIndex]->pos[1];
    int newX = posX - 1;
    int newY = posY;
    char moverType = gameMap[posY][posX].type;

    if(newX >= 10){
        printf("Invalid move: Out of bounds.\n");
        return false;
    }

    for(int i = 0; i < 4; i++){
        if(enemyTeam->members[i]->pos[0] == newX && enemyTeam->members[i]->pos[1] == newY){
            printf("Enemy detected! Attacking...\n");
            attack(team->members[characterIndex], enemyTeam->members[i], gameMap);
            return true;
        }
    }
    if(gameMap[posY][newX].type == '.'){
        team->members[characterIndex]->pos[0] = newX;  
        gameMap[posY][posX].type = '.'; 
        gameMap[newY][newX].type = moverType;
        return true;
    }
    else{
        printf("Can't move due to '%c' blocking\n", gameMap[newY][newX].type);    
    }

    return false;  
}

bool moveUp(Team* team, Team* enemyTeam, Tile gameMap [10][10], int characterIndex){
    int posX = team->members[characterIndex]->pos[0];
    int posY = team->members[characterIndex]->pos[1];
    int newY = posY - 1;
    int newX = posX;
    char moverType = gameMap[posY][posX].type;

    if(newY >= 10){
        printf("Invalid move: Out of bounds.\n");
        return false;
    }

    for(int i = 0; i < 4; i++){
        if(enemyTeam->members[i]->pos[0] == posX && enemyTeam->members[i]->pos[1] == newY){
            printf("Enemy detected! Attacking...\n");
            attack(team->members[characterIndex], enemyTeam->members[i], gameMap);
            return true;
        }
    }
    if(gameMap[newY][newX].type == '.'){
        team->members[characterIndex]->pos[1] = newY;  
        gameMap[posY][posX].type = '.'; 
        gameMap[newY][newX].type = moverType;
        return true;
    }
    else{
        printf("Can't move due to '%c' blocking\n", gameMap[newY][newX].type); 
    }

    return false;
}

bool moveDown(Team* team, Team* enemyTeam, Tile gameMap [10][10], int characterIndex){
    int posX = team->members[characterIndex]->pos[0];
    int posY = team->members[characterIndex]->pos[1];
    int newY = posY + 1;
    int newX = posX;
    char moverType = gameMap[posY][posX].type;

    if(newY >= 10){
        printf("Invalid move: Out of bounds.\n");
        return false;
    }

    for(int i = 0; i < 4; i++){
        if(enemyTeam->members[i]->pos[0] == posX && enemyTeam->members[i]->pos[1] == newY){
            printf("Enemy detected! Attacking...\n");
            attack(team->members[characterIndex], enemyTeam->members[i], gameMap);
            return true;
        }
    }
    if(gameMap[newY][newX].type == '.'){
        team->members[characterIndex]->pos[1] = newY;  
        gameMap[posY][posX].type = '.'; 
        gameMap[newY][newX].type = moverType;
        return true;
    }
    else{
        printf("Can't move due to '%c' blocking\n", gameMap[newY][newX].type); 
    }

    return false;
}