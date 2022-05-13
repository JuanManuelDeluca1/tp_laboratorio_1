/*
 ============================================================================
 Name        : fors.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int mostrarEntero(int* vec, int tam);
int ordenarEnterosAsc(int* vec, int tam);
int ordenarEneteros(int* vec, int tam, int criterio);

int main(void) {
	int vec[TAM]={5,8,2,9,4};
	int criterio=0;
	ordenarEneteros(vec, TAM, criterio);
	mostrarEntero(vec, TAM);
	return 0;
}
int mostrarEntero(int* vec, int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
	  for(int i=0;i<tam;i++)
	  {
		 printf("%d", vec[i]);
	  }
	  todoOk=1;
	}
	/*for(i=TAM-1;i>0-1;i--)
	{
		printf("%d", numeros[i]);
	}*/
	return todoOk;
}
int ordenarEnterosAsc(int* vec, int tam)
{
	int todoOk = 0;
	int vecAux;
    if(vec != NULL && tam > 0)
	{
	 for(int i = 0; i<TAM-1 ; i++)
	 {
		for(int j = i+1; j<TAM ; j++)
		{
			if(vec[i] > vec[j])
			{
				vecAux = vec[i];
				vec[i] = vec[j];
				vec[j] = vecAux;
			}
		}
	  }
	  todoOk = 1;
	}
	return todoOk;

}
int ordenarEneteros(int* vec, int tam, int criterio)
{
	int todoOk = 0;
	int vecAux;
	if(vec != NULL && tam > 0 && criterio>=0 && criterio<=1)
	{
		for(int i = 0; i<TAM-1 ; i++)
	    {
		   	for(int j = i+1; j<TAM ; j++)
		   	{
		      if(criterio == 1 && vec[i] < vec[j])
			  {
				vecAux = vec[i];
				vec[i] = vec[j];
			    vec[j] = vecAux;
			  }
		       else
		       {
		    	 vecAux = vec[i];
		         vec[i] = vec[j];
		         vec[j] = vecAux;
		       }
		     }
		}
		 todoOk = 1;
	  }
	return todoOk;
}






