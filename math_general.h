#ifndef MATH_GENERAL_H_
#define MATH_GENERAL_H_
#include <math.h>

/* Algorithm Description:
 * the pdf of uniform distribution is:
 * f(x) = 1/(b-a) if a <= x <= b else 0
 * the mean if (a+b)/2 and the varience is (a-b)^2/12
 *
 * generating algorithm:
 * x_i = (k*x_i-1 + c) mod M
 * y_i = x_i / M
 * z_i = a + (b-a)*y_i then z_i is between in (a,b)
 */

// generate the random double number between a and b
double uniform(double a, double b, long int *seed){
	double t;
	*seed = 2045 * (*seed) + 1;
	*seed = *seed - (*seed/1048576) * 1048576;
	t = (*seed)/1048576.0;
	t = a + (b-a) * t;
	
	return t;
}

/* Algorithm Description:
 * suppose r_1,r_2 ... is according to uniform distribution (0,1).
 * E(r_i) = 1/2, D(r_i) = 1/12. Acoording to Central Limit Theorems，
 * x = sqrt(12/n) * (Sigma(r_i) - n/2) closed to N(0,1) while n is so bigger.
 * normally, n=12, and x = Sigma(r_i) - 6,
 * y = mean + sigma * x and y closed to N(mean, sigma^2).
 */

// generate the random double number regarding Gaussian distribution N(u,o^2)
double gauss(double mean, double sigma, long int *seed){
	int i; double x, y;

	for(x=0, i=0; i<12; i++){
		x += uniform(0.0, 1.0, seed);
	}
	x = x - 6.0;
	y = mean + x * sigma;
	
	return y;
}

// generate the mean=beta, variance=beta^2 exponent distribution
double exponent(double beta,long int *seed){
	double u, x;
	u = uniform(0.0, 1.0, seed);
	x = -beta * log(u);

	return x;
}

#endif
