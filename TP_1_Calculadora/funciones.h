#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
/** \brief sumatoria de dos operandos.
 *
 * \param operando 1.
 * \param operando 2.
 * \param bandera operando 1.
 * \param bandera operando 2.
 * \return resultado de la suma validada.
 *
 */

float sumar (float,float,int,int);
/** \brief resta de dos operandos.
 *
 * \param operando 1.
 * \param operando 2.
 * \param bandera operando 1.
 * \param bandera operando 2.
 * \return resultado de la resta validado.
 *
 */

float restar (float,float,int,int);
/** \brief dividir oprendio 1, sobre operando 2.
 *
 * \param operando 1.
 * \param operando 2.
 * \param bandera operando 1.
 * \param bandera operando 2.
 * \return resultado de la divicion validado.
 *
 */

float dividir (float,float,int,int);
/** \brief
 *
 * \param operando 1.
 * \param operando 2.
 * \param bandera operando 1.
 * \param bandera operando 2.
 * \return resultado de la multiplicacion validado.
 *
 */

float multiplicar(float,float,int,int);
/** \brief obtener el factorial del operando 1.
 *
 * \param operando 1.
 * \param bandera operando 1.
 * \return factorial del operando 1.
 *
 */

long long int factorial(float,int);
/** \brief obtener y mostrar el factorial.
 *
 * \param operando 1.
 * \param bandera operando 1.
 * \return mostrar el resultado del factorial del operando ya validado.
 *
 */

long long int factorialMost(float,int);
/** \brief preguntar por un dato.
 *
 * \param pregunta.
 * \return dato ingresado.
 *
 */

float preguntar (char titulo[]);
/** \brief dar el menu de opciones.
 *
 * \param operando 1.
 * \param operando 2.
 * \param bandera operando 1.
 * \param bandera operando 2.
 * \return el menu de opciones actualizado.
 *
 */

int opciones (float,float,int,int);
/** \brief realizar todas las operaciones.
 *
 * \param operando 1.
 * \param operando 2.
 * \param bandera operando 1.
 * \param bandera operando 2.
 * \return las respuestas de todas las operaciones ya validados.
 *
 */

float todosCalculos (float,float,int,int);

#endif // FUNCIONES_H_INCLUDED
