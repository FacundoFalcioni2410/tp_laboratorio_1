#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "informes.h"
#include "sector.h"
#include "utn.h"


void bajaEmpleado(eEmpleados x[],int tam, eSector sectores[],int tamSec)
{
    int id;
    int indice;
    char respuesta;

    system("cls");
    printf("***BAJA EMPLEADO***\n\n");

    printf("Ingrese ID DEL EMPLEADO A DAR DE BAJA: ");
    fflush(stdin);
    scanf("%d",&id);

    indice = buscarEmpleado(x,tam,id);

    if(indice == -1)
    {
        printf("\nNo hay ningun empleado registrado con el ID: %d\n\n",id);
    }
    else
    {
        mostrarEmpleado(x[indice],sectores,tamSec);

        printf("\n\nDesea continuar con la baja?");
        fflush(stdin);
        scanf("%c",&respuesta);

        if(respuesta == 's')
        {
            x[indice].isEmpty = 1;
            printf("\nBaja realizada con exito\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la operacion\n\n");
        }
    }
}



int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int tam)
{
    int todoOk = 0;

    for(int i = 0; i < tam; i++)
    {
        if(sectores[i].id == id)
        {
            strcpy(descripcion, sectores[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}


void inicializarEmpleados(eEmpleados x[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        x[i].isEmpty = 1;
    }
}

void mostrarEmpleado(eEmpleados x, eSector sectores[], int tamSec)
{
    char nombreSector[20];

    cargarDescripcionSector(nombreSector,x.idSector,sectores,tamSec);

    printf("%d %10s %10s    %6.2f      %10s\n",x.id,x.nombre,x.apellido,x.sueldo, nombreSector);
}

void mostrarEmpleados(eEmpleados x[], int tam, eSector sectores[] ,int tamSec)
{
    int flag;

    flag = 0;

    system("cls");
    printf("*** Listado de Empleados ***\n\n");
    printf("***ID  NOMBRE    APELLIDO 	  SUELDO     SECTOR***\n");

    for(int i = 0; i < tam; i++)
    {
        if(x[i].isEmpty == 0)
        {
            mostrarEmpleado(x[i],sectores,tamSec);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay empleados para mostrar\n");
    }
}

void ordenarEmpleadosAlfabeticamente(eEmpleados x[], int tam, eSector sectores[], int tamSec)
{
    eEmpleados auxiliar;

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(strcmp(x[i].apellido, x[j].apellido) > 0)
            {
                auxiliar=x[i];
                x[i]=x[j];
                x[j]=auxiliar;
            }
            else if(x[i].apellido == x[j].apellido && strcmp(sectores[i].descripcion, sectores[j].descripcion) > 0)
            {
                auxiliar=x[i];
                x[i]=x[j];
                x[j]=auxiliar;
            }
        }
    }
}



int buscarEspacioLibre(eEmpleados x[], int tam)
{
    int indice;

    indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleados x[], int tam, int id)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(x[i].isEmpty == 0 && x[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaEmpleado(int proximoId,eEmpleados x[], int tam, eSector sectores[], int tamSec)
{
    int alta;
    int indice;
    eEmpleados auxiliar;

    alta = 0;
    indice = buscarEspacioLibre(x,tam);

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        auxiliar.id=proximoId;

        utn_getCadena(auxiliar.nombre, 51,3,"Ingrese nombre del empleado: ","Error. Nombre invalido.\n");

        normalizeStr(auxiliar.nombre);

        utn_getCadena(auxiliar.apellido, 51,3,"Ingrese apellido del empleado: ","Error. Apellido invalido.\n");

        normalizeStr(auxiliar.apellido);

        utn_getFlotante(&auxiliar.sueldo, 3, "Ingrese sueldo del empleado: ","Error. Sueldo invalido", 10000, 1000000);

        switch(mostrarSectores(sectores, tamSec))
        {
        case 1:
        	auxiliar.idSector = 1;
        	break;
        case 2:
        	auxiliar.idSector = 2;
        	break;
        case 3:
        	auxiliar.idSector = 3;
        	break;
        case 4:
        	auxiliar.idSector = 4;
        	break;
        }

        auxiliar.isEmpty = 0;


        x[indice] = auxiliar;
        alta = 1;
    }
    return alta;
}

void modificarEmpleado(eEmpleados x[],int tam, eSector sectores[],int tamSec)
{
	int id;
	int indice;
	char respuesta;

	system("cls");
	printf("***MODIFICAR EMPLEADO***\n\n");

	printf("Ingrese ID DEL EMPLEADO A MODIFICAR: ");
	fflush(stdin);
	scanf("%d",&id);

	indice = buscarEmpleado(x,tam,id);

	if(indice == -1)
	{
		printf("No hay ningun empleado registrado con el ID: %d\n\n",id);
	}
	else
	{
		mostrarEmpleado(x[indice],sectores,tamSec);

	    printf("\n\nDesea realizar una modificacion sobre este empleado?");
	    fflush(stdin);
	    scanf("%c",&respuesta);

	    if(respuesta == 's')
	    {
	    		switch(menuModificarEmpleado())
	    		{
				case 1:
			        utn_getCadena(x[indice].nombre, 51,3,"Ingrese nombre del empleado: ","Error. Nombre invalido.\n");

			        normalizeStr(x[indice].nombre);
					break;
				case 2:
					utn_getCadena(x[indice].apellido, 51,3,"Ingrese apellido del empleado: ","Error. Apellido invalido.\n");

					normalizeStr(x[indice].apellido);
					break;
				case 3:
			        utn_getFlotante(&x[indice].sueldo, 3, "Ingrese sueldo del empleado: ","Error. Sueldo invalido", 10000, 1000000);
					break;
				case 4:
					printf("Ingrese el sector:");
					fflush(stdin);
					scanf("%d", &x[indice].idSector);
					break;
	    	    }
    		printf("\n\nModificacion realizada con exito\n\n");
	    }
	    else
	    {
	        printf("Se ha cancelado la operacion\n\n");
	    }
	 }
}

int menuModificarEmpleado()
{
	int opcion;

	system("cls");
	printf("*** MODIFICAR EMPLEADO ***\n\n");
	printf("Que desea modificar?\n");
	printf("1. Nombre\n");
	printf("2. Apellido\n");
	printf("3. Salario\n");
	printf("4. Sector\n");
	printf("Ingrese una opcion: ");
	fflush(stdin);
	utn_getEntero(&opcion,3,"Ingrese la opcion deseada: ", "Error. Opcion ingresada invalida\n",1,4);

	return opcion;

}
