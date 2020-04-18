#include <stdio.h>
#include <stdlib.h>
#include "falcioni.h"

int main()
{
    int numero1;
    int numero2;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    int resultadoMultiplicacion;
    unsigned long long resultadoFactorialA;
    unsigned long long resultadoFactorialB;
    char respuesta='s';
    int operando1;
    int operando2;
    int operacionesRealizadas;

    operando1 = 0;
    operando2 = 0;
    operacionesRealizadas = 0;

    do
    {
        switch(menuOpciones(numero1, numero2,operando1,operando2))
        {
        case 1:
            numero1=ObtenerOperando(numero1);
            operando1=1;
            system("pause");
            break;
        case 2:
            numero2=ObtenerOperando(numero2);
            operando2=1;
            system("pause");
            break;
        case 3:
            if (operando1 && operando2)
            {
                resultadoSuma=sumar(numero1,numero2);
                resultadoResta=restar(numero1,numero2);
                resultadoDivision=dividir(numero1,numero2);
                resultadoMultiplicacion=multiplicar(numero1,numero2);
                resultadoFactorialA=factorial(numero1);
                resultadoFactorialB=factorial(numero2);
                operacionesRealizadas=1;
                printf("\n\nOperaciones realizadas!\n\n");
                system("pause");
            }
            else
            {
                printf("\n\nPrimero debe ingresar ambos operando\n\n");
                system("pause");
            }
            break;
        case 4:
            if (operacionesRealizadas)
            {
                printf("\na)El resultado de %d + %d es: %d",numero1, numero2, resultadoSuma);
                printf("\nb)El resultado de %d - %d es: %d",numero1,numero2, resultadoResta);
                if(numero2==0)
                {
                    printf("\nc)ERROR. NO SE PUEDE DIVIDIR POR 0");
                }
                else
                {
                    printf("\nc)El resultado de %d / %d es de: %.2f",numero1,numero2,resultadoDivision);
                }
                printf("\nd)El resultado de %d * %d es de: %d",numero1,numero2,resultadoMultiplicacion);
                printf("\ne)El resultado del factorial de %d es: %llu",numero1,resultadoFactorialA);
                printf(" y el resultado del factorial de %d es: %llu\n\n",numero2,resultadoFactorialB);
                system("pause");
                operando1=0;
                operando2=0;
                operacionesRealizadas=0;
            }
            else
            {
                printf("\n\nPrimero debe realizar las operaciones (opcion 3)\n\n");
                system("pause");
            }
            break;
        case 5:
            printf("\n\n¿Desea continuar? s/n\n\n");
            fflush(stdin);
            scanf("%c",&respuesta);
            break;
        }
    }
    while(respuesta == 's');
}
