#include "misc.h"
#include "grid.h"

void printHelp()
{
    printf("\nGrid traversal algorithm. For given NxM grid with blocked and unblocked squares and a maximum number "
            "of movement poists returns the path with highest number of unique unblocked squares \n(one of paths, if multiple paths for specific grid "
            "and movement points amount are possible) and a number of visited unblocked squares.\n\n"
            "Usage:\n"
            "grid_traversal N M <lst_blk_squares> mov_points [options]\n"
            "where:\n"
            "N               - number of rows in grid\n"
            "M               - number of columns in grid\n"
            "lst_blk_squares - list of blocked points in format \"(a,b) (c,d) ... \", where a,b c,d - coordinates of squares\n"
            "mov_points      - available movement points\n\n"
            "Example:\n"
            "grid_traversal 5 5 \"(1,1) (2,4) (2,5)\" 10   - 5x5 grid with blocked (1,1) (2,4) and (2,5) squares and 10 movement points \n\n"
            "Options:\n"
            "--draw          - Draw input grid with blocked squares and output grid with traversed path.\n"
            "--help          - Display this infomation.\n");
}

params* parseParms(const int argc, char* const argv[])
{
    int paramNumber = 0;

    if(argc >= 5)
    {
        params* param = malloc(sizeof(params));
        
        if (param)
        {
            for (int i = 1 ; i < argc; i++)
            {
                if (strcmp("--help", argv[i]) == 0)
                {
                    printHelp();
                }
                else if (strcmp("--draw", argv[i]) == 0)
                {
                    setlocale(LC_ALL, "");
                    drawGrid = true;
                }
                else if (paramNumber == 0)
                {
                    param->N = atoi(argv[i]);
                    paramNumber++;
                }
                else if (paramNumber == 1)
                {
                    param->M = atoi(argv[i]);
                    paramNumber++;
                }
                else if (paramNumber == 2)
                {
                    param->blockedSquares = malloc(sizeof(char) * strlen(argv[i]));
                    strcpy(param->blockedSquares, argv[i]);
                    paramNumber++;
                }
                else if (paramNumber == 1)
                {
                    param->mov_points = atoi(argv[i]);
                    paramNumber++;
                }
            }
        }
        return param;
    }
    else
    {
        printf("Wrong number of parameters.\n");
        printHelp();
    }
    return NULL;
}

void clearParams(params* params)
{
    free(params->blockedSquares);
    free(params);
}

