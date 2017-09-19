#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fileop.h"

int main(void)
{

    DIR *d;
    struct dirent *dir;
    d = opendir("D://uyt//");
    //char *word_array[10];
    char *file_name_array[10];
    char *fg;
    int i = 0;
    if (d)

    {
        while ((dir = readdir(d)) != NULL)
        {
            char* ch=dir->d_name;
            if(strstr(ch,".txt")!=NULL)
            {

                FILE *fp;
                fp = fopen(ch,"r");
                //word_array[i] = read_line(fp);
                printf("%s \t", dir->d_name);
                fg = fileoperation(fp);
                printf("%s", fg);

                printf("\n");
                //printf("%d",strlen(ch));
                file_name_array[i] = (char*)calloc(sizeof(char), sizeof(strlen(ch)));
                file_name_array[i] = ch;
                //printf("%s\n\n\n",word_array[i]);
                i++;
            }
        }
        closedir(d);
    }
    //printf(strlen(word_array[i]));
    return(0);
}

