#ifndef CHARACTER_H
#define CHARACTER_H
#include <stdbool.h>

typedef struct Character{
    int health;
    int attack;
    int pos [2];
    bool bulldozer;
    bool berserker;

}Character;

#endif 