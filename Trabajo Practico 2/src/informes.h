#include "sector.h"
#include "arrayEmployees.h"

#ifndef INFORMES_H_
#define INFORMES_H_



#endif /* INFORMES_H_ */

/**
 * @fn int menuInformes()
 * @brief despliega un menu en el cual se muestra los distintos informes que hay
 * @return retorna la opcion que corresponde a cada item del menu
 */
int menuInformes();

/**
 * @fn void informar(eEmpleados[], int, eSector[], int)
 * @brief llama a las distintas funciones que realizan los informes
 * @param x parametro requerido para poder realizar la llamada a las distintas funciones
 * @param tam parametro requerido para poder realizar la llamada a las distintas funciones
 * @param sectores parametro requerido para poder realizar la llamada a las distintas funciones
 * @param tamSec parametro requerido para poder realizar la llamada a las distintas funciones
 */
void informar(eEmpleados x[],int tam, eSector sectores[],int tamSec);


/**
 * @fn void informarEmpleadosOrdenadosAlfabeticamente(eEmpleados[], int, eSector[], int)
 * @brief informa los empleados por orden alfabetico
 * @param x vector en el cual se encuentras los empleados a informar
 * @param tam tamaño del vector
 * @param sectores parametro requerido para poder realizar la llamada a la funcion mostrarEmpleado
 * @param tamSec parametro requerido para poder realizar la llamada a la funcion mostrarEmpleado
 */
void informarEmpleadosOrdenadosAlfabeticamente(eEmpleados x[], int tam, eSector sectores[],int tamSec);


/**
 * @fn void informarSueldosYPromedio(eEmpleados[], int, eSector[], int)
 * @brief informa el total de sueldos, el promedio del mismo y que empleado gana por encima del sueldo promedio
 * @param x vector en el cual se encuentra el sueldo de los empleados
 * @param tam tamaño del vector
 * @param sectores parametro requerido para poder realizar la llamada a la funcion mostrarEmpleado
 * @param tamSec parametro requerido para poder realizar la llamada a la funcion mostrarEmpleado
 */
void informarSueldosYPromedio(eEmpleados x[], int tam, eSector sectores[],int tamSec);
