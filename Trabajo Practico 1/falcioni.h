#ifndef FALCIONI_H_INCLUDED
#define FALCIONI_H_INCLUDED
/** \brief suma dos numeros
 *
 * \param a primer numero (sumando)
 * \param b segundo numero a sumar (sumando)
 * \return resultado de la suma entre a y b (total)
 *
 */

int sumar(int a, int b);

/** \brief resta dos numeros
 *
 * \param a primer numero (minuendo)
 * \param b segundo numero (sustraendo)
 * \return resultado de la resta de a y b (diferencia)
 *
 */

int restar(int a, int b);

/** \brief divide dos numeros
 *
 * \param a numero dividendo
 * \param b numero divisor
 * \return resultado entre la division de a y b (cociente)
 *
 */


float dividir(int a, int b);

/** \brief multiplica dos numeros
 *
 * \param a primer numero a multiplicar (factor)
 * \param b segundo numero a multiplicar (factor)
 * \return resultado de la multiplicacion de a y b (producto)
 *
 */


int multiplicar(int a, int b);

/** \brief calcula el factorial de un numero
 *
 * \param a numero ingresado para sacar el factorial
 * \return resultado del factorial del numero
 *
 */

unsigned long long factorial(int a);

/** \brief Muestra el menu de opciones, con los operandos cargados, y pide una opcion
 *
 * \param operando 1
 * \param operando 2
 * \return Devuelve la opcion que ingresa el usuario
 *
 */


int menuOpciones(int a, int b,int flag1, int flag2);

/** \brief obtiene el operando
 *
 * \param numero que va a recibir lo que el usuario ingrese
 * \return devuelve el operando
 *
 */

int ObtenerOperando(int a);
#endif // FALCIONI_H_INCLUDED
