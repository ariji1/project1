
//main driver file to run the program
#include <dirent.h>//library to open directories
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fileop.h" // user header file
#include <math.h>
#include "frequency.h" // user header file 2

int main(int argc,char  *argv[]) //argc will be 2 if user enters any argument, argv[] will contain the path that is entered via the terminal
{
    char folder[1000];
    DIR *d;
    float percentage[100];
    struct dirent *dir;
    if(argc == 2){
        d=opendir(argv[1]); 
        strcpy(folder,argv[1]);
        strcat(folder,"//");
    }
    else{

        d = opendir("."); // to open the directory
        strcpy(folder,".");//copy the name of the default directory to the string folder
        strcat(folder,"//");
    }
    char *file_name_array[10];
    char *fg;
    int i = 0;
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            char* ch=dir->d_name;
            if(strstr(ch,".txt")!=NULL)// filtering the text file
            {
                file_name_array[i] = (char*)calloc(sizeof(char), sizeof(strlen(ch)));
                strcpy(file_name_array[i],ch);
                i++;
            }
        }  
        closedir(d);
    }
    for(int j = 0;j<i;j++)
    {
        printf("=%s\n",file_name_array[j]);//printing the file name array
    }
    int counter = 0;
    char *str1;	
    char *str2;
    int filesCount=i;
   
    float matrix [filesCount][filesCount];
    matrix[0][0]=100.00;
    for(int j = 0;j<i;j++)
    {

        for(int k = j+1;k<i;k++)
        {
            char file_path[1000];
            char file_path2[1000];
            strcpy(file_path,folder);
            strcat(file_path,file_name_array[j]);// concatenating the filename to the file path, after filtering for text files
            printf("filepath1 %s\n",file_path);
	        str1  = fileoperation(file_path);
            printf("str1 %s\n",str1); // string 1 from the first file will be here
            strcpy(file_path2,folder);
            strcat(file_path2,file_name_array[k]);
            printf("filepath2 %s\n",file_path2);
            str2 = fileoperation(file_path2);
            printf("str2 %s\n",str2);//string 2 from the second file will be here
            percentage[counter] = bag_of_words(str1,str2);//this will store the percentages after calculation directly into the arrays
            matrix[j][k]=percentage[counter];
            matrix[k][j]=percentage[counter];
            counter++;
            
       }
    }
     printf("\t");
    for(int i = 0;i<filesCount;i++){
        printf("%12s",file_name_array[i] );//printing the file name array top and side
        matrix[i][i]=100.00;
    }
     printf("\n");
     for(int i = 0;i<filesCount;i++)
     {
        printf("%s",file_name_array[i] );
        for (int j = 0; j < filesCount; j++)
        {
            /* code */printf("%12.2f",matrix[i][j]);//printing the percentages
        }
        printf("\n");
    }
 }   

