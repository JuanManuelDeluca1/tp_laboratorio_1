/*
 * menu.c
 *
 *  Created on: 9 may. 2022
 *      Author: juanm
 */
#include <stdio.h>
#include <stdlib.h>



int menu()
{
    int opcion;

        printf("  *** Menu de Opciones ***\n\n");
        printf("1- Alta auto\n");
        printf("2- Modificar alta\n");
        printf("3- Bajar auto\n");
        printf("4- listar autos\n");
        printf("5- liatar marcas\n");
        printf("6- listar colores\n");
        printf("7- listar servicios\n");
        printf("8- alta trabajp\n");
        printf("9- listar trabajo\n");
        printf("10- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);


        return opcion;
}
void confirmarSalida(char* p)
{
    char confirma;
    printf("Confirma salida?: ");
    fflush(stdin);
    scanf("%c", &confirma);

    // asigno el valor de la variable confirma a la variable salir de main
    // a traves de p que recibe la direccion de salir
    *p = confirma;

}
int opcionesCambio()
{
	int opcion;
	printf("1) Cambiar color\n");
	printf("2) Cambiar marca\n");
	printf("3) Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
