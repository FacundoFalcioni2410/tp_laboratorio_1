#include <stdio.h>
#include <stdlib.h>

int sumar(int a, int b)
{
    float resultadoSuma;

    resultadoSuma=a+b;

    return resultadoSuma;
}

int restar(int a, int b)
{
    float resultadoResta;

    resultadoResta=a-b;

    return resultadoResta;
}

float dividir(int a, int b)
{
    float resultadoDivision;

    resultadoDivision=(float)a/b;

    return resultadoDivision;
}

int multiplicar(int a, int b)
{
    int resultadoMultiplicacion;

    resultadoMultiplicacion=a*b;

    return resultadoMultiplicacion;
}

unsigned long long factorial(int a)
{
    unsigned long long resultado;

    resultado = 0;

    if(a >=0)
    {
        if(a == 1 || a == 0)
        {
            resultado = 1;
        }
        else
        {
            resultado = a * factorial(a -1);
        }
    }

    return resultado;
}

int menuOpciones(int a, int b, int flag1, int flag2)
{
    int opcion;

    system("cls");
    printf("-------------------TRABAJO PRACTICO-------------------------\n\n");
    if(flag1)
    {
        printf("1) Ingrese el primer operando (A = %d)\n",a);
    }
    else
    {
        printf("1) Ingrese el primer operando (A = X)\n");
    }
    if (flag2)
    {
        printf("2) Ingrese el segundo operando (B = %d)\n",b);
    }
    else
    {
        printf("2) Ingrese el segundo operando (B = Y)\n");
    }
    printf("3) Realizar las siguientes operaciones:\n\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\nd) Calcular la multiplicacion (A*B)\ne) Calcular el factorial (A! y B!)\n");
    printf("4) Mostrar resultados\n");
    printf("5) Salir\n\n");
    printf("Indique una opcion del 1 al 5: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int ObtenerOperando(int a)
{
    int operando;

    printf("\n\nIngrese el operando: ");
    scanf("%d",&operando);

    return operando;
}
