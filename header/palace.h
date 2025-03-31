#ifndef PALACE_H
#define PALACE_H

typedef struct palace{
    int health;
    int pos[2];
}Palace;

void initPalace(Palace *p);

#endif 