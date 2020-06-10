#ifndef MATH_GENERAL_H_
#define MATH_GENERAL_H_
/*
 * Algorithm Description:
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


#endif
