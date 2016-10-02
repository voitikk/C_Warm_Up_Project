//Alex Voitik
//lexer.c
//Compiler Construction
//C Warm-up Project

#include "global.h"

char lexbuff[BSIZE];
int lineno = 1;
int tokenval = NONE;

int lexan(){
    int t;
    while(1){
        t = getchar();
        if(t == ' ' || t == '\t')
            ;
        else if(t == '\n')
            lineno = lineno + 1;
        else if(isdigit(t)) {
            ungetc( t, stdin);
            scanf("%d", &tokenval);
            return NUM;
        }
        else if(isalpha(t)){
            int p, b = 0;
            while (isalnum(t)){
                lexbuff[b] = t;
                t = getchar();
                b = b + 1;
                if (b >= BSIZE)
                    error("compiler error");
            }
            lexbuff[b] = EOS;
            if (t != EOF)
                ungetc(t, stdin);
            p = lookup(lexbuff);
            if(p == 0)
                p = insert(lexbuff, ID);
            tokenval = p;
            return symtable[p].token;
        }
        else if(t == EOF)
            return DONE;
        else {
            tokenval = NONE;
            return t;
        }
    }
}
    
