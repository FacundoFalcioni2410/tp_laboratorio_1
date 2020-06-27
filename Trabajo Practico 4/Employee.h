#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief reserva un espacio en memoria para un nuevo empleado
 *
 * \return devuelve un puntero de empleado al espacio de memoria creado
 *
 */
Employee* employee_new();

/** \brief crea un empleado y llama a distintas funciones para asignarle los campos al empleado
 *
 * \param idStr char* id
 * \param nombreStr char* nombre
 * \param horasTrabajadasStr char* horas trabajadas
 * \param salaryStr* sueldo
 * \return devuelve puntero al empleado creado y con los datos cargados
 *
 */
Employee* employee_newParametrosStr(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salaryStr);

/** \brief crea un empleado y llama a distintas funciones para asignarle los campos al empleado
 *
 * \param id int
 * \param nombreStr char* nombre
 * \param horasTrabajadas int horas trabajadas
 * \param salary int sueldo
 * \return devuelve puntero al empleado creado y con los datos cargados
 *
 */
Employee* employee_newParametros(int id,char* nombreStr,int horasTrabajadas, int salary);

/** \brief elimina un empleado de memoria
 *
 * \param x Employee* empleado a eliminar
 * \return void
 *
 */

void employee_delete(Employee* x);

/** \brief se encarga de realizar el alta del empleado
 *
 * \param lista LinkedList* array del LinkedList
 * \return devuelve 0 si se pudo dar de alta el empleado, en caso contrario devuelve 1
 *
 */
int employee_add(LinkedList* lista);

/** \brief se encarga de cargar el id en el empleado
 *
 * \param x Employee* empleado en el que se procedera a cargar el dato
 * \param id int id que se le va a cargar al empleado
 * \return retorna 0 si se pudo cargar, 1 si no se pudo
 *
 */
int employee_SetId(Employee* x, int id);

/** \brief obtiene el id de empleado en concreto
 *
 * \param x Employee* empleado en el que se encuentra el dato a obtener
 * \param id int* lugar donde se va a cargar el dato a obtener
 * \return retorna 0 si se pudo obtener el dato, 1 si no se pudo
 *
 */
int employee_getId(Employee* x,int* id);

/** \brief se encarga de cargar el nombre en el empleado
 *
 * \param x Employee* empleado en el que se procedera a cargar el dato
 * \param nombre char* nombre que se le va a cargar al empleado
 * \return retorna 0 si se pudo cargar, 1 si no se pudo
 *
 */
int employee_setNombre(Employee* x,char* nombre);

/** \brief obtiene el nombre de un empleado en concreto
 *
 * \param x Employee* empleado en el que se encuentra el dato a obtener
 * \param nombre char* lugar donde se va a cargar el dato a obtener
 * \return retorna 0 si se pudo obtener el dato, 1 si no se pudo
 *
 */
int employee_getNombre(Employee* x,char* nombre);

/** \brief se encarga de cargar las horas trabajadas en el empleado
 *
 * \param x Employee* empleado en el que se procedera a cargar el dato
 * \param horasTrabajadas int horas trabajadas que se le va a cargar al empleado
 * \return retorna 0 si se pudo cargar, 1 si no se pudo
 *
 */
int employee_setHorasTrabajadas(Employee* x,int horasTrabajadas);

/** \brief obtiene las horas trabajadas de un empleado en concreto
 *
 * \param x Employee* empleado en el que se encuentra el dato a obtener
 * \param horasTrabajadas int* lugar donde se va a cargar el dato a obtener
 * \return retorna 0 si se pudo obtener el dato, 1 si no se pudo
 *
 */
int employee_getHorasTrabajadas(Employee* x,int* horasTrabajadas);

/** \brief se encarga de cargar el sueldo en el empleado
 *
 * \param x Employee* empleado en el que se procedera a cargar el dato
 * \param sueldo int sueldo que se le va a cargar al empleado
 * \return retorna 0 si se pudo cargar, 1 si no se pudo
 *
 */
int employee_setSueldo(Employee* x,int sueldo);

/** \brief obtiene el sueldo de un empleado en concreto
 *
 * \param x Employee* empleado en el que se encuentra el dato a obtener
 * \param sueldo int* lugar donde se va a cargar el dato a obtener
 * \return retorna 0 si se pudo obtener el dato, 1 si no se pudo
 *
 */
int employee_getSueldo(Employee* x,int* sueldo);

/** \brief busca un empleado por su id
 *
 * \param lista donde se encuentra el empleado
 * \param id del empleado que se quiere buscar
 * \return devuelve 0 si pudo encontrarlo, 1 si no pudo
 *
 */

int findEmployeeById(LinkedList* this, int id);

/** \brief verifica si los empleados tienen mas de 35000 de sueldo
 *
 * \param elemento de una estructura
 * \return devuelve 1 si cumple la condicion, 0 si no la cumple
 *
 */
int filtrarSueldo(void* unEmpleado);

/** \brief obtiene el id a utilizar por la funcion add que se encuentra guardado en un archivo binario
 *
 * \param puntero donde se va a guardar el id del archivo
 * \return devuelve 0 si pudo obtenerlo, 1 si no pudo
 *
 */
int getId(int* id);

/** \brief guarda el proximo id a utilizarse en un archivo binario
 *
 * \param id a guardar
 * \return retorna 0 si pudo guardarlo, 1 si no pudo
 *
 */
int nextId(int id);

/** \brief reubica un empleado de la lista en otra posicion deseada por el usuario
 *
 * \param lista de empleados
 * \return devuelve 0 si reubico al empleado con exito, 1 si no lo pudo realizar
 *
 */

int reubicarEmpleado(LinkedList* this);

#endif // employee_H_INCLUDED
