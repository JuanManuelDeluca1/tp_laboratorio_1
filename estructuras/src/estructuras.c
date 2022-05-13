/*
 ============================================================================
 Name        : estructuras.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int legajo;
	char nombre[20];
	char sexo;
	int nota1;
	int nota2;
	float promedio;
}eAlumno;

int limpiarBarraN(char cadena[], int tam);
void mostrarAlumno(eAlumno alumno1);
int cargarAlumno(eAlumno* pAlumno1);
int main(void)
{
	eAlumno alumno1;
	cargarAlumno(&alumno1);
	mostrarAlumno(alumno1);
	return 0;
}
int cargarAlumno(eAlumno* pAlumno1)
{
	int todoOk = 0;
	if(pAlumno1 != NULL)
	{
		printf("ingrese legajo: ");
		scanf("%d", &pAlumno1->legajo);

		printf("ingrese nombre: ");
		fflush(stdin);
		fgets(pAlumno1->nombre, 20, stdin);
		limpiarBarraN(pAlumno1->nombre, 20);

		printf("ingrese nombre: ");
		fflush(stdin);
		scanf(pAlumno1->sexo);



		printf("ingrese nota 1: ");
		scanf("%d", &pAlumno1->nota1);

		printf("ingrese nota 2: ");
		scanf("%d", &pAlumno1->nota2);
		todoOk=1;
	}

	return todoOk;
}
void mostrarAlumno(eAlumno alumno1)
{
	  printf("legajo: %d\n", alumno1.legajo);
	  printf("nombre: %s\n", alumno1.nombre);
	  printf("sexo: %c\n", alumno1.sexo);
	  printf("nota1: %d\n", alumno1.nota1);
	  printf("nota2: %d\n", alumno1.nota2);
	  alumno1.promedio =  (float) (alumno1.nota1 + alumno1.nota2) / 2;
	  printf("promedio: %f\n", alumno1.promedio);




}

int limpiarBarraN(char cadena[], int tam)
{
	int todoOk = 0;
	if(cadena != NULL && tam >0)
	{
		for(int i=0;i<tam;i++)
		{
			if(cadena[i] == '\n')
			{
				cadena[i] = '\0';
				break;
			}
		}
		todoOk =1;
	}
	return todoOk;
}









































