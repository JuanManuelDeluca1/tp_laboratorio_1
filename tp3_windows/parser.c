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
	Passenger* p;
	if(pArrayListPassenger != NULL)
	{
	  while( !feof(pFile))
	  {
		  fscanf("%d, [^,],[^,],%.2f,%d,[^,]\n", p->id, p->nombre, p->apellido, p->precio, p->tipoPasajero, p->codigoVuelo);
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
	Passenger auxPassenger;
	fread(&auxPassenger, sizeof(Passenger), 1 ,pFile);
    return 1;
}
