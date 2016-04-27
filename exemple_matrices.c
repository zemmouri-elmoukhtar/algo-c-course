#include <stdio.h>

// Définition de constantes pour la taille max de la matrice
#define NBLIG 10
#define NBCOL 20

/*
Fonction pour lire une matrice de taille nxm
*/
void readMat (float M[][NBCOL], int n, int m){
	int i, j;
	for(i=0; i<n; i++){
		for (j=0; j<m; j++){
			printf("Donner l'élément %d  %d : ", i, j);
			scanf("%f", &M[i][j]);
		}
	}
}

/*
Fonction pour afficher une matrice de taille nxm
*/
void printMat (float M[][NBCOL], int n, int m){
	int i, j;
	for(i=0; i<n; i++){
		for (j=0; j<m; j++){
			printf("%.2f\t", M[i][j]);
		}
		printf("\n");
	}
}

/*
Fonction somme de deux matrices
*/
void somme (float A[][NBCOL], float B[][NBCOL], float S[][NBCOL], int n, int m){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			S[i][j] = A[i][j] + B[i][j];
		}
	}
}

/*
Fonction produit de deux matrices 
*/
void produit(float A[][NBCOL], float B[][NBCOL], float P[][NBCOL], int n, int p, int m){
	int i, j, k;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			P[i][j] = 0;
			for (k=0; k<p; k++)
				P[i][j] += A[i][k]*B[k][j];
		}
	}
}



int main()
{
	float a[NBLIG][NBCOL] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	float b[NBLIG][NBCOL] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
	float s[NBLIG][NBCOL];
	float c[NBLIG][NBCOL];
	int n = 3, m = 3 , p = 3;
/*
	do{
		printf("Donner le nombre de lignes et de colonnes  : ");
		scanf("%d%d", &n, &m);
	}while (n<=0 || n>NBLIG || m<=0 || m>NBCOL);

	readMat(A, n, m);
*/
	printf("Matrice 1 : \n");
	printMat(a, n, m);
	printf("Matrice 2 : \n");
	printMat(b, n, m);

	somme(a, b, s, n, m);

	printf("Matrice somme : \n");
	printMat(s, n, m);

	produit(a, b, c, n, p, m);
	printf("Matrice produit : \n");
	printMat(c, n, m);	


	return 0;
}