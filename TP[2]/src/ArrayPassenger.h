/*
 * ArrayPassenger.h
 *
 *  Created on: 18 abr. 2022
 *      Author: juanm
 */


#define APELLIDOyTIPO 0
#define CODIGOyACTIVO 1
#define ACS 1
#define DESC 0



#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;
	int isEmpty;

}typedef Pasajeros;

#endif /* ARRAYPASSENGER_H_ */

//abm pasajeros
int inicializarPasajero(Pasajeros* vec, int tam);
int buscarPasajeroLibre(Pasajeros vec[], int tam, int* pIndex);
int buscarPasajero(Pasajeros vec[], int tam,int id, int* pIndex);
int agregarPasajero(Pasajeros* vec, int tam, int id, char nombre[], char apellido[], float precio,
char codigoVuelo[], int tipoPasajero,int estadoVuelo);
int modificarPasajeroPorID(Pasajeros* vec, int tam, int id);
int removerPasajero(Pasajeros* list, int tam);

//ordenar pasajeros
int ordenarPasajerosPorApellidoYTipoAcd(Pasajeros vec[], int tam);
int odernarPasajeroPorCodigoYVuelosActivosAcd(Pasajeros vec[], int tam);
int ordenarPasajerosPorApellidoYTipoDes(Pasajeros vec[], int tam);
int odernarPasajeroPorCodigoYVuelosActivosDes(Pasajeros vec[], int tam);

//precio y promedio de pasajeross
int precioPasajeros(Pasajeros* list, int tam, float promedio, float precio);

//harcodeo de pasajeros
int hardcodearPasajeros(Pasajeros* list, int tam, int cant, int id);

//mostrar pasajeros
int imprimirPasajeros(Pasajeros* list, int tam);
void mostrarPasajeros(Pasajeros e);



