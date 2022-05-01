/*
 ============================================================================
 Name        : claseTP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "array.h"
#define TAM 3

int menu();
void confirmarSalida(char* p);
int main(void)
{
	setbuf(stdout,NULL);
	eEmpleado lista[TAM];
	int proximoLegajo = 10000;
	char salir;
	int indice;
	do
	{
		switch(menu())
		{
			case 1:
				printf("1) Alta de cliente\n");
				if(altaEmpleado(lista, TAM, &proximoLegajo))
				{
					printf("se agrego empleado\n");
				}
				else
				{
					printf("problema para hacer empleado\n");
				}
			break;
			case 2:
				printf("2) Modificacion de cliente\n");
			break;
			case 3:
				printf("3) Baja de cliente\n");
				bajaEmpleado(lista, TAM);
			break;
			case 4:
				listarEmpleados(lista, TAM);
			break;
			case 5:
				inecializarEmpleados(lista, TAM);
				buscarEmpleadoLibre(lista, TAM, &indice);

			break;
			case 8:
			   confirmarSalida(&salir);
			break;

		}
		system("pause");

	}while(salir != 's');
	return 0;
}
int menu()
{
	int opcion;
	printf("     ***ABMA Empleado ***\n");
	printf("1) Alta de cliente\n");
	printf("2) Modificacion de cliente\n");
	printf("3) Baja de cliente\n");
	printf("4) Informar sobre clientes\n");
	printf("5) 	Busacar espacio\n");
	printf("8) Salir\n");
	printf("Ingrese una opcion: ");
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
