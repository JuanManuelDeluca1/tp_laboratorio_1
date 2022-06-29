#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int id;
	char nombre[200];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	Passenger* p = NULL;
	if(pArrayListPassenger != NULL)
	{
		fscanf(pFile, "%s", nombre);
	   while( !feof(pFile))
	   {
		   fscanf(pFile, "%d, [^,],[^,],%.2f,%d,[^,]\n", &id, nombre, apellido, &precio, &tipoPasajero, codigoVuelo);
		   Passenger_Parametro(id, nombre, apellido,precio, tipoPasajero, codigoVuelo);
	   }
	}
    return 1;
}
/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int id;
		char nombre[200];
		char apellido[50];
		float precio;
		int tipoPasajero;
		char codigoVuelo[4];
		Passenger* p = NULL;
		if(pArrayListPassenger != NULL)
		{
			fscanf(pFile, "%s", nombre);
		   while( !feof(pFile))
		   {
			   fscanf(pFile, "%d, [^,],[^,],%.2f,%d,[^,]\n", &id, nombre, apellido, &precio, &tipoPasajero, codigoVuelo);
			   Passenger_Parametro(id, nombre, apellido,precio, tipoPasajero, codigoVuelo);
		   }
	   }
	   return 1;
}
