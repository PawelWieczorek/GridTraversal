#include <stdio.h>
#include "grid.h"
#include "misc.h"

int main(int argc, char *argv[])
{
    params* params = parseParms(argc, argv);

    if (params)
    {
        grid* grid = createGrid(params->N, params->M, params->blockedSquares);

        

        clearGrid(grid);
        clearParams(params);
    }

    return 0;
}
