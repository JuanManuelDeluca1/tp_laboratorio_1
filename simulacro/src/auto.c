/*
 * auto.c
 *
 *  Created on: 9 may. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "marca.h"
#include "color.h"
#include "auto.h"
#include "menu.h"

int inicializarAuto(eAuto vec[], int tam)
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




int buscarAutoLibre(eAuto vec[], int tam, int* pIndex)
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
int buscarAutos(eAuto vec[], int tam,int id, int* pIndex)
{
	int todoOk=-0;
	    if(vec != NULL && tam>0 && pIndex != NULL && id > 0)
		{
	    	*pIndex=-1;
			for(int i=0;i<tam;i++)
			{
				if(vec[i].isEmpty == 0 && vec[i].id == id)
				{
					*pIndex=i;
					break;
				}
			}
			todoOk=1;
		}
		return todoOk;
}
int altaAuto(eAuto vec[], int tam, int* pLegajo)
{
    int todoOk = 0;
    int indice;
    int auxMarca;
    int auxColor;
    char auxChar[20];
    eAuto nuevoAuto;


    if(vec != NULL && tam > 0 && pLegajo != NULL)
    {
        if( buscarAutoLibre(vec, tam, &indice) )
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                // aca caigo cuando haya lugar

                printf("Ingrese el id del color: ");
                fflush(stdin);
                scanf("%d", &auxColor);

                while(auxColor <= 5000 && auxColor >= 5004)
                {
                    printf("No exite el id del color. Reingrese el id: ");
                    scanf("%d", &auxColor);
                }
                nuevoAuto.idColor = auxColor;

                printf("Ingrese el id de la marca: ");
                fflush(stdin);
                scanf("%d", &auxMarca);

                while(auxMarca <= 1000 && auxMarca >= 1004)
                {
                    printf("No exite el id de la marca. Reingrese el id: ");
                    scanf("%d", &auxMarca);
                }
                nuevoAuto.idMarca = auxMarca;

                printf("Ingrese el tipo de caja: ");
                fflush(stdin);
                gets(auxChar);

                while(strlen(auxChar) > 20)
                {
                	printf("Nombre del tipo de caja muy largo. Reingrese el Nombre: ");
                	fflush(stdin);
                    gets(auxChar);
                }
                strcpy(nuevoAuto.caja, auxChar);

                nuevoAuto.isEmpty = 0;
                nuevoAuto.id = *pLegajo;
                *pLegajo = *pLegajo + 1;
                vec[indice] = nuevoAuto;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}

int modificarPasajeroPorID(eAuto vec[],int tam)
{
	int todoOk=0;
	int indice;
	int id;
	char salir;
	if(vec != NULL && tam>0)
	{
		listarAuto(vec, tam);
		printf("ingrese id:\n");
		scanf("%d", &id);
	   	if(buscarAutos(vec, tam, id, &indice))
	   	{
			 if(indice==-1)
	   		 {
	   			  printf("no hay un empleado con legajo %d\n", id);
			 }
	   		 else
		     {
	   			 mostrarAuto(vec[indice]);

	   			do
	   			{
	   				switch(opcionesCambio())
	   				{
	   				case 1:
					printf("%d \n", vec[indice].idColor);

					printf("ingrese su nuevo color:\n");
					fflush(stdin);
					scanf("%d", &vec[indice].idColor);
					while(vec[indice].idColor >= 5000 || vec[indice].idColor < 5004)
					{
						printf("id del color inexicistente. Reingrese id:\n ");
	   		            fflush(stdin);
	   		         scanf("%d", &vec[indice].idColor);
					}
					printf("%d nuevo id de color es \n", vec[indice].idColor);
					break;
	   				case 2:
	   				printf("%d \n", vec[indice].idMarca);

	   				printf("Ingrese el nuevo id de marca:\n ");
	   				fflush(stdin);
	   				scanf("%d", &vec[indice].idMarca);

	   				while(vec[indice].idMarca > 1000 || vec[indice].idMarca < 1004)
	   			    {
	   					printf("Id de marca inexicistente. Reingrese id de marca:\n ");
	   					fflush(stdin);
	   					scanf("%d", &vec[indice].idMarca);
	   			    }
	   			   printf("%d id de la marca es \n", vec[indice].idMarca);
	   			   break;
	   			   case 3:
	   				   confirmarSalida(&salir);
	   			   break;
	   			   default:
	   					printf("opcion Invalida!\n\n");
	   		      }
	   	        system("pause");
	          }while(salir != 's');
	     }
      }
	  else
	  {
			printf("Ocurrio un problema\n");
      }
    todoOk=1;
    }
 return todoOk;
}



























void mostrarAuto(eAuto e)
{

    printf("%d      %d      %d      %s\n", e.id, e.idMarca, e.idColor, e.caja);

}


int listarAuto(eAuto vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        //system("cls");
        printf("          *** Listado de Pasajeros ***\n\n");
        printf("id    idMarca    idColor    tipoCaja\n");
        printf("-----------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
        	if(!vec[i].isEmpty)
        	{
        		mostrarAuto(vec[i]);
        	}
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}
