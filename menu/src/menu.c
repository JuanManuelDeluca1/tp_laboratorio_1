/*
 ============================================================================
 Name        : menu.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int menu();


void saludar();

void brindar();

void despedir();

void confirmarSalida(char* p);




int main()
{
    char salir = 'n';
    int flagSaludo = 1; // si vale 1 significa que no se saludo
    int flagBrindis = 1; // si vale 1 significa que no se brindo

    do{

        switch(menu()){
            case 1: saludar();
                    flagSaludo = 0;
                    break;

            case 2:
                if(flagSaludo == 0){
                brindar();
                flagBrindis = 0;
                }
                else{
                    printf("Para brindar primero debemos saludarnos\n");
                }
                 break;

            case 3:
                if(flagBrindis == 0){
                    despedir();
                    flagBrindis = 1;
                    flagSaludo = 1;
                }
                else if(flagSaludo == 1){
                    printf("Como nos vamos a despedir si ni siquiera nos saludamos\n");
                }
                else{
                    printf("Antes de despedirnos primero brindemos\n");
                }

                 break;

            case 4: confirmarSalida(&salir);
                    break;
            default:
                    printf("Opcion Invalida!\n\n");
        }
        system("pause");

    }while(salir != 's');






    return 0;
}




int menu(){
    int opcion;

        system("cls");
        printf("  *** Menu de Opciones ***\n\n");
        printf("1- Saludar\n");
        printf("2- Brindar\n");
        printf("3- Despedir\n");
        printf("4- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        system("cls");

        return opcion;
}

void saludar(){
    printf("Hola que tal?\n");
}

void brindar(){
    printf("Chin chin\n");
}

void despedir(){
    printf("Chau nos vemos\n");
}

void confirmarSalida(char* p){
    char confirma;
    printf("Confirma salida?: ");
    fflush(stdin);
    scanf("%c", &confirma);

    // asigno el valor de la variable confirma a la variable salir de main
    // a traves de p que recibe la direccion de salir
    *p = confirma;

}



