#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include <string.h>
#define ARCH /C:/Users/Leonel/Desktop/TP3/TP_3_Cascara/peliculas.html
#define TAM 10

int main()
{
    char seguir='s';
    int opcion=0;
    xPelicula movie[TAM];
    xPelicula* peli=&movie[0];
    inicializarPeli(peli,TAM);
    cargarBinario(peli,TAM);

    while(seguir=='s')
    {

        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Listar\n\n");
        printf("6- Salir\n");
        printf("opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            generarPelis(peli,TAM);
            guardarBinario(peli,TAM);
            system("pause");
            system("cls");

            break;
        case 2:
            borrarPeli(peli,TAM);
            guardarBinario(peli,TAM);
            system("pause");
            system("cls");
            break;
        case 3:
            modificarPeli(peli,TAM);
            guardarBinario(peli,TAM);
            system("pause");
            system("cls");
            break;
        case 4:
            GenerarPagina(peli,TAM);
            system("pause");
            system("cls");
            break;
        case 5:
            mostrar(peli,TAM);
            system("pause");
            system("cls");
            break;
        case 6:
            seguir = 'n';
            break;
        default:
            system("cls");
            printf("\nIngrese una opcion entre 1-6");
        }
    }
    return 0;
}


