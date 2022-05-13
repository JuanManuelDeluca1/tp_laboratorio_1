/*
 ============================================================================
 Name        : estrucutrasArrays.c
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

#define TAM 5

int main()
{
    eEmpleado lista[TAM];

    //cargarEmpleados(lista, TAM);
    listarEmpleados(lista, TAM);

    //ordenarEmpleadosLegajoAsc(lista, TAM);
    //ordenarEmpleadosNombreAsc(lista, TAM);
    ordenarEmpleadosSexoAsc(lista, TAM);

    listarEmpleados(lista, TAM);


    return 0;
}

