/*
 * funciones.c
 *
 *  Created on: 12 abr. 2022
 *      Author: juanm
 */

#include <stdio.h>
#include <stdlib.h>


int menu()
{
	int opciones;
	printf("1)ingrese sus Km: \n");
	printf("2)ingrese precio del vuelo: \n");
	printf("3) calcule todos los costos \n");
	printf("4) informar resultado\n");
	printf("5) Carga forzada de datos \n");
	printf("6) Salir\n");
	printf(" ingresar una opcion: ");
	scanf("%d", &opciones);
	return opciones;
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

int ingresarKm()
{
	int km;
	printf("ingrese los Kilometros");
	scanf("%d", &km);
	return km;
}

int ingresarPrecioVueloLatam()
{
	float latam;
	printf("ingrese precio del vuelo con latam: ");
	fflush(stdin);
	scanf("%f", &latam);

	return latam;
}

int ingresarPrecioVueloAerolineas()
{
	float aerolineas;
	printf("ingrese precio del vuelo con aerolineas: ");
	fflush(stdin);
	scanf("%f", &aerolineas);

	return aerolineas;
}

void tarjetaDebito(int num1, int num2, float* p)
{

	num2 = num1 * 10 / 100;
	*p = num1 - num2;


}

void tarjetaCredito(int num1, int num2, float* p)
{

	num2 = num1 * 25 / 100;
	*p = num1 + num2;


}

void precioBitcoin(int num1, float* p)
{
	*p = num1 / 4606954.55;
}

void precioKm(int num1, int num2, float* p)
{
	*p = num1/num2;
}

void diferenciaDePrecio (int num1, int num2, float* p)
{
	if(num1 > num2)
	{
	  *p = num1-num2;
	}
	else
	{
	  *p = num2-num1;
	}

}

void cargaForzada(float* descuentoLatam, float* descuentoAerolineas, float* interesLatam, float* interesAerolineas,
float* bitcoinLatam, float* bitcoinAerolineas, float* precioKmLatam, float* precioKmAerolineas,
float* diferenciaPrecio)
{
	int x = 7090;
	float y = 162965;
	float z = 159339;


		//calculos Latam
		tarjetaDebito(z, z, descuentoLatam);
	    tarjetaCredito(z, z, interesLatam);
		precioBitcoin(z, bitcoinLatam);
		precioKm(z, x, precioKmLatam);
		//calculos Aerolineas
		tarjetaDebito(y, y, descuentoAerolineas);
		tarjetaCredito(y, y, interesAerolineas);
		precioBitcoin(y, bitcoinAerolineas);
		precioKm(y, x, precioKmAerolineas);

		diferenciaDePrecio(y, z, diferenciaPrecio);



}
