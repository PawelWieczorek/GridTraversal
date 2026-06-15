#include <stdio.h>
#include "grid.h"
#include "misc.h"

int main(int argc, char *argv[])
{
    params* params = parseParms(argc, argv);

    if (params)
    {
        // grid* grid = createGrid(8,8, "(3,1) (3,2) (3,3) (3,4) (3,5) (4,4) (5,4) (6,6) (7,7)");
        grid* grid = createGrid(params->N, params->M, params->blockedSquares);

        clearGrid(grid);
        clearParams(params);
    }

    return 0;
}
