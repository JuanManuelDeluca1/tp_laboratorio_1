/*
 * auto.h
 *
 *  Created on: 9 may. 2022
 *      Author: juanm
 */

#ifndef AUTO_H_
#define AUTO_H_

typedef struct{

    int id;
    int idMarca;
    int idColor;
    char caja[20];
    int isEmpty;

}eAuto;

#endif /* AUTO_H_ */

int inicializarAuto(eAuto vec[], int tam);
int buscarAutoLibre(eAuto vec[], int tam, int* pIndex);
int buscarAutos(eAuto vec[], int tam,int id, int* pIndex);
int altaAuto(eAuto vec[], int tam, int* pLegajo);
int modificarPasajeroPorID(eAuto vec[],int tam);

void mostrarAuto(eAuto e);
int listarAuto(eAuto vec[], int tam);