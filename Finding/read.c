#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

train* get_train_set(){
   train* new = (train*)malloc(sizeof(train));
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
      char quote[s];
      for(int i = 0; i <= s; i++){
         quote[i] = line[i];
      }
      int label =  atoi(&line[s]);
      new -> sentences[count] = quote;
      new -> labels[count] = label;
      count ++;
   }
   fclose(fp);
   return new;
}