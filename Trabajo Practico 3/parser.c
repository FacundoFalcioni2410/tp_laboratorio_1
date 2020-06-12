#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    char header[4][128];
    char buffer[4][128];
    int cant;
    Employee* newEmployee;
    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",header[0],header[1], header[2], header[3]);

        while(!(feof(pFile)))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",buffer[0],buffer[1], buffer[2], buffer[3]);

            if(cant == 4)
            {
                todoOk = 0;
                newEmployee = employee_newParametrosStr(buffer[0],buffer[1],buffer[2],buffer[3]);
                ll_add(pArrayListEmployee,newEmployee);
            }
            else
            {
                break;
            }
        }
    }
    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 1;
	Employee* Employee;

	if(pFile != NULL)
	{
		do
		{
			Employee = employee_new();
			if(fread(Employee, sizeof(Employee), 1, pFile))
			{
				ll_add(pArrayListEmployee, Employee);
				todoOk = 0;//exito
			}
		}while(!feof(pFile));
	}

    return todoOk;
}
