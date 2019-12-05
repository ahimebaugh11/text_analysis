#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word { 
    char txt[50]; 
    struct Word *next; 
} Word;

void print(struct Word head){
    int count = 0;
    struct Word word = head;
    while(count<10){
        printf("%s", word.txt);
        count++;
        word = *(head.next);
    }
};


#endif