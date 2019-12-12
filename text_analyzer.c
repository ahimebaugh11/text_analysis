#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text_analyzer.h"


// COMPILATION/RUN COPY PASTE
/*

gcc text_analyzer.c -o analyzer.exe
gcc text_analyzer.h

./analyzer.exe

*/
Word* createWord(){
    Word* new; 
    new = (struct Word*)malloc(sizeof(struct Word));
    new->after = NULL;
    new->before = NULL;
    return new;
}

void print(struct Word* head){
    int count = 0;
    struct Word word = *head;
    while(count<10){
        printf("%s", word.txt);
        printf("%s", "\n");
        count++;
        word = *(word.after);
    }
};

Word* parse(int *length)
{

    //Process
    // Create first word
    // Assign Head
    // create next word
    // assign last_ptr's next value to new word
    // repeat

    // initiates stuff for reading in text file
    char buf[50];
    FILE *f;
    f=fopen("test_text.txt","r");


    // initiates pointers

    

    Word* head = NULL;
    Word* last = NULL;
    Word* current = NULL;

    while (1)
    {
        length++;

        //if end of file, set pointer to head
        if(feof(f)){
            (*last).after = head;
            break;
        }

        //next word
        fscanf(f,"%s",buf);
        




        //printf("%s", "\n");
        //printf("%s", "head pointer: ");
        //printf("%s", (*head).txt);
        //printf("%s", "\n");
        //printf("%s", "last pointer: ");
        //printf("%s", (*last).txt);
        //printf("%s", "\n");
        




        // IF first word, create new word and set as last word and head, iterate
        if(last == NULL){
            
            head = createWord();
            last = head;
            current = head;
            strcpy((*head).txt, buf);

            
            //printf("%s", (*head).txt);
            //printf("%s", "\n");
        }

        // else, create new word, copy string, set last.next to current pointer, 
        // set new last pointer, iterate
        else{
            Word* newWord = createWord();
            current = newWord;
            strcpy((*current).txt, buf);

            //printf("%s", (*newWord).txt);
            //printf("%s", "\n");
            //printf("%s", "current pointer: ");
            //printf("%s", (*current).txt);
            //printf("%s", "\n");


            last->after = current;
            current->before = last;
            last = current;
        }
        //printf("%s", buf);
        //printf("%s", "\n");
    }
    fclose(f);
    return head;
}


void trim(Word *head, int *length)
{
    // remove common words like "the", "a", "and", "or"

    // Remove non-alphanumeric characters
}

void word_analyze(Word *head, int *length)
{
    // find shortest

    // find longest

    // Count number of occurences of each unique word

}

void phrase_analyze(Word *head, int *length)
{
    // find most common pair of words

}

int main(int argc, char* argv[]){
    int length = 0;
    
    Word* head = parse(&length);
    print(head);
    /*
    trim(&head, &length);
    word_analyze(&head, &length);
    phrase_analyze(&head, &length);*/
}