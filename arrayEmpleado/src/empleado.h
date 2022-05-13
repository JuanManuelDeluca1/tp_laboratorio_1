/*
 * empleado.h
 *
 *  Created on: 4 may. 2022
 *      Author: juanm
 */

#include "fecha.h"
#include "sector.h"

#define NOMBRE 0
#define EDAD 1
#define LEGAJO 2
#define SEXO 3
#define SUELDO 4

#define ASC 1
#define DESC 0



#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED



typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    int edad;
    float sueldo;
    eFecha fIngreso;
    int idSector;
    int isEmpty;
} eEmpleado;


#endif // EMPLEADO_H_INCLUDED

int mostrarEmpleado(eEmpleado e, eSector sectores[], int tam);
int listarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
int cargarEmpleados(eEmpleado vec[], int tam);
int ordenarEmpleadosLegajoAsc(eEmpleado vec[], int tam);
int ordenarEmpleadosNombreAsc(eEmpleado vec[], int tam);
int ordenarEmpleadosSexoAsc(eEmpleado vec[], int tam);

int inicializarEmpleados(eEmpleado vec[], int tam);

int buscarEmpleadoLibre(eEmpleado vec[], int tam, int* pIndex);
int buscarEmpleado(eEmpleado vec[], int tam,int legajo, int* pIndex);
int altaEmpleado(eEmpleado vec[], int tam, int* pLegajo);
int bajaEmpleado(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int modificarEmpleado(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int hardcodearEmpleados(eEmpleado vec[], int tam, int cant, int* pLegajo);
int menuModificarEmpleado();

//Informes
int listarVarones(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int listarMujeres(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int listarEmpleadosMayoresA(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int informarPromedioSueldos(eEmpleado vec[], int tam);
int informarEmpleadoMayorEdad(eEmpleado vec[], int tam,eSector sectores[], int tamSec);



/** \brief Ordena un array de empleados de acuerdo al campo y modo especificado
 *
 * \param vec[] eEmpleado   Array de empleados
 * \param tam int   tamanio del array de empleados
 * \param campo int  campo por el cual se ordena O nombre, 1 legajo......(Se adjuntan defines)
 * \param criterio int  asc 1 desc 0
 * \return int  retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int ordenarEmpleados(eEmpleado vec[], int tam, int campo, int criterio);

int ordenarEmpleadosPorSexoYLegajo(eEmpleado vec[], int tam);







