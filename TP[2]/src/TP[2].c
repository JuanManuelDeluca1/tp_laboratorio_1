/*
 ============================================================================
 Name        : TP[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ArrayPassenger.h"
#include "menu.h"

#define TAM 200
#define APE 0
#define TIP 1


int main(void)
{
	setbuf(stdout,NULL);
	Pasajeros eList[TAM];

	char salir;
	int flagCarga = 0;
	int proximoId = 10000;
	char nombre[51];
	char apellido[51];
	float precio = 0;
	char codigoVuelo[10];
	int tipoPasajero = 0;
	int estadoVuelo = 0;
	int indice;
	float promedio = 0;
	float precio2 = 0;
	int orden;
	do
	{
		switch(menu())
		{
			case 1:
				if(flagCarga == 0)
				{
					inicializarPasajero(eList, TAM);
					buscarPasajeroLibre(eList, TAM, &indice);
					flagCarga = 1;
				}
				if(flagCarga == 1)
				{
					agregarPasajero(eList, TAM, proximoId, nombre,  apellido,  precio, codigoVuelo,
					tipoPasajero,  estadoVuelo);
					proximoId = proximoId + 1;
					printf("Se agrego pasajero\n");
				}
				else
				{
					printf("problema al agregar pasajero\n");
				}
			break;
			case 2:
				if(flagCarga == 1)
				{
					modificarPasajeroPorID(eList, TAM, proximoId);
				}
				else
				{
					printf("debe cargar un pasajero primero\n\n");
				}
			break;
			case 3:
				if(flagCarga == 1)
				{
					removerPasajero(eList, TAM);
				}
				else
				{
					printf("debe cargar un pasajero primero\n\n");
				}
			break;
			case 4:
				if(flagCarga == 1)
				{
					printf("Usted quiere que se lo ordene en acendete(1) o desendente(0)\n");
					scanf("%d", &orden);
					if(orden >= 0 && orden <= 1)
					{
						if(orden == 1)
						{
							imprimirPasajeros(eList, TAM);
							ordenarPasajerosPorApellidoYTipoAcd(eList, TAM);
							odernarPasajeroPorCodigoYVuelosActivosAcd(eList, TAM);
							precioPasajeros(eList, TAM, promedio, precio2);


						}
						else
						{
							imprimirPasajeros(eList, TAM);
							ordenarPasajerosPorApellidoYTipoDes(eList, TAM);
							odernarPasajeroPorCodigoYVuelosActivosDes(eList, TAM);
						    precioPasajeros(eList, TAM, promedio, precio2);
						}
					}


				}
				else
				{
					printf("debe cargar un pasajero primero\n\n");
				}
			break;
			case 5:
				if(flagCarga == 0)
				{
					inicializarPasajero(eList, TAM);
					buscarPasajeroLibre(eList, TAM, &indice);
					flagCarga = 1;
				}
				if(flagCarga == 1)
				{
					hardcodearPasajeros(eList, TAM, 10, proximoId);
					imprimirPasajeros(eList, TAM);
				}
				else
				{
					printf("problema al agregar pasajero\n");
				}
			break;
			case 6:
				confirmarSalida(&salir);
			break;
			default:
				printf("opcion Invalida!\n\n");
		}
		system("pause");

	}while(salir != 's');
	return 0;
}
