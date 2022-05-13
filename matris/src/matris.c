/*
 ============================================================================
 Name        : matris.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define FIL 3
#define COL 5

int mostrarVectorEnteros(int vec[], int tam);
int mostrarMatrizEnteros(int filas, int col, int mat[][col]);
int cargarMatrizEnteros(int filas, int col, int mat[][col]);

int main()
{
	setbuf(stdout,NULL);



    // printf("%d\n", vec[5] );
    // mostrarVectorEnteros(vec, COL);

    int numeros[FIL][COL];

    cargarMatrizEnteros(FIL, COL, numeros);


    // mostrarVectorEnteros(numeros, 48);
    // printf("%d\n", numeros[3][4]);
    // mostrarVectorEnteros(numeros[2], COL);
    mostrarMatrizEnteros(FIL, COL, numeros);





    return 0;
}


int mostrarVectorEnteros(int vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            printf("%d ", vec[i]);
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}


int mostrarMatrizEnteros(int filas, int col, int mat[][col])
{
    int todoOk = 0;
    if(mat != NULL && filas > 0)
    {
        for(int i=0; i < filas; i++)  // recorre las filas
        {
            for(int j = 0; j < col; j++) // recorre columnas
            {

                printf("%d ", mat[i][j]);

            }
            printf("\n");
        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;
}

int cargarMatrizEnteros(int filas, int col, int mat[][col])
{
    int todoOk = 0;
    if(mat != NULL && filas > 0)
    {
        for(int i=0; i < filas; i++)  // recorre las filas
        {
            for(int j = 0; j < col; j++) // recorre columnas
            {

                printf("Ingrese un numero: ");
                scanf("%d", &mat[i][j]);
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

