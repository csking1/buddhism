// get quotes and labels from text file

// also count and return the number of unigrams and bigrams

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
   FILE *fp;
   char line[300];
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

      // copy the line into an arra
      for(int i = 0; i <= s; i++){
         quote[i] = line[i];
      }


      // get the integer at the end of the string
      char label =  atoi(&line[s]);
      printf("%d\n", label);

      sentences[count] = quote;
      labels[count] = label;
      count ++;

   }

   // for (int i = 0; i < 152; i++){
   //    printf("%s\n", sentences[i]);
   // }

   // for (int i = 0; i < 152; i++){
   //    printf("%d\n", labels[i]);
   // }

   // fclose(fp);

   return(0);
}