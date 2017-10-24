#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <string.h>

int EspacioLibre(xPelicula* pelicula,int tam)
{
    int i;
    int flag=-1;
    for(i=0; i<tam; i++)
    {
        if((pelicula+i)->estado==-1)
        {
            flag=i;
            break;
        }
    }
    return flag;
}
void inicializarPeli(xPelicula* peli,int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        strcpy((peli+i)->titulo,"");
        strcpy((peli+i)->genero,"");
        (peli+i)->duracion=-1;
        strcpy((peli+i)->descripcion,"");
        (peli+i)->puntaje=-1;
        strcpy((peli+i)->linkImagen,"");
        (peli+i)->id=-1;
        (peli+i)->estado=-1;

    }
}
void generarDatos(xPelicula* pelicula,int tam)
{

    int i,j;


    for(i=0; i<tam; i++)
    {
        if((pelicula+i)->estado==-1)
        {

            printf("Ingrese el titulo de la pelicula: ");
            fflush(stdin);
            gets((pelicula+i)->titulo);

            while(strlen((pelicula+i)->titulo)>50)
            {
                printf("\nIngrese un titulo mas corto:\n");
                fflush(stdin);
                gets((pelicula+i)->titulo);
            }
            printf("Ingrese el genero de la peliluca: ");
            fflush(stdin);
            gets((pelicula+i)->genero);
            while(strlen((pelicula+i)->genero)>19)
            {
                printf("\nIngrese un Genero mas acotado:\n");
                fflush(stdin);
                gets((pelicula+i)->genero);
            }
            printf("Ingrese la duracion de la pelicula en minutos: ");
            scanf("%d",&(pelicula+i)->duracion);
            while((pelicula+i)->duracion>200||(pelicula+i)->duracion<30)
            {
                printf("\nIngrese una duracion coherente: ");
                scanf("%d",&(pelicula+i)->duracion);
            }
            printf("Ingrese la descripcion de la pelicula: ");
            fflush(stdin);
            gets((pelicula+i)->descripcion);
            while(strlen((pelicula+i)->descripcion)>49)
            {
                printf("\nIngrese una descripcion  mas corta:\n");
                fflush(stdin);
                gets((pelicula+i)->descripcion);
            }
            printf("Ingrese el puntaje de la pelicula(1-10): ");
            scanf("%d",&(pelicula+i)->puntaje);
            while((pelicula+i)->puntaje<1||(pelicula+i)->puntaje>10)
            {
                printf("Ingrese el puntaje de la pelicula entre 1 y 10: ");
                scanf("%d",&(pelicula+i)->puntaje);
            }
            printf("Ingrese el link de la pelicula: ");
            fflush(stdin);
            gets((pelicula+i)->linkImagen);

            while(strlen((pelicula+i)->linkImagen)>200)
            {
                printf("\nPor favor ingrese un link mas corto:\n");
                fflush(stdin);
                gets((pelicula+i)->linkImagen);
            }
            printf("Ingrese el Codigo de la pelicula(100-1000): ");
            scanf("%d",&(pelicula+i)->id);
            while((pelicula+i)->id<100||(pelicula+i)->id>1000)
            {
                printf("Ingrese el Codigo de la pelicula entre (100-1000): ");
                scanf("%d",&(pelicula+i)->id);
            }
            for(j=0; j<tam; j++)
            {
                if((pelicula+j)->estado!=-1)
                {

                    while((pelicula+i)->id==(pelicula+j)->id)
                    {
                        printf("\nEste Codigo ya fue registrado Por favor ingrese otro: ");
                        scanf("%d",&(pelicula+i)->id);
                    }
                }
            }

            (pelicula+i)->estado=1;

            printf("\n\t\tPELICULA INGRESADA\n\t\n");

            mostrarPeli((pelicula+i));

            break;
        }
    }
}
void mostrar(xPelicula* pelicula,int tam)
{
    int i;
    printf("\n\t\tPELICULAS REGISTRADAS\t\t\n");
    for(i=0; i<tam; i++)
    {
        if((pelicula+i)->estado!=-1)
        {
            printf("\n\nLink de imagen: %s\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nValoracion: %d\nCodigo Peli: %d\n\n",(pelicula+i)->linkImagen,(pelicula+i)->titulo,(pelicula+i)->genero,(pelicula+i)->duracion,(pelicula+i)->descripcion,(pelicula+i)->puntaje,(pelicula+i)->id);

        }
    }
}
void generarPelis(xPelicula* pelicula,int tam)
{

    int EL;

    EL=EspacioLibre(pelicula,tam);
    if(EL==-1)
    {
        printf("No hay mas espacio disponible \n");

    }

    else
    {
        generarDatos(pelicula,tam);

    }


}
void mostrarPeli(xPelicula* pelicula)
{
    printf("Link de imagen: %s\nTitulo: %s\nGenero: %s \nDuracion: %d \nDescripcion: %s\nValoracion: %d\nCodigo Peli: %d\n",(pelicula)->linkImagen,(pelicula)->titulo,(pelicula)->genero,(pelicula)->duracion,(pelicula)->descripcion,(pelicula)->puntaje,(pelicula)->id);

}
void borrarPeli(xPelicula* pelicula,int tam)
{
    int i;
    int flag=0;
    int aux;

    char respuesta='s';
    printf("\nPor favor ingrese el codigo de la pelicula: ");
    scanf("%d",&aux);
    for(i=0; i<tam; i++)
    {
        if(aux==(pelicula+i)->id)
        {
            if((pelicula+i)->estado!= -1)
            {
                flag=1;
                printf(" Desea eliminar esta pelicula?(s/n)\n %s \n",(pelicula+i)->titulo);
                fflush(stdin);
                respuesta=getch();
                while(respuesta!='s'&&respuesta!='n')
                {
                    printf("Debe responder (s/n)\n");
                    fflush(stdin);
                    respuesta=getch();
                }
                if(respuesta=='s')
                {
                    (pelicula+i)->estado= -1;

                    printf("Pelicula eliminada con exito\n");
                    system("pause");
                    system("cls");
                    break;
                }
                else
                {
                    printf("Accion cancelada por el usuario\n");
                    system("pause");
                    system("cls");
                    break;
                }
            }
        }


    }
    if(flag==0)
    {
        printf(" Pelicula inexistente\n");
        system("pause");
        system("cls");

    }

}
void modificarPeli(xPelicula* pelicula,int tam)
{
    int i;
    int flag=0;
    int aux;

    char respuesta='s';
    printf("\ningrese el codigo de la pelicula: ");
    scanf("%d",&aux);
    for(i=0; i<tam; i++)
    {
        if(aux==(pelicula+i)->id)
        {
            if((pelicula+i)->estado!= -1)
            {
                flag=1;
                printf(" Desea modificar esta pelicula?(s/n)\n %s \n",(pelicula+i)->titulo);
                fflush(stdin);
                respuesta=getch();
                while(respuesta!='s'&&respuesta!='n')
                {
                    printf("Por favor responda (s/n)\n");
                    fflush(stdin);
                    respuesta=getch();
                }
                if(respuesta=='s')
                {

                    if((pelicula+i)->estado!=-1)
                    {

                        printf("Ingrese el titulo de la pelicula: ");
                        fflush(stdin);
                        gets((pelicula+i)->titulo);

                        while(strlen((pelicula+i)->titulo)>50)
                        {
                            printf("\ningrese un titulo mas corto:\n");
                            fflush(stdin);
                            gets((pelicula+i)->titulo);
                        }
                        printf("Ingrese el genero de la peliluca: ");
                        fflush(stdin);
                        gets((pelicula+i)->genero);
                        while(strlen((pelicula+i)->genero)>19)
                        {
                            printf("\ningrese un Genero mas acotado:\n");
                            fflush(stdin);
                            gets((pelicula+i)->genero);

                        }
                        printf("Ingrese la duracion de la pelicula en minutos: ");
                        scanf("%d",&(pelicula+i)->duracion);
                        while((pelicula+i)->duracion>200||(pelicula+i)->duracion<30)
                        {
                            printf("\nIngrese una duracion coherente: ");
                            scanf("%d",&(pelicula+i)->duracion);
                        }
                        printf("Ingrese la descripcion de la pelicula: ");
                        fflush(stdin);
                        gets((pelicula+i)->descripcion);
                        while(strlen((pelicula+i)->descripcion)>49)
                        {
                            printf("\nPor favor ingrese una descripcion  mas corta:\n");
                            fflush(stdin);
                            gets((pelicula+i)->descripcion);

                        }
                        printf("Ingrese el puntaje de la pelicula(1-10): ");
                        scanf("%d",&(pelicula+i)->puntaje);
                        while((pelicula+i)->puntaje<1||(pelicula+i)->puntaje>10)
                        {
                            printf("Ingrese el puntaje de la pelicula entre 1 y 10: ");
                            scanf("%d",&(pelicula+i)->puntaje);
                        }
                        printf("Ingrese el link de la pelicula: ");
                        fflush(stdin);
                        gets((pelicula+i)->linkImagen);

                        while(strlen((pelicula+i)->linkImagen)>200)
                        {
                            printf("\nPor favor ingrese un link mas corto:\n");
                            fflush(stdin);
                            gets((pelicula+i)->linkImagen);

                        }


                        printf("Pelicula modificada con exito\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                }

            }

        }


    }
    if(flag==0)
    {
        printf(" Pelicula inexistente\n");
        system("pause");
        system("cls");

    }

}
void GenerarPagina(xPelicula* pelicula,int tam)
{

    int i;
    FILE* PELI;

    PELI=fopen("C:peliculas.html","w+");
    if(PELI==NULL)
    {
        printf("\nError al abrir el archivo\n");
        exit(1);
    }
    for(i=0; i<tam; i++)
    {
        if((pelicula+i)->estado!=-1)
        {

            fprintf(PELI,"<article class='col-md-4 article-intro'>\
                    <a href='#'>\
                    <img class='img-responsive img-rounded' src='%s'\
                    alt=''>\
                    </a>\
                    <h3>\
                    <a href='#'>%s</a>\
                    </h3>\
                    <ul>\
                    <li>Género:%s</li>\
                    <li>Puntaje:%d</li>\
                    <li>Duración:%d</li>\
                    </ul>\
                    <p>%s.</p>\
                    </article>",(pelicula+i)->linkImagen,(pelicula+i)->titulo,(pelicula+i)->genero,(pelicula+i)->puntaje,(pelicula+i)->duracion,(pelicula+i)->descripcion);


        }


    }
    printf("\nArchivo creado con exito!\n");

    fclose(PELI);

}
int cargarBinario(xPelicula* pelicula,int tam)
{
    int retorno=-1;
    FILE* pPelis;
    pPelis=fopen("bin.dat","rb");
    if(pPelis==NULL)
    {
        pPelis=fopen("bin.dat","wb");
        if(pPelis==NULL)
        {
            printf("No se pudo abrir el archivo");
            system("pause");
            return retorno;
        }
    }
    fread(pelicula,sizeof(xPelicula),tam,pPelis);
    retorno=0;
    fclose(pPelis);
    return retorno;
}
void guardarBinario(xPelicula* pelicula,int tam)
{
    FILE* pPelis;
    pPelis=fopen("bin.dat","wb");
    if(pPelis==NULL)
    {
        printf("Error al abrir el archivo binario\n");
        exit(1);
    }
    fwrite(pelicula,sizeof(xPelicula),tam,pPelis);
    printf("\nArchivo binario guardado con exito!\n");
    fclose(pPelis);
}
int ValidarId(xPelicula* pelicula,int tam,int aux)
{
    int i,flag=0;

    while(aux<100||aux>1000)
    {
        flag=2;

    }

    for(i=0; i<tam; i++)
    {
        if((pelicula+i)->estado!=-1)
        {

            while(aux==(pelicula+i)->id)
            {
                flag=1;
            }

        }


    }
    return flag;
}
