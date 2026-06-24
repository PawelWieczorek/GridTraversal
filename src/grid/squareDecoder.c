#include "squareDecoder.h"

bool* decodeBlockedSquares(const char* squares, const unsigned N, const unsigned M)
{
    char* tmp = malloc(strlen(squares));
    if (tmp)
    {
        strcpy(tmp, squares);
    }
    else
    {return NULL;}

    bool* squaresTable = calloc(N * M, sizeof(bool));

    if (squaresTable)
    {
        int idx = 0;
        char** square = (char**)malloc(N * M * sizeof(char*));
        char* squareToken = strtok(tmp, " ");
        while (squareToken)
        {
            square[idx] = malloc(strlen(squareToken));
            if(square)
            {
                strcpy(square[idx], squareToken);
                idx++;
            }
            squareToken = strtok(NULL, " ");
        }
        for (int i=0; i<idx; i++)
        {
            char* xCoord = strtok(square[i],"(),");
            int iXCoord = atoi(xCoord) - 1;

            char* yCoord = strtok(NULL, "(),");
            int iYCoord = atoi(yCoord) - 1;
            
            if (iXCoord >= 0 && iXCoord <= (N - 1) && iYCoord >= 0 && iYCoord <= (M - 1))
            {
                squaresTable[iYCoord * N + iXCoord] = true;
            }

            free(square[i]);
        }
    }
    free(tmp);
    return squaresTable;
}