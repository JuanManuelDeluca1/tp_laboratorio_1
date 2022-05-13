/*
 * menu.c
 *
 *  Created on: 18 abr. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>

int menu()
{
	int opcion;
	printf("1) Alta de cliente\n");
	printf("2) Modificacion de cliente\n");
	printf("3) Baja de cliente\n");
	printf("4) Informar sobre clientes\n");
	printf("5) Carga forzada\n");
	printf("6) Salir\n");
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

int opcionesCambio()
{
	int opcion;
	printf("1) Cambiar nombre\n");
	printf("2) Cambiar apellido\n");
	printf("3) Cambiar precio\n");
	printf("4) Cambiar codigo de vuelo\n");
	printf("5) Cambiar tipo de pasaje\n");
	printf("6) Cambiar estado de vuelo\n");
	printf("7) Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
