/*
 * marca.h
 *
 *  Created on: 9 may. 2022
 *      Author: juanm
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct{

    int id;
    char descripcion[20];
    int isEmpty;

}eMarcas;


#endif /* MARCA_H_ */
int inicializarMarca(eMarcas vec[], int tam);
int buscarMarcaLibre(eMarcas vec[], int tam, int* pIndex);
void mostrarMarcas(eMarcas e);
int listarMarcas(eMarcas vec[], int tam);
