/*
 * array.c
 *
 *  Created on: 27 abr. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array.h"

int inecializarEmpleados(eEmpleado vec[], int tam)
{
	int todoOk=0;
	if(vec != NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			vec[i].isEmpty = 1;
		}
		todoOk=1;
	}
	return todoOk;
}
int buscarEmpleadoLibre(eEmpleado vec[], int tam, int* pIndex)
{
	int todoOk=-0;
    if(vec != NULL && tam>0 && pIndex != NULL)
	{
    	*pIndex=-1;
		for(int i=0;i<tam;i++)
		{
			if(vec[i].isEmpty == 1)
			{
				*pIndex=i;
				break;
			}
		}
		todoOk=1;
	}
	return todoOk;
}
int altaEmpleado(eEmpleado vec[], int tam, int* pLegajo)
{
	int todoOk = 0;
	int indice;
	char auxCad[100];
	eEmpleado aux;
	if(vec != NULL && tam>0 && pLegajo != NULL)
	{
		if(buscarEmpleadoLibre(vec, tam, &indice))
		{
			if(indice == -1)
			{
				printf("no hay lugar en el sistema");
			}
			else
			{
			// aca caigo cuando halla lugar ´para guardar empleado
				  printf("Ingrese el nombre del alumno: ");
		          fflush(stdin);
     	          gets(auxCad);

     	          while(strlen(auxCad) >= 20)
		          {
			            printf("Nombre demasiado largo. Reingrese nombre: ");
		                fflush(stdin);
		                gets(auxCad);
	              }
		          strcpy(aux.nombre, auxCad);


	             printf("Ingrese sexo('m' o 'f'): ");
				 fflush(stdin);
				 scanf("%c", &aux.sexo);

				 printf("Ingrese edad: ");
				 scanf("%d", &aux.edad);

			     printf("Ingrese sueldo: ");
				 scanf("%f", &aux.sueldo);
				 aux.isEmpty = 0;
				 aux.legajo = *pLegajo;
				 *pLegajo = *pLegajo +1;
				  vec[indice] =  aux;
		          todoOk=1;
			}
		}
		else
		{

		}

	}
	return todoOk;
}

int buscarEmpleado(eEmpleado vec[], int tam,int legajo, int* pIndex)
{
	int todoOk=-0;
	    if(vec != NULL && tam>0 && pIndex != NULL && legajo > 0)
		{
	    	*pIndex=-1;
			for(int i=0;i<tam;i++)
			{
				if(vec[i].isEmpty == 0 && vec[i].legajo == legajo)
				{
					*pIndex=i;
					break;
				}
			}
			todoOk=1;
		}
		return todoOk;
}
int bajaEmpleado(eEmpleado vec[], int tam)
{
	int todoOk=0;
	int legajo;
	int indice;
	char confirmar;
		    if(vec != NULL && tam>0)
			{
		    	listarEmpleados(vec, tam);
		    	printf("ingrese legajo:\n");
		    	scanf("%d", &legajo);
		    	if(buscarEmpleado(vec, tam, legajo, &indice))
		    	{
		    		if(indice==-1)
		    		{
		    			printf("no hay un empleado con legajo %d\n", legajo);

		    		}
		    		else
		    		{
		    			mostrarEmpleado(vec[indice]);
		    			printf("Confirmar baja?:");
		    			fflush(stdin);
		    			scanf("%c", &confirmar);
		    			if(confirmar!= 's' && confirmar != 'S')
		    			{
		    				printf("Baja del usuario confirmada\n");
		    			}
		    			else
		    			{
		    				vec[indice].isEmpty = 1;
		    				printf("Baja confirmada");
		    				todoOk=1;
		    			}
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



























void mostrarEmpleado(eEmpleado e)
{

    printf("%4d    %s    %c    %d    %.2f    \n", e.legajo, e.nombre, e.sexo, e.edad, e.sueldo);

}


int listarEmpleados(eEmpleado vec[], int tam)
{
    int todoOk = 0;
    int flag=0;
    if(vec != NULL && tam > 0)
    {
        //system("cls");
        printf("          *** Listado de Empleados ***\n\n");
        printf("id    nombres    apellido    precio    codigo    tipo    estado\n");
        printf("-----------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
        	if(!vec[i].isEmpty)
        	{
        		mostrarEmpleado(vec[i]);
        		flag++;
        	}
        }
        if(flag==0)
        {
        	printf("no hay empleados en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}
