#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math_general.h"

int main(){
	int i,n,p,q;
	long seed;
	double mean, sigma, x[200];
	static double a[3] = {1.0, 1.45, 0.6};
	static double b[3] = {1.0, -0.2, -0.1};
	FILE *fp;
	n = 200;
	p = 2;
	q = 2;
	// seed = 13579l;
	srand((unsigned)time(NULL));
	seed = rand() % 10000 + 1;
	
	mean = 0.0;
	sigma = 0.5;

	arma(a, b, p, q, mean, sigma, &seed, x, n);
	for(i=0; i<32; i+= 4){
		printf("	%10.7lf		%10.7lf", x[i],x[i+1]);
		printf("	%10.7lf		%10.7lf", x[i+2],x[i+3]);
		printf("\n");
	}
	fp = fopen("arma.txt", "w");
	for(i=0; i<n; i++){
		fprintf(fp, "%d %lf\n",i,x[i]);
	}
	fclose(fp);
}
