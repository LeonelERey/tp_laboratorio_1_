
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Funciones.h"

EClub* newClub()
{
    EClub* aux;
    aux = (EClub*) malloc (sizeof(EClub));
    return aux;
}
EClub* newClubParametros( char nombre[],int posicion,int seguidores,char apodo[])
{
    EClub* Club;
    ArrayList* lista;

    Club = newClub();
    if(Club!=NULL)
    {
        strcpy(Club->nombre,nombre);
        Club->posicion=posicion;
        Club->seguidores=seguidores;
        strcpy(Club->apodo,apodo);
    }
    return Club;
}
int cargarBinario( EClub* Club,ArrayList* lista)
{
    int retorno=-1;
    FILE* bin;
    bin=fopen("Club.dat","rb");
    if(bin==NULL)
     {
             printf("No se pudo abrir el archivo");
             system("pause");
             return retorno;
     }
    fread(Club,sizeof(EClub),al_len(lista),bin);
    retorno=0;
    fclose(bin);
    return retorno;
}
void generarBinario(ArrayList* lista,  EClub* aux)
{
    int i;
    FILE* bin;
    bin = fopen("Club.dat","wb");

    if(bin != NULL)
    {
        for(i=0; i<al_len(lista); i++)
        {
            aux = newClub();
            aux = al_get(lista,i);
            fwrite(aux, sizeof(EClub),al_len(lista),bin);
        }
        printf("Archivo generado correctamente!\n");
    }
    else
    {
        printf("Ha ocurrido un error!\n");
    }
    fclose(bin);
}
void guardarBinario(EClub* club,ArrayList* lista)
{

}

void agregarEquipo(ArrayList* lista,EClub* club)
{
    char nombre[50],apodo[50];
    int posicion,seguidores;

    printf("ingrese el nombre del Club\n ");
    fflush(stdin);
    gets(nombre);
    printf("ingrese el apodo del Club\n ");
    fflush(stdin);
    gets(apodo);
    printf("ingrese la cantidad de seguidores\n");
    scanf("%d",&seguidores);
    printf("ingrese la posicion de su equipo \n");
    scanf("%d",&posicion);
    club=newClubParametros(nombre,posicion,seguidores,apodo);
    if(club!=NULL)
    {
        lista->add(lista,club);
        generarBinario(lista,club);
    }
}
void mostrarEquipo(ArrayList* lista,EClub* club)
{
    int i;
    printf("Tabla de posiciones \n");
    printf("Equipos\t\t Apodo\t Posicion\t\tSeguidores\n");
    for(i=0; i<lista->len(lista); i++)
    {
        club=(EClub*)lista->get(lista,i);
        if(club!=NULL)
        {
            printf("\n %s\t\t %20s\t %d\t\%d\n",club->nombre,club->apodo,club->posicion,club->seguidores);
        }
        else
        {
            printf("\nNo hay equipos ingresados");
        }
    }
}
void EliminarEquipo(ArrayList* lista, EClub* club)
{
    club=newClub();

    char respuesta;
    int i,posicion;
    int auxI=-1;

    printf("\nIngrese la posicion del equipo que desea eliminar\n");
    scanf("%d",&posicion);

    for(i=0; i<lista->len(lista); i++)
    {
        club=(EClub*)lista->get(lista,i);
        if(club->posicion==posicion)
        {
            auxI=i;
            break;
        }
    }
    if(lista->contains(lista,&*(club+auxI))!=1)
    {
        printf("\nClub inexistente\n");
    }
    else
    {
        club=(EClub*)lista->get(lista,auxI);
        printf("\n %s\t %s\t %d\t %d\n",club->nombre,club->apodo,club->posicion,club->seguidores);

        printf("\nDesea eliminar este Club??(s/n)\n");
        fflush(stdin);
        scanf("%c",&respuesta);
        if(respuesta=='s')
        {
            lista->remove(lista,auxI);
            printf("Club eliminado");
            generarBinario(lista,club);

        }
        else
        {
            printf("\nEliminacion cancelada\n");
        }
    }
}

void ModifocarEquipo(ArrayList* lista, EClub* club)
{
    club=newClub();

    char respuesta;
    int i,posicion;
    int auxI=-1;

    printf("\nIngrese la posicion del equipo que desea Modificar\n");
    scanf("%d",&posicion);

    for(i=0; i<lista->len(lista); i++)
    {
        club=(EClub*)lista->get(lista,i);
        if(club->posicion==posicion)
        {
            auxI=i;
            break;
        }
    }
    if(auxI==-1)
    {
        printf("\nClub inexistente\n");
    }
    else
    {
        //club=(EClub*)lista->get(lista,auxI);
        printf("\n %s\t %s\t %d\t %d\n",(club+auxI)->nombre,(club+auxI)->apodo,(club+auxI)->posicion,(club+auxI)->seguidores);
        printf("\nDesea modificar este Club??(s/n)\n");
        fflush(stdin);
        scanf("%c",&respuesta);
        if(respuesta=='s')
        {
            printf("ingrese el nombre del Club\n ");
            fflush(stdin);
            gets(club->nombre);
            printf("ingrese el apodo del Club\n ");
            fflush(stdin);
            gets(club->apodo);
            printf("Ingrese la cantidad de seguidores\n");
            scanf("%d",&club->seguidores);
            printf("ingrese la posicion de su equipo \n");
            scanf("%d",&club->posicion);
            club=(EClub*)lista->set(lista,auxI,club);
            generarBinario(lista,club);

        }
        else
        {
            printf("\nModificacion cancelada cancelada\n");
        }
    }
}
void PosicionEspecificada(ArrayList* lista, EClub* club)
{
    int i;
    int auxi,posicion;

    printf("ingrese el nombre del Club\n ");
    fflush(stdin);
    gets(club->nombre);
    printf("ingrese el apodo del Club\n ");
    fflush(stdin);
    gets(club->apodo);
    printf("ingrese la cantidad de seguidores\n");
    scanf("%d",&club->seguidores);
    printf("ingrese la posicion donde quiere ubicar su club");
    scanf("%d",&posicion);
    //club->posicion=posicion;
    for(i=0; i<lista->len(lista); i++)
    {
        club=(EClub*)lista->get(lista,i);
        if(club->posicion==posicion)
        {
            auxi=i;
            break;
        }
    }
    printf("\ni=%d\n",auxi);
    lista->set(lista,auxi,club);
    lista->push(lista,auxi,club);
    if(lista->push(lista,auxi,club)==0)
    {
        printf("\nSu club fue insertado correctamente");
    }
    else
    {
        printf("\n No se ha podido añadir este nuevo equipo");
    }
}
/*int ordenarPosicion(ArrayList* lista,EClub* club)
{
    int i,j;
    int ret=0;
    EClub* equipo;
    for(i=0; i<lista->len(lista)-1; i++)
    {
        club=(EClub*)lista->get(lista,i);
        if(j=i+1;j<lista->len(lista);j++)
        {
             equipo=(EClub*)lista->get(lista,j);

             if(club->posicion>equipo->posicion)
             {
                 ret=1;
             }
        }
    }
    return ret;

}*/
int comparaPersonas(void* club,void* Equipo)
{

    if(((EClub*)club)->posicion > ((EClub*)Equipo)->posicion)
    {
        return 1;
    }
    if(((EClub*)club)->posicion < ((EClub*)Equipo)->posicion)
    {
        return -1;
    }
    return 0;
}
//*******************************************************
int LeerEquipos( FILE* Archivo,ArrayList* lista)
{
    char  posicion[500],nombre[500], apodo[500],seguidores[500];
    EClub* Equipo;
    if(Archivo==NULL||lista==NULL)
    {
        return -1;
    }

    fscanf(Archivo, "%[^,],%[^,],%[^,],%[^\n]\n",nombre,apodo,seguidores,posicion);

    while(!feof(Archivo))
    {
        fscanf(Archivo, "%[^,],%[^,],%[^,],%[^\n]\n",nombre,apodo,seguidores,posicion);
        Equipo=newClub();

        if(Equipo!=NULL)

        {

            Equipo->posicion=atoi(posicion);
            strcpy(Equipo->nombre,nombre);
            strcpy(Equipo->apodo,apodo);
            Equipo->seguidores=atoi(seguidores);

            al_add(lista,Equipo);


        }


    }

    return 0;

}






