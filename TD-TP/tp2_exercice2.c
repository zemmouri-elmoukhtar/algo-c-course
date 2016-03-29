/* 
	Exercice 2 de la série de TP 2
	2015-2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
Fonction pour générer un entier aléatoire enre min et max
*/
int entierAleatoire(int min, int max){
	return rand() % (max - min + 1) + min;
}

/**
Fonction pour générer un réel aléatoire entre min et max
*/
double reelAleatoire(double min, double max){
	double a;
	a = (double) rand() / (double)RAND_MAX;
	return a * (max - min) + min;
}

/**
Fonction qui simule l'expérience aléatoire : lancer d'un dé n fois
*/
void simulationDe(int n){
	int a=0, b=0, c=0, d=0, e=0, f=0;  //fréquences des 6 face du dé
	int i, x;

	srand(time(NULL));
	for (i=0; i<n; i++){
		x = entierAleatoire(1, 6);
		switch (x){
			case 1 : {a++; break;}
			case 2 : {b++; break;}
			case 3 : {c++; break;}
			case 4 : {d++; break;}
			case 5 : {e++; break;}
			case 6 : {f++; break;}
		}
	}

	printf("\nResultat de l'experience : \n");
	printf("face 1 : %d fois\n", a);
	printf("face 2 : %d fois\n", b);
	printf("face 3 : %d fois\n", c);
	printf("face 4 : %d fois\n", d);
	printf("face 5 : %d fois\n", e);
	printf("face 6 : %d fois\n", f);
}

/**
Fonction pour tirer un point aléatoire et tester s'il est
à l'intérieur du cercle ou non
*/
int pointSuivant (double r){
	double x, y;

	x = (double)rand()/(double)RAND_MAX;
	y = (double)rand()/(double)RAND_MAX;
	
	if (x*x + y*y <= r*r) return 1;
	else return 0;
}

/**
Fonction pour estimer la surface d'un cercle à l'aide 
de la méthode de Monté Carlo"
*/
double surfaceCercle (double r, int n){
	int i, cpt;

	srand(time(NULL));

	for (i=0; i<n; i++)
		if (pointSuivant(r)) cpt++;
	
	return 4 * r * r * ((double)cpt/(double)n);
} 


/**
Fonction principale 
*/
int main()
{
	int n;
	double r, s, pi;

	printf("\n\n:::::::::::: SIMULATION DU DE ::::::::::::::::::::::::\n\n");
	printf("Donner le nombre de lancees : ");
	scanf("%d", &n);
	simulationDe(n);

	printf("\n\n:::::::::::: SURFACE DU CERCLE ET PI :::::::::::::::::\n\n");
	printf("Donnez le rayon du cercle : ");
	scanf("%lf", &r);
	printf("Donnez le nombre de points : ");
	scanf("%d", &n);

	s = surfaceCercle(r, n);
	pi = s / (r*r);
	printf("\nSurface du cercle : %f\n", s);
	printf("Valeur de pi : %.20f\n", pi);

	//system("pause");
	return 0;
}