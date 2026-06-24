#ifndef MISC_H
#define MISC_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

struct params_t
{
    unsigned int N;
    unsigned int M;
    char* blockedSquares;
    unsigned int mov_points;
};

typedef struct params_t params;

void printHelp(void);
params* parseParms(const int argc, char* const argv[] );
void clearParams(params* params);

#endif //MISC_H