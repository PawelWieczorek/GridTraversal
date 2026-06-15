#ifndef GRID_H
#define GRID_H

#include <stdbool.h>
#include <stdlib.h>

extern bool drawGrid;

typedef struct square_t square;
typedef struct grid_t grid;

struct square_t
{
    bool isBlocked;
    int xPosition;
    int yPosition;
    square* north;
    square* south;
    square* west;
    square* east;
};

struct grid_t
{
    int N;
    int M;
    square* squareList;
};

grid* createGrid(const unsigned int N, const unsigned int M, const char* blockedSquares);
void clearGrid(grid* grid);

#endif //GRID_H