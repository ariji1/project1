//this header files converts the files into strings, after removing the special characters and converting them into lower case
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * fileoperation(char *filepath)
{
   FILE * fp; // file pointer to open a file
   fp = fopen(filepath,"r");
   char *ptr=NULL; // pointer to get the string
   char c='\0';
   ptr = (char*)malloc(sizeof(char)); // dynamic allocation of memory for the string, initialize with 1 char size, 1 byte
   int i = 0, j = 1;
   while (c != EOF) 
   {
         c = fgetc(fp);// scans every character of the string
         if(c >= 65 && c <= 90) // converts lower case to upper case
         {
             c = c+32;
             ptr[i++] = c;
             ptr = realloc(ptr, i+1); // increases memory by 1 character for every character read
         }
         else if(c == 32 ||( c >= 97 && c<= 122) ) // accepts space, upper case charaters
         {
             ptr[i++] = c;
             ptr = realloc(ptr,i+1);
         }
   }
   ptr[i] = '\0';
   printf("my string %s\n", ptr); // to check the string entered
   //int l = strlen(ptr);
   
   fclose(fp); //close the file pointer
   return ptr; // returning the string
}
