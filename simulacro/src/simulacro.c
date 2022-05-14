/*
 ============================================================================
 Name        : simulacro.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "fecha.h"
#include "marca.h"
#include "color.h"
#include "auto.h"
#include "servicio.h"
#include "trabajo.h"

#define TAM 5
#define TAMM 5
#define TAMC 5
#define TAML 4

int main(void)
{
	setbuf(stdout,NULL);
	char salir;
	int indice;
	int proximoIdAutos = 3000;
	int flag = 0;
	eAuto autos[TAM];
	eMarcas marcas[TAMM] =
	{
		{1000, "Renault"},
		{1001, "Ford"},
        {1002, "Chevrolet"},
	    {1003, "Fiat"},
	    {1004, "Peugeot"}

	};
	eColores colores[TAMC] =
	{
		{5000, "Negro"},
		{5001, "Blanco"},
	    {5002, "Rojo"},
		{5003, "Gris"},
		{5004, "Azul"}

	};
	/*eServicio Lavados[TAMC] =
	{
		{20000, "Lavado"},
		{20001, "Pulido"},
	    {20002, "Encerado"},
		{20003, "Completo"},

	};*/
	do
	{
		switch(menu())
		{
		case 1:
			if(flag == 0)
			{
				inicializarAuto(autos, TAM);
			    buscarAutoLibre(autos , TAM, &indice);
				flag = 1;
			}
			else
			{
				printf("Lavadero lleno");
			}
			if(flag == 1)
			{
				listarColores(colores, TAM);
				listarMarcas(marcas, TAM);
				altaAuto(autos, TAM, &proximoIdAutos);
			}
     	break;
		case 2:
			if(flag == 0)
			{
				 printf("no hay ningun auto en el sistema");
			}
			else
			{
				listarColores(colores, TAM);
				listarMarcas(marcas, TAM);
				modificarPasajeroPorID(autos, TAM);
			}

		break;
		case 3:
			  printf("3- Bajar auto\n");

		break;
		case 4:
			 printf("4- listar autos\n");
		break;
		case 5:
	        printf("5- liatar marcas\n");
		break;
		case 6:
			 printf("6- listar colores\n");
		break;
		case 7:
			  printf("7- listar servicios\n");
		break;
		case 81:
			printf("8- alta trabajp\n");
		break;
		case 9:
			 printf("9- listar trabajo\n");
		break;
		case 10:
			confirmarSalida(&salir);
		break;
		default:
		     printf("Opcion Invalida!\n\n");
		}
	system("pause");

	}while(salir != 's');

	return 0;
}