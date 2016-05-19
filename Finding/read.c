// get quotes and labels from text file

#include <stdio.h>

int main(){
   FILE *fp;
   char line[300];
   int sentences[152]; /* 152 = the size of the training set*/
   int count = 0;
   int labels[152];

   fp = fopen("Data/training.txt" , "r");
   if(fp == NULL)
   {
      perror("Error opening file");
      return(-1);
   }
   
   while (fgets(line, 300, fp)){

      int s = strlen((line)) - 1;
      printf("%d\n", s);

      char quote[s];
      for(int i = 0; i <= s; i++){
         quote[i] = line[i];
      }

      char label =  atoi(&line[s]);

      sentences[count] = &quote;
      labels[count] = &label;
      count ++;

   }

   for (int i = 0; i < 152; i++){
      printf("%s\n", &sentences[i]);
   }

   for (int i = 0; i < 152; i++){
      printf("%s\n", &labels[i]);
   }

   fclose(fp);

   return(0);
}