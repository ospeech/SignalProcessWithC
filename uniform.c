#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math_general.h"
int main(){
	double a,b,x;
	int i,j;
	long int s;
	a = 0.0;b = 1.0;
   	/* s = 13579;*/
	srand((unsigned)time(NULL));
	s = rand() % 10000 + 1;
	for(i=0; i<10; i++){
		for(j=0; j<5; j++){
			x = uniform(a,b,&s);
			printf("%13.7f",x);
		}
		printf("\n");
	}
}
