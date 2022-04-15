/*
 ============================================================================
 Name        : vectores.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "vectorChar.h"
#define TAM 5



int main(void)
{
	setbuf(stdout,NULL);
	int numeros[TAM];
	int suma;
	float promedio;
	char letras[TAM] = {'s', 'o', 'l', 't', 'm'};
	int cantidad = 0;
	char nombre[20];


	cargarVector(numeros, TAM);
	mostrarEntero(numeros, TAM);
	sumarEntero(numeros, TAM, &suma);
	promediarEntero(numeros, TAM, &promedio);
	mostrarCaracteres(letras, TAM);
	pasarAMyusculas(letras, TAM);
	mostrarCaracteres(letras, TAM);
	contarVocales(letras, TAM, &cantidad);
	pedirCdena(nombre, TAM);


	return 0;
}

