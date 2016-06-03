#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "train.h"
#include "thread.h"
#include "classifier.h"

Thread* initialize_thread(char* path, Classifier *clf, int size){
   Thread* t = malloc(sizeof(t) * size);
   t->clf = clf;
   FILE *fp = fopen(path, "r");
   printf("%d\n", size);

   char line[300]; /* 300 is an arbitrary length to read in lines from the text file*/
   int count = 0;
   if(fp == NULL){
      perror("Error opening file");
      return NULL;
   }
   if ((t->table = malloc(sizeof(t->table) * size*size)) == NULL){
    return NULL;
   }
   for (int i = 0; i < size; i++) {
       t->table[i] = NULL;
   }

   while (fgets(line, 300, fp)){
      	if (count < size) {
   		    printf("%d\n", count);
	        	  char* quote = strdup(line);

         		LinkedTest* new = malloc(sizeof(*new));
      		 new->quote = quote;
      
      		 char* copy = strdup(quote);

      		float c = get_score(t->clf, copy);
     		     new->score = c;
      		 t->table[count] = new;
      		count ++;
      		}
	     else {
		       t->size = count;
		       return t;   
		    }
	  }
   return t;

}


// write out the 5,000 top and 5,000 lowest quotes to a csv to hand off to NYTimes

// For now just write out the first 10,000. Handle the sorting later
void write_quotes(char* path, Thread* t){
   FILE *fp = fopen(path, "w");

   for (int i = 5000; i < 15000; i++){
      LinkedTest* q = t->table[i];
      if (q != NULL){

         char* copy = strdup(q->quote);
         int l = strlen(copy);
         char* grams[l];
         for (int i = 0; i < l; i++){
            grams[i] = NULL;
         }
         int s = get_grams(copy, grams);
         if (s >= 2){
            fprintf(fp, "%f%s%s", q->score, ", ", q->quote);
         }
      }
   }
}
