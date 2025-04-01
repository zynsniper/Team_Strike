#ifndef DEFENDER_H
#define DEFENDER_H
#include <stdbool.h>
typedef struct Defender{
    int health;
    int pos [2];
    struct Defender * next;
}Defender;
void initDefender(Defender ** defHead, int health, int x, int y);
bool removeDef(Defender *defender);
 #endif