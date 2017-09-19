#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{ 
	x[] = {1,2,3,4,5};
	y[] = {1,2,3,4,4,5};

	float freq1=0,dot=0,freq2=0,prob=0;
            int sq1=0,sq2=0;
            for(i=0;i<4;i++){
                sq1=sq1+(x[i]*x[i]);
                sq2=sq2+(y[i]*y[i]);
                dot=dot+(x[i]*y[i]);

            }
            freq1=sqrtf(abs(sq1));
            freq2=sqrtf(abs(sq2));
            prob=dot/(freq1*freq2);
            printf("%.2f\t", (prob * 100));

}