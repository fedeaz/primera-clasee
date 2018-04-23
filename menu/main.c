#include <stdio.h>
#include <stdlib.h>
//#include "menu.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int isEmpty;

}eEmpleado;


int menu();

void inicializarEmpleado(eEmpleado vec[], int);

int buscarLibre(eEmpleado vec[], int);

int buscarEmpleado(eEmpleado vec[], int, int);

void alta(eEmpleado vec[],int);




int main()
{
    int salir = 1;
    eEmpleado gente[50];

    do
    {
        switch(menu())
        {
        case 1:
            printf("\n alta \n");
            system("pause");
            break;

        case 2:
            printf("\n baja \n");
            system("pause");
            break;

        case 3 :
            printf("\n modificacion \n");
            system("pause");
            break;

        case 4:
            printf("\n listar \n");
            system("pause");
            break;

        case 5:
            printf("\n ordenar \n");
            system("pause");
            break;

        case 6:
            printf("\n salir \n");
            salir = 0;
            system("pause");

        default:
            printf("\n Opcion Incorrecta \n");
            system("pause");

            break;
        }
    }while(salir==1);
    return 0;
}


int menu()
{

    int resultado;
    system("cls");
    printf("1- alta\n");
    printf("2-baja\n");
    printf("3-modificacion\n");
    printf("4-listar\n");
    printf("5-ordenar\n");
    printf("6-salir\n");
    printf("\nIndique opcion: ");
    scanf("%d", &resultado);
    return(resultado);

}

void inicializarEmpleado(eEmpleado vec [], int tam)
{
    int i;

    for(i=0;i< tam; i++)
    {
        vec [i].isEmpty = 0;
    }

}

int buscarLibre(eEmpleado vec[], int tam)
{
    int indeice = -1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(vec[i].isEmpty ==0)
        {
            indeice = 1;
            break;
        }
    }
    return indeice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int indice = -1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(vec[i].legajo== legajo)
        {
            indice = vec[i].legajo;
        }
    }
    return indice;
}

void alta(eEmpleado vec[],int tam)
{
    int indice;
    int esta;
    int lega;
    eEmpleado nuevoEmpleado;



    indice = buscarLibre(vec, tam);
    if(indice == -1)
    {

        printf("no hay lugar disponible");

    }
    else
    {
        printf("ingrese el legajo ");
        scanf("%d" &lega );
    }

    esta = buscarEmpleado(vec,tam,lega);

   if(esta != -1)
    {
        printf("\n el legajo ya corresponde a un empleado");
        mostrarEmpleado(vec[esta]);
    }
    else
    {
        nuevoEmpleado.isEmpty =0;
        nuevoEmpleado.legajo = lega;

        printf("ingrese el nombre\n");
        fflush(stdin);
        gets(nuevoEmpleado.nombre);

        printf("ingrese el sexo\n");
        fflush(stdin);
        scanf("%c", &nuevoEmpleado.sexo);

        printf("ingrese el sueldo\n");
        scanf(%"f", &nuevoEmpleado.sueldo);

        printf("ingrese la fecha de ingreso  d m a\n");
        scanf("%d %d %d", &nuevoEmpleado.fechaIngreso.dia, &nuevoEmpleado.fechaIngreso.mes, &nuevoEmpleado.fechaIngreso.anio);
    }
}
