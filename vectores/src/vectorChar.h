/*
 * vectorChar.h
 *
 *  Created on: 13 abr. 2022
 *      Author: juanm
 */

#ifndef VECTORCHAR_H_
#define VECTORCHAR_H_
#include <stdio.h>
#include <stdlib.h>

int mostrarEntero(int* vec, int tam);
int cargarVector(int* vec, int tam);
int sumarEntero(int* vec, int tam, int* pTotal);
int promediarEntero(int* vec, int tam, float* pTotal);
char mostrarCaracteres(char* vec, int tam);
char pasarAMyusculas(char* vec, int tam);
int contarVocales(char* vec, int tam, int* pCantidad);
char pedirCdena(char* vec, int tam);

#endif /* VECTORCHAR_H_ */
