#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lib.h"
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
    int i;

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
        printf("5- informar\n\n");
        printf("6- Salir\n");

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
            nuevoAlquiler(alquiler,TA);
            break;
        case 5:
            //mostarCliente(cliente,TAM);
            //mostarAlquiler(alquiler,TA);
            clientesAlquileres(cliente,alquiler,TAM,TA);
            break;
        case 6:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
