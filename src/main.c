#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "grid.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    grid* grid = createGrid(8,8);
    initGrid(grid, "(3,1) (3,2) (3,3) (3,4) (3,5) (4,4) (5,4) (6,6) (7,7)");

    clearGrid(grid);

    return 0;
}