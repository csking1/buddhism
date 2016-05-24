// get quotes and labels from text file

// also count and return the number of unigrams and bigrams

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
   FILE *fp;
   char line[300]; /* 300 is an arbitrary length to read in lines from the text file*/
   char* sentences[152]; /* 152 = the size of the training set*/
   int count = 0;
   int labels[152];

   fp = fopen("Data/training.txt" , "r");
   if(fp == NULL)
   {
      perror("Error opening file");
      return(-1);
   }

   while (fgets(line, 300, fp)){

      int s = strlen((line)) - 3;
      // printf("%d\n", s);

      char quote[s];

      // copy the line into an array
      for(int i = 0; i <= s; i++){
         quote[i] = line[i];
      }

      // get the integer at the end of the string
      char label =  atoi(&line[s]);
      printf("%s\n", quote);

      sentences[count] = quote;
      labels[count] = label;
      count ++;

   }

   fclose(fp);

   return(0);
}