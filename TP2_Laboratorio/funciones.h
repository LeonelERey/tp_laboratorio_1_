#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * \param estructura.
 * \param array de la estructura.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona[],int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * \param estructura.
 * \param array de la estructura.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona[],int,int);
/** \brief iniciar toda la estrutura en 0.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return toda la estructura inicializada.
 *
 */
void inicializar (EPersona[],int);
/** \brief mostrar los datos de una persona.
 *
 * \param la estructura con la posicion de array.
 * \return un texto con los datos de la persona.
 *
 */
void mostrar (EPersona);
/** \brief mostar un listado, con los datos de todas las personas registraas.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return mostrar una por una las personas ingresadas.
 *
 */
void mostrarTodos(EPersona[],int);
/** \brief realizar las preguntas correspondientes para registrar los datos.
 *
 * \param estructura.
 * \param el array de la estructura.
 * \return los datos ingresados por el usuario.
 *
 */
void agregarPersona(EPersona[],int);
/** \brief realizar la eliminacion de una persona reguistrada.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return la persona dada de baja.
 *
 */
void eliminarPersona(EPersona[],int);

void rellenarArray(EPersona[],int);
/** \brief ordenar las personas ingresadas alfabeticamente
  *
  * \param estructura.
  * \param array de la estructura.
  * \return las personas ordenadas alfabeticamente.
  *
  */
void listaPersonas(EPersona[],int);
/** \brief mostar las cntidada de personar con cierta edad.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return un grafico marcando con '*' la cantidad de personas.
 *
 */
void grafico(EPersona[],int);
/** \brief contar la cantdad de personas, verificando q esta exista.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return la cantidad de personas ya verificado.
 *
 */
int cont18(EPersona[],int);
/** \brief contar la cantdad de personas, verificando q esta exista.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return la cantidad de personas ya verificado.
 *
 */
int cont19a35(EPersona[],int);
/** \brief contar la cantdad de personas, verificando q esta exista.
 *
 * \param estructura.
 * \param array de la estructura.
 * \return la cantidad de personas ya verificado.
 *
 */
int cont35(EPersona[],int);

#endif // FUNCIONES_H_INCLUDED

