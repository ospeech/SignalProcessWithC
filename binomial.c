#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math_general.h"

int main(){
	int i,j,n,x;
	long int s;
	double p;
	n = 5; p = 0.7;
	srand((unsigned)time(NULL));
	s = rand() % 10000 + 1;
	for(i=0; i<10; i++){
		for (j=0; j<5; j++){
			x = binomial(n, p, &s);
			printf("%11d",x);
		}
		printf("\n");
	}
}
