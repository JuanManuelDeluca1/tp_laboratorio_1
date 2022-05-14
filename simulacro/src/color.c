/*
 * color.c
 *
 *  Created on: 9 may. 2022
 *      Author: juanm
 */

#include <stdio.h>
#include <stdlib.h>

#include "color.h"

int inicializarColor(eColores vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}




int buscarColorLibre(eColores vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

void mostrarColores(eColores e)
{

    printf("%d      %s\n", e.id, e.descripcion);

}


int listarColores(eColores vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        //system("cls");
        printf("          *** Listado de colores ***\n\n");
        printf("id    descripcion\n");
        printf("-----------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
        	if(!vec[i].isEmpty)
        	{
        		mostrarColores(vec[i]);
        	}
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}