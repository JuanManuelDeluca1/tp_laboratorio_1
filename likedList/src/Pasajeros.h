/*
 * Pasajeros.h
 *
 *  Created on: 17 jun. 2022
 *      Author: juanm
 */

#ifndef SRC_PASAJEROS_H_
#define SRC_PASAJEROS_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];

}Passenger;

Passenger* Passenger_new();
void passenger_Destroy(Passenger* p);
Passenger* newPassenger_Parametros(int id, char* nombre, char* apellido, float precio, int tipo, char* codigoVuelo);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

//Mostrar
int mostrarPassenger(Passenger* e);


// Orden
int ordenar_Passenger(void* a, void* b);

#endif /* SRC_PASAJEROS_H_ */
