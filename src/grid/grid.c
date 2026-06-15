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

    for (int xIdx = 0; xIdx < grid->N; xIdx++)
    {
        for (int yIdx = 0; yIdx < grid->M; yIdx++)
        {
            grid->squareList[xIdx,yIdx].isBlocked = *(decodedBlockedSquares + yIdx * grid->N + xIdx);

            if (drawGrid)
            {   
                if(grid->squareList[xIdx,yIdx].isBlocked)
                {
                    printf("%ls",L"\u25a0 ");
                }
                else
                {
                    printf("%ls",L"\u25a1 ");
                }
            }

            if (xIdx == 0)
            {
                grid->squareList[xIdx, yIdx].west = NULL;
            } else
            {
                grid->squareList[xIdx, yIdx].west = &grid->squareList[xIdx - 1, yIdx];
            }

            if (yIdx == 0)
            {
                grid->squareList[xIdx, yIdx].north = NULL;
            } else
            {
                grid->squareList[xIdx, yIdx].north = &grid->squareList[xIdx, yIdx - 1];
            }

            if (xIdx == grid->N - 1)
            {
                grid->squareList[xIdx, yIdx].east = NULL;
            } else
            {
                grid->squareList[xIdx, yIdx].east = &grid->squareList[xIdx + 1, yIdx];
            }

            if (xIdx == grid->M - 1)
            {
                grid->squareList[xIdx, yIdx].south = NULL;
            } else
            {
                grid->squareList[xIdx, yIdx].west = &grid->squareList[xIdx, yIdx + 1];
            }
        }
        if(drawGrid) {printf("%c",'\n');}
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
