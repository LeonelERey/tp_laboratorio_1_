#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lib.h"
//#define mescladora 1001
//#define taladro 1002
//#define amoladora 1000
void inicializarCliente(xCliente cliente[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        cliente[i].estado=0;
    }
}
void inicializarAlquiler(xAlquiler alquiler[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        alquiler[i].estado=0;
    }
}
void altaCliente(xCliente cliente[],int tam)
{
    int i;
    int j;
    int cont=1;
    for(i=0; i<tam; i++)
    {
        if(cliente[i].estado==0)
        {
            cliente[i].idCliente=cont;
            printf("ingrese el nombre del cliente:");
            fflush(stdin),
                   gets(cliente[i].nombre);
            printf("ingrese el apellido del cliente:");
            fflush(stdin),
                   gets(cliente[i].apellido);
            printf("ingrese el numero de documento:");
            scanf("%d",&cliente[i].DNI);
            for(j=0; j<tam; j++)
            {
                if(cliente[j].estado==1)
                {
                    while(cliente[i].DNI==cliente[j].DNI)
                    {
                        printf("el numero de documento y existe!!\n reingrese:");
                        scanf("%d",&cliente[i].DNI);
                    }
                }
            }
            while(cliente[i].DNI<10000000||cliente[i].DNI>99999999)
            {
                printf("reingrese el numero de documento con 8 caracteres:");
                scanf("%d",&cliente[i].DNI);
            }
            cliente[i].estado=1;
            break;
        }
        cont++;
    }
}
void cargarCliente(xCliente cliente[],int tamInteg)
{

    int i;
    int ids[]= {1,2,3,4,5};
    char nombres[][20]= {"bruno","ariel","jorge","lucas","matias"};
    char apellidos[][20]= {"gonzalez","echeverri","martines","peres","gonzalez"};
    int dni[]= {11111111,22222222,33333333,44444444,55555555};
    int estado[]= {1,1,1,1,1};

    for(i=0; i<tamInteg; i++)
    {
        strcpy(cliente[i].nombre,nombres[i]);
        strcpy(cliente[i].apellido,apellidos[i]);
        cliente[i].idCliente=ids[i];
        cliente[i].DNI=dni[i];
        cliente[i].estado=estado[i];
    }


}
void caragarAlquileres(xAlquiler alquiler[],int tam)
{
    int tiempoEstimado[]= {10,15,24,36,12,5,50,4,8,16};
    char equipo[][30]= {"taladro","amoladora","taladro","mescladora","amoladora","mescladora","taladro","mescladora","amoladora","taladro"};
    int idCliente[]= {1,2,1,4,5,1,5,3,4,1};
    char operador[][20]= {"juan","martin","pedro","juan","martin","lucas","oscar","martin ","lucas","pedro"};
    int i;

    for(i=0; i<tam; i++)
    {
        alquiler[i].idCliente=idCliente[i];
        alquiler[i].tiempo=tiempoEstimado[i];
        strcpy(alquiler[i].equipo,equipo[i]);
        strcpy(alquiler[i].operador,operador[i]);
        alquiler[i].estado=1;
    }

}
void mostarCliente(xCliente cliente[],int tamInteg)
{
    int i;

    for(i=0; i<tamInteg; i++)
    {
        if(cliente[i].estado==1)
        {
            printf("%d==%s==%s\n",cliente[i].idCliente,cliente[i].apellido,cliente[i].nombre);
        }

    }

}
void mostarAlquiler(xAlquiler alquiler[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(alquiler[i].estado==1)
        {
            printf("%s==%s==%d==%d\n",alquiler[i].equipo,alquiler[i].operador,alquiler[i].idCliente,alquiler[i].tiempo);
        }

    }
}
void nuevoAlquiler(xAlquiler alquiler[],int tam)
{
    int i;
    int j;
    for(i=0; i<tam; i++)
    {

        if(alquiler[i].estado==0)
        {
            printf("id del cliente:");
            scanf("%d",&alquiler[i].idCliente);
            printf("equipo que va a alquilar:");
            scanf("%d",alquiler[i].equipo);
            printf("tiempo estimado de alquiler:");
            scanf("%d",&alquiler[i].tiempo);
            printf("ingrese el nombre del operador:");
            fflush(stdin);
            gets(alquiler[i].operador);
            break;
        }


    }
}
void clientesAlquileres(xCliente cliente[],xAlquiler alquiler[],int tam,int tama)
{
    /*int i;
    int j;
    for(i=0; i<tam; i++)
    {
        printf("===============================================\n");
        printf("%s %s:\n",cliente[i].nombre,cliente[i].apellido);
        for(j=0; j<tama; j++)

        {
            if(alquiler[j].idCliente==cliente[i].idCliente)
            {
                printf("%s %d %d %s\n",alquiler[j].equipo,alquiler[j].idCliente,alquiler[j].tiempo,alquiler[j].operador);
            }
        }

    }*/
    int i;
    int j;
    for(i=0; i<tam; i++)
    {
        if(cliente[i].estado==1)
        {
            printf("===============================================\n");
            printf("%s %s:\n",cliente[i].apellido,cliente[i].nombre);
            for(j=0; j<tama; j++)
            {
                if(alquiler[j].estado==1&&alquiler[j].idCliente==cliente[i].idCliente)
                {
                    printf("%s==%s==%d==%s\n",alquiler[j].equipo,cliente[i].nombre,alquiler[j].tiempo,alquiler[j].operador);
                }

            }
        }
    }
}
void modificacion(xCliente cliente[],int tam)
{
    int i;
    int aux;

    printf("ingres el id del usuario:");
    scanf("%d", &aux);

    for(i=0; i<tam; i++)
    {
        if(cliente[i].idCliente==aux)
        {
            printf("el cliente a modificar es:%s==%s\n",cliente[i].apellido,cliente[i].nombre);
            printf("ingrese un nuevo nombre:");
            fflush(stdin);
            gets(cliente[i].nombre);
            printf("ingrese un nuevo apellido:");
            fflush(stdin);
            gets(cliente[i].apellido);
        }
    }
}
void darBaja (xCliente cliente[], int tam)
{
    int i;
    int aux;
    char respuesta;

    printf("ingres el id del cliente:");
    scanf("%d", &aux);
    for(i=0; i<tam; i++)
    {
        if(cliente[i].idCliente==aux)
        {
            printf("usted desea eliminar este cliente %s %s s/n:\n",cliente[i].apellido,cliente[i].nombre);
            respuesta=getch();
            while(respuesta!='s'&&respuesta!='n'&&respuesta!='S'&&respuesta!='N')
            {
                system("color C");
                printf("debe responder con s o n.\n");
                respuesta=getch();
            }
            if(respuesta=='S'||respuesta=='s')
            {
                cliente[i].estado=0;
                printf("se a eliminado correctamente la persona.\n");

            }
        }
    }
}
/*int obtenerEspacioLibre(xCliente cliente[],int tam)
{
    int i;
    int retorno;
    for(i=0; i<tam; i++)
    {
        if(cliente[i].estado==0)
        {
            retorno=i;
            return retorno;
        }
    }
    return -1;
}*/
