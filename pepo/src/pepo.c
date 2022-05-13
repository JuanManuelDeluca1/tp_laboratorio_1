/*
 ============================================================================
 Name        : pepo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	int numero1 = 5;
	int numero2 = 10;
	int suma;
	char i;
	suma = numero1 + numero2;

	printf("%d\n\n", suma);
	do
	{
		printf("que onda rey\n");
		printf("queres otro que onda rey?:\n");
		scanf("%s", &i);

	}while(i != 'n');





	return 0;
}
