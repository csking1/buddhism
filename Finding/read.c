// get quotes and labels from text file

#include <stdio.h>

int main(){
   FILE *fp;
   char line[256];

   /* opening file for reading */
   fp = fopen("Data/training.txt" , "r");
   if(fp == NULL)
   {
      perror("Error opening file");
      return(-1);
   }
   while (fgets(line, sizeof(line), fp)){

      int s = sizeof(line) - 10;
      for(int i = 0; i < s; i++){
         char val = line[i];
         printf("%c",  val);
         // if (val == '1' || val == '0'){
         //    printf("%s\n", val);
         // }
      }
      printf("value = %d\n", atoi(&line[strlen(line) - 1]));




   }

   fclose(fp);

   return(0);
}