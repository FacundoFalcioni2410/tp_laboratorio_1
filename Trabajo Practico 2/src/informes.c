#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "sector.h"
#include "informes.h"

void informar(eEmpleados x[],int tam, eSector sectores[], int tamSec)
{

    char respuesta;
    respuesta = 'n';

    do
    {
        switch(menuInformes())
        {
        case 1:
        	informarEmpleadosOrdenadosAlfabeticamente(x, tam, sectores, tamSec);
            break;
        case 2:
        	informarSueldosYPromedio(x, tam, sectores,tamSec);
            break;
        case 3:
            printf("Desea salir? ");
            fflush(stdin);
            scanf("%c", &respuesta);
            break;
        }
        printf("\n\n");
        system("pause");
    }
    while(respuesta == 'n');
}

void informarEmpleadosOrdenadosAlfabeticamente(eEmpleados x[], int tam, eSector sectores[],int tamSec)
{
    system("cls");
    printf("\n\n*** EMPLEADOS ORDENADOS ALFABETICAMENTE ***\n\n");

    for(int i = 0; i < tam; i++)
    {
        ordenarEmpleadosAlfabeticamente(x,tam, sectores, tamSec);
    }

    mostrarEmpleados(x,tam,sectores,tamSec);
}

void informarSueldosYPromedio(eEmpleados x[], int tam, eSector sectores[],int tamSec)
{
	int flag = 0;
    float sueldosTotales = 0;
    int contador = 0;
    float promedio = 0;

    system("cls");
    printf("***** SUELDOS *****\n\n");

    for(int i = 0; i < tam; i++)
    {
    	if(x[i].isEmpty == 0)
    	{
    		sueldosTotales+=x[i].sueldo;
    		contador++;
    	}
    }

    promedio = sueldosTotales/contador;

    contador = 0;

    printf("La cantidad de sueldos totales es de %.2f\nEl promedio de sueldos es: %.2f\n",sueldosTotales,promedio);

    printf("\n*** EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO ***\n\n");

    printf("*** ID  NOMBRE    APELLIDO 	  SUELDO     SECTOR ***\n");

    for(int i = 0; i < tam; i++)
    {
    	if(x[i].sueldo > promedio && x[i].isEmpty == 0)
    	{
    		contador++;
    		mostrarEmpleado(x[i],sectores,tamSec);
    		flag = 1;
    	}
    }

    printf("\n\nLa cantidad de empleados que superan el sueldo promedio es de: %d",contador);

    if(!flag)
    {
    	printf("\n\nNingun empleado supera el promedio\n\n");
    }
}

int menuInformes()
{

    int opcion;

    system("cls");
    printf("***** Menu de Informes *****\n\n");
    printf("1. Empleados ordenados alfabeticamente por apellido y sector.\n");
    printf("2. Cantidad de sueldos totales, promedio de sueldos y que personas tienen un sueldo mas grande que el informe.\n");
    printf("3. Salir.\n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
