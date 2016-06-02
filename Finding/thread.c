#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "thread.h"


// path to file on server is /home/ec2-user/s3fs-fuse-1.78/gutenberg_text/GutenFiles/file_1.txt


Thread* initialize_thread(char* path, Classifier *clf, int size){
   Thread* t = malloc(sizeof (*t));
   t->clf = clf;
   FILE *fp = fopen(path, "r");

   char line[300]; /* 300 is an arbitrary length to read in lines from the text file*/
   int count = 0;
   if(fp == NULL){
      perror("Error opening file");
      return NULL;
   }
   if ((t->table = malloc(sizeof(t->table) * size)) == NULL){
    return NULL;
  }
   // initialize table with nulls
  for (int i = 0; i < size; i++) {
    t->table[i] = NULL;
  }

   while (fgets(line, 300, fp)){

      int s = strlen((line)) - 2;
      char* quote = (char*)malloc(sizeof(char)*(s+1));
      LinkedTest* new = malloc(size * sizeof(*new));

      for(int i = 0; i < s; i++){
         quote[i] = line[i];
      }

      new->quote = quote;
      new->score = get_score(t->clf, quote);
      t->table[count] = new;
      count ++;
   }

   return t;
}
