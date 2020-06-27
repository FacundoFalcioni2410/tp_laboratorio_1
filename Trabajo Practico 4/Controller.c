#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Employee.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        if(!(parser_EmployeeFromText(pFile,pArrayListEmployee)))
        {
            todoOk = 0;
            printf("\nDatos cargados con exito!\n");
        }
    }
    else
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    fclose(pFile);

    return todoOk;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    FILE* pFile = fopen(path,"rb");

    if(pFile != NULL)
    {
        if(parser_EmployeeFromBinary(pFile,pArrayListEmployee) == 0)
        {
            printf("\nDatos cargados con exito\n");
            todoOk = 0;
        }
    }
    else
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    fclose(pFile);

    return todoOk;
}

int controller_ListEmployee(Employee* x)
{
    int todoOk;
    int id;
    char nombre[128];
    int horas;
    int sueldo;

    if(x != NULL)
    {
        employee_getId(x,&id);
        employee_getNombre(x,nombre);
        employee_getHorasTrabajadas(x,&horas);
        employee_getSueldo(x,&sueldo);
        printf("%4d   %10s      %4d           %6d\n",id,nombre,horas,sueldo);
        todoOk = 0;
    }
    return todoOk;
}


int controller_ListEmployees(LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    int len = ll_len(pArrayListEmployee);

    Employee* auxEmployee;
    system("cls");
    printf("  ID        NOMBRE   HORAS TRABAJADAS SUELDO\n\n");

    for(int i = 0; i < len; i++)
    {
        auxEmployee = (Employee*) ll_get(pArrayListEmployee,i);
        if(auxEmployee != NULL)
        {
            controller_ListEmployee(auxEmployee);
            todoOk = 0;
        }
    }
    if(todoOk == 1)
    {
        printf("No hay empleados para mostrar\n");
    }
    return todoOk;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk;

    if(employee_add(pArrayListEmployee))
    {
        todoOk = 0;
    }
    return todoOk;
}

void menuModificar(int* option)
{
   printf("Que desea modificar?: ");
   printf("\n1. Nombre\n");
   printf("2. Horas trabajadas\n");
   printf("3. Sueldo\n");
   printf("Eliga una opcion: ");
   fflush(stdin);
   scanf("%d",option);
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    int id;
    int index;
    int option;
    char nombre[128];
    int horas;
    int sueldo;
    char confirm = 'n';
    Employee* auxEmployee;

    system("cls");
    utn_getEntero(&id,3,"Ingrese el ID del empleado que desea modificar: ","ERROR. ID invalido\n",1,1500);
    index = findEmployeeById(pArrayListEmployee,id);
    if(index == -1)
    {
        printf("\nNo hay empleados ingresados con ese ID\n");
    }
    else
    {
        printf("%4d   %10s      %4d           %6d\n",id,nombre,horas,sueldo);
        auxEmployee = (Employee*) ll_get(pArrayListEmployee,index);
        controller_ListEmployee(auxEmployee);
        printf("\nDesea modificar a este empleado?: ");
        fflush(stdin);
        scanf("%c",&confirm);
        if(confirm != 'n')
        {
            menuModificar(&option);
            switch(option)
            {
            case 1:
                fflush(stdin);
                utn_getCadena(nombre,128,3,"Ingrese nombre: ","ERROR. Nombre invalido\n");
                employee_setNombre(auxEmployee,nombre);
                break;
            case 2:
                do
                {
                    printf("Ingrese las horas trabajadas: ");
                    fflush(stdin);
                    scanf("%d",&horas);
                }while(horas < 0);
                employee_setHorasTrabajadas(auxEmployee,horas);
                break;
            case 3:
                do
                {
                    printf("Ingrese el sueldo: ");
                    fflush(stdin);
                    scanf("%d",&sueldo);
                }while(sueldo < 0);
                employee_setSueldo(auxEmployee,sueldo);
                break;
                todoOk = 0;
                ll_set(pArrayListEmployee,index,auxEmployee);
            }
        }
    }
    return todoOk;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    int id;
    int index;
    char confirm = 'n';
    Employee* auxEmployee;

    system("cls");
    utn_getEntero(&id,3,"Ingrese el ID del empleado que desea eliminar: ","ERROR. ID invalido\n",1,1500);
    index = findEmployeeById(pArrayListEmployee,id);

    if(index == -1)
    {
        printf("\nNo hay empleados ingresados con ese ID\n");
    }
    else
    {
        printf("\n  ID        NOMBRE   HORAS TRABAJADAS SUELDO\n\n");
        auxEmployee = (Employee*) ll_get(pArrayListEmployee,index);
        controller_ListEmployee(auxEmployee);
        printf("\nDesea eliminar a este empleado?: ");
        fflush(stdin);
        scanf("%c",&confirm);
        if(confirm != 'n')
        {
            ll_remove(pArrayListEmployee,index);
            todoOk = 0;
        }
    }

    return todoOk;
}

int compararNombre(void* a, void* b)
{
    int retorno;
    Employee* empleado1;
    Employee* empleado2;

    if(a != NULL && b != NULL)
    {
        empleado1 = (Employee*) a;
        empleado2 = (Employee*) b;

        retorno = strcmp(empleado1->nombre,empleado2->nombre);
    }

    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    printf("\nEspere unos segundos por favor...\n");
    ll_sort(pArrayListEmployee,compararNombre,1);
    todoOk = 0;
    return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path,"w");
    int len = ll_len(pArrayListEmployee);
    Employee* auxEmployee;
    int id;
    char nombre[128];
    int horas;
    int sueldo;

    fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");

    for(int i = 0; i < len; i++)
    {
        auxEmployee = ll_get(pArrayListEmployee, i);

        employee_getId(auxEmployee,&id);
        employee_getNombre(auxEmployee,nombre);
        employee_getHorasTrabajadas(auxEmployee,&horas);
        employee_getSueldo(auxEmployee,&sueldo);

        fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horas,sueldo);
    }

    fclose(pFile);

    return 1;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    FILE* pFile = fopen(path,"wb");
    int len = ll_len(pArrayListEmployee);
    Employee* auxEmployee;

    for(int i = 0; i < len; i++)
    {
        auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
        if(auxEmployee != NULL)
        {
            fwrite(auxEmployee,sizeof(Employee),1,pFile);
            todoOk = 0;
        }
    }

    if(!todoOk)
    {
        printf("\nDatos guardados correctamente\n");
    }

    fclose(pFile);
    return todoOk;
}

int controller_emptyLinkedList(LinkedList* this)
{
    int todoOk = 1;

    if(this != NULL)
    {
        ll_clear(this);
        todoOk = 0;
    }

    return todoOk;
}

LinkedList* controller_backUpList(LinkedList* this)
{
    LinkedList* newList;

    if(this != NULL)
    {
        newList = ll_clone(this);
    }

    return newList;
}

int controller_compareLinkedList(LinkedList* this, LinkedList* this2)
{
    int todoOk = 1;

    if(this != NULL && this2 != NULL)
    {
        if(ll_containsAll(this2,this))
        {
            todoOk = 0;
        }

    }
    return todoOk;
}
