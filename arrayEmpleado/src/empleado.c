/*
 * empleado.c
 *
 *  Created on: 4 may. 2022
 *      Author: juanm
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "empleado.h"

int mostrarEmpleado(eEmpleado e, eSector sectores[], int tam)
{
    int todoOk = 0;
    char descSector[20];

    if(sectores != NULL && tam > 0){

    cargarDescripcionSector( sectores, tam, e.idSector, descSector);



    printf("  %4d       %15s       %c      %2d    %9.2f    %02d/%02d/%d   %10s\n",
           e.legajo,
           e.nombre,
           e.sexo,
           e.edad,
           e.sueldo,
           e.fIngreso.dia,
           e.fIngreso.mes,
           e.fIngreso.anio,
           descSector
          );
        todoOk = 1;
    }
    return todoOk;
}


int listarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int todoOk = 0;
    int flag = 0;
    if(vec != NULL && tam > 0)
    {
        system("cls");
        printf("          *** Listado de Empleados ***\n\n");
        printf(" Legajo          Nombre        Sexo    Edad    Sueldo        F.Ingreso  Sector\n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrarEmpleado(vec[i], sectores, tamSec);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay empleados en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}



int cargarEmpleados(eEmpleado vec[], int tam)
{
    int todoOk = 0;
    char auxCad[100];
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            printf("Ingrese legajo: ");
            scanf("%d", &vec[i].legajo);

            printf("Ingrese el nombre del empleado: ");
            fflush(stdin);
            gets(auxCad);

            while(strlen(auxCad) >= 20)
            {
                printf("Nombre demasiado largo. Reingrese nombre: ");
                fflush(stdin);
                gets(auxCad);
            }
            strcpy(vec[i].nombre, auxCad);


            printf("Ingrese sexo('m' o 'f'): ");
            fflush(stdin);
            scanf("%c", &vec[i].sexo);

            printf("Ingrese edad: ");
            scanf("%d", &vec[i].edad);

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[i].sueldo);
        }

        todoOk = 1;
    }
    return todoOk;
}

int ordenarEmpleadosLegajoAsc(eEmpleado vec[], int tam)
{
    int todoOk = 0;
    eEmpleado auxEmpleado;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if(vec[i].legajo > vec[j].legajo)
                {
                    auxEmpleado = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmpleado;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarEmpleadosNombreAsc(eEmpleado vec[], int tam)
{
    int todoOk = 0;
    eEmpleado auxEmpleado;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if(strcmp(vec[i].nombre, vec[j].nombre) > 0)
                {
                    auxEmpleado = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmpleado;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarEmpleadosSexoAsc(eEmpleado vec[], int tam)
{
    int todoOk = 0;
    eEmpleado auxEmpleado;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if(vec[i].sexo > vec[j].sexo)
                {
                    auxEmpleado = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmpleado;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int ordenarEmpleados(eEmpleado vec[], int tam, int campo, int criterio)
{
    int todoOk = 0;
    eEmpleado auxEmpleado;
    if(vec != NULL && tam > 0 && campo >= 0 && campo <= 4 && criterio >= 0 && criterio <= 1)
    {

        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if( (strcmp(vec[i].nombre, vec[j].nombre) > 0 && campo == 0 && criterio)
                        || (strcmp(vec[i].nombre, vec[j].nombre) < 0 && campo == 0 && !criterio )
                        || (vec[i].edad > vec[j].edad && campo == 1 && criterio)
                        || (vec[i].edad < vec[j].edad && campo == 1 && !criterio)
                        || (vec[i].legajo > vec[j].legajo && campo == 2 && criterio)
                        || (vec[i].legajo < vec[j].legajo && campo == 2 && !criterio)
                        || (vec[i].sexo > vec[j].sexo && campo == 3 && criterio)
                        || (vec[i].sexo < vec[j].sexo && campo == 3 && !criterio)
                        || (vec[i].sueldo > vec[j].sueldo && campo == 4 && criterio)
                        || (vec[i].sueldo < vec[j].sueldo && campo == 4 && !criterio)
                  )
                {
                    auxEmpleado = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmpleado;
                }
            }
        }





        todoOk = 1;
    }
    return todoOk;
}


int ordenarEmpleadosPorSexoYLegajo(eEmpleado vec[], int tam)
{
    int todoOk = 0;
    eEmpleado auxEmpleado;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                // si son del mismo sexo y estan desordenados por legajo swapeo
                if( ((vec[i].sexo == vec[j].sexo) &&  (vec[i].legajo > vec[j].legajo))
                        || ((vec[i].sexo != vec[j].sexo) &&(vec[i].sexo > vec[j].sexo) ))
                {
                    auxEmpleado = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmpleado;
                }
                // y sino si son de distinto sexo y estan desordenados por sexo swapeo

            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int inicializarEmpleados(eEmpleado vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}




int buscarEmpleadoLibre(eEmpleado vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaEmpleado(eEmpleado vec[], int tam, int* pLegajo)
{
    int todoOk = 0;
    int indice;
    char auxCad[100];
    eEmpleado nuevoEmpleado;
    eFecha fecha;

    if(vec != NULL && tam > 0 && pLegajo != NULL)
    {
        if( buscarEmpleadoLibre(vec, tam, &indice) )
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                // aca caigo cuando haya lugar

                printf("Ingrese el nombre del empleado: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevoEmpleado.nombre, auxCad);

                printf("Ingrese sexo('m' o 'f'): ");
                fflush(stdin);
                scanf("%c", &nuevoEmpleado.sexo);

                printf("Ingrese edad: ");
                scanf("%d", &nuevoEmpleado.edad);

                printf("Ingrese sueldo: ");
                scanf("%f", &nuevoEmpleado.sueldo);

                printf("Ingrese Fecha ingreso dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

                nuevoEmpleado.fIngreso = fecha;

                nuevoEmpleado.isEmpty = 0;
                nuevoEmpleado.legajo = *pLegajo;
                *pLegajo = *pLegajo + 1;
                vec[indice] = nuevoEmpleado;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}


int buscarEmpleado(eEmpleado vec[], int tam,int legajo, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL && legajo > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty == 0 &&  vec[i].legajo == legajo )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int bajaEmpleado(eEmpleado vec[], int tam,eSector sectores[], int tamSec)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;
    if(vec != NULL && tam > 0)
    {
        listarEmpleados(vec, tam, sectores, tamSec);
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        if( buscarEmpleado(vec, tam, legajo, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un empleado con legajo %d\n", legajo);
            }
            else
            {
                mostrarEmpleado(vec[indice], sectores, tamSec);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja realizada con el exito!!!\n");
                    todoOk = 1;
                }
            }

        }
        else
        {
            printf("Ocurrio un problema al buscar empleado\n");
        }

        todoOk = 1;
    }
    return todoOk;
}


int modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char salir = 'n';
    char auxCad[100];
    eFecha fecha;
    if(vec != NULL && tam > 0)
    {
        listarEmpleados(vec, tam, sectores, tamSec);
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        if( buscarEmpleado(vec, tam, legajo, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un empleado con legajo %d\n", legajo);
            }
            else
            {
                mostrarEmpleado(vec[indice], sectores, tamSec);


                do
                {
                    switch(menuModificarEmpleado())
                    {

                    case 1:
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(auxCad);
                        strcpy(vec[indice].nombre, auxCad);
                        printf("Se ha modificado el nombre\n");
                        break;

                    case 2:
                        printf("Ingrese nuevo sexo: ");
                        fflush(stdin);
                        scanf("%c", &vec[indice].sexo);
                        printf("Se ha modificado el sexo\n");
                        break;

                    case 3:
                        printf("Ingrese nueva edad: ");
                        scanf("%d", &vec[indice].edad);
                        printf("Se ha modificado la edad\n");
                        break;

                        break;
                    case 4:
                        printf("Ingrese nuevo sueldo: ");
                        scanf("%f", &vec[indice].sueldo);
                        printf("Se ha modificado el sueldo\n");

                        break;
                    case 5:
                        printf("Ingrese nueva fecha: ");
                        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

                        vec[indice].fIngreso = fecha;
                        printf("Se ha modificado la fecha\n");
                        break;
                    case 6:
                        salir = 's';
                        break;
                    }
                    system("pause");

                }
                while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar empleado\n");
        }

        todoOk = 1;
    }
    return todoOk;
}


int hardcodearEmpleados(eEmpleado vec[], int tam, int cant, int* pLegajo)
{

    int todoOk = 0;
    eEmpleado impostores[] =
    {
        {0, "Juan", 'm', 30, 100000,{2,5,2022},5000,0},
        {0, "Daniela", 'f', 23, 120000,{4,12,2020},5000,0},
        {0, "Lucia", 'f', 20, 140000,{23,10,2019},5004,0},
        {0, "Mauro", 'm', 27, 120000,{1,2,2021},5001,0},
        {0, "Diego", 'm', 27, 110000,{26,8,2018},5000,0},
        {0, "Juana", 'f', 30, 130000,{5,6,2019},5003,0},
        {0, "Miguel", 'm', 23, 120000,{7,3,2021},5002,0},
        {0, "Luciano", 'm', 21, 150000,{6,11,2018},5004,0},
        {0, "Marina", 'f', 27, 120000,{29,1,2020},5001,0},
        {0, "Dalma", 'f', 24, 110000,{2,9,2021},5002,0}
    };

    if(vec != NULL && tam > 0 && pLegajo != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = impostores[i];
            vec[i].legajo = *pLegajo;
            *pLegajo = *pLegajo +1;

        }
        todoOk = 1;
    }
    return todoOk;

}

int menuModificarEmpleado()
{
    int opcion;
    printf("     *** Campos a modificar ***\n");
    printf("1- Nombre\n");
    printf("2- Sexo\n");
    printf("3- Edad\n");
    printf("4- Sueldo\n");
    printf("5- Fecha de Ingreso\n");
    printf("6- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int listarVarones(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 )
    {
        system("cls");
        printf("    *** Informe Empleados Masculinos   ***\n");
        printf(" Legajo          Nombre        Sexo    Edad    Sueldo        F.Ingreso\n");
        printf("-------------------------------------------------------------------------\n");

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && vec[i].sexo == 'm' )
            {
                mostrarEmpleado(vec[i], sectores, tamSec);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarMujeres(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 )
    {
        system("cls");
        printf("    *** Informe Empleados Femeninos   ***\n");
        printf(" Legajo           Nombre        Sexo    Edad    Sueldo        F.Ingreso\n");
        printf("-------------------------------------------------------------------------\n");

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && vec[i].sexo == 'f' )
            {
                mostrarEmpleado(vec[i], sectores, tamSec);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int listarEmpleadosMayoresA(eEmpleado vec[], int tam,eSector sectores[], int tamSec)
{
    int todoOk = 0;
    int edad;
    if(vec != NULL && tam > 0 )
    {
        system("cls");
        printf("Ingrese edad: ");
        scanf("%d", &edad);

        system("cls");
        printf("    *** Informe Empleados Mayores a %d anios   ***\n", edad);
        printf(" Legajo           Nombre        Sexo    Edad    Sueldo        F.Ingreso\n");
        printf("-------------------------------------------------------------------------\n");

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && vec[i].edad > edad )
            {
                mostrarEmpleado(vec[i], sectores, tamSec);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int informarPromedioSueldos(eEmpleado vec[], int tam)
{

    int todoOk = 0;
    float acumSueldos = 0;
    int contEmpleados = 0;
    float promedio = 0;

    if(vec != NULL && tam > 0 )
    {

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                acumSueldos += vec[i].sueldo;
                contEmpleados++;
            }
        }

        if(contEmpleados > 0)
        {
            promedio = acumSueldos / contEmpleados;
        }

        system("cls");
        printf("    *** Informe Promedio Sueldos   ***\n\n");
        printf("Promedio: $ %.2f\n", promedio);

        todoOk = 1;
    }
    return todoOk;

}

int informarEmpleadoMayorEdad(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int todoOk = 0;
    int mayorEdad;
    int flag = 0;

    if(vec != NULL && tam > 0 )
    {

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && (vec[i].edad > mayorEdad || !flag)  )
            {
                mayorEdad = vec[i].edad;
                flag = 1;
            }
        }

        system("cls");
        printf("     *** Informe Empleado Mayor   ***\n");
        printf("------------------------------------------\n\n");

        if(flag == 0)
        {
            printf("No hay empleados cargados en el sistema\n\n");
        }
        else
        {

            for(int i=0; i < tam; i++)
            {
                if( !vec[i].isEmpty && vec[i].edad == mayorEdad)
                {
                    mostrarEmpleado(vec[i], sectores, tamSec);
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}






