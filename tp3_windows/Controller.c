#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* f = fopen(path, "r");
	Passenger* pasajero = NULL;
	if(f != NULL && pArrayListPassenger != NULL)
	{
		 pasajero = (Passenger*)parser_PassengerFromText(f, pArrayListPassenger);
		 ll_add(pArrayListPassenger, pasajero);
	}
	else
	{
		printf("No se encontro el archivo");
		exit(1);
	}

    return 1;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* f = fopen(path, "rb");
	Passenger* pasajeroBinario = NULL;
		if(f != NULL && pArrayListPassenger != NULL)
		{
			pasajeroBinario = parser_PassengerFromBinary(f, pArrayListPassenger);
			ll_add(pArrayListPassenger, pasajeroBinario);
		}
		else
		{
			printf("No se encontro el archivo");
			exit(1);
		}

	    return 1;
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* pId)
{
	int todoOk = 0;
	int id = 1001;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipo;
	char codigoVuelo[4];
	Passenger* newPassenger = NULL;
	if(pArrayListPassenger != NULL)
	{
		Passenger* newPassenger = Passenger_new();
			if(newPassenger != NULL)
			{
				printf("Ingrese el nombre del pasajero:\n ");
				fflush(stdin);
			    gets(nombre);

			    while(strlen(nombre) >= 51)
			    {
			    	printf("Nombre demasiado largo. Reingrese nombre:\n ");
			    	fflush(stdin);
					gets(nombre);
			    }
			    strcpy(newPassenger->nombre, nombre);

				printf("Ingrese el apellido del pasajero:\n ");
				fflush(stdin);
				gets(apellido);

				while(strlen(apellido) >= 51)
				{
					printf("Apellido demasiado largo. Reingrese Apellido:\n ");
					fflush(stdin);
					gets(apellido);
				}

				strcpy(newPassenger->apellido, apellido);

				printf("Ingrese precio:\n ");
				fflush(stdin);
				scanf("%f", &precio);

				newPassenger->precio = precio;

				printf("Ingrese codigo del vuelo:\n ");
				fflush(stdin);
				gets(codigoVuelo);

				while(strlen(codigoVuelo) >= 10)
				{
					printf("Codigo del vuelo demasiado largo. Reingrese codigo \n");
					fflush(stdin);
					gets(codigoVuelo);
				}
				strcpy(newPassenger->codigoVuelo, codigoVuelo);

				printf("Ingrese la clase del aciento (1(prime)/2(media)/3(turista))): \n");
				fflush(stdin);
				scanf("%d", &tipo);

				while(tipo > 3 || tipo < 0)
				{
					printf("clase inexistente (1(prime)/2(media)/3(turista))):\n ");
					fflush(stdin);
					scanf("%d", &tipo);
				}
				newPassenger->tipoPasajero = tipo;

			    newPassenger->id = id + 1;;
			}
		if(newPassenger != NULL)
		{
		  ll_add(pArrayListPassenger, newPassenger);
		}

	}


    return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	if(pArrayListPassenger != NULL)
	{

	}
	return todoOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int idAux;
	if(pArrayListPassenger != NULL)
	{
		printf("Ingrese nuevo ID del pasajero que quiere eliminar:\n");
		scanf("%d", &idAux);
		ll_remove(pArrayListPassenger, ll_get(pArrayListPassenger, idAux));
	}
    return todoOk;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* aux = NULL;

	FILE* f = fopen("data.cvs", "r");
	if(f != NULL)
	{
		for(int i=0; i < ll_len(pArrayListPassenger); i++)
		{
			aux = (Passenger*) ll_get(pArrayListPassenger, i);
			mostrarPassenger(aux);
		}
	}

    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* aux;
	ll_sort(pArrayListPassenger, sortPassengerName, 1);
	for(int i=0;i<ll_len(pArrayListPassenger);i++)
	{
		aux = ll_get(pArrayListPassenger, i);
		mostrarPassenger(aux);
	}
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{

    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	return 1;
}

