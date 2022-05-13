/*
 * sector.c
 *
 *  Created on: 4 may. 2022
 *      Author: juanm
 */

#include <stdio.h>
#include <stdlib.h>
#include "sector.h"
#include <string.h>



int listarSectores(eSector sectores[], int tam){
int todoOk = 0;

    if(sectores != NULL && tam > 0){
        system("cls");
        printf("   *** Lista de Sectores  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s\n", sectores[i].id, sectores[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int cargarDescripcionSector(eSector sectores[], int tam, int id, char descripcion[]){
int todoOk = 0;

    if(sectores != NULL && tam > 0 && id >= 5000 && id <= 5004 && descripcion != NULL){
     for(int i=0; i < tam; i++){

        if(sectores[i].id == id){
            strcpy(descripcion, sectores[i].descripcion);
            break;
        }
     }
     todoOk = 1;
    }
  return todoOk;
}




