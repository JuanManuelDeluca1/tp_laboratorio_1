/*
 * color.h
 *
 *  Created on: 9 may. 2022
 *      Author: juanm
 */

#ifndef COLOR_H_
#define COLOR_H_

typedef struct{

    int id;
    char descripcion[20];
    int isEmpty;

}eColores;


#endif /* COLOR_H_ */
int inicializarColor(eColores vec[], int tam);
int buscarAutoColor(eColores vec[], int tam, int* pIndex);
void mostrarColores(eColores e);
int listarColores(eColores vec[], int tam);
