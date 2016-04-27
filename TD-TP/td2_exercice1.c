#include <stdio.h>

#define  TAILLE_MAX   10

/*
Fonction qui retourne le nombre d'occurrence d'un élément 
x dans un tableau t
*/
int nombreOccurrence (int t[], int n, int x){
	int i, cpt = 0;
	for (i=0; i<n; i++)
		if (t[i] == x) cpt++;
	return cpt;
}

/*
Fonction qui affiche l'élément le plus fréquent
dans un tableau t
*/
void frequentElement (int t[], int n){
	int i, cptmax, imax, cpt;
	cptmax = 0;
	for (i=0; i<n; i++){
		cpt = nombreOccurrence (t, n, t[i]);
		if (cpt > cptmax){
			cptmax = cpt;
			imax = i;
		}
	}
	printf("L'élément le plus fréquent est : %d\n", t[imax]);
	printf("Son indice :                     %d\n", imax);
	printf("Son nombre d'occurrence :        %d\n", cptmax);
}


int prime (int n){
	if (n==1) return 0;
	for (int i=2; i <= n/2; i++)
		if (n%i == 0) return 0;
	return 1;
}


int main()
{
	int t[TAILLE_MAX] = {5, 5, 7, 2, 7, 8, 7, 3};
	int n = 8;
	int i, j;




	//Question 1 : les deux plus grand éléments
	
	int a, b;
	a = t[0];
	i = 1;
	while (i<n && t[i] == a) {
		i++;
	}
	if (i<n){
		if (t[i] > a) b = t[i];
		else {b = a; a = t[i]; }

		for (i=i+1; i<n; i++){
			if (t[i]>b) {a = b; b = t[i];}
			else if (t[i]>a && t[i] != b) a = t[i];
		}
		printf("les deux max : %d\t%d\n", a, b);
	}
	else printf("une seule valeur dans le tableau : %d\n", a);




	//Question 2 : élément le plus fréquent

	int cpt , cptmax, imax;
	cptmax = 0;
	for (i=0; i<n; i++){
		cpt = 1;
		for (j = i+1; j<n; j++){
			if (t[i] == t[j]) cpt++;
		}
		if (cpt > cptmax){
			cptmax = cpt;
			imax = i;
		}
	}
	printf("L'élément le plus fréquent est :  %d\n",t[imax]);
	printf("Son indice :                      %d\n", imax);
	printf("Son nombre d'occurence :          %d\n", cptmax);

	//Ou bien, on fait appel à la fonction frequentElement
	frequentElement(t, n);




	//Question 3 : la mediane
	//On suppose un tableau de taille impaire et sans répétition

	int mediane, droit, gauche;
	for (i=0; i<n; i++){
		mediane = t[i]; droit = 0; gauche = 0;
		for (j=0; j<n; j++){
			if (t[i] < mediane ) gauche++;
			else droit ++;
		}
		if (gauche == droit) break;
	}
	printf("La valeur de la mediane est : %d\n",mediane);




	//Question 4 : nombres premiers dans le tableau

	printf("Les éléments premiers dans le tableau sont : \n");
	for (i = 0; i < n; i++)
	{
		if (prime(t[i])) printf("%d\n", t[i]);
	}


	//Question 5 : inversion du tableau :

	int tmp;
	i = 0; j = n-1;
	while (i < j){
		tmp  = t[i];
		t[i] = t[j];
		t[j] = tmp;
		i++;
		j--;
	}

	printf("Les éléments du tableau apres inversion : \n");
	for (i=0; i<n; i++)
		printf("%d\n", t[i]);

	return 0;
}