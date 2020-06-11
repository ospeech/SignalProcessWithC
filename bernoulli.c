#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math_general.h"

int main(){
	int i,j,x;
	long int s;
	double p;
	p = 0.3;
	srand((unsigned)time(NULL));
	s = rand() % 10000 + 1;
	for(i=0; i<10; i++){
		for (j=0; j<5; j++){
			x = bernoulli(p, &s);
			printf("%11d",x);
		}
		printf("\n");
	}
}
