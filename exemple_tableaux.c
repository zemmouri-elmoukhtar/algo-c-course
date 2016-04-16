#include <stdio.h>

//Définition d'une constante pour la taille max du tab
#define 	N 		100

/*
Fonction pour lire n éléments réels dans un tableau
*/
void readTab (float t[], int n){
	int i;
	for (i=0; i<n; i++){
		printf("Donner l'élément %d : ", i+1);
		scanf("%f", &t[i]);
	}
}

/*
Fonction pour afficher les élements d'un tableau
*/
void printTab (float t[], int n, char c){
	int i;
	for (i=0; i<n; i++){
		printf("%f%c", t[i], c);
	}
	printf("\n");
}

/*
Fonction qui retourne la somme des éléments d'un tableau
*/
float sum (float t[], int n){
	int i;
	float s;
	s = 0;
	for (i=0; i<n; i++)
		s += t[i];
	return s;
}

/*
Fonction qui retourne la moyenne des éléments d'un tableau
*/
float avg (float t[], int n){
	return sum(t, n)/(float)n;
}

/*
Fonction qui retourne la valeur minimale des éléments d'un tableau
*/
float min (float t[], int n){
	int i;
	float m;
	m = t[0];
	for (i=1; i<n; i++)
		if (t[i] < m) m = t[i];
	return m;
}

/*
Fonction qui retourne la valeur maximale des éléments d'un tableau
*/
float max (float t[], int n){
	int i;
	float m;
	m = t[0];
	for (i=1; i<n; i++)
		if (t[i] > m) m = t[i];
	return m;
}

/**
Fonction pour chercher une valeur x dans un tableau t
Retourne l'indice de la première occurrence de x dans t
et -1 si x n'existe pas dans t
*/
int find (float t[], int n, float x){
	int i;
	for (i=0; i<n; i++)
		if (t[i] == x) return i;
	return -1;
}

/*
Fonction de recherche Dichotomique
Le tableau doit être trié par ordre croissant
*/
int findDicho (float t[], int n, float x){
	int d, f, m;
	d = 0; f = n-1;
	while (d <= f){
		m = (d+f)/2;
		if (t[m] == x) return m;
		if (t[m] < x) d = m+1;
		if (t[m] > x) f = m-1;
	}
	return -1;
}

/**
Fonction de recherche dichotomique par récurrence
*/
int findDichoRec (float t[], int n, float x, int d, int f){
	int m;
	if (d <= f){
		m = (d+f)/2;
		if (t[m] == x) return m;
		if (t[m] < x) return findDichoRec (t, n, x, m+1, f);
		if (t[m] > x) return findDichoRec (t, n, x, d, m-1);
	}
	else return -1;
}

/*
Fonction principale main
*/
int main()
{
	float t[N] = {4, 1, 5, 1, 2, 8, 6, 7};
	int n = 8;
	float x;
	int i;
	

	/*
	do {
		printf("Donner le nombre d'élément entre 1 et  %d : ", N);
		scanf("%d", &n);
	}while (n < 1 || n > N);

	readTab(t, n);
	*/
	
	printf("Les éléments du tableau sont : \n");
	printTab(t, n, '\n');

	printf("Somme des éléments : %f\n", sum(t, n));
	printf("Moyenne des éléments : %f\n", avg(t, n));
	printf("Valeur Min des éléments : %f\n", min(t, n));
	printf("Valeur Max des éléments : %f\n", max(t, n));

	printf("Donner la valeur à chercher : ");
	scanf("%f", &x);

	i = find(t, n, x);

	if (i != -1) printf("%f se trouve à la position %d \n",x, i);
	else printf("%f n'existe pas dans le tableau \n", x);

	return 0;
}