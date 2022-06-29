/*
 * menu.c
 *
 *  Created on: 27 jun. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


int menu()
{
	int opcion;
	printf("1) Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n");
	printf("2) Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n");
	printf("3)  Alta de pasajero\n");
	printf("4) Modificar datos de pasajero\n");
	printf("5) Baja de pasajero\n");
	printf("6) Listar pasajeros\n");
	printf("7) Ordenar pasajeros\n");
	printf("8) Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n");
	printf("9) Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n");
	printf("10) Salir\n");
	printf("Ingrese una opcion: \n");
	scanf("%d", &opcion);

	return opcion;
}
void confirmarSalida(char* p)
{
	char confirmar;
	printf("Confirmar salida?:");
	fflush(stdin);
	scanf("%c", &confirmar);

	*p = confirmar;
}

