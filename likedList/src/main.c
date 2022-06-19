/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pasajeros.h"
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int main(void)
{
	setbuf(stdout,NULL);

	Passenger* pasj = NULL;
	Passenger* aux = NULL;
	LinkedList* listaPasajeros = ll_newLinkedList();
	LinkedList* auxList = ll_newLinkedList();
	LinkedList* newList = ll_newLinkedList();
	LinkedList* copiList = ll_newLinkedList();

	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int cant;



	if(listaPasajeros == NULL)
	{
	   	printf("No hay memoria disponible");
	   	exit(1);
	}

	FILE* f = fopen("Lista.csv", "r");

	if(f != NULL)
	{

		cant = fscanf(f, "%d, %[^,], %[^,], %f, %d, %[^,]\n", &id, nombre, apellido, &precio, &tipoPasajero, codigoVuelo);
		if(cant == 6)
	    {
			pasj = newPassenger_Parametros(id, nombre, apellido, precio, tipoPasajero, codigoVuelo);
			if(pasj != NULL)
			{
				ll_add(listaPasajeros, pasj);
			}
		 }
		fclose(f);
	}

	printf("cant %d\n", ll_len(listaPasajeros));

	for(int i=0;i<ll_len(listaPasajeros);i++)
	{
		aux = (Passenger*) ll_get(listaPasajeros, i);
		mostrarPassenger(aux);
	}

	ll_sort(listaPasajeros, ordenar_Passenger, 1);

	for(int i=0;i<ll_len(listaPasajeros);i++)
	{
		aux = ll_get(listaPasajeros, i);
		mostrarPassenger(aux);
	}


	ll_push(listaPasajeros, 5, pasj);
	ll_pop(listaPasajeros, 2);
	ll_set(listaPasajeros, 3, pasj);
	ll_remove(listaPasajeros, 4);
	ll_clear(listaPasajeros);
	ll_indexOf(listaPasajeros, pasj);
	ll_isEmpty(listaPasajeros);
	ll_contains(listaPasajeros, pasj);
	ll_containsAll(listaPasajeros, auxList);
	ll_subList(newList, 3, 2);
	ll_clone(copiList);




	ll_deleteLinkedList(listaPasajeros);








	/*startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
    startTesting(19); // ll_sort*/

    return 0;
}

































