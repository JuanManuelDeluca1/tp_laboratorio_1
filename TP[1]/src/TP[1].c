/*
 ============================================================================
 Name        : TP[1].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
	setbuf(stdout,NULL);

	char salir;
	int flagkm = 1;
	int flagPrecio = 1;
	int flagCalcular = 1;
	float x;
	float y;
	float z;
	float descuentoLatam;
	float descuentoAerolineas;
	float interesLatam;
	float interesAerolineas;
	float bitcoinLatam;
	float bitcoinAerolineas;
	float precioKmLatam;
	float precioKmAerolineas;
	float diferenciaPrecio;
	do {
		switch(menu())
		{
			case 1:
				x=ingresarKm();
				printf("sus kilometros son %.2f\n: ", x);
				flagkm = 0;

			break;
			case 2:
				if(flagkm == 0)
				{
				  y = ingresarPrecioVueloAerolineas();
				  z = ingresarPrecioVueloLatam();
				  flagPrecio = 0;
				}
				else
				{
					printf("primero debe ingresar los km \n");
				}
			break;
			case 3:
				if(flagPrecio == 0)
				{
					//calculos Latam
	    		    tarjetaDebito(z, z, &descuentoLatam);
			     	tarjetaCredito(z, z, &interesLatam);
			        precioBitcoin(z, &bitcoinLatam);
					precioKm(z, x, &precioKmLatam);
					//calculos Aerolineas
					tarjetaDebito(y, y, &descuentoAerolineas);
					tarjetaCredito(y, y, &interesAerolineas);
					precioBitcoin(y, &bitcoinAerolineas);
				    precioKm(y, x, &precioKmAerolineas);
					diferenciaDePrecio(y, z, &diferenciaPrecio);
				    flagCalcular = 0;
				}
				else
				{
				  printf("debe ingresar los precios primero \n");
				}
		    break;
			case 4:
				if(flagCalcular == 0)
				{
					//muestra Latam
					printf("kilometros totales: %.2f\n", x);
					printf("Latam:$ %.2f\n", z);
					printf("el descuento con es:$ %.2f\n", descuentoLatam);
					printf("el interes con  es:$ %.2f\n", interesLatam);
					printf("el precio a bitcoin es: %.11f\n", bitcoinLatam);
					printf("el precio por km es:$ %.2f\n", precioKmLatam);
					//muestra Aerolineas
					printf("Aerolineas:$ %.2f\n", y);
					printf("el descuento con aerolineas es:$ %.2f\n", descuentoAerolineas);
					printf("el interes con aerolineas es:$ %.2f\n", interesAerolineas);
					printf("el precio a bitcoin es: %.11f\n", bitcoinAerolineas);
					printf("el precio por km es:$ %.2f\n", precioKmAerolineas);

					printf("la diferencia de precoi es:$ %.2f\n", diferenciaPrecio);
				}
				else
				{
					printf("debes ingresar la opcion calcular primero \n");
				}

		    break;
			case 5:
				x = 7090;
			    y = 162965;
			    z = 159339;
				cargaForzada(&descuentoLatam, &descuentoAerolineas, &interesLatam,
				&interesAerolineas, &bitcoinLatam, &bitcoinAerolineas, &precioKmLatam,
				&precioKmAerolineas,&diferenciaPrecio);
				//muestra Latam
				printf("kilometros totales: %.2f\n", x);
				printf("Latam:$ %.2f\n", z);
				printf("el descuento con es:$ %.2f\n", descuentoLatam);
				printf("el interes con  es:$ %.2f\n", interesLatam);
				printf("el precio a bitcoin es: %.11f\n", bitcoinLatam);
				printf("el precio por km es:$ %.2f\n", precioKmLatam);
				//muestra Aerolineas
				printf("Aerolineas:$ %.2f\n", y);
				printf("el descuento con aerolineas es:$ %.2f\n", descuentoAerolineas);
				printf("el interes con aerolineas es:$ %.2f\n", interesAerolineas);
				printf("el precio a bitcoin es: %.11f\n", bitcoinAerolineas);
				printf("el precio por km es:$ %.2f\n", precioKmAerolineas);

				printf("la diferencia de precoi es:$ %.2f\n", diferenciaPrecio);

		    break;
			case 6:
				confirmarSalida(&salir);
			break;
			default:
				 printf("Opcion Invalida!\n\n");
		}


	}while(salir != 's' );



	return 0;
}
