/*
 ============================================================================
 Name        : matrisTarea.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5
#define COL 20
#define ASC 1
#define DESC 1

int listarAlumnos(int[],char[][20],char[],int[],int[],float [],int); // deber 25/4
int cargarAlumnos(int[],char[][20],char[],int[],int[],int);
int ordenarAlumnosNombre(int[],char[][20],char[],int[],int[],float [],int,int);
int ordenarAlumnosLeg(int[],char[][20],char[],int[],int[],float [],int,int);
int ordenarAlumnosSexo(int[],char[][20],char[],int[],int[],float [],int,int);
int ordenarAlumnosPromedio(int[],char[][20],char[],int[],int[],float [],int,int);

int main()
{
    int legajos[TAM] ={1234, 4432, 6123, 1128, 2378};
    char nombres[TAM][COL] = {
        {"Jose"},
        {"Andrea"},
        {"Juliana"},
        {"Joaquin"},
        {"Luis"}
    };
    char sexos[TAM] = {'m', 'f', 'f', 'm', 'm'};
    int notas1[TAM] = {6,7,2,10,10};
    int notas2[TAM] = {8,2,4,6,10};
    float promedios[TAM];
    int respuesta;
    int seCargoAlumnos = 0;


    do{
        printf("1) Ingresar alumno \n");
        printf("2) Lista Alumnos \n");
        printf("3) Ordenar alumnos por nombre \n");
        printf("4) Ordenar alumnos por legajo \n");
        printf("5) Ordenar alumnos por sexo \n");
        printf("6) Ordenar alumnos por promedio \n");
        printf("7) Salir \n");
        fflush(stdin);
        scanf("%d",&respuesta);
        fflush(stdin);

        switch(respuesta){
            case 1:
                seCargoAlumnos = cargarAlumnos(legajos,nombres,sexos,notas1,notas2,TAM);
                if(seCargoAlumnos)
                    calcularPromedios(notas1,notas2,promedios,TAM);
                break;
            case 2:
                if(seCargoAlumnos)
                    listarAlumnos(legajos,nombres,sexos,notas1,notas2,promedios,TAM);
                break;
            case 3:
                if(seCargoAlumnos)
                    ordenarAlumnosNombre(legajos,nombres,sexos,notas1,notas2,promedios,ASC,TAM);
                break;
            case 4:
                if(seCargoAlumnos)
                    ordenarAlumnosLeg(legajos,nombres,sexos,notas1,notas2,promedios,ASC,TAM);
                break;
            case 5:
                if(seCargoAlumnos)
                    ordenarAlumnosSexo(legajos,nombres,sexos,notas1,notas2,promedios,ASC,TAM);
                break;
            case 6:
                if(seCargoAlumnos)
                    ordenarAlumnosPromedio(legajos,nombres,sexos,notas1,notas2,promedios,ASC,TAM);
                break;
            case 7:
                printf("Saliendo.. \n");
            break;
            default:
                printf("Ingrese una opcion valida del menu \n");
            break;
        }

        if(!seCargoAlumnos){
            printf("Error,  antes de acceder a la opcion debe cargar los alumnos \n");
        }


    }while(respuesta != 7);

    return 0;

}

int cargarAlumnos(int legajos[],char nombres[][20],char sexos[],int n1[],int n2[],int tam){
   int todoOk = 0;
    if(n1 && n2 && legajos && nombres && sexos  && tam >0)
    {
        for(int i=0;i<tam;i++){
            printf("Ingrese el legajo \n");
            scanf("%d",&legajos[i]);
            fflush(stdin);

            printf("Ingrese el nombre \n");
            gets(nombres[i]);
            fflush(stdin);
            while(strlen(nombres[i]) > 19){
                printf("Ingrese un nombre mas corto \n");
                gets(nombres[i]);
                fflush(stdin);
            }

            printf("Ingrese el sexo \n");
            scanf("%c",&sexos[i]);
            fflush(stdin);
            while(sexos[i] != 'f' && sexos[i] != 'm'){
                printf("Error en sexo, ingrese 'f' o 'm' \n");
                scanf("%c",&sexos[i]);
                fflush(stdin);
            }

            printf("Ingrese la nota del primer parcial \n");
            scanf("%d",&n1[i]);
            fflush(stdin);
            while(n1[i] > 10 || n1[i] < 0){
                printf("Error en nota ingresada , debe ser del 0 al 10\n");
                scanf("%d",&n1[i]);
                fflush(stdin);
            }

            printf("Ingrese la nota del segundo parcial \n");
            scanf("%d",&n2[i]);
            fflush(stdin);
            while(n2[i] > 10 || n2[i] < 0){
                printf("Error en nota ingresada , debe ser del 0 al 10\n");
                scanf("%d",&n2[i]);
                fflush(stdin);
            }

        }

        todoOk = 1;
    }
    return todoOk;
}

int calcularPromedios(int n1[],int n2[],float proms[],int tam){
    int todoOk = 0;
    if(n1 && n2 && proms && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            proms[i] =  (float) (n1[i] + n2[i]) / 2;
        }

        todoOk = 1;
    }
    return todoOk;
}

void swapString (char* n1,char* n2){
    char aux[100];
    strcpy(aux,n1);
    strcpy(n1,n2);
    strcpy(n2,aux);
}

void swapChar (char* n1,char* n2){
    char aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

void swapEnteros(int* n1,int* n2){
    int aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

void swapFlotantes(float* n1,float* n2){
    float aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}


int listarAlumnos(int legajos[],char nombres[][20],char sexos[],int n1[],int n2[],float proms[],int tam){
   int todoOk = 0;
    if(n1 && n2 && legajos && nombres && sexos && proms && tam >0)
    {
        //system("cls");
        printf("      *** Listado de Alumnos ***\n\n");
        printf("Legajos\tNombres\t\t\tSexo\tParcial1\tParcial2\tPromedio\n");

        for(int i=0; i < tam; i++)
        {
            printf("%d\t%-20s\t%c\t%2d\t\t%2d\t\t%5.2f\n",legajos[i],nombres[i],sexos[i],n1[i], n2[i], proms[i]);
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;

}

int ordenarAlumnosNombre(int legajos[],char nombres[][20],char sexos[],int n1[],int n2[],float proms [],int criterio,int tam){
    int todoOk = 0;

    if(n1 && n2 && legajos && nombres && sexos && proms && tam >0 && (criterio ==0 || criterio == 1)){
        for(int i=0;i<tam-1;i++){
            for(int j=i+1;j<tam;j++){
                if((criterio && 0 < strcmp(nombres[i],nombres[j])) || (!criterio && 0 > strcmp(nombres[i],nombres[j]))){
                    swapEnteros(&n1[i],&n1[j]);
                    swapEnteros(&n2[i],&n2[j]);
                    swapFlotantes(&proms[i],&proms[j]);
                    swapEnteros(&legajos[i],&legajos[j]);
                    swapChar(&sexos[i],&sexos[j]);
                    swapString(&nombres[i],&nombres[j]);
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int ordenarAlumnosLeg(int legajos[],char nombres[][20],char sexos[],int n1[],int n2[],float proms [],int criterio,int tam){
    int todoOk = 0;

    if(n1 && n2 && legajos && nombres && sexos && proms && tam >0 && (criterio ==0 || criterio == 1)){
        for(int i=0;i<tam-1;i++){
            for(int j=i+1;j<tam;j++){
                if((criterio && legajos[i] > legajos[j]) || (!criterio && legajos[i] < legajos[j])){
                    swapEnteros(&n1[i],&n1[j]);
                    swapEnteros(&n2[i],&n2[j]);
                    swapFlotantes(&proms[i],&proms[j]);
                    swapEnteros(&legajos[i],&legajos[j]);
                    swapChar(&sexos[i],&sexos[j]);
                    swapString(&nombres[i],&nombres[j]);
                }
            }
        }
        todoOk=1;
    }
    return todoOk;

}

int ordenarAlumnosSexo(int legajos[],char nombres[][20],char sexos[],int n1[],int n2[],float proms [],int criterio,int tam){
      int todoOk = 0;

    if(n1 && n2 && legajos && nombres && sexos && proms && tam >0 && (criterio ==0 || criterio == 1)){
        for(int i=0;i<tam-1;i++){
            for(int j=i+1;j<tam;j++){
                if((criterio && sexos[i] > sexos[j]) || (!criterio && sexos[i] < sexos[j])){
                    swapEnteros(&n1[i],&n1[j]);
                    swapEnteros(&n2[i],&n2[j]);
                    swapFlotantes(&proms[i],&proms[j]);
                    swapEnteros(&legajos[i],&legajos[j]);
                    swapChar(&sexos[i],&sexos[j]);
                    swapString(&nombres[i],&nombres[j]);
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int ordenarAlumnosPromedio(int legajos[],char nombres[][20],char sexos[],int n1[],int n2[],float proms [],int criterio,int tam){
      int todoOk = 0;

    if(n1 && n2 && legajos && nombres && sexos && proms && tam >0 && (criterio ==0 || criterio == 1)){
        for(int i=0;i<tam-1;i++){
            for(int j=i+1;j<tam;j++){
                if((criterio && proms[i] > proms[j]) || (!criterio && proms[i] < proms[j])){
                    swapEnteros(&n1[i],&n1[j]);
                    swapEnteros(&n2[i],&n2[j]);
                    swapFlotantes(&proms[i],&proms[j]);
                    swapEnteros(&legajos[i],&legajos[j]);
                    swapChar(&sexos[i],&sexos[j]);
                    swapString(&nombres[i],&nombres[j]);
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}
