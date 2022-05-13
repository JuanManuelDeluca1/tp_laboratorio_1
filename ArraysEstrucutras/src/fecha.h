/*
 * fecha.h
 *
 *  Created on: 9 may. 2022
 *      Author: juanm
 */

#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

#endif // FECHA_H_INCLUDED

int validarFecha(eFecha unaFecha);
