#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math_general.h"

int main(){
	int i,j;
	long int s;
	double p, x, mean, sigma;
	p = 0.4; mean = 0.0; sigma = 1.0;
	srand((unsigned)time(NULL));
	s = rand() % 10000 + 1;
	for(i=0; i<10; i++){
		for (j=0; j<5; j++){
			x = bern_gauss(p,mean,sigma, &s);
			printf("%13.7f",x);
		}
		printf("\n");
	}
}
