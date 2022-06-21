/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* newPassenger = (Passenger*)calloc(1,sizeof(newPassenger));
	return newPassenger;
}

void passenger_Destroy(Passenger* p)
{
	free(p);
}

Passenger* newPassenger_Parametros(char* nombre, char* apellido, float precio, int tipo, char* codigoVuelo)
{
	Passenger* newPassenger = Passenger_new();
	if(newPassenger != NULL)
	{
		if(!(Passenger_setNombre(newPassenger, nombre)&&
			 Passenger_setApellido(newPassenger, apellido)&&
			 Passenger_setCodigoVuelo(newPassenger, codigoVuelo)&&
			 Passenger_setTipoPasajero(newPassenger, tipo)&&
			 Passenger_setPrecio(newPassenger, precio)))
		{
			passenger_Destroy(newPassenger);
			newPassenger = NULL;
		}
	}
	return newPassenger;
}

Passenger* Passenger_newParametros(char* nombreStr,int tipoPasajeroStr)
{
	Passenger* newPassenger = Passenger_new();
	if(newPassenger != NULL)
	{
		if(!(Passenger_setNombre(newPassenger, nombreStr)&&
			 Passenger_setTipoPasajero(newPassenger, tipoPasajeroStr)))
			{
				passenger_Destroy(newPassenger);
				newPassenger = NULL;
			}
		}
		return newPassenger;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL && strlen(nombre) < 51 && strlen(nombre) > 2)
	{
		strcpy(this->nombre, nombre);
		strlwr(this->nombre);
		(this->nombre)[0] = toupper((this->nombre[0]));
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk=1;
	}
	return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOk = 0;
	if(this != NULL && apellido != NULL && strlen(apellido) < 51 && strlen(apellido) > 2)
	{
		strcpy(this->apellido, apellido);
		strlwr(this->apellido);
		(this->apellido)[0] = toupper((this->apellido[0]));
		todoOk = 1;
	}
	return todoOk;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int todoOk = 0;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		todoOk=1;
	}
	return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = 0;
	if(this != NULL && codigoVuelo != NULL && strlen(codigoVuelo) < 5)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		todoOk = 1;
	}
	return todoOk;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int todoOk = 0;
	if(this != NULL && tipoPasajero < 4)
	{
		this->tipoPasajero = tipoPasajero;
		todoOk = 1;
	}
	return todoOk;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int todoOk = 0;
	if(this != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int todoOk = 0;
	if(this != NULL && precio < 1000001 && precio > 20000)
	{
		this->precio =  precio;
		todoOk = 1;
	}
	return todoOk;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int todoOk = 0;
	if(this != NULL)
	{
		*precio = this->precio;
		todoOk = 1;
	}
	return todoOk;
}

int mostrarPassenger(Passenger* e)
{
    int todoOk = 0;
    if(e != NULL)
    {
        printf("%d %s %s %.2f %d &s\n", e->id, e->nombre, e->apellido, e->precio, e->tipoPasajero, e->codigoVuelo);
        todoOk = 1;
    }
    return todoOk;
}

int sortPassengerName(void* a, void* b)
{
	int retorno = 0;
	Passenger* x;
	Passenger* y;

	if(a != NULL && b != NULL)
	{
		x = (Passenger*) a;
		y = (Passenger*) b;
		retorno = strcmp (x->nombre, y->nombre);
	}

	return retorno;
}
