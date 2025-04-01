#ifndef PALACE_H
#define PALACE_H
#include "defender.h"
typedef struct palace{
    int health;
    int pos[2];
    Defender * rootDef;
}Palace;

void initPalace(Palace *p);

#endif 