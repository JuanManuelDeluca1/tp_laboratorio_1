/*
 * trabajo.h
 *
 *  Created on: 9 may. 2022
 *      Author: juanm
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct{

    int id;
    char patente[20];
    int idServicio;
    int idAuto;
    eFecha fecha;
    float precio;

}eTrabajo;

#endif /* TRABAJO_H_ */
