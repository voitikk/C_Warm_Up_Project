//Alex Voitik
//global.h
//Compiler Construction
//C Warm-up Project

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BSIZE 128
#define NONE -1
#define EOS '\0'

#define NUM  256
#define DIV  257
#define MOD  258
#define ID   259
#define DONE 260

int tokenval;
int lineno;

struct entry {
    char *lexptr;
    int token;
};

#define SYMMAX 100
struct entry symtable[SYMMAX];