 /*
 * ArrayPassenger.c
 *
 *  Created on: 18 abr. 2022
 *      Author: juanm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "menu.h"

int inicializarPasajero(Pasajeros* vec, int tam)
{
	int todoOk=0;
	if(vec != NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			vec[i].isEmpty = 1;
		}
	todoOk=1;
	}
	return todoOk;
}
int buscarPasajeroLibre(Pasajeros vec[], int tam, int* pIndex)
{
	int todoOk=-0;
    if(vec != NULL && tam>0 && pIndex != NULL)
	{
    	*pIndex=-1;
		for(int i=0;i<tam;i++)
		{
			if(vec[i].isEmpty == 1)
			{
				*pIndex=i;
				break;
			}
		}
		todoOk=1;
	}
	return todoOk;
}
int buscarPasajero(Pasajeros vec[], int tam,int id, int* pIndex)
{
	int todoOk=-0;
	    if(vec != NULL && tam>0 && pIndex != NULL && id > 0)
		{
	    	*pIndex=-1;
			for(int i=0;i<tam;i++)
			{
				if(vec[i].isEmpty == 0 && vec[i].id == id)
				{
					*pIndex=i;
					break;
				}
			}
			todoOk=1;
		}
		return todoOk;
}

int agregarPasajero(Pasajeros* vec, int tam, int id, char nombre[], char apellido[], float precio,
		char codigoVuelo[], int tipoPasajero,int estadoVuelo)
{
	int todoOk = 0;
	int indice;
	Pasajeros aux;
	if(vec != NULL && tam>0 && id>0 && nombre != NULL && apellido != NULL && precio >= 0 && codigoVuelo != NULL
		&& tipoPasajero >= 0 && estadoVuelo >= 0)
	{
		if(buscarPasajeroLibre(vec, tam, &indice))
		{
			if(indice == -1)
			{
				printf("No hay lugar en el sistema\n");
			}
			else
			{
			// aca caigo cuando halla lugar ?para guardar empleado
				printf("Ingrese el nombre del pasajero:\n ");
				fflush(stdin);
			    gets(nombre);

			    while(strlen(nombre) >= 51)
		        {
	             	 printf("Nombre demasiado largo. Reingrese nombre:\n ");
      	             fflush(stdin);
		             gets(nombre);
	       		}
	            strcpy(aux.nombre, nombre);

	            printf("Ingrese el apellido del pasajero:\n ");
	            fflush(stdin);
	            gets(apellido);

	            while(strlen(apellido) >= 51)
	            {
	            	printf("Apellido demasiado largo. Reingrese Apellido:\n ");
			        fflush(stdin);
			        gets(apellido);
	            }

	            strcpy(aux.apellido, apellido);

	            printf("Ingrese precio:\n ");
	            fflush(stdin);
	            scanf("%f", &precio);

	            aux.precio = precio;

	            printf("Ingrese codigo del vuelo:\n ");
	            fflush(stdin);
	            gets(codigoVuelo);

	            while(strlen(codigoVuelo) >= 10)
	            {
					  printf("Codigo del vuelo demasiado largo. Reingrese codigo \n");
					  fflush(stdin);
					  gets(codigoVuelo);
	            }
	            strcpy(aux.codigoVuelo, codigoVuelo);

	            printf("Ingrese la clase del aciento (1(prime)/2(media)/3(turista))): \n");
	            fflush(stdin);
	            scanf("%d", &tipoPasajero);

	            while(tipoPasajero > 3 || tipoPasajero < 0)
	            {
					  printf("clase inexistente (1(prime)/2(media)/3(turista))):\n ");
					  fflush(stdin);
					  scanf("%d", &tipoPasajero);
	            }

	            aux.tipoPasajero = tipoPasajero;

	            printf("Ingrese el estado del vuelo (1(activo)/2(demorado)/3(cancelado)): \n");
	            fflush(stdin);
	            scanf("%d", &estadoVuelo);

	            while(estadoVuelo > 3 || estadoVuelo < 0)
	            {
					  printf("Ingrese el estado del vuelo (1(activo)/2(demorado)/3(cancelado)): \n");
					  fflush(stdin);
					  scanf("%d", &estadoVuelo);
	            }

			   aux.estadoVuelo = estadoVuelo;

			   aux.isEmpty = 0;
               aux.id = id;
			   vec[indice] =  aux;
			   todoOk=1;
			}
		}

	}
		return todoOk;
}
int modificarPasajeroPorID(Pasajeros* vec, int tam, int id)
{
	int todoOk=0;
	int indice;
	char salir;
	if(vec != NULL && tam>0)
	{
		imprimirPasajeros(vec, tam);
		printf("ingrese legajo:\n");
		scanf("%d", &id);
	   	if(buscarPasajero(vec, tam, id, &indice))
	   	{
			 if(indice==-1)
	   		 {
	   			  printf("no hay un empleado con legajo %d\n", id);
			 }
	   		 else
		     {
	   			 mostrarPasajeros(vec[indice]);

	   			do
	   			{
	   				switch(opcionesCambio())
	   				{
	   				case 1:
					printf("%s \n", vec[indice].nombre);

					printf("ingrese su nuevo nombre:\n");
					fflush(stdin);
					gets(vec[indice].nombre);
					while(strlen(vec[indice].nombre) >= 51)
					{
						printf("Nombre demasiado largo. Reingrese nombre:\n ");
	   		            fflush(stdin);
	                    gets(vec[indice].nombre);
					}
					printf("%s nuevo nombre \n", vec[indice].nombre);
					break;
	   				case 2:
	   				printf("%s \n", vec[indice].apellido);

	   				printf("Ingrese el  nuevo apellido:\n ");
	   				fflush(stdin);
	   				gets(vec[indice].apellido);

	   				while(strlen(vec[indice].apellido) >= 51)
	   			    {
	   					printf("Apellido demasiado largo. Reingrese Apellido:\n ");
	   					fflush(stdin);
	   	        		gets(vec[indice].apellido);
	   			    }
	   				printf("%s nuevo apellido \n", vec[indice].apellido);
	   				break;
	   				case 3:
					printf("%f \n", vec[indice].precio);

	   				printf("Ingrese nuevo precio:\n ");
					fflush(stdin);
					scanf("%f", &vec[indice].precio);

					printf("%f nuevo precio \n", vec[indice].precio);
	   				break;
	   				case 4:
	   				printf("%s \n", vec[indice].codigoVuelo);

	   			    printf("Ingrese nuevo codigo del vuelo:\n ");
	   				fflush(stdin);
	   				gets(vec[indice].codigoVuelo);

	   				while(strlen(vec[indice].codigoVuelo) >= 10)
	   				{
	   					printf("Codigo del vuelo demasiado largo. Reingrese codigo \n");
	   					fflush(stdin);
	   					gets(vec[indice].codigoVuelo);
	   				}
	   				printf("%s nuevo codigo de vuelo\n", vec[indice].codigoVuelo);
	   			    break;
	   				case 5:
	   				printf("%d \n", vec[indice].tipoPasajero);

	   				printf("Ingrese la nueva clase del aciento (1(prime)/2(media)/3(turista))): \n");
	   				fflush(stdin);
	   			    scanf("%d", &vec[indice].tipoPasajero);

	   				while(vec[indice].tipoPasajero > 3 || vec[indice].tipoPasajero < 0)
	   				{
	   					printf("clase inexistente (1(prime)/2(media)/3(turista))):\n ");
	   	     			fflush(stdin);
	   					scanf("%d", &vec[indice].tipoPasajero);
	   				}
	   			   printf("%d nuevo tipo de vuelo\n", vec[indice].tipoPasajero);
	  			   break;
	  			   case 6:
	  			   printf("%d \n", vec[indice].estadoVuelo);
	  			   printf("Ingrese el estado del vuelo (1(activo)/2(demorado)/3(cancelado)): \n");
	  			   fflush(stdin);
	  			   scanf("%d", &vec[indice].estadoVuelo);

	  			   while(vec[indice].estadoVuelo > 3 || vec[indice].estadoVuelo < 0)
	  			   {
	  				   printf("Ingrese el estado del vuelo (1(activo)/2(demorado)/3(cancelado)): \n");
	  				   fflush(stdin);
	  				   scanf("%d", &vec[indice].estadoVuelo);
	 			   }
	  			   printf("%d nuevo estado de vuelo:\n", vec[indice].estadoVuelo);
	   			   break;
	   			   case 7:
	   				   confirmarSalida(&salir);
	   			   break;
	   			   default:
	   					printf("opcion Invalida!\n\n");
	   		      }
	   	        system("pause");
	          }while(salir != 's');
	     }
      }
	  else
	  {
			printf("Ocurrio un problema\n");
      }
    todoOk=1;
    }
 return todoOk;
}

int removerPasajero(Pasajeros* vec, int tam)
{
	int todoOk=0;
	int id;
	int indice;
	char confirmar;
	if(vec != NULL && tam>0)
	{
		imprimirPasajeros(vec, tam);
		printf("ingrese legajo:\n");
		scanf("%d", &id);
    	if(buscarPasajero(vec, tam, id, &indice))
    	{
			 if(indice==-1)
	   		 {
	   			  printf("no hay un pasajero con legajo %d\n", id);

			 }
	   		 else
		     {
	  			 mostrarPasajeros(vec[indice]);
			     printf("Confirmar baja?:");
			     fflush(stdin);
			     scanf("%c", &confirmar);
			     if(confirmar != 's' && confirmar != 'S')
			     {
			    	 printf("No se borro el usuario\n");
			     }
			     else
			     {
			    	 vec[indice].isEmpty = 1;
			    	 printf("Baja del usuario confirmada\n");
			    	 todoOk=1;
			     }
			  }
		}
		else
		{
			printf("Ocurrio un problema\n");
    	}
    	todoOk=1;
	}
	return todoOk;
}


int ordenarPasajerosPorApellidoYTipoAcd(Pasajeros vec[], int tam)
{
    int todoOk = 0;
    int mostrar = 0;
    Pasajeros auxPasajeros;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if( ((vec[i].tipoPasajero == vec[j].tipoPasajero) &&  (vec[i].apellido > vec[j].apellido))
                	|| ((vec[i].tipoPasajero != vec[j].tipoPasajero) &&(vec[i].tipoPasajero > vec[j].tipoPasajero)) )
                {
                    auxPasajeros = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajeros;
                    mostrar = 1;
                }
            }
        }
        if(mostrar == 1)
        {
        	printf(" POR APELLDIO Y TIPO\n");
        	imprimirPasajeros(vec, tam);
        }
        todoOk = 1;
    }
    return todoOk;
}
int odernarPasajeroPorCodigoYVuelosActivosAcd(Pasajeros vec[], int tam)
{
    int todoOk = 0;
    int mostrar = 0;
    Pasajeros auxPasajeros;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if( ((vec[i].estadoVuelo == 1) && (vec[i].codigoVuelo == vec[j].codigoVuelo))
                	|| ((vec[i].estadoVuelo != 1) && (vec[i].estadoVuelo > vec[j].estadoVuelo)) )
                {
                    auxPasajeros = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajeros;
                    mostrar = 1;
                }
            }
        }
        if(mostrar == 1)
        {
        	printf(" POR CODIGO Y VUELO ACTIVO\n");
        	imprimirPasajeros(vec, tam);
        }
        todoOk = 1;
    }
    return todoOk;
}
int ordenarPasajerosPorApellidoYTipoDes(Pasajeros vec[], int tam)
{
    int todoOk = 0;
    int mostrar = 0;
    Pasajeros auxPasajeros;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if( ((vec[i].tipoPasajero == vec[j].tipoPasajero) &&  (vec[i].apellido < vec[j].apellido))
                    || ((vec[i].tipoPasajero != vec[j].tipoPasajero) &&(vec[i].tipoPasajero <vec[j].tipoPasajero)) )
                {
                    auxPasajeros = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajeros;
                    mostrar = 1;
                }
            }
        }
        if(mostrar == 1)
        {
        	printf(" POR APELLDIO Y TIPO\n");
        	imprimirPasajeros(vec, tam);
        }
        todoOk = 1;
    }
    return todoOk;
}


int odernarPasajeroPorCodigoYVuelosActivosDes(Pasajeros vec[], int tam)
{
    int todoOk = 0;
    int mostrar = 0;
    Pasajeros auxPasajeros;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if( ((vec[i].codigoVuelo == vec[j].codigoVuelo) &&  (vec[i].estadoVuelo == 3))
                   || ((vec[i].estadoVuelo != 3) && (vec[i].estadoVuelo < vec[j].estadoVuelo)) )
                {
                    auxPasajeros = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajeros;
                    mostrar = 1;
                }
            }
        }
        if(mostrar == 1)
        {
        	printf(" POR CODIGO Y VUELO ACTIVO\n");
        	imprimirPasajeros(vec, tam);
        }
        todoOk = 1;
    }
    return todoOk;
}

int precioPasajeros(Pasajeros* list, int tam, float promedio, float precio)
{
	int todoOk = 0;
	int j = 0;
	int contadorMasPromedio = 0;
	if(list != NULL && tam > 0 && promedio >= 0)
	{

		for(int i=0; i < tam; i++)
		{
			if(list[i].isEmpty == 0)
			{
			  precio += list[i].precio;
			  j++;
			}
		}
		if(j > 0)
		{
			printf("pecio total %.3f\n", precio);
			promedio  = (float) precio / j;
			printf("el promedio es:%.3f\n", promedio);
		}

		for(int i=0; i<tam;i++)
		{
			if(list[i].isEmpty == 0)
			{
			  if(list[i].precio > promedio)
			  {
				  contadorMasPromedio++;
			  }
			}
		}
		if(contadorMasPromedio > 0)
		{
			printf("los pasajeros que superen el precio promedio son %d\n", contadorMasPromedio);
		}
		else
		{
			printf("ningun pasajero supera el promedio\n");
		}
		todoOk = 1;
	}
	return todoOk;
}

int hardcodearPasajeros(Pasajeros* list, int tam, int cant, int id)
{

    int todoOk = 0;
    Pasajeros impostores[] =
    {
        {0, "Juan", "Gonzalez", 45000, "qwe",1,3,0},
        {0, "Daniela", "Ferrer", 100000, "asd",2,1,0},
        {0, "Lucia", "Gomez", 26000, "zxc",3,2,0},
        {0, "Mauro", "Rodriguez", 32500, "ghj",1,2,0},
        {0, "Diego", "Fernandez", 540000, "vbn",2,1,0},
        {0, "Juana", "Alvarez", 20000, "rty",3,3,0},
        {0, "Miguel", "Canata", 23000, "uio",2,3,0},
        {0, "Luciano", "Rueda", 31000, "klu",1,3,0},
        {0, "Marina", "Polti", 27000, "mnb",1,1,0},
        {0, "Dalma", "Prez", 240000, "poi",2,2,0}
    };

    if(list != NULL && tam > 0 && id >=0 && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            list[i] = impostores[i];
            list[i].id = id;
            id = id +1;

        }
        todoOk = 1;
    }
    return todoOk;

}































void mostrarPasajeros(Pasajeros e)
{

    printf(" %4d %10s  %10s   %5.2f   %5s    %5d    %5d\n",
    		e.id,
			e.nombre,
			e.apellido,
			e.precio,
			e.codigoVuelo,
			e.tipoPasajero,
			e.estadoVuelo);

}


int imprimirPasajeros(Pasajeros* vec, int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        //system("cls");
        printf("          *** Listado de Pasajeros ***\n\n");
        printf("id      nombres     apellido     precio    codigo    tipo    estado\n");
        printf("-----------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
        	if(!vec[i].isEmpty)
        	{
        		mostrarPasajeros(vec[i]);
        	}
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}


