#include <stdio.h>
#include <stdlib.h>

typedef struct tile {
    char type; // 'P' for palace, 'O' for obstacle, '.' for open space
    int x, y;
} tile;
