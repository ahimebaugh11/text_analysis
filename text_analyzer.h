#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word { 
    char txt[50]; 
    struct Word *after; 
    struct Word *before;
} Word;




#endif