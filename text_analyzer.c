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

Word* deleteWord(Word* delete){
    (*((*delete).before)).after = (*delete).after;
    (*((*delete).after)).before = (*delete).before;
    Word* new_current = (*delete).after;
    
    return new_current;
}

void print(struct Word* head, int* length){
    int count = 0;
    struct Word word = *head;
    while(count<*length){
        printf("%s", word.txt);
        printf("%s", "\n");
        count++;
        word = *(word.after);
       
    }
};

Word* parse(int* length, char path[50])
{

    // initiates stuff for reading in text file
    char buf[50];
    FILE *f;
    f=fopen(path,"r");


    // initiates pointers
    Word* head = NULL;
    Word* last = NULL;
    Word* current = NULL;

    while (1)
    {
        
        
        //if end of file, set pointer to head
        if(feof(f)){
            (*last).after = head;
            (*head).before = last;
            break;
        }


        *length = *length + 1;
        
        //next word
        fscanf(f,"%s",buf);

        // IF first word, create new word and set as last word and head, iterate
        if(last == NULL){
            
            head = createWord();
            
            strcpy((*head).txt, buf);
            last = head;
            current = head;

        }

        // else, create new word, copy string, set last.next to current pointer, 
        // set new last pointer, iterate
        else{
            Word* newWord = createWord();
            strcpy((*newWord).txt, buf);

            current = newWord;
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


void trim(Word* head, Word* rem_head, int* length, int* rem_length)
{
    // remove common words like "the", "a", "and", "or"
    int count = 0;
    int inner_count = 0;
    struct Word* current = head;
    struct Word* rem_current = rem_head;
    
    while(count<*length){
        int indicator = 0;
        inner_count = 0;
        while(inner_count<*rem_length){
            
            if(strcmp((*current).txt, (*rem_current).txt) == 0)
                {

                *length = *length - 1;
                current = deleteWord(current);
                rem_current = (*rem_current).after;
                indicator = 1;
                continue;
            }
            else{
                rem_current = (*rem_current).after;
            }
            inner_count++;
        }

        if(indicator == 0){
            current = (*current).after;
        }
        count++;
        
        
    }

    // Remove non-alphanumeric characters
}

void word_analyze(Word* head, int* length)
{
    // find shortest

    // find longest
    int count = 0;
    struct Word* current = head;
    int len = 0;
    int min = 50;
    char min_word[50];
    int max = 0;
    char max_word[50];
    while(count<*length){
        len = strlen((*current).txt);
        if(len < min){
            min = len;
            strcpy(min_word, (*current).txt);
        }    
        if(len > max){
            max = len;
            strcpy(max_word, (*current).txt);
        }            
        
        
        
        
        current = (*current).after;
        count++;
        
        
    }
    printf("%s", "Max: ");
    printf("%s", max_word);
    printf("%s", " with a length of ");
    printf("%d", max);
    printf("%s", " letters");
    printf("%s", "\n");
    printf("%s", "Min: ");
    printf("%s", min_word);
    printf("%s", " with a length of ");
    printf("%d", min);
    printf("%s", " letters");
    printf("%s", "\n");


    // Count number of occurences of each unique word

}

void phrase_analyze(Word *head, int *length)
{
    // find most common pair of words

}

int main(int argc, char* argv[]){
    int length = 0;
    int* ptr = &length;
    char path1[50] = "test_text.txt";
    Word* head = parse(ptr, path1);

    int rem_length = 0;
    int* ptr2 = &rem_length;
    char path2[50] = "stop-word-list.txt";
    Word* rem_head = parse(ptr2, path2);
 
    trim(head, rem_head, ptr, ptr2);
    //print(head, ptr);
    
    word_analyze(head, ptr);

    //phrase_analyze(&head, &length);
}