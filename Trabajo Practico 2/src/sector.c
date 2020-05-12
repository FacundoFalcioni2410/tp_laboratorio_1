#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "informes.h"
#include "utn.h"


int mostrarSectores(eSector sectores[], int tam)
{
	int opcion;

	system("cls");
	printf("\n\n*** SECTORES ***\n\n");

	for(int i = 0; i < tam; i++)
	{
		printf("%d   %10s \n", sectores[i].id, sectores[i].descripcion);
	}
	utn_getEntero(&opcion,3,"Ingrese la opcion deseada: ", "Error. Opcion ingresada invalida\n",1,5);

	return opcion;
}
