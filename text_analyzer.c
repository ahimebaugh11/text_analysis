#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text_analyzer.h"


//Process
// Create first word
// Assign Head
// create next word
// assign last_ptr's next value to new word
// repeat

struct Word* parse()
{
   // initiates stuff for reading in text file
   char buf[50];
   FILE *f;
   f=fopen("test_text.txt","r");


   // initiates pointers
   struct Word *head = NULL;
   struct Word *last = NULL;
   struct Word *current = NULL;

   while (1)
   {
      //printf("%s", "HEAD:\n");
      //printf("%s", (*head).txt);
      //printf("%s", "\n");

      //if end of file, set pointer to head
      if(feof(f)){
         last->next = head;
         break;
      }

      //next word
      fscanf(f,"%s",buf);

      // IF first word, create new word and set as last word and head, iterate
      if(last == NULL){
         printf("%s", "last == NUll\n");
         
         struct Word newWord; 
         strcpy(newWord.txt, buf); 
         printf("%s", newWord.txt);
         printf("%s", "\n");
         last = &newWord;
         head = last;
      }

      // else, create new word, copy string, set last.next to current pointer, 
      // set new last pointer, iterate
      else{
         printf("%s", "else case\n");
         struct Word newWord; 
         strcpy(newWord.txt, buf); 
         printf("%s", newWord.txt);
         printf("%s", "\n");
         current = &newWord;
         last->next = current;
         last = current;
      }
      //printf("%s", buf);
      //printf("%s", "\n");
   }
   fclose(f);
   return head;
}

void analyze()
{








}


int main(int argc, char* argv[]){
   struct Word* head = parse();
   analyze(head);
}