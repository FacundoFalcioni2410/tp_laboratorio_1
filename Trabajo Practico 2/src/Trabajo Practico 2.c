#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "sector.h"
#include "informes.h"

#define TAM 1000
#define TAMSEC 4

/**
 * @fn int menu()
 * @brief menu principal del programa
 * @return devuelve la opcion ingresada por el usuario
 */
int menu();

int main()
{

	setbuf(stdout, NULL);

    char respuesta = 's';
    char confirma= 'n';
    int proximoId;

    eSector sectores[] = { {1, "Sitemas"}, {2,"RRHH"}, {3, "Ventas"}, {4, "Compras"}, {5, "Contable"} };
    eEmpleados lista[TAM];
    proximoId = 1000;
    inicializarEmpleados(lista,TAM);

    do
    {
        switch(menu())
        {
        case 1:
            if(altaEmpleado(proximoId,lista,TAM, sectores, TAMSEC))
            {
                proximoId++;
            }
            break;
        case 2:
        	if(-1 != buscarEspacioLibre(lista,TAM))
        	{
            	modificarEmpleado(lista,TAM,sectores,TAMSEC);
        	}

            break;
        case 3:
        	if(-1 !=buscarEspacioLibre(lista,TAM))
        	{
                bajaEmpleado(lista,TAM,sectores,TAMSEC);
        	}
            break;
        case 4:
        	if(-1 != buscarEspacioLibre(lista,TAM))
        	{
        		informar(lista,TAM,sectores,TAMSEC);
        	}
            break;
        case 5:
            printf("Confirma salida?\n");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma == 's')
            {
                scanf("%c",&respuesta);
            }
            break;
        }

        system("pause");

    }
    while(respuesta=='s');

    printf("\n\n");


    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("***** Gestion de Empleados *****\n\n");
    printf("1. Alta\n");
    printf("2. Modificar\n");
    printf("3. Baja\n");
    printf("4. Informes\n");
    printf("5. Salir\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

//INFORMAR EMPLEADOS POR SECTOR
//MOSTRAR SECTORES, EN EL MOMENTO DE LA ALTA
