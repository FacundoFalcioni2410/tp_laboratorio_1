#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 1;
	Employee* auxEmployee;
    Employee* newEmployee;
    int id;
    char nombre[128];
    int horas;
    int sueldo;
	if(pFile != NULL)
	{
		do
		{
			auxEmployee = employee_new();
			if(fread(auxEmployee, sizeof(Employee), 1, pFile))
			{
			    employee_getId(auxEmployee,&id);
			    employee_getNombre(auxEmployee,nombre);
			    employee_getSueldo(auxEmployee,&sueldo);
			    employee_getHorasTrabajadas(auxEmployee,&horas);
			    newEmployee = employee_newParametros(id,nombre,horas,sueldo);
				employee_delete(auxEmployee);
				ll_add(pArrayListEmployee,newEmployee);
				todoOk = 0;//exito
			}
		}while(!feof(pFile));
	}

    return todoOk;
}
