#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int opciones (float num1,float num2,int flag,int flag1)
{
    int opcion;
    if(flag!=1&&flag!=1)
    {
        system("color F");
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        scanf("%d",&opcion);
        while(opcion<1||opcion>9)
        {
            system("color C");
            printf("el valor ingresado no esta dentro de las opciones\nreingrese entre 1 y 9:");
            scanf("%d", &opcion);
        }

    }
        else
        {
            if(flag==1&&flag1==1)
            {
                system("color F");
                printf("1- Ingresar 1er operando (A=%f)\n",num1);
                printf("2- Ingresar 2do operando (B=%f)\n",num2);
                printf("3- Calcular la suma (A+B)\n");
                printf("4- Calcular la resta (A-B)\n");
                printf("5- Calcular la division (A/B)\n");
                printf("6- Calcular la multiplicacion (A*B)\n");
                printf("7- Calcular el factorial (A!)\n");
                printf("8- Calcular todas las operacione\n");
                printf("9- Salir\n");
                scanf("%d",&opcion);
                while(opcion<1||opcion>9)
                {
                    system("color C");
                    printf("el valor ingresado no esta dentro de las opciones\nreingrese entre 1 y 9:");
                    scanf("%d", &opcion);
                }
            }
            else
            {
                system("color F");
                printf("1- Ingresar 1er operando (A=%f)\n",num1);
                printf("2- Ingresar 2do operando (B=y)\n");
                printf("3- Calcular la suma (A+B)\n");
                printf("4- Calcular la resta (A-B)\n");
                printf("5- Calcular la division (A/B)\n");
                printf("6- Calcular la multiplicacion (A*B)\n");
                printf("7- Calcular el factorial (A!)\n");
                printf("8- Calcular todas las operacione\n");
                printf("9- Salir\n");
                scanf("%d",&opcion);
                while(opcion<1||opcion>9)
                {
                    system("color C");
                    printf("el valor ingresado no esta dentro de las opciones\nreingrese entre 1 y 9:");
                    scanf("%d", &opcion);
                }
                flag1=1;
            }
        }
        return opcion;

    }
    float preguntar (char titulo[])
    {
        float dato;

        system("color B");
        printf("%s", titulo);
        scanf("%f", &dato);
        system("pause");
        system("cls");

        return dato;
    }
    float sumar (float num1,float num2,int flag,int flag1)
    {
        float resultado;
        if(flag==1&&flag1==1)
        {
            resultado=num1+num2;
            system("color A");
            printf("la sumatoria de los numeros es: %f\n",resultado);
        }
        else
        {
            system("color C");
            printf("no a ingresado alguno de los numeros!!\n");

        }

    }

    float restar (float num1,float num2,int flag,int flag1)
    {
        float resultado;
        if(flag==1&&flag1==1)
        {
            resultado=num1-num2;
            system("color A");
            printf("la resta de los numeros es: %f\n",resultado);
        }
        else
        {
            system("color C");
            printf("no a ingresado alguno de los numeros!!\n");

        }

    }


    float dividir (float num1,float num2,int flag,int flag1)
    {
        float respuesta;
        if(flag==1&&flag1==1)
        {
            if(num2!=0)
            {
                respuesta=num1/num2;
                system("color A");
                printf("la divicion de los numeros es: %.2f\n",respuesta);
            }
            else
            {
                system("color C");
                num2=preguntar("no se puede realizar la operacion con 0!!\ningrese otro numero:");
            }

        }
        else
        {
            system("color C");
            printf("no a ingresado alguno de los numeros!!\n");

        }


    }
    float multiplicar(float num1,float num2,int flag,int flag1)
    {
        float resultado;
        if(flag==1&&flag1==1)
        {

            resultado=num1*num2;
            system("color A");
            printf("la multiplicacion de los numeros es: %f\n",resultado);

        }
        else
        {
            system("color C");
            printf("no a ingresado alguno de los numeros!!\n");

        }
    }
    long long int factorial(float num1,int flag)
    {
        long long int resultado;

        if((int)num1==0)
        {
            return 1;
        }
        resultado=(int)num1*factorial((int)num1-1,flag);

        return resultado;

    }
    long long int factorialMost(float num1,int flag)
    {
        float aux;
        float aux2;

        long long int resultado;
        aux=num1;
        aux2=(int)aux-num1;
        if(aux2==0)
        {
            if(flag==1)
            {
                resultado=factorial(num1,flag);
                system("color A");
                printf("el factorial del numero es: %lld\n",resultado);

            }
            else
            {
                system("color C");
                printf("no a ingresado el primer numeros!!\n");

            }
        }
        else
        {
            system("color C");
            printf("no se puede realizar esta operacion con un numero con coma.\n");
        }

    }
    float todosCalculos (float num1,float num2,int flag,int flag1)
    {
        float respuestaComa;
        long long int respuesta;
        if(flag==1&&flag1==1)
        {
            respuestaComa=sumar(num1,num2,flag,flag1);
            system("color D");
            respuestaComa=restar(num1,num2,flag,flag1);
            respuestaComa=dividir(num1,num2,flag,flag1);
            respuestaComa=multiplicar(num1,num2,flag,flag1);
            respuesta=factorialMost(num1,flag);
            system("pause");
            system("cls");

        }
        else
        {
            system("color C");
            printf("no a ingresado alguno de los numeros!!\n");
            system("pause");
            system("cls");

        }
    }

