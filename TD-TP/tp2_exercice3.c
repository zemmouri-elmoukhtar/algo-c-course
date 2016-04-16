#include <stdio.h>

// Variable globale
int N = 0;

/*
Fonction qui retourne le nième terme de la suite de Fibonacci
*/
long fibo(int n){
	if (n==1 || n==0) return 1;
	else return fibo(n-1) + fibo(n-2);
}


/*
Fonction qui retourne le nième terme de la suite de Fibonacci
et qui compte le nombre d'appels récursifs 
*/
long fibo2(int n){
	N++;
	if (n==1 || n==0) return 1;
	else return fibo2(n-1) + fibo2(n-2);
}


/*
Fonction qui retourne le nième terme de la suite de Fibonacci
en réduisant le nombre d'appels recursif
et qui compte le nombre d'appels récursifs 
*/
long fibo3(int n, int u0, int u1){
	N++;
	if (n==0) return u0;
	if (n==1) return u1;
	else return fibo3(n-1, u1, u0+u1);
}


int main()
{
	int n, i;
	long u;

	printf("Donner n : ");
	scanf("%d", &n);

	// Affichage des n termes et le nombres d'appels récurssifs
	printf("i     fibo(i)   N\n");

	for (i=0; i<=n; i++){
		N = 0;
		u = fibo2(i);
		printf("%d\t%ld\t%d\n",i, u, N);
	}

	// Affichage des n termes et le nombres d'appels récurssifs réduits
	printf("i     fibo(i)   N\n");

	for (i=0; i<=n; i++){
		N = 0;
		u = fibo3(i, 1, 1);
		printf("%d\t%ld\t%d\n",i, u, N);
	}

	return 0;
}
