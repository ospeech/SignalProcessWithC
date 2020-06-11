#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math_general.h"

// generate 50 numbers of alpha = 1.0, beta=1.0
int main(){
	int i,j;
	long int s;
	double x, alpha,beta;
	alpha = beta = 1.0;
	srand((unsigned)time(NULL));
	s = rand() % 10000 + 1;
	for(i=0; i<10; i++){
		for (j=0; j<5; j++){
			x = cauchy(alpha,beta, &s);
			printf("%13.7f",x);
		}
		printf("\n");
	}
}
