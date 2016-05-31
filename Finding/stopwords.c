#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "classifier.h"
#include "hash_tables.h"
#include "stopwords.h"

StopWords* get_stopwords(){
   StopWords* t = malloc(sizeof *t);
   FILE *fp;
   char line[20]; /* an arbitrary length to read in lines from the text file*/
   int count = 0;
   fp = fopen("Data/stopwords.txt", "r");
   if(fp == NULL){
      perror("Error opening file");
      return NULL;
   }
   while (fgets(line, 300, fp)){
      int s = strlen((line)) - 2;
      char* quote = (char*)malloc(sizeof(char) * s);
      for(int i = 0; i <= s; i++){
         quote[i] = line[i];
      }
      t->words[count] = quote;
      count ++;
   }
   //fclose(fp);
   return t;
}