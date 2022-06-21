#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();
void confirmarSalida(char* p);


int main()
{
	setbuf(stdout,NULL);
    char salida;

    LinkedList* listaPasajeros = ll_newLinkedList();


    if(listaPasajeros == NULL)
    {
    	printf("No hay memoria disponible");
    	exit(1);
    }
    else
    {
    	 do
    	 {
    	     switch(menu())
    	     {
    	      case 1:
    	         controller_loadFromText("data.csv",listaPasajeros);
    	      break;
    	      case 2:
    	    	  controller_loadFromBinary("data.bin", listaPasajeros);
    	      break;
    	      case 3:
    	         controller_addPassenger(listaPasajeros);
    	      break;
    	      case 4:
    	    	  controller_editPassenger(listaPasajeros);
    	      break;
    	      case 5:
    	    	  controller_removePassenger(listaPasajeros);
    	      break;
    	      case 6:
    	    	  controller_ListPassenger(listaPasajeros);
    	      break;
    	      case 7:
    	    	  controller_sortPassenger(listaPasajeros);
    	      break;
    	      case 8:
    	    	  controller_saveAsText("data.csv", listaPasajeros);
    	      break;
    	      case 9:
    	    	  controller_saveAsBinary("data.bin", listaPasajeros);
    	      break;
    	      case 10:
    	         confirmarSalida(&salida);
    	      break;
    	     }
    	  }while(salida != 's');
    }
    return 0;
}


int menu()
{
	int opcion;
	printf("1) Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n");
	printf("2) Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n");
	printf("3)  Alta de pasajero\n");
	printf("4) Modificar datos de pasajero\n");
	printf("5) Baja de pasajero\n");
	printf("6) Listar pasajeros\n");
	printf("7) Ordenar pasajeros\n");
	printf("8) Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n");
	printf("9) Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n");
	printf("10) Salir\n");
	printf("Ingrese una opcion: \n");
	scanf("%d", &opcion);

	return opcion;
}
void confirmarSalida(char* p)
{
	char confirmar;
	printf("Confirmar salida?:");
	fflush(stdin);
	scanf("%c", &confirmar);

	*p = confirmar;
}
