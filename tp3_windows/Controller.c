#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Passenger.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* f = fopen("path", "r");
	if(f == NULL && pArrayListPassenger == NULL)
	{
		printf("No se pudo abrir el archivo\n");
		exit(1);
	}
	else
	{
		parser_PassengerFromText(f, pArrayListPassenger);
		fclose(f);
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
	FILE* f = fopen("path", "rb");
	if(f == NULL && pArrayListPassenger == NULL)
	{
		printf("No se pudo abrir el archivo\n");
		exit(1);
	}
	else
	{
		parser_PassengerFromBinary(f, pArrayListPassenger);
		fclose(f);
	}
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* newPassenger = NULL;

	int todoOk = 0;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];


	if(pArrayListPassenger == NULL)
	{
		printf("No se pudo conseguir memoria\n");
		exit(1);
	}
	else
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

		printf("Ingrese el apellido del pasajero:\n ");
		fflush(stdin);
		gets(apellido);

		 while(strlen(apellido) >= 51)
		 {
			 printf("Apellido demasiado largo. Reingrese Apellido:\n ");
			 fflush(stdin);
			 gets(apellido);
		 }

		printf("Ingrese precio:\n ");
		fflush(stdin);
		scanf("%f", &precio);

		printf("Ingrese codigo del vuelo:\n ");
		fflush(stdin);
		gets(codigoVuelo);

		 while(strlen(codigoVuelo) >= 5)
		 {
			 printf("Codigo del vuelo demasiado largo. Reingrese codigo \n");
			 fflush(stdin);
			 gets(codigoVuelo);
		 }

	   printf("Ingrese la clase del aciento (1(Executiveclas)/2(FirstClas)/3(EconomyClas))): \n");
	   fflush(stdin);
	   scanf("%d", &tipoPasajero);

	   while(tipoPasajero > 3 || tipoPasajero < 0)
	   {
			printf("clase inexistente (1(Executiveclas)/2(FirstClas)/3(EconomyClas))):\n ");
			fflush(stdin);
			scanf("%d", &tipoPasajero);
	   }

	}
	newPassenger = newPassenger_Parametros(nombre, apellido,  precio, tipoPasajero, codigoVuelo);
	if(newPassenger == NULL)
	{
		printf("No se pudo conseguir memoria o campos invalios\n");
		exit(1);
	}
	else
	{
		ll_add(pArrayListPassenger, newPassenger);
		todoOk = 1;
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
	int id;
	char nombre[50];
	int tipoPasajero;
	Passenger* aux = NULL;
	if(pArrayListPassenger != NULL)
	{
		printf("Ingrese id del usuario que quiera cambiar los parametros:\n");
		scanf("%d", &id);
		for(int i=0; i<ll_len(pArrayListPassenger);i++)
		{
			aux = (Passenger*) ll_get(pArrayListPassenger, i);
			if(id == aux->id )
			{

				printf("ingrese nuevo nombre:\n");
				fflush(stdin);
				gets(nombre);
				printf("ingrese nuevo clase:\n");
				scanf("%d", &tipoPasajero);
				if(Passenger_newParametros(nombre, tipoPasajero))
				{
					strcpy(aux->nombre, nombre);
					aux->tipoPasajero = tipoPasajero;
					todoOk = 1;
					exit(1);
				}
			}
		}
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
	int id;
	Passenger* aux = NULL;
	if(pArrayListPassenger != NULL)
	{
		printf("ingrese el id del pasajero que quiere eliminar: \n");
		scanf("%d", &id);
		for(int i=0; i<ll_len(pArrayListPassenger);i++)
		{
			aux = (Passenger*) ll_get(pArrayListPassenger, i);
			if(id == aux->id )
			{
				ll_remove(pArrayListPassenger, i);
				printf("Pasajeros eliminado con exito");
				todoOk = 1;
				exit(1);
			}

		}
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
	FILE* f = fopen("path", "a");
	if(f == NULL && pArrayListPassenger == NULL)
	{
		printf("No se pudo abrir el archivo\n");
		exit(1);
	}
	else
	{
		parser_PassengerFromText(f, pArrayListPassenger);
		fclose(f);
	}
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
	FILE* f = fopen("path", "ab");
	if(f == NULL && pArrayListPassenger == NULL)
	{
		printf("No se pudo abrir el archivo\n");
		exit(1);
	}
	else
	{
		parser_PassengerFromBinary(f, pArrayListPassenger);
		fclose(f);
	}
	return 1;
}

