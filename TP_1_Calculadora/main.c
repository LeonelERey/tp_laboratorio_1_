#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float num1;
    float num2;
    long long int respuesta;
    float respuestaComa;
    int flag=0;
    int flag2=0;
    float aux;
    float aux2;

    while(seguir=='s')
    {
        opcion=opciones(num1,num2,flag,flag2);

        switch(opcion)
        {
        case 1:
            num1=preguntar("ingrese el primer numero:");
            flag=1;

            break;
        case 2:
            num2=preguntar("ingrese el segundo numero:");
            flag2=1;

            break;
        case 3:
            respuestaComa=sumar(num1,num2,flag,flag2);
            system("pause");
            system("cls");
            break;

        case 4:
            respuestaComa=restar(num1,num2,flag,flag2);
            system("pause");
            system("cls");
            break;

        case 5:
            respuestaComa=dividir(num1,num2,flag,flag2);
            system("pause");
            system("cls");
            break;

        case 6:
            respuestaComa=multiplicar(num1,num2,flag,flag2);
            system("pause");
            system("cls");
            break;

        case 7:
            respuesta=factorialMost(num1,flag);
            system("pause");
            system("cls");
            break;
        case 8:
            respuestaComa=todosCalculos(num1,num2,flag,flag2);
            break;
        case 9:
            seguir = 'n';
            break;
        }
    }


    return 0;
}
