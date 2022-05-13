/*
 * empleado.h
 *
 *  Created on: 25 abr. 2022
 *      Author: juanm
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_
typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    int edad;
    float sueldo;
} eEmpleado;


#endif // EMPLEADO_H_INCLUDED

void mostrarEmpleado(eEmpleado empleado);
int listarEmpleados(eEmpleado vec[], int tam);
int cargarEmpleados(eEmpleado vec[], int tam);
int ordenarEmpleadosLegajoAsc(eEmpleado vec[], int tam);
int ordenarEmpleadosNombreAsc(eEmpleado vec[], int tam);
int ordenarEmpleadosSexoAsc(eEmpleado vec[], int tam);




