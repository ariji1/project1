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
float lcs(char *buff, char *buff1)
{
			int t = 0,i,j;
            int bufflen1 = 0;
            struct wordsbag arr[1000] = {'\0'};
            for (i = 0; i < strlen(buff); i++) {
                if (isalnum(buff[i])) {
                    int k = 0;
                    int z = 0;
                    struct wordsbag wordsbag1={'\0'};
                    for (k = i; k < strlen(buff); k++) {
                        if (buff[k] != ' ') {
                            wordsbag1.word[z] = buff[k];
                            bufflen1++;
                            z++;
                        } else {
                            break;
                        }
                    }
                    arr[t] = wordsbag1;
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
                            wordsbag2.word[z] = buff1[k];
                            bufflen2++;
                            z++;
                        } else {
                            break;
                        }
                    }
                    arr1[t1] = wordsbag2;
                    t1++;
                    i = i + z;
                }
            }
            int lcs = 0;
            int len = 0;
            for (i = 0; i < t; i++) {
                int x = i;
                int l[50]={-1};
                    int pos = 0;
                for (j = 0; j < t1; j++) {
                    int h = strcmp(arr[i].word, arr1[j].word);
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
            float den = bufflen1 + bufflen2;
            float prob = ((2 * lcs) / den) * 100;
            //printf("%f\t", prob);
            return prob;
            //fclose(fp);
            //fclose(fp1);

}