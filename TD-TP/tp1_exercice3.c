#include <stdio.h>


int main()
{
	char c;

	printf("Table des caractères ASCII : \n\n");

	printf("Char    Déc     Hex \n");

	c = 0;
	do{
		printf("%c\t%d\t%x\n", c, c, c);
		c++;
	}while (c!=0);

	return 0;
}