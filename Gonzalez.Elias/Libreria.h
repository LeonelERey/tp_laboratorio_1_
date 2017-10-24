
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int idCliente;
    int DNI;
    char nombre[20];
    char apellido[20];
    int estado;
} xCliente;
typedef struct
{
    int idCliente;
    char equipo[15];
    int tiempo;
    int tiempoReal;
    char operador[15];
    int estado;
    char estaAlquiler[20];
    int orden;

} xAlquiler;
/** \brief mostrar los cliente en memoria.
 *
 * \param array de estructura.
 * \param tamaño del array.
 *
 */

void mostarCliente(xCliente[],int);
/** \brief cargar el array de estructura.
 *
 * \param array de estructura.
 * \param tamaño del array.
 *
 */

void cargarCliente(xCliente[],int);
/** \brief cargar el array de estructura.
 *
 * \param array de estructura.
 * \param tamaño del array.
 *
 */

void caragarAlquileres(xAlquiler[],int);
/** \brief inicializar el estado del array de estructura.
 *
 * \param array de estructura.
 * \param tamaño del array.
 *
 */

void inicializarCliente(xCliente[],int);
/** \brief inicializar el estado del array de estructura.
 *
 * \param array de estructura.
 * \param tamaño del array.
 *
 */

void inicializarAlquiler(xAlquiler[],int);
/** \brief cargar un nuevo cliente.
 *
 * \param array de estructura.
 * \param tamaño del array.
 *
 */

void altaCliente(xCliente[],int);
//void mostarCliente(xCliente[],int);
//void mostarAlquiler(xAlquiler[],int);
/** \brief dar de alta un nuevo alquiler
 *
 * \param array de estructura.
 * \param tamaño del array.
 * \param array de estructura.
 * \param tamaño del array.
 *
 */

void nuevoAlquiler(xAlquiler[],xCliente[],int,int);
/** \brief mostar los clientes con sus respectivos alquileres.
 *
 * \param array de estructura.
 * \param tamaño del array.
 * \param array de estructura.
 * \param tamaño del array.
 *
 */

void clientesAlquileres(xCliente[],xAlquiler[],int,int);
/** \brief modificar un cliente.
 *
 * \param array de estructura.
 * \param tamaño del array.
 *
 */

void modificacion(xCliente[],int);
/** \brief dar de baja un cliente.
 *
 * \param array de estructura.
 * \param tamaño del array.
 *
 */

void darBaja (xCliente[],int);
/** \brief buscar una persona por dni.
 *
 * \param array de estructura.
 * \param tamaño del array.
 * \param dni a buscar.
 * \return si encontro o no el dni.
 *
 */

int buscarPorId(xCliente[],int,int);
/** \brief buscar una alquiler por orden.
 *
 * \param array de estructura.
 * \param tamaño del array.
 * \param orden a buscar.
 * \return si encontro o no la orden.
 *
 */

int buscarPorOrden(xAlquiler[],int,int);
/** \brief buscar un espacio libre.
 *
 * \param array de estructura.
 * \param tamaño del array.
 * \return la posicion en la cual no se puede ingresar algo.
 *
 */

int obtenerEspacioLibre(xCliente[],int);
/** \brief buscar un espacio libre.
 *
 * \param array de estructura.
 * \param tamaño del array.
 * \return la posicion en la cual no se puede ingresar algo.
 *
 */

int obtenerEspacioLibreAlqui(xAlquiler[],int);
/** \brief finalizar un alquiler.
 *
 * \param array de estructura.
 * \param tamaño del array.
 *
 */

void finDeAlquiler(xAlquiler[],int);
/** \brief mostrar el cliente con mas alquileres.
 *
 * \param array de estructura.
 * \param array de estructura.
 * \param tamaño del array.
 * \param tamaño del array.
 *
 */

void clienteMasCanci(xAlquiler[],xCliente[],int,int);
/** \brief mostrar el equipo mas alquilado.
 *
 * \param array de estructura.
 * \param tamaño del array.
 *
 */

void equipoMasVendido(xAlquiler[],xCliente[],int,int);
/** \brief promedio de horas real de los alquileres vendidos.
 *
 * \param array de estructura.
 * \param tamaño del array.
 *
 */

void promedioHoras(xAlquiler[],int);
/** \brief vacia los datos que esten ingresados en un cliente.
 *
 * \param array de estructura.
 * \param tamaño del array.
 *
 */

void vaciar(xCliente[],int);
