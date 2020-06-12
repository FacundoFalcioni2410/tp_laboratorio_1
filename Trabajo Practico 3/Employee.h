#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametrosStr(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salaryStr);
Employee* employee_newParametros(int id,char* nombreStr,int horasTrabajadas, int salary);


void employee_delete(Employee* x);
int employee_add(LinkedList* lista);

int employee_SetId(Employee* x, int id);
int employee_getId(Employee* x,int* id);

int employee_setNombre(Employee* x,char* nombre);
int employee_getNombre(Employee* x,char* nombre);

int employee_setHorasTrabajadas(Employee* x,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* x,int* horasTrabajadas);

int employee_setSueldo(Employee* x,int sueldo);
int employee_getSueldo(Employee* x,int* sueldo);

int findEmployeeById(LinkedList* this, int id);

#endif // employee_H_INCLUDED
