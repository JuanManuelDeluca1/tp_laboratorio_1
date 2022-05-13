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
{// mustra las vocales
	int todoOk;
	x = tolower(x);
	if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
	{
		todoOk = 1;
	}
	return todoOk;
}
char pedirCdena(char* vec, int tam)
{// pide letras para un char
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
		printf("ingrese su nombre: ");
		scanf("%s", vec);
		printf("su nombre es: %s\n", vec);
	}
	return todoOk;
}
int mostrarEntero(int* vec, int tam)
{//mustra los enteros del vector
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
int mostrarFlotante(float* vec, int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0)
	{
	  for(int i=0;i<tam;i++)
	  {
		 printf("%.2f", vec[i]);
	  }
	  todoOk=1;
	}

	return todoOk;
}
int ordenarEneteros(int* vec, int tam, int criterio)
{// ordena los numero de un vector
	int todoOk = 0;
	int vecAux;
	if(vec != NULL && tam > 0 && criterio>=0 && criterio<=1)
	{
		for(int i = 0; i<tam-1 ; i++)
	    {
		   	for(int j = i+1; j<tam ; j++)
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
char mostrarCaracteres(char* vec, int tam)
{//mustras los caracteres de un vec
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
{// pasa la letras de un vector a mayusculas
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
{// cuenta las vocales
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
{// carga un vector
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

int sumarEntero(int* vec, int tam, int* pTotal)
{// sumas los numeros de un vec
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
{// promedio los numeros de un vector
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
void swap(int* num1, int* num2)
{
	int aux;
	aux = *num1;
	*num1 = *num2;
	*num2 = aux;
}
void swapString (char* n1,char* n2){
    char aux[100];
    strcpy(aux,n1);
    strcpy(n1,n2);
    strcpy(n2,aux);
}

void swapChar (char* n1,char* n2){
    char aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}
void swapFlotantes(float* n1,float* n2){
    float aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}
int listarNotas(int n1[], int n2[], float proms[], int tam){
 int todoOk = 0;
    if(n1 != NULL && n2 != NULL && proms != NULL && tam > 0)
    {
        system("cls");
        printf("      *** Listado de Notas ***\n\n");
        printf("  Parcial1   Parcial2   Promedio\n");

        for(int i=0; i < tam; i++)
        {
            printf("      %2d         %2d        %5.2f\n", n1[i], n2[i], proms[i]);
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int ordenarPromedios(int n1[], int n2[], float proms[], int tam, int criterio)
{
	int todoOk = 0;
	int vecAux;
	if(n1 != NULL && n2 != NULL && proms != NULL && tam > 0 && criterio>=0 && criterio<=1)
	{
		for(int i = 0; i<tam-1 ; i++)
	    {
		   	for(int j = i+1; j<tam ; j++)
		   	{
		      if(criterio == 1 && proms[i] < proms[j])
			  {
				vecAux = proms[i];
				proms[i] = proms[j];
			    proms[j] = vecAux;
			  }
		       else
		       {
		    	 vecAux = proms[i];
		         proms[i] = proms[j];
		         proms[j] = vecAux;
		       }
		     }
		}
		 todoOk = 1;
	  }
	return todoOk;

}
