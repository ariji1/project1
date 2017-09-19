#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 128
//struct word_frequency
//  {
//     char *word;
//     int count;
//  }word1_bag[1000],word2_bag[1000];

void main()
{
    char **word1_bag;
    word1_bag = (char**)malloc(50*sizeof(char*));
    
    for(int i=0;i<100;i++)
    {

        word1_bag[i] = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
    }
    char str1[]= "Hello there there there there hello am am am";
    char str2[]= " Nom Nom lets eat you";
    //printf("hmm\n");
    char *token1;
    token1 = strtok(str1," ");
    //printf("%s",token1);
    int i = 0;
    while(token1 != NULL)
    {
      strcpy(word1_bag[i],token1);
      token1 = strtok(NULL," ");
      i++;
    }
    printf("%d",strlen(str1) );

    for(int j = 0;j<i;j++)
    {
        printf("%s\n",word1_bag[j]);
    }

}
