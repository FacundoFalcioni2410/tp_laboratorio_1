#include "sector.h"

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_



typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int isEmpty;
    int idSector;

} eEmpleados;



#endif /* ARRAYEMPLOYEES_H_ */

/**
 * @fn void ordenarEmpleadosAlfabeticamente(eEmpleados[], int)
 * @brief funcion que ordena alfabeticamente a los empleados
 * @param x vector en el que se encuentras los empleados a ordenar
 * @param tam tamaño
 */
void ordenarEmpleadosAlfabeticamente(eEmpleados x[], int tam, eSector sectores[], int tamSec);

/**
 * @fn void mostrarEmpleado(eEmpleados, eSector[], int)
 * @brief imprimir los empleados
 * @param x empleado a mostrar
 * @param sectores parametro requerido para poder realizar la llamada a la funcion cargarDescripcionSector
 * @param tamSec parametro requerido para poder realizar la llamada a la funcion cargarDescripcionSector
 */
void mostrarEmpleado(eEmpleados x, eSector sectores[], int tamSec);

/**
 * @fn void mostrarEmpleado(eEmpleados, eSector[], int)
 * @brief recorre un vector de empleados para pasarselo a la funcion mostrarEmpleado y que esta los imprima
 * @param x vector a recorrer
 * @param sectores parametro requerido para poder realizar la llamada a la funcion mostrarEmpleado
 * @param tamSec parametro requerido para poder realizar la llamada a la funcion mostrarEmpleado
 */
void mostrarEmpleados(eEmpleados x[], int tam, eSector sectores[], int tamSec);

/**
 * @fn void inicializarEmpleados(eEmpleados[], int)
 * @brief inicializa todos los huecos del vector para que el programa los reconozca como vacios
 * @param vec vector en el cual estan los empleados
 * @param tam tamaño del vector
 */
void inicializarEmpleados(eEmpleados x[], int tam);

/**
 * @fn int menuModificarEmpleado()
 * @brief menu que se muestra para preguntarle al usuario que dato del empleado desea modificar
 * @return devuelve la opcion ingresada por el usuario
 */
int menuModificarEmpleado();

/**
 * @fn int buscarEspacioLibre(eEmpleados[], int)
 * @brief busca un espacio libre para que a la hora de dar de alta un empleado no sobreescrbir otro
 * @param x vector en el cual se busca el espacio libre
 * @param tam tamaño del vector
 * @return devuelve -1 si no encontro espacio libre, de lo contrario devuelve el indice del vector x
 */
int buscarEspacioLibre(eEmpleados x[], int tam);

/**
 * @fn int buscarEmpleado(eEmpleados[], int, int)
 * @brief busca un empleado por el id proporcionado por el usuario
 * @param x vector en el cual se busca al empleado
 * @param tam tamaño del vector
 * @param id id del empleado a buscar
 * @return retorna -1 si el id del empleado solicitado no existe, de lo contrario devuelve el indice del vector
 */
int buscarEmpleado(eEmpleados x[], int tam, int id);


/**
 * @fn int altaEmpleado(int, eEmpleados[], int)
 * @brief realiza el alta de un empleado en un vector proporcionado por el usuario
 * @param proximoId id autoincremental, cada vez que un alta se realiza con exito se suma un 1 para que cada id sea distinto
 * @param x vector en el cual se desea realizar el alta
 * @param tam tamaño del vector
 * @param parametro requerido por funcion mostrarSectores
 * @param parametro requerido por funcion mostrarSectores
 * @return retorna 1 si se realizo con exito el alta, de lo contrario devuelve 0
 */
int altaEmpleado(int proximoId,eEmpleados x[], int tam, eSector sectores[], int tamSec);

/**
 * @fn void bajaEmpleado(eEmpleados[], int, eSector[], int)
 * @brief se utiliza para dar de baja a un empleado
 * @param x vector donde se necuentra el empleado a dar de baja
 * @param tam tamaño de dicho vector
 * @param sectores parametro requerido para poder realizar la llamada a  la funcion mostrarEmpleado
 * @param tamSec parametro requerido para poder realizar la llamada a  la funcion mostrarEmpleado
 */
void bajaEmpleado(eEmpleados x[],int tam, eSector sectores[],int tamSec);

/**
 * @fn void modificarEmpleado(eEmpleados[], int, eSector[], int)
 * @brief realiza una modificacion en un campo de un empleado ubicado en el vector x
 * @param x vector en el cual se encuentra el empleado a modificar
 * @param tam tamaño del vector
 * @param sectores parametro requerido para poder realizar la llamada a  la funcion mostrarEmpleado
 * @param tamSec parametro requerido para poder realizar la llamada a  la funcion mostrarEmpleado
 */
void modificarEmpleado(eEmpleados x[],int tam, eSector sectores[],int tamSec);


/**
 * @fn int cargarDescripcionSector(char[], int, eSector[], int)
 * @brief copia el contenido de una cadena a la otra, siempre y cuando se cumpla la condicion de que el id de sector que ingrese el usuario sea igual al de un sector existente, en dicho caso se copia el nombre del mismo a la cadena destino
 * @param descripcion cadena en la cual va a ser copiado la cadena origen
 * @param id id de sector en el cual se va a igualar para ver si corresponde a un sector existente o no
 * @param sectores vector donde se encuentra la cadena origen
 * @param tam tamaño del vector
 * @return retorna un 1 si se realizo con exito o un 0 si hubo algun error
 */
int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int tam);
