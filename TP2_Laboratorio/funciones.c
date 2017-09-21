#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

void inicializar (EPersona persona[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        persona[i].estado=0;
    }
}
int obtenerEspacioLibre(EPersona persona[],int tam)
{
    int i;
    int retorno;
    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==0)
        {
            retorno=i;
            return retorno;
        }
    }
    return -1;
}
int buscarPorDni(EPersona persona[],int tam,int dni)
{
    int i;
    int retorno;
    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==1&&persona[i].dni==dni)
        {
                    retorno=i;
                    return retorno;
        }
    }
    return -1;
}
void mostrar (EPersona persona)
{
    printf("%18s\t%8d\t%3d\n",persona.nombre,persona.dni,persona.edad);
}
void mostrarTodos(EPersona persona[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==1)
        {
            mostrar(persona[i]);
        }
    }
}
void agregarPersona(EPersona persona[],int tam)
{
    int i;
    int j;
    int espacio;
    espacio=obtenerEspacioLibre(persona,tam);
    if(espacio!=-1)
    {
        for(i=0; i<tam; i++)
        {
            if(persona[i].estado==0)
            {
                printf("ingrese el nombre de la persona:");
                fflush(stdin),
                gets(persona[i].nombre);
                printf("ingrese el numero de documento:");
                scanf("%d",&persona[i].dni);
                for(j=0; j<tam; j++)
                {
                    if(persona[j].estado==1)
                    {
                        while(persona[i].dni==persona[j].dni)
                        {
                            system("color C");
                            printf("el numero de documento y existe!!\n reingrese:");
                            scanf("%d",&persona[i].dni);
                        }
                    }
                }
                while(persona[i].dni<10000000||persona[i].dni>99999999)
                {
                    system("color C");
                    printf("reingrese el numero de documento con 8 caracteres:");
                    scanf("%d",&persona[i].dni);
                }
                system("color F");
                printf("ingrese la edad de la persona:");
                scanf("%d",&persona[i].edad);
                while(persona[i].edad<1||persona[i].edad>102)
                {
                    system("color C");
                    printf("reingrese una edad coherente:");
                    scanf("%d",&persona[i].edad);
                }
                system("color F");
                persona[i].estado=1;
                printf("persona ingresada: \n");
                printf("\tNOMBRE\t\tDNI\t\tEDAD\n");
                mostrar(persona[i]);
                system("pause");
                system("cls");
                break;
            }
        }
    }
    else
    {
        system("color C");
        printf("ya no hay mas espacion en la base de datos!!!!!\n");
        system("pause");
        system("cls");
    }
}
void eliminarPersona(EPersona persona[],int tam)
{
    int alguien;
    int i;
    int dniEliminar;
    char respuesta;


    printf("ingrese el numero de documento que decea eliminar:");
    scanf("%d",&dniEliminar);
    alguien=buscarPorDni(persona,tam,dniEliminar);
    if(alguien!=-1)
    {
        for(i=0; i<tam; i++)
        {
            if(persona[alguien].dni==persona[i].dni)
            {
                printf("usted desea eliminar esta persona s/n:\n");
                printf("\tNOMBRE\t\tDNI\t\tEDAD\n");
                mostrar(persona[i]);
                respuesta=getch();
                while(respuesta!='s'&&respuesta!='n'&&respuesta!='S'&&respuesta!='N')
                {
                    system("color C");
                    printf("debe responder con s o n.");
                    respuesta=getch();
                }
                if(respuesta=='S'||respuesta=='s')
                {
                    persona[i].estado=0;
                    system("color A");
                    printf("se a eliminado correctamente la persona.\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    system("color B");
                    printf("la operacion fue cancelada.\n");
                    system("pause");
                    system("cls");
                }
            }
        }
    }
    else
    {
        system("color C");
        printf("el numero de documento ingresado no a sido encontrado!!!!\nreoprima la opcion 2 e ingrese un dni existente.\n");
        system("pause");
        system("cls");
    }
}
void listaPersonas(EPersona persona[], int tam)
{
    int i;
    int j;
    EPersona auxPersona;
    system("color E");
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(stricmp(persona[i].nombre,persona[j].nombre)>0)
            {
                auxPersona = persona[i];
                persona[i] = persona[j];
                persona[j] = auxPersona;
            }
        }
    }
    printf("\tNOMBRE\t\tDNI\t\tEDAD\n");
    mostrarTodos(persona,tam);
    system("pause");
    system("cls");
}
void grafico(EPersona persona[], int tam)
{
    int contMenor18;
    int contEntre19y35;
    int contMayor35;
    int i;
    int maximo;
    int flag;

    contMenor18=cont18(persona,tam);
    contMayor35=cont35(persona,tam);
    contEntre19y35=cont19a35(persona,tam);

    if(contMenor18>=contMayor35&&contMenor18>=contEntre19y35)
    {
        maximo=contMenor18;
    }
    else
    {
        if(contEntre19y35>=contMenor18&&contEntre19y35>=contMayor35)
        {
            maximo=contEntre19y35;
        }
        else
        {
            maximo=contMayor35;
        }
    }

    for(i=maximo; i>0; i--)
    {
        flag=0;
        system("color D");
        while(flag!=1)
        {
            if(i<= contMenor18)
            {
                printf("    *");
            }
            if(i<= contEntre19y35)
            {
                flag=1;
                printf("\t  *");
            }
            if(i<= contMayor35)
            {
                if(flag==1)
                {
                    printf("\t *");
                }
                else
                {
                    printf("\t\t *");
                }
            }
            flag=1;
            printf("\n");
        }

    }
    printf("  |<18\t19-35\t>35|\n");
    system("pause");
    system("cls");

}
void rellenarArray(EPersona persona[],int tam)
{
    int i;
    char nombre[][20]= {"alejo fernandes","marcor colvo","marta juares","julia martines","matin gomez","paula sanchez","evelin juares","leonel rey","pedro gomez","paula gonzalez","martina gonzalez","pepe lupez","jose messi","flor gimenez","augusto lopez","german scarafilo","mariana sanchez","santiago rey","victoria rey","carlos gomez"};
    int edad[]= {15,2,15,26,58,49,62,54,47,51,23,58,62,45,21,10,15,54,18,39};
    int dni[]= {11111111,22222222,33333333,44444444,55555555,66666666,77777777,88888888,99999999,12121212,13131313,14141414,15151515,16161616,17171717,18181818,19191919,21212121,23232323,24242424};

    for(i=0; i<tam; i++)
    {
        persona[i].estado=1;
    }
    for(i=0; i<tam; i++)
    {
        strcpy(persona[i].nombre,nombre[i]);
        persona[i].dni=dni[i];
        persona[i].edad=edad[i];
    }
    system("pause");
    system("cls");

}
int cont18 (EPersona persona[],int tam)
{
    int i;
    int contMenor18=0;

    for(i=0; i<tam; i++)
    {
        if(persona[i].edad<=18&&persona[i].estado==1)
        {
            contMenor18++;
        }

    }
    return contMenor18;
}

int cont19a35 (EPersona persona[],int tam)
{
    int i;
    int contEntre19y35=0;

    for(i=0; i<tam; i++)
    {
        if(persona[i].edad<=35&&persona[i].edad>=19&&persona[i].estado==1)
        {
            contEntre19y35++;
        }

    }
    return contEntre19y35;
}

int cont35 (EPersona persona[],int tam)
{
    int i;
    int contMayor35=0;

    for(i=0; i<tam; i++)
    {
        if(persona[i].edad>35&&persona[i].estado==1)
        {
            contMayor35++;
        }

    }
    return contMayor35;
}
