#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	double x, y;
	double eps = 1e-6;
	int k; 


	x = 1.0;
	y = 2.0/3.0;
	k = 1;

	while (fabs(y-x) >= eps){
		x = y;
		k++;
		if (k%2 == 0)	y = x + 1.0 / (2*k + 1);
		else 			y = x - 1.0 / (2*k + 1);
	}

	printf("Approximation de PI =  %.20f \n", 4*y);

	return 0;
}