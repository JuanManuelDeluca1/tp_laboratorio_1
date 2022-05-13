/*
 ============================================================================
 Name        : arrayEmpleado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "empleado.h"
#include "sector.h"


#define TAM 10
#define TAMS 5

int menu();

int main()
{
    //int indice;
	setbuf(stdout,NULL);
    char salir = 'n';
    int proximoLegajo = 10000;
    eEmpleado lista[TAM];
    eSector sectores[TAMS] ={
        {5000, "Sistemas"},
        {5001, "RRHH"},
        {5002, "Contable"},
        {5003, "Legales"},
        {5004, "Ventas"}
    };




    inicializarEmpleados(lista, TAM);


    hardcodearEmpleados(lista, TAM, 10, &proximoLegajo);

    do
    {
        switch(menu())
        {

        case 1:
            if( altaEmpleado(lista, TAM, &proximoLegajo))
            {
                printf("Empleado agregado con exito!!!\n");
            }
            else
            {
                printf("Problema al hacer el alta de empleado\n");
            }

            break;
        case 2:
            if( bajaEmpleado(lista, TAM, sectores, TAMS) == 0)
            {
                printf("Problema al hacer la baja de empleado\n");
            }
            break;
        case 3:
            if( modificarEmpleado(lista, TAM, sectores, TAMS) == 0)
            {
                printf("Problema al hacer la modificacion de empleado\n");
            }
            break;

            break;
        case 4:
            printf("Ordenar Empleados\n");
            break;
        case 5:
            listarEmpleados(lista, TAM, sectores, TAMS);
            break;

        case 6:
            listarVarones(lista, TAM, sectores, TAMS);
            break;
         case 7:
            listarMujeres(lista, TAM, sectores, TAMS);
            break;
         case 8:
            listarEmpleadosMayoresA(lista, TAM, sectores, TAMS);
            break;
         case 9:
            informarPromedioSueldos(lista, TAM);
            break;
         case 10:
            informarEmpleadoMayorEdad(lista, TAM, sectores, TAMS);
            break;
         case 11:
            listarSectores(sectores, TAMS);
            break;

        case 20:
            salir = 's';
            break;
        }
        system("pause");

    }
    while(salir != 's');

    return 0;
}

int menu()
{

    int opcion;
    system("cls");
    printf("     *** ABM Empleados ***\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificar Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Listar Empleados Masculinos\n");
    printf("7- Listar Empleados Femeninos\n");
    printf("8- Listar Empleados Mayores a una edad determinada\n");
    printf("9- Informe promedio sueldos\n");
    printf("10- Informe empleado de mayor edad\n");
    printf("11- Listar Sectores\n");
    printf("20- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;

}



