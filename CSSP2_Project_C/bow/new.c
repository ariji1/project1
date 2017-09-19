#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_WORD_LENGTH 128
//struct word_frequency
//  {
//     char *word;
//     int count;
//  }word1_bag[1000],word2_bag[1000];

float bag_of_words(char *string1, char*string2)
{
        char word1_bag[50][MAX_WORD_LENGTH];
        char word2_bag[50][MAX_WORD_LENGTH];
    // char **word1_bag=NULL;
    // char **word2_bag=NULL;
    // printf("string 1 %s\n", string1 );
    // printf("string 2%s\n", string2 );
    // //char **word1_bag_freq;
    // //char **word2_bag_freq;
    // word1_bag = (char**)malloc(50*sizeof(char*));
    // memset(word1_bag,'\0',50);
    // // word1_bag_freq = (char**)malloc(50*sizeof(char*));
    // word2_bag = (char**)malloc(50*sizeof(char*));
    // memset(word2_bag,'\0',50);
    // // word2_bag_freq = (char**)malloc(50*sizeof(char*));
    // printf("string 1 %s\n", string1 );
    // printf("string 2%s\n", string2 );
    // for(int k=0;k<100;k++)
    // {

    //     word1_bag[k] = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));

    // }
    // for(int j=0;j<100;j++)
    // {

    //     word2_bag[j] = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
    // }
    // for(int i=0;i<100;i++)
    // {

    //     word1_bag_freq[i] = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
    // }
    // for(int i=0;i<100;i++)
    // {

    //     word2_bag_freq[i] = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
    // }
    //char *string1;
    //char *string2;
    //printf("hmm\n");
     printf("string 1 %s\n", string1 );
    printf("string 2%s\n", string2 );

    char *token2;
    token2 = strtok(string2," ");
    int i2 = 0;
    while(token2 != NULL)
    {
      strcpy(word2_bag[i2],token2);
      printf("token2 %s\n",token2 );
      token2 = strtok(NULL," ");
      
      i2++;
    }

    int bag2_size = i2; 





    char *token1;
    token1 = strtok(string1," ");
    printf("xx %s",token1);
    int g = 0;
    while(token1 != NULL)
    {
      strcpy(word1_bag[g],token1);
      printf(" token1 %s\n",token1 );
      token1 = strtok(NULL," ");
      g++;
    }

   	int bag1_size = g;
    printf("bva %d\n",bag1_size);
   

    //printf("%d\n", i2);

    // for(int i = 0;i<i2;i++)
    // {
    // 	printf("%s",word2_bag[i]);
    // }

    // printf("%d\n", i2 );
    
    //block for string 1
    int l,count1[300],count,counter = 0;
    for(int j = 0;j<g;j++)
    {
    	count = 1;
    	
    	for(int k = j+1;k<g;)
    	{
    		if(strcmp(word1_bag[k], word1_bag[j])== 0)

    		{
    			count++;
    			for (l = k;l<g;l++)
    			{
    				strcpy(word1_bag[l], word1_bag[l+1]);
    			}
    			g--;
    			
    		}
    		else{ 
    			k++;
    		}
    	}
    	//printf("%d\n", count);
    	count1[counter]=count;
    	//printf("%d\n", counter);
    	//printf("%d\n",count1[counter] );
    	counter++;
    }
   // printf("%d\n",i);
   // for(int h = 0;h<i;h++)
   // {
   // 	printf("%s\t",word1_bag[h]);
   // }
    // block for string 2
   int l2, count2[300],k=0;
   counter = 0;
    for(int j = 0;j<i2;j++)
    {
    	count = 1;
    	for(int k = j+1;k<i2;)
    	{
    		//printf("%d***%d\n",j,k );
    		if(strcmp(word2_bag[k], word2_bag[j])== 0)
    		{
    			count++;
    			for (int l2 = k;l2<i2;l2++)
    			{
    				strcpy(word2_bag[l2],word2_bag[l2+1]);

    			}
    			i2--;
    			//printf("%d###%d\n",j,i2);
    		}
    		else{ 
    			k++;
    		}
    	}
    	count2[counter]=count;
    	counter++;
    }  

   // printf("%d\n",i2);
   // for(int h = 0;h<i2;h++)
   // {
   // 	printf("%d\t %s\n",count2[h],word2_bag[h]);
   // }

    //to calculate sum

    // for(int i = 0;i<bag1_size;i++)
    // {
    // 	printf("%d\n",count1[i]);
    // }

    int sum = 0;

    
    for(int i = 0;i<bag1_size;i++)
    {
        printf("im in 1 \n");
    	for(int j = 0;j<bag2_size;j++)
    	{
            printf("im in 2\n");
    		if(strcmp(word1_bag[i],word2_bag[j])==0)
    		{
                printf("im in\n");
    			sum = sum+(count1[i]*count2[j]);
    			break;
    		}
    	}
    } printf(" sum1 %d",sum);

    int d1 = 0;
    int d2 = 0;

    for(int i = 0; i<bag1_size;i++)
    {
    	d1 = d1+(count1[i]*count1[i]);
    }

    for(int i = 0;i<bag2_size;i++)
    {

    	d2 = d2+(count2[i]*count2[i]);
    }
	printf("sum %d d1 %d d2 %d\n",sum,d1,d2);
    printf("sum is %f\n",pow(d1*d2,0.5));
    float percentage;
    percentage = (sum)/sqrt(d1*d2);
    printf("%f percent\n", percentage);
    return percentage*100;

}


