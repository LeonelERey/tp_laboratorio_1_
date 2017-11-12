#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int Arch;
    ArrayList* lista;
    EClub* auxi;
    lista = al_newArrayList();
    cargarBinario(auxi,lista);
    FILE* archivo=fopen("club.csv","r");

    while(seguir=='s')
    {
        printf("1- Cargar Equipos\n");
        printf("2- Agregar Equipo\n");
        printf("3- Listar clubes\n");
        printf("4- Modificar datos del club\n");
        printf("5- Descender club\n");
        printf("6- Eliminar todos los equipos\n");
        printf("7- Ordenar por posicion\n");
        printf("8- Ingresar un equipo en la posicion especificada\n\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            Arch=LeerEquipos(archivo,lista);
            if(Arch==-1)
            {
                printf(" Error al abrir el archivo\n");
            }
            else
            {
                printf(" Archivo cargado con exito\n");
            }
            break;
        case 2:
            agregarEquipo(lista,auxi);
            break;
        case 3:
            if(lista->isEmpty(lista))
            {
                printf("No se han cargado equipos\n");
            }
            else
            {
                mostrarEquipo(lista,auxi);
            }
            break;
        case 4:
            ModifocarEquipo(lista,auxi);
            break;
        case 5:
            EliminarEquipo(lista,auxi);
            break;
        case 6:
            lista->clear(lista);
            if(lista->clear(lista)==0)
            {
                printf("Todos los equipos fueron eliminados");
            }
            break;
        case 7:
            lista->sort(lista,comparaPersonas,1);
            mostrarEquipo(lista,auxi);
            break;
        case 8:
            PosicionEspecificada(lista,auxi);
            break;
        case 9:
            seguir = 'n';
            //fclose(archivo);
            break;
        default:
            printf("Ingreso una opcion incorrecta! \n");
            break;
        }
    }


    return 0;
}
