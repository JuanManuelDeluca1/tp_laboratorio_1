/*
 * array.h
 *
 *  Created on: 27 abr. 2022
 *      Author: juanm
 */

#ifndef ARRAY_H_
#define ARRAY_H_
struct
{
	int legajo;
	char nombre[20];
	char sexo;
	int edad;
	float sueldo;
	int isEmpty;

}typedef eEmpleado;
int inecializarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleado(eEmpleado e);
int listarEmpleados(eEmpleado vec[], int tam);
int buscarEmpleadoLibre(eEmpleado vec[], int tam, int* pIndex);
int altaEmpleado(eEmpleado vec[], int tam, int* pLegajo);
int buscarEmpleado(eEmpleado vec[], int tam,int legajo, int* pIndex);
int bajaEmpleado(eEmpleado vec[], int tam);
#endif /* ARRAY_H_ */
