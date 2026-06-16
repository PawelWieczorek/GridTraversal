#include "grid.h"
#include "squareDecoder.h"

bool drawGrid = false;

static bool initGrid(const grid* grid, const char* blockedPoints);

grid* createGrid(const unsigned int N, const unsigned int M, const char* blockedSquares)
{
    grid* grid = NULL;

    if (N > 0 && M > 0)
    {
        grid = malloc(sizeof(grid));
        
        if(grid)
        {
            grid->squareList = malloc(N * M * sizeof(square));
            grid->M = M;
            grid->N = N;

            if (!initGrid(grid, blockedSquares))
            {
                clearGrid(grid);
                grid = NULL;
            }
        }
    }

    return grid;
}

static bool initGrid(const grid* grid, const char* blockedPoints)
{
    if(!grid)
    {
        printf("No grid provided!\n");
        return false;
    }

    bool* decodedBlockedSquares = decodeBlockedSquares(blockedPoints, grid->N, grid->M);

    if (!decodedBlockedSquares)
    {    
        printf("Could not decode squares\n");
        return false;
    }

    for (int idx = 0; idx < grid->N * grid->M; idx++)
    {
        grid->squareList[idx].isBlocked = decodedBlockedSquares[idx];

        if (drawGrid)
        {   
            if(grid->squareList[idx].isBlocked)
            {
                printf("%ls",L"\u25a0 ");
            }
            else
            {
                printf("%ls",L"\u25a1 ");
            }
        }

        if ((idx % grid->N) == 0)
        {
            grid->squareList[idx].west = NULL;
        } else
        {
            grid->squareList[idx].west = &grid->squareList[idx - 1];
        }

        if (idx < grid->M)
        {
            grid->squareList[idx].north = NULL;
        } else
        {
            grid->squareList[idx].north = &grid->squareList[idx - grid->M];
        }

        if (idx % grid->N == grid->N - 1)
        {
            grid->squareList[idx].east = NULL;
            if(drawGrid) {printf("%c",'\n');}
            
        } else
        {
            grid->squareList[idx].east = &grid->squareList[idx + 1];
        }

        if (idx > (grid->M - 1) * grid->N)
        {
            grid->squareList[idx].south = NULL;
        } else
        {
            grid->squareList[idx].south = &grid->squareList[idx + grid->M];
        }

            grid->squareList[idx].vertexLevel = 0;
    }

    for (int yIdx = 0; yIdx < grid->M; yIdx++)
    {
        for (int xIdx = 0; xIdx < grid->N; xIdx++)
        {    
            volatile square square = grid->squareList[yIdx * grid->N + xIdx];
            
            if (!square.isBlocked)
            {
                if (square.east)
                {
                    if (!square.east->isBlocked)
                    grid->squareList[yIdx * grid->N + xIdx].vertexLevel++;
                }

                if (square.west)
                {
                    if (!square.west->isBlocked)
                    grid->squareList[yIdx * grid->N + xIdx].vertexLevel++;
                }

                if (square.south)
                {
                    if (!square.south->isBlocked)
                    grid->squareList[yIdx * grid->N + xIdx].vertexLevel++;
                }

                if (square.north)
                {
                    if (!square.north->isBlocked)
                    grid->squareList[yIdx * grid->N + xIdx].vertexLevel++;
                }
            }
        }
    }
    free(decodedBlockedSquares);

    return true;
}

void clearGrid(grid *grid)
{
    if(!grid)
    {
        return;
    }
    if (grid->squareList)
    {
        free(grid->squareList);
    }
    free(grid);
}
