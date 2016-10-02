//Alex Voitik
//error.c
//Compiler Construction
//C Warm-up Project

#include "global.h"

error(m)
    char *m;
{
        fprintf(stderr, "line %d: %s\n", lineno, m);
        exit(1);
}