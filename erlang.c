#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math_general.h"

int main(){
	int i,j,m;
	long int s;
	double x, beta;
	m = 3;beta = 1.0;
	srand((unsigned)time(NULL));
	s = rand() % 10000 + 1;
	for(i=0; i<10; i++){
		for (j=0; j<5; j++){
			x = erlang(m,beta, &s);
			printf("%13.7f",x);
		}
		printf("\n");
	}
}
