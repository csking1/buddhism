#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"


// path to file on server is /home/ec2-user/s3fs-fuse-1.78/gutenberg_text/GutenFiles/file_1.txt


Thread* initialize_thread(char* path, Classifier *clf){
   Thread* t = malloc(sizeof (*t));
   FILE *fp;
   char line[300]; /* 300 is an arbitrary length to read in lines from the text file*/
   int count = 0;
   fp = fopen(path, "r");
   if(fp == NULL){
      perror("Error opening file");
      return NULL;
   }
   while (fgets(line, 300, fp)){

      int s = strlen((line)) - 3;
      char* quote = (char*)malloc(sizeof(char) * (s+1));
      
      for(int i = 0; i < s; i++){
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
