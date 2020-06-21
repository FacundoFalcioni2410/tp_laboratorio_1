/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* nombre del archivo del que se cargaran los datos
 * \param pArrayListEmployee LinkedList* array del LinkedList
 * \return int devuelve 1 si hay errores, 0 esta todo bien
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* nombre del archivo del que se cargaran los datos
 * \param pArrayListEmployee LinkedList* array del LinkedList
 * \return int devuelve 1 si hay errores, 0 esta todo bien
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
