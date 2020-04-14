/*
 ============================================================================
 Name        : clase6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "nico.h"

#define QTY_ALUMNOS 9
//int sortArray(int array[],int len, int or);
int printArray(int* pArray, int limite);
int ordenarArray(int* pArray, int limite);
void intSwap(int* pNumeroA, int* pNumeroB);

int sortArray(int* pArray, int len);

int main(void) {
	setbuf(stdout,NULL);

	int edades[]= {54,26,93,17,77,31,44,55,27};
	int respuesta;

	printArray(edades,QTY_ALUMNOS);

	respuesta = ordenarArray(edades,QTY_ALUMNOS);
	printf("Ordenado\n");
	printArray(edades,QTY_ALUMNOS);
	printf("\nVueltas\n%d",respuesta);

	respuesta = ordenarArray(edades,QTY_ALUMNOS);
	printf("\nVueltas\n%d",respuesta);



    /*
	do
	{


		printf("Elija una opcion: \n1-mostrar: \n2-ordenar de forma ascendente: \n3-ordenar de forma descendente: ");
		scanf("%d",&opcion);
		switch(opcion)
		{
		case 1:
			imprimirArray(numeros,10);
			break;
		case 2:
			sortArray(numeros,10,1);
			break;
		case 3:
			sortArray(numeros,10,2);
			break;

		}


	}while(opcion == 5);*/






	return EXIT_SUCCESS;
}

int printArray(int* pArray, int limite)
{
	int i;
	int retorno = -1;
	if(pArray != NULL && limite >= 0)
	{
		retorno = 0;
		for(i=0; i<limite; i++)
		{
			printf("[DEBUG] Indice: %d - Valor: %d\n ",i,pArray[i]);
		}
	}

	return retorno;
}
int ordenarArray(int* pArray, int limite)
{
	int retorno = -1;
	int i;
	int buffer;
	int flagSwap;
	int contador = 0;
	int limiteVariable;

	if(pArray != NULL && limite > 0)
	{
		limiteVariable = limite -1;
		retorno = 0;
		do
		{
			flagSwap = 0;
			for(i=0; i<limiteVariable;i++)
			{
				contador++;
				if(pArray[i] < pArray[i+1])
				{
					//intSwap(pArray+i,pArray+i+1);
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
					flagSwap = 1;
				}
			}

			limiteVariable--;
		}while(flagSwap);
		retorno = contador;

	}

	return retorno;
}
void intSwap(int* pNumeroA, int* pNumeroB)
{
	int buffer;
	buffer = *pNumeroA;
	*pNumeroA = *pNumeroB;
	*pNumeroB = buffer;
}

int sortArray(int* pArray, int len)
{
	int retorno = -1;
	int swap;
	int buffer;
	int limite;
	int i;
	int contador = 0;



	if(pArray != NULL && len > 0)
	{
		limite = len-1;
		do
		{
			swap = 0;

			for(i=0; i<limite; i++)
			{
				if(pArray[i] > pArray[i+1])
				{
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
					swap = 1;
				}
				contador++;

			}
			limite--;
		}while(swap);

	}
	retorno = contador;

	return retorno;
}

/*
int sortArray(int array[],int len, int or)
{
	int aux;
	int i;
	int j;
	if(or == 1)
	{
		for(i=0;i<9;i++)
		{
			for(j=i+1; j<10; j++)
			{
				if(array[i] > array[j])
				{
					aux = array[i];
					array[i] = array[j];
					array[j] = aux;

				}
			}
		}
	}
	else if(or == 2)
	{
		for(i=0;i<9;i++)
				{
					for(j=i+1; j<10; j++)
					{
						if(array[j] > array[i])
						{
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;

						}
					}
				}
	}

return 0;
}*/
