#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Libreria.h"
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
    int aux;

    aux=obtenerEspacioLibre(cliente,tam);
    if(aux!=-1)
    {
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
    else
    {
        printf("ya no se pueden cargar mas cliente.\n");
        system("pause");
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
    char estadoAlqui[][20]= {"alquilado","alquilado","alquilado","alquilado","alquilado","alquilado","alquilado","alquilado","alquilado","alquilado"};
    int ordenes[]= {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009};
    //int estado[]={1,-1,1,-1,-1,1,-1,1,-1,1};
    int i;
    for(i=0; i<tam; i++)
    {
        alquiler[i].idCliente=idCliente[i];
        alquiler[i].tiempo=tiempoEstimado[i];
        strcpy(alquiler[i].equipo,equipo[i]);
        strcpy(alquiler[i].operador,operador[i]);
        strcpy(alquiler[i].estaAlquiler,estadoAlqui[i]);
        alquiler[i].orden=ordenes[i];

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
void nuevoAlquiler(xAlquiler alquiler[],xCliente cliente[],int tam,int tama)
{
    int i;
    int equipo;
    int retorno;
    int aux;
    char taladro[15]="taladro";
    char amoladora[15]="amoladora";
    char mescladora[15]="mescladora";

    aux=obtenerEspacioLibreAlqui(alquiler,tam);
    if(aux!=-1)
    {
        for(i=0; i<tam; i++)
        {

            if(alquiler[i].estado==0)
            {
                printf("id del cliente:");
                scanf("%d",&alquiler[i].idCliente);
                retorno=buscarPorId(cliente,tama,alquiler[i].idCliente);
                while(retorno==-1)
                {
                    printf("ingrese un id existente:");
                    scanf("%d",&alquiler[i].idCliente);
                    retorno=buscarPorId(cliente,tama,alquiler[i].idCliente);
                }
                printf("equipo que va a alquilar:");
                scanf("%d",&equipo);
                while(equipo<1||equipo>3)
                {
                    printf("ingrese el equipo entre 1 y 3:");
                    scanf("%d",&equipo);
                }
                switch(equipo)
                {
                case 1:
                    strcpy(alquiler[i].equipo,taladro);
                    break;
                case 2:
                    strcpy(alquiler[i].equipo,mescladora);
                    break;
                case 3:
                    strcpy(alquiler[i].equipo,amoladora);
                    break;
                }
                printf("tiempo estimado de alquiler:");
                scanf("%d",&alquiler[i].tiempo);
                printf("ingrese el nombre del operador:");
                fflush(stdin);
                gets(alquiler[i].operador);
                alquiler[i].estado=1;

                break;
            }

        }
    }
    else
    {
        printf("ya no se puede alquilar mas maquinas.");
        system("pause");
    }

}
void clientesAlquileres(xCliente cliente[],xAlquiler alquiler[],int tam,int tama)
{
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
                if(alquiler[j].estado==1)
                {
                    if(alquiler[j].idCliente==cliente[i].idCliente)
                    {
                        printf("%s==%dhs==%s\n",alquiler[j].equipo,alquiler[j].tiempo,alquiler[j].operador);
                    }

                }

            }
        }
    }
}
void modificacion(xCliente cliente[],int tam)
{
    int i;
    int aux;
    int retorno;

    printf("ingres el id del usuario:");
    scanf("%d", &aux);
    retorno=buscarPorId(cliente,tam,aux);
    while(retorno==-1)
    {
        printf("ingrese un id existente:");
        scanf("%d",&aux);
        retorno=buscarPorId(cliente,tam,aux);
    }

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
    int retorno;
    char respuesta;

    printf("ingres el id del cliente:");
    scanf("%d", &aux);
    retorno=buscarPorId(cliente,tam,aux);
    while(retorno==-1)
    {
        printf("ingrese un id existente:");
        scanf("%d",&aux);
        retorno=buscarPorId(cliente,tam,aux);
    }
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
int obtenerEspacioLibreAlqui(xAlquiler alquiler[],int tam)
{
    int i;
    int retorno;
    for(i=0; i<tam; i++)
    {
        if(alquiler[i].estado==0)
        {
            retorno=i;
            return retorno;
        }
    }
    return -1;
}
int buscarPorId(xCliente persona[],int tam,int dni)
{
    int i;
    int retorno;
    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==1&&persona[i].idCliente==dni)
        {
            retorno=i;
            return retorno;
        }
    }
    return -1;
}
int buscarPorOrden(xAlquiler alquiler[],int tam,int orden)
{
    int i;
    int retorno;
    for(i=0; i<tam; i++)
    {
        if(alquiler[i].estado==1&&alquiler[i].orden==orden)
        {
            retorno=i;
            return retorno;
        }
    }
    return -1;
}
int obtenerEspacioLibre(xCliente persona[],int tam)
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
void finDeAlquiler(xAlquiler alquiler[],int tam)
{
    int aux;
    int confirmar;
    int i;
    char finalizado[15]= {"finalizado"};
    printf("ingrese la orden del alquiler:");
    scanf("%d",&aux);
    confirmar=buscarPorOrden(alquiler,tam,aux);
    while(confirmar==-1)
    {
        printf("ingrese una orden de alquiler existente:");
        scanf("%d",&aux);
        confirmar=buscarPorOrden(alquiler,tam,aux);
    }

    for(i=0; i<tam; i++)
    {
        if(alquiler[i].orden==aux)
        {
            printf("ingrese la hora real de alquiler:");
            scanf("%d",&alquiler[i].tiempoReal);
            alquiler[i].estado=-1;
            strcpy(alquiler[i].estaAlquiler,finalizado);
            printf("alquiler finalizado.\n");
            system("pause");
        }

    }

}
void clienteMasCanci(xAlquiler alquiler[],xCliente cliente[],int tam,int tamInteg)
{
    int i;
    int j;
    int cont1=0;
    int cont2=0;
    int aux;
    int aux2;

    for(i=0; i<tamInteg; i++)
    {
        for(j=0; j<tam; j++)
        {
            if(alquiler[j].idCliente==cliente[i].idCliente)
            {
                cont2++;
            }

        }
        if(cont2>=cont1)
        {
            if(cont1==cont2)
            {
                aux2=i;
            }
            else
            {
                cont1=cont2;
                aux=i;
            }

        }
        cont2=0;
    }
    for(i=0; i<tam; i++)
    {

        if(alquiler[i].idCliente==cliente[aux].idCliente)
        {
            printf("===============================================\n");
            printf("el cliente con mas alquileres es: %s %s\n",cliente[aux].apellido,cliente[aux].nombre);
            if(alquiler[i].idCliente==cliente[aux2].idCliente)
            {
                printf("y tambien:%s %s\n",cliente[aux2].apellido,cliente[aux2].nombre);
            }
            break;
        }
    }

}
void equipoMasVendido(xAlquiler alquiler[],int tam)
{
    int i;
    int j;
    int cont1=0;
    int cont2=0;
    int contAux;
    int aux;
    int aux2;

    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam; j++)
        {
            if(strcmp(alquiler[j].equipo,alquiler[i].equipo)==0)
            {
                cont2++;
            }

        }
        if(cont2>=cont1)
        {
            contAux=cont2;
            if(cont1==cont2)
            {
                aux2=i;
            }
            else
            {
                cont1=cont2;
                aux=i;
            }

        }
        cont2=0;
    }
    for(i=0; i<tam; i++)
    {

        if(strcmp(alquiler[i].equipo,alquiler[aux].equipo)==0)
        {
            printf("===============================================\n");
            printf("el equipo mas alquilado es: %s con:%d ventas\n",alquiler[aux].equipo,contAux);
            if(strcmp(alquiler[i].equipo,alquiler[aux2].equipo)==0)
            {
                printf("y tambien:%s con:%d ventas\n",alquiler[aux2].equipo,contAux);
            }
            break;
        }
    }
}
void promedioHoras(xAlquiler alquiler[],int tam)
{
    int i;
    int cont=0;
    int acumulador=0;
    float promedio;
    printf("===============================================\n");
    for(i=0;i<tam;i++)
    {
        if(alquiler[i].estaAlquiler==-1)
        {
            acumulador=acumulador+alquiler[i].tiempoReal;
            cont++;
        }
    }
    if(alquiler[i].estaAlquiler==-1)
    {
        promedio=(float)acumulador/cont;
        printf("el promedio de las hora reales es: %f",promedio);
    }
    else
    {
        printf("el promedio de las hora reales es: 0\n");
    }

}
