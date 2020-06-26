#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* nombre del archivo en donde se guardan los datos
 * \param pArrayListEmployee LinkedList* array del LinkedList
 * \return int devuelve 1 si hay errores, 0 esta todo bien
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.bien (modo binario).
 *
 * \param path char* nombre del archivo en el que se guardan los datos de forma binaria
 * \param pArrayListEmployee LinkedList* array del LinkedList
 * \return int devuelve 1 si hay errores, 0 esta todo bien
 *
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* Array del LinkedList
 * \return int devuelve 0 si se agrego al empleado, 1 si no se pudo realizar
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* array del LinkedList
 * \return int devuelve 0 si se modifico al empleado, o 1 si no se pudo
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* array del LinkedList
 * \return int devuelve 0 si se borro al empleado, o 1 si no se pudo
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados

 * \param pArrayListEmployee
 * \return int devuelve 0 si no pudo mostrar el empleado, 0 si pudo hacerlo
 *
 */
int controller_ListEmployees(LinkedList* pArrayListEmployee);

/** \brief Listar empleado
 *
 * \param Employee* x empleado a mostrar
 * \return int devuelve 0 si no pudo mostrar el empleado, 0 si pudo hacerlo
 *
 */
int controller_ListEmployee(Employee* x);

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve 0 si se logro ordenar, 0 1 si no se pudo
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* nombre del archivo en el que se guardan los datos
 * \param pArrayListEmployee LinkedList* array del LinkedList
 * \return int devuelve 0 si se pudo guardar, o 1 si no se pudo
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* nombre del archivo en el que se guardan los datos
 * \param pArrayListEmployee LinkedList* array del LinkedList
 * \return int devuelve 0 si se pudo guardar, o 1 si no se pudo
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief muestra el menu de modificar empleado
 *
 * \param opcion int* pasa por referencia la opcion elegida por el usuario
 * \return void
 *
 */
void menuModificar(int* option);

/** \brief compara los nombres entre dos empleados
 *
 * \param a void* elemento 1
 * \param b void* elemento 2
 * \return devuelve el orden del strcmp, si es 1 ordena alfabeticamente, si es 0 se mantiene igual y si es -1 ordena de la Z a la A
 *
 */
int compararNombre(void* a, void* b);

/** \brief vacia una lista
 *
 * \param lista a ser vaciada
 * \return devuelve 0 si pudo vaciarla, 1 si no pudo
 *
 */
int controller_emptyLinkedList(LinkedList* this);

/** \brief crea un back up de la lista
 *
 * \param lista a realizarle el back up
 * \return devuelve una nueva lista, la cual contiene los mismos elementos que la pasada por parametro
 *
 */
LinkedList* controller_backUpList(LinkedList* this);

/** \brief compara ambas listas para saber si son iguales o no
 *
 * \param lista 1
 * \param lista 2
 * \return devuelve 0 si son iguales, 1 si no lo son
 *
 */
int controller_compareLinkedList(LinkedList* this, LinkedList* this2);
