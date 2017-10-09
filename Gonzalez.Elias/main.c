#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Libreria.h"
#define TAM 10
#define TA 20
#define Equipo (AMOLADORA-MEZCLADORA-TALADRO)
#define Estado (ALQUILADO-FINALIZADO)
int main()
{
    xCliente cliente[TAM];
    xAlquiler alquiler[TA];
    char seguir='s';
    int opcion;

    inicializarCliente(cliente,TAM);
    inicializarAlquiler(alquiler,TA);
    cargarCliente(cliente,5);
    caragarAlquileres(alquiler,10);
    while(seguir=='s')
    {
        printf("1- Alta cliente\n");
        printf("2- Modificar clinte\n");
        printf("3- Baja del cliente\n");
        printf("4- nuevo alquiler\n");
        printf("5- Finalizar alquiler\n");
        printf("6- informar\n\n");
        printf("7- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaCliente(cliente,TAM);
            break;
        case 2:
            modificacion(cliente,TAM);
            break;
        case 3:
            darBaja(cliente,TAM);
            break;
        case 4:
            nuevoAlquiler(alquiler,cliente,TA,TAM);
            break;
        case 5:
            finDeAlquiler(alquiler,TA);
            break;
        case 6:
            clientesAlquileres(cliente,alquiler,TAM,TA);
            clienteMasCanci(alquiler,cliente,TAM,TA);
            equipoMasVendido(alquiler,TA);
            break;
        case 7:
            seguir = 'n';
            break;
        default:
            printf("ingres una opcion entre 1 y 7:");
            scanf("%d",&opcion);
        }
    }

    return 0;
}
