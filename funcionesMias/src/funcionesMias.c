/*
 ============================================================================
 Name        : funcionesMias.c
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
	printf("hello word");
	return 0;
}
int esVocal(char x)
{
	int todoOk;
	x = tolower(x);
	if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
	{
		todoOk = 1;
	}
	return todoOk;
}
char pedirCdena(char* vec, int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
		printf("ingrese su nombre: ");
		scanf("%s", vec);
		printf("su nombre es: %s\n", vec);
	}
	return todoOk;
}
