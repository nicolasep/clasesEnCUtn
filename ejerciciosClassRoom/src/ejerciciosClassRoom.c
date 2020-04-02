/*
 ============================================================================
 Name        : ejerciciosClassRoom.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int mostrarNumeros(int vec[], int tam);

int main(void) {
	setbuf(stdout,NULL);
	//EJERCICIO 1
	/*Solicitar al usuario 5 números, almacenar estos en un array de enteros, permitir listarlos por
	 *  pantalla indicando el máximo, el mínimo y el promedio. Permitir Modificar el valor de
	 *  cualquiera de los números cargados indicando el índice del mismo y su nuevo valor.*/

	int bufferInt[5];
	int i;
	int opcion;
	int maximo;
	int minimo;
	int acumulador=0;
	float promedio;
	int contadorIngresos=0;
	int opcionModificar;
	int buffer;

	for(i=0; i<5; i++)
	{
		printf("Ingrese numero %d:",i+1);
		scanf("%d",&bufferInt[i]);
		contadorIngresos++;
	}

	do
	{
		system("cls");

		if(contadorIngresos==5)
		{

			for(i=0; i<5; i++)
				{
					if(i==0)
					{
						maximo = bufferInt[i];
						minimo = bufferInt[i];
					}
					else
					{
						if(bufferInt[i] > maximo)
						{
							maximo = bufferInt[i];
						}
						else
						{
							if(bufferInt[i] < minimo)
							{
								minimo = bufferInt[i];
							}
						}
					}
					acumulador += bufferInt[i];
				}
			promedio =(float) acumulador / i;

			printf("ELIJA UNA OPCION \n");
			printf("1 - LISTAR NUMEROS\n");
			printf("2 - MODIFICAR NUMEROS\n");
			printf("3 - SALIR\n");
			scanf("%d",&opcion);

			switch(opcion)
			{
			case 1:
					mostrarNumeros(bufferInt,5);
					printf("El numero maximo es: %d y el minimo es: %d\n",maximo,minimo);
					printf("El promedio es: %.2f\n",promedio);

				break;
			case 2:
				mostrarNumeros(bufferInt,5);
				printf("Ingrese el indice del numero a modificar: ");
				scanf("%d",&opcionModificar);
				printf("Ingrese el nuevo numero: ");
				scanf("%d",&buffer);
				bufferInt[opcionModificar-1] = buffer;
				break;
			case 3:

				break;
			default:
				printf("OPCION INCORRECTA\n");
				break;
			}
		}
		else
		{
			printf("No se ingresaron los 5 numeros\n");
			break;
		}
		system("pause");



	}while(opcion != 3);







	return EXIT_SUCCESS;
}

int mostrarNumeros(int vec[], int tam)
{
	int flag=-1;
	int i;
	for(i=0; i<tam; i++)
	{
		if(i==0)
		{
			printf("INDICE  NUMERO\n");
		}

		printf("%d         %d\n",(i+1),vec[i]);
		if(i==4)
		{
			flag = 1;
		}

	}


	return flag;
}
