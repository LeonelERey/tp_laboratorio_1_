#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include <conio.h>
#define TAM 20

int menu (int);
int main()
{
    char seguir='s';
    int opcion=0;
    EPersona persona[TAM];
    inicializar(persona,TAM);

    while(seguir=='s')
    {
        //system("color F");
        opcion=menu(opcion);
        switch(opcion)
        {
        case 1:
            agregarPersona(persona,TAM);
            break;
        case 2:
            eliminarPersona(persona,TAM);
            break;
        case 3:
            rellenarArray(persona,TAM);
            break;
        case 4:
            listaPersonas(persona,TAM);
            break;
        case 5:
            grafico(persona,TAM);
            break;
        case 6:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
int menu (int opcion)
{
        system("color F");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Completar automaticamento el array\n");
        printf("4- Imprimir lista ordenada por  nombre\n");
        printf("5- Imprimir grafico de edades\n\n");
        printf("6- Salir\n");
        printf("opcion:");
        scanf("%d",&opcion);
        while(opcion<1||opcion>6)
        {
            system("color C");
            printf("ingrese una opcion valida:");
            scanf("%d",&opcion);
        }
        system("color F");
    return opcion;
}

