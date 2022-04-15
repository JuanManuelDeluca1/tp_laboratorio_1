/*
 * funciones.h
 *
 *  Created on: 12 abr. 2022
 *      Author: juanm
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>

int menu();
void confirmarSalida(char* p);
int ingresarKm();
int ingresarPrecioVueloLatam();
int ingresarPrecioVueloAerolineas();
void tarjetaDebito(int num1, int num2, float* p);
void tarjetaCredito(int num1, int num2, float* p);
void precioBitcoin(int num1, float* p);
void precioKm(int num1, int num2, float* p);
void diferenciaDePrecio (int num1, int num2, float* p);
void cargaForzada(float* descuentoLatam, float* descuentoAerolineas, float* interesLatam, float* interesAerolineas,
float* bitcoinLatam, float* bitcoinAerolineas, float* precioKmLatam,float* precioKmAerolineas,
float* diferenciaPrecio);
#endif /* FUNCIONES_H_ */
