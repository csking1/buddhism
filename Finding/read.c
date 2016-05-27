#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

TrainSet* get_train_set(){
   TrainSet* t = (TrainSet*)malloc(sizeof(TrainSet));
   FILE *fp;
   char line[300]; /* 300 is an arbitrary length to read in lines from the text file*/
   int count = 0;
   fp = fopen("Data/training.txt" , "r");

   if(fp == NULL){
      perror("Error opening file");
      return NULL;
   }
   while (fgets(line, 300, fp)){
      int s = strlen((line)) - 3;
      char* quote = (char*)malloc(sizeof(char) * s);
      for(int i = 0; i <= s; i++){
         quote[i] = line[i];
      }
      int label =  atoi(&line[s]);
      t->sentences[count] = quote;
      t->labels[count] = label;
      count ++;
   }
   //fclose(fp);
   return t;
}

void* print_quotes(TrainSet* t){
   for (int i=0; i<152; i++){
      printf("%s\n", t-> sentences[i]);
   }
   return NULL;
}