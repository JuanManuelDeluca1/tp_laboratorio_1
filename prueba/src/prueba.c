/*
 ============================================================================
 Name        : prueba.c
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
	int x;
	printf("ingrese un numero: ");
	scanf("%d", &x);
	while(x > 10 || x < 0)
	{
		printf("ingrese un numero: ");
			scanf("%d", &x);
	}
	return 0;
}
