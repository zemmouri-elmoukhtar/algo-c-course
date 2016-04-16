/* 
	Exercice 1 de la série de TP 2
	2015-2016
*/ 


#include <stdio.h>
#include <stdlib.h>


//Declaration des fonctions

long fact(int);
long binome(int, int);
void printPascal(int);

/* Fonction itérative pour calculer la factorielle d'un entier */
long fact (int n){
	int i;
	long f = 1;
	for (i=2; i<=n; i++)
		f *= i;
	return f;
}

/* Fonction binomiale : choix de k parmi n */
long binome(int n , int k){
	return fact(n)/(fact(k)*fact(n-k));
}

/* Fonction pour afficher le triangle de Pascal de n+1 lignes */
void printPascal(int n){
	int i, j;
	for (i=0; i<=n; i++){
		for (j=0; j<=i; j++){
			printf("%ld\t", binome(i,j));
		}
		printf("\n");
	}
}

/* Fonction principale main */
int main()
{
	int n;

	printf("Donnez la taille du triangle : ");
	scanf("%d", &n);
	printPascal(n);
	//system("pause");
	return 0;
}