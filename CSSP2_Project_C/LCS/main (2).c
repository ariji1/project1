#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

struct wordsbag{
    char word[100];
    int count1;
    int count2;
};

struct files{
    char filename[1000];
};

int main(int argc,char  *argv[]) {
    char folder[1000];
    DIR *d;
    int h = 0;
    struct dirent *dir;
    if(argc == 2){
        d=opendir(argv[1]);
        strcpy(folder,argv[1]);
        strcat(folder,"//");// remember to change this to two backward slashes if you're using windows
    }

    else{
         d = opendir(".");
         strcpy(folder,".");
         strcat(folder,"//");// remember to change this to two backward slashes if you're using windows
         
    }

    struct files files1[10];
    if (d) {
        while ((dir = readdir(d)) != NULL) {//block of code is same as in bag of words
            char* ch=dir->d_name;
            //int len = strlen(dir->d_name);

            if (strstr(ch,".txt")!=NULL) {
                //printf("%s\n", dir->d_name);
                strcpy(files1[h].filename, ch);
                h++;
            }
        }
        closedir(d);//close the directory
    }
    printf("\t\t");
    int y = 0;
    for (y = 0; y < h; y++) {
        printf("%s\t", files1[y].filename);//printing elements from the file name array, here it is declared as a struct
    }
    printf("\n");
    int u = 0, v = 0;
    for (u = 0; u < h; u++) {
        printf("%s\t", files1[u].filename);//printing elements from the file name array, this will print the columns.
        for (v = 0; v < h; v++) {
            FILE *fp, *fp1;
            char f1[1000] = {'\0'}, f2[1000] = {'\0'};
            strcat(f1, folder);
            strcat(f1, files1[u].filename);//after filtering for the text files, this particularconcatenation joins, filename with the path
            strcat(f2, folder);
            strcat(f2, files1[v].filename);//after filtering for the text files, this particularconcatenation joins, filename with the path
            fp = fopen(f1, "r");
            fp1 = fopen(f2, "r");
            char buff[1000]={'\0'};
            char buff1[1000]={'\0'};
            int i = 0;
            fscanf(fp, "%[^\Z]s", buff);//buff contains the contents of the file in as a string, it will open it and store it here, ignore the numbers
            fscanf(fp1, "%[^\Z]s", buff1);//buff1 contains the contents of the second file as a string, it will open it and store it here
            int j = 0;
            int c = 0;
            for (i = 0; i < strlen(buff); i++) { //removing the numbers from the string
                if (!isalnum(buff[i])) {
                    buff[i] = ' ';
                }
            }
            for (i = 0; i < strlen(buff1); i++) {
                if (!isalnum(buff1[i])) {
                    buff1[i] = ' ';
                }
            }
            int t = 0;
            int bufflen1 = 0;
            struct wordsbag arr[1000] = {'\0'};
            for (i = 0; i < strlen(buff); i++) {
                if (isalnum(buff[i])) {
                    int k = 0;
                    int z = 0;
                    struct wordsbag wordsbag1={'\0'};
                    for (k = i; k < strlen(buff); k++) {
                        if (buff[k] != ' ') {
                            wordsbag1.word[z] = buff[k]; //stores the words in the wordsbag1
                            bufflen1++;//stores the number of words in bag1.
                            z++;
                        } else {
                            break;
                        }
                    }
                    arr[t] = wordsbag1;//copying every element to arr[t] from wordsbag1
                    t++;
                    i = i + z;
                }
            }
            i = 0;
            int t1 = 0;
            int bufflen2 = 0;
            struct wordsbag arr1[1000] = {'\0'};
            for (i = 0; i < strlen(buff1); i++) {
                if (isalnum(buff1[i])) {
                    int k = 0, z = 0;
                    struct wordsbag wordsbag2={'\0'};
                    for (k = i; k < strlen(buff1); k++) {
                        if (buff1[k] != ' ') {
                            wordsbag2.word[z] = buff1[k];//stores the words in the wordsbag2
                            bufflen2++;//stores the number of words in bag2
                            z++;
                        } else {
                            break;
                        }
                    }
                    arr1[t1] = wordsbag2; //copying every element to words arr1[t1]
                    t1++;
                    i = i + z;
                }
            }
            int lcs = 0;//declaring index for the lcs. this accounts as frequency later
            int len = 0;
            for (i = 0; i < t; i++) {
                int x = i;
                int l[50]={-1};
                    int pos = 0;
                for (j = 0; j < t1; j++) {
                    int h = strcmp(arr[i].word, arr1[j].word);//compare word by word and increase the count for every dissimilar words.
                    if (h == 0) {
                        l[pos] = j;
                        pos++;
                    }
                }
                int k = 0;
                k = 0;
                if (pos > 0) {
                    for (k = 0; k < pos; k++) {
                        int p = l[k];
                        int z = 0;
                        int pos_i = x;
                        len = 0;
                        for (z = 0; z < t1; z++) {
                            int b = strcmp(arr1[p].word, arr[pos_i].word);
                            while (b == 0) {
                                b = strcmp(arr1[p].word, arr[pos_i].word);
                                if (b == 0) {
                                    len = len + (strlen(arr[pos_i].word));
                                    p++;
                                    pos_i++;
                                }
                                if((p>=t1)||(pos_i>=t)){
                                    break;
                                }
                            }
                        }
                        if (len > lcs) {
                            lcs = len;
                        }
                    }
                }
            }
            float den = bufflen1 + bufflen2;//denominator for the problem
            float prob = ((2 * lcs) / den) * 100;
            printf("%0.2f\t\t", prob);
            fclose(fp);
            fclose(fp1);
        }
        printf("\n");
    }
    return 0;
}
