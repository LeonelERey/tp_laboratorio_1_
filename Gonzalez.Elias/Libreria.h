
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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
void cargarCliente(xCliente[],int);
void caragarAlquileres(xAlquiler[],int);
void inicializarCliente(xCliente[],int);
void inicilizarAlquiler(xAlquiler[],int);
void altaCliente(xCliente[],int);
void mostarCliente(xCliente[],int);
void mostarAlquiler(xAlquiler[],int);
void nuevoAlquiler(xAlquiler[],xCliente[],int,int);
void clientesAlquileres(xCliente[],xAlquiler[],int,int);
void modificacion(xCliente[],int);
void darBaja (xCliente[],int);
int buscarPorId(xCliente[],int,int);
int buscarPorOrden(xAlquiler[],int,int);
int obtenerEspacioLibre(xCliente[],int);
int obtenerEspacioLibreAlqui(xAlquiler[],int);
void finDeAlquiler(xAlquiler[],int);
void clienteMasCanci(xAlquiler[],xCliente[],int,int);
void equipoMasVendido(xAlquiler[],int);
