#include <stdio.h>

/**
Fonction qui affiche un caractère x n fois
*/
void repeatChar(char x, int n){
	int i;
	for (i=0; i<n; i++)
		printf("%c", x);
}

/**
Fonction pour afficher l'arbre de sapin :)
*/
void printTree(int n){
	int i, t;

	for (i=0; i<n; i++){
		repeatChar(' ', n-1-i);
		repeatChar('*', 2*i+1);
		printf("\n");
	}

	t = (n-1)/6;
	for (i=0; i<n/3; i++){
		repeatChar(' ', n-t-1);
		repeatChar('|', 2*t + 1);
		printf("\n");
	}

	for (i=0; i<n/2; i++){
		printf("-\\/-");
	}

	printf("\n\n");
}

/**
Fonction pour affichage du traingle de nombres de 1 à n(n+1)/2
*/
void printTriangle(int n){
	int i, j, v;

	v = 1;
	for (i=0; i<n; i++){
		for (j=0; j<=i; j++){
			printf("%d\t", v);
			v++;
		}
		printf("\n");
	}
}


int main(int argc, char const *argv[])
{
	int n; 

	// Question 1 - affichage de l'arbre
	printf("Donnez la taille de l'arbre : ");
	scanf("%d", &n);
	printTree(n);

	// Question 2 - affichage du traingle
	printf("\nDonnez la taille du triangle : ");
	scanf("%d", &n);
	printTriangle(n);
	printf("\n\n");

	return 0;
}

