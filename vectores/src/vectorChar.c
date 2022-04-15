/*
 * vectorChar.c
 *
 *  Created on: 13 abr. 2022
 *      Author: juanm
 */

#include <stdio.h>
#include <stdlib.h>

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
char mostrarCaracteres(char* vec, int tam)
{
	int todoOk =0;
    if(vec != NULL && tam > 0)
    {
	   for(int i = 0; i<tam; i++)
	   {
		  printf("%c ", vec[i]);

	   }
	   todoOk=1;
    }
	return todoOk;
}
char pasarAMyusculas(char* vec, int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
		for(int i = 0; i<tam; i++)
		{
			vec[i] = toupper(vec[i]);
		}
		todoOk =1;
	}
	return todoOk;
}
int contarVocales(char* vec, int tam, int* pCantidad)
{
	int todoOk=0;
	char caracterActual;
	if(vec != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			caracterActual = tolower(vec[i]);
			if(caracterActual == 'a' || caracterActual == 'e' || caracterActual == 'i' || caracterActual == 'o' ||
				caracterActual == 'u')
			{
				(*pCantidad) ++;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
int cargarVector(int* vec, int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
		for(int i = 0; i<tam; i++)
		{
			printf("ingrese un numero:");
			scanf("%d", &vec[i]);

			}
		todoOk=1;
	}
	return todoOk;
}

int mostrarEntero(int* vec, int tam)
{
	int todoOk = 0;
	for(int i=0;i<tam;i++)
	{
		printf("%d", vec[tam-1-i]);
	}
	/*for(i=TAM-1;i>0-1;i--)
	{
		printf("%d", numeros[i]);
	}*/
	if(vec != NULL && tam > 0)
	{
		todoOk=1;
	}

	return todoOk;
}
int sumarEntero(int* vec, int tam, int* pTotal)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0 && pTotal != NULL)
	{
		*pTotal = 0;
		for(int i=0; i<tam; i++)
		{
			*pTotal+=vec[i];
		}
		todoOk=1;
	}
	printf("\nla suma es: %d\n", *pTotal);
	return todoOk;
}
int promediarEntero(int* vec, int tam, float* pTotal)
{
	int i;
	if(vec != NULL && tam > 0 && pTotal != NULL)
	{
		*pTotal = 0;
		for(i=0; i<tam; i++)
		{
			*pTotal+=vec[i];
		}
		*pTotal = *pTotal/i;
	}
	printf("el promedio es: %.2f\n", *pTotal);
	return *pTotal;
}
