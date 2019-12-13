#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
        //printf("%s", "||||||||||||");
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
        current->occurences = 0;
        
    }
    fclose(f);
    return head;
}



Word* unique_parse(int* uni_length, int* full_length,  struct Word* head)
{

    // initiates pointers
    Word* full_head = head;
    Word* full_current = NULL;
    Word* uni_head = head;
    Word* uni_current = NULL;
    Word* uni_last = head;
    Word temp;
    
    
    full_current = full_head;

    int full_count = 0;
    int count = 0;
    
    // counts occurences
    while (full_count < *full_length)
    {   
        
        temp = *full_head;
        count = 0;
        while (count < *full_length)
        {  
            

            if( strcmp((temp).txt, (*full_current).txt) == 0){
                
                (*full_current).occurences += 1;
            }

            temp =  *(temp.after);
            count++;
        }

        if((*full_current).occurences < 2){
            *uni_length = *uni_length + 1;

            /*
            uni_current->after = full_current;
            uni_last->after = uni_current;
            uni_current->before = uni_last;
            uni_current = full_current;*/

        }
        
        full_current =  (*full_current).after;
        full_count++;
    }


    full_count = 0;
    while (full_count < *full_length)
    {   
        
        printf("%s", (*full_current).txt);
        printf("%s", " occurred ");
        printf("%d",  (*full_current).occurences);
        printf("%s", " times.");
        printf("%s", "\n");
        
        full_current =  (*full_current).after;
        full_count++;
        

    }
    


    printf("%s", "\n");
        
    printf("%s", "Number of unique words: ");
    printf("%d", uni_length);
    printf("%s", "\n");
    return head;

}





// remove common words like "the", "a", "and", "or"
void trim(Word* head, Word* rem_head, int* length, int* rem_length)
{
    
    int count = 0;
    int inner_count = 0;
    struct Word* current = head;
    struct Word* rem_current = rem_head;

    // iterates word list
    while(count<*length){


        int indicator = 0;
        inner_count = 0;
        
        int string_len = strlen( (*current).txt );
        int i = 1;

        //trim punctuation from right
        while(ispunct(((*current).txt)[string_len-i]) != 0 ){
            ((*current).txt)[string_len-i] = '\0';
            i++;
        }
        
        //trim punctuation from left
        i = 0;
        while(ispunct(((*current).txt)[i]) != 0 ){
            ((*current).txt)[i] = '\0';
            i++;
        }

        // send everything to lower case
        for(int i = 0; (*current).txt[i]; i++){
            (*current).txt[i] = tolower((*current).txt[i]);
        }


        // iterates stop word list
        while(inner_count<*rem_length){
        
            //checks if on removal list
            if(strcmp((*current).txt, (*rem_current).txt) == 0)
            {
                *length = *length - 1;
                current = deleteWord(current);
                rem_current = (*rem_current).after;
                indicator = 1;
                continue;
            }

            // these two check for an empty word
            else if(strcmp((*current).txt, "") == 0)
            {
                *length = *length - 1;
                current = deleteWord(current);
                rem_current = (*rem_current).after;
                indicator = 1;
                continue;
            }

            else if((*current).txt[0] == '\0' )
            {
                *length = *length - 1;
                current = deleteWord(current);
                rem_current = (*rem_current).after;
                indicator = 1;
                continue;
            }
            else if(strlen((*current).txt) < 3 )
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
            count++;
        }
    }

}

void word_analyze(Word* head, int* length)
{
    // instantiates variables for analysis
    int count = 0;
    struct Word* current = head;
    int len = 0;
    int min = 50;
    char min_word[50];
    int max = 0;
    char max_word[50];

    // iterates through list of words
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

    // prints analysis to the user
    printf("%s", "Max: \"");
    printf("%s", max_word);
    printf("%s", "\" with a length of ");
    printf("%d", max);
    printf("%s", " letters");
    printf("%s", "\n");
    printf("%s", "Min: \"");
    printf("%s", min_word);
    printf("%s", "\" with a length of ");
    printf("%d", min);
    printf("%s", " letters");
    printf("%s", "\n");
    







}

void phrase_analyze(Word *head, int *length)
{
    // find most common pair of words

}

int main(int argc, char* argv[]){



    // setting length, and creating linked list of words
    int length = 0;
    int* ptr = &length;
    char path1[50] = "test_text.txt";
    Word* head = parse(ptr, path1);

    

    // setting length, and creating linked list of words to remove
    int rem_length = 0;
    int* ptr3 = &rem_length;
    char path2[50] = "stop-word-list.txt";
    Word* rem_head = parse(ptr3, path2);
 
    
    trim(head, rem_head, ptr, ptr3);

    // setting length, and creating linked list of unique words
    int unique_length = 0;
    int* ptr2 = &unique_length;
    Word* unique_head = unique_parse(ptr2, ptr, head);




    //print(head, ptr);
    //print(unique_head, ptr2);
    word_analyze(head, ptr);

    //phrase_analyze(&head, &length);
}