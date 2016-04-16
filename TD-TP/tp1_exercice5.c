#include <stdio.h>
#include <math.h>

/*
Fonction un quart de cerle de rayon r = 1 
*/
double f (double x){
	return sqrt(1.0 - x*x);
}

/*
Fonction pour calculer l'intégral d'une fonction f sur 
l'interval [a, b] avec une subdivision de taille n
*/
double integrationRectangles (double a, double b, int n){
	double x, w, s;
	int i;

	w = (b-a)/n;

	for (s = 0, i=0; i<n; i++){
		x = a + i*w + w/2.0;
		s += w * f(x);
	}

	return s;
}


int main(int argc, char const *argv[])
{
	int n;
	double pi;

	printf("Donner n : ");
	scanf("%d", &n);

	pi = 4 * integrationRectangles(0.0, 1.0, n);

	printf("Valeur approchée de pi = %.10f\n", pi);
	
	return 0;
}