#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

void employee_delete(Employee* x)
{
    free(x);
    x = NULL;
}

Employee* employee_newParametrosStr(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salaryStr)
{
    Employee* newEmployee = NULL;
    newEmployee = employee_new();


        if(employee_SetId(newEmployee,atoi(idStr))
           && employee_setNombre(newEmployee, nombreStr)
           && employee_setHorasTrabajadas(newEmployee,atoi(horasTrabajadasStr))
           && employee_setSueldo(newEmployee,atoi(salaryStr)))
        {
            employee_delete(newEmployee);
        }
        else
        {
            employee_SetId(newEmployee,atoi(idStr));
            employee_setNombre(newEmployee, nombreStr);
            employee_setHorasTrabajadas(newEmployee,atoi(horasTrabajadasStr));
            employee_setSueldo(newEmployee,atoi(salaryStr));
        }

    return newEmployee;
}

Employee* employee_newParametros(int id,char* nombreStr,int horasTrabajadas, int salary)
{
    Employee* newEmployee = NULL;
    newEmployee = employee_new();


        if(employee_SetId(newEmployee,id)
           && employee_setNombre(newEmployee, nombreStr)
           && employee_setHorasTrabajadas(newEmployee,horasTrabajadas)
           && employee_setSueldo(newEmployee,salary))
        {
            employee_delete(newEmployee);
        }
        else
        {
            employee_SetId(newEmployee,id);
            employee_setNombre(newEmployee, nombreStr);
            employee_setHorasTrabajadas(newEmployee,horasTrabajadas);
            employee_setSueldo(newEmployee,salary);
        }

    return newEmployee;
}


int employee_SetId(Employee* x, int id)
{
    int todoOk = 1;

    if(x != NULL && id > 0)
    {
        x->id = id;
        todoOk = 0;
    }
    return todoOk;
}

int employee_getId(Employee* x,int* id)
{
    int todoOk = 1;

    if(x != NULL && id != NULL)
    {
        *id = x->id;
        todoOk = 0;
    }

    return todoOk;
}

int employee_setNombre(Employee* x, char* nombre)
{
    int todoOk = 1;

    if(x != NULL && nombre != NULL)
    {
        normalizeStr(nombre);
        strcpy(x->nombre,nombre);
        todoOk = 0;
    }

    return todoOk;
}



int employee_getNombre(Employee* x, char* nombre)
{
    int todoOk = 1;

    if(x != NULL && nombre !=NULL)
    {
        strcpy(nombre,x->nombre);
        todoOk = 0;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* x, int horasTrabajadas)
{
    int todoOk = 1;

    if(x != NULL && horasTrabajadas  > 0 && horasTrabajadas < 1000)
    {
        x->horasTrabajadas = horasTrabajadas;
        todoOk = 0;
    }

    return todoOk;
}

int employee_getHorasTrabajadas(Employee* x,int* horasTrabajadas)
{
    int todoOk = 1;

    if(x != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = x->horasTrabajadas;
        todoOk = 0;
    }

    return todoOk;
}

int employee_setSueldo(Employee* x, int sueldo)
{
    int todoOk = 1;

    if(x != NULL && sueldo > 8000 && sueldo < 200000)
    {
        x->sueldo = sueldo;
        todoOk = 0;
    }

    return todoOk;
}

int employee_getSueldo(Employee* x,int* sueldo)
{
    int todoOk = 1;

    if(x != NULL && sueldo != NULL)
    {
        *sueldo = x->sueldo;
        todoOk = 0;
    }

    return todoOk;
}


int getId(int* id)
{
    FILE* pFile = fopen("nextID.bin","rb");
    int todoOk = 1;
    *id = 1001;

    if(pFile != NULL)
    {
        fread(id,sizeof(int),1,pFile);
        todoOk = 0;
        fclose(pFile);
    }
    return todoOk;
}

int nextId(int id)
{
    FILE* pFile = fopen("nextID.bin", "wb");
    int todoOk = 1;

    id++;

    if(pFile != NULL)
    {
        fwrite(&id,sizeof(int),1,pFile);
        todoOk = 0;
        fclose(pFile);
    }

    return todoOk;
}



int employee_add(LinkedList* lista)
{
    int todoOk = 1;
    int id;
    char bufferName[128];
    int bufferHours;
    int bufferSalary;
    Employee* auxEmployee;

    getId(&id);

    if(!(utn_getCadena(bufferName,128,3,"Ingrese nombre: ","ERROR. Nombre invalido.\n")))
    {
        do
        {
            printf("Ingrese las horas trabajadas: ");
            scanf("%d",&bufferHours);

        }while(bufferHours < 0 || bufferHours > 600);
        do
        {
            printf("Ingrese el sueldo: ");
            scanf("%d",&bufferSalary);
        }while(bufferSalary < 8000 || bufferSalary > 150000);

        auxEmployee = employee_newParametros(id,bufferName,bufferHours,bufferSalary);
        if(auxEmployee!= NULL)
        {
            ll_add(lista,auxEmployee);
            nextId(id);
            todoOk = 0;
        }
    }

    return todoOk;
}

int findEmployeeById(LinkedList* this, int id)
{
    int indice = -1;
    int len = ll_len(this);
    int idAux;
    int flag = 1;
    Employee* empleado;

    for(int i = 0; i < len; i++)
    {
        empleado = (Employee*) ll_get(this,i);
        employee_getId(empleado,&idAux);
        if(idAux == id)
        {
            indice = ll_indexOf(this,empleado);
            flag = 0;
            break;
        }
    }

    if(flag == 1)
    {
        printf("No hay empleados ingresados con ese ID");
    }

    return indice;
}



int filtrarSueldo(void* unEmpleado)
{
    int returnAux = 0;
    int sueldo;
    Employee* x;
    if(unEmpleado != NULL)
    {
        x = (Employee*) unEmpleado;
        employee_getSueldo(x,&sueldo);
        if(sueldo >= 35000)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int reubicarEmpleado(LinkedList* this)
{
    int todoOk = 1;
    int indiceEmpleado;
    int indiceAUbicar;
    Employee* auxEmployee;

    system("cls");

    if(this != NULL)
    {
        if(!(utn_getEntero(&indiceEmpleado,3,"Ingrese el indice del empleado que desea mover de posicion: ","ERROR. Indice invalido.\n",0,ll_len(this))))
        {
            auxEmployee = (Employee*) ll_pop(this,indiceEmpleado);
            if(auxEmployee != NULL)
            {
                if(!(utn_getEntero(&indiceAUbicar,3,"Ingrese el indice donde desea ubicar al empleado: ","ERROR. Indice invalido.\n",0,ll_len(this))))
                {
                    todoOk = ll_push(this,indiceAUbicar,auxEmployee);
                }
            }
        }
    }

    return todoOk;
}
