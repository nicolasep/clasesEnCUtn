/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
 *      Author: Jesi
 */
#include <stdio.h>
#include <stdlib.h>


/*
int dividir(float* pResultado, int numero1, int numero2)
{
	int flag = -1;
	float resultado;

	if(pResultado !=NULL && numero2 != 0)
	{
		resultado =(float) numero1/numero2;
		*pResultado = resultado;
		flag = 0;
	}
	return flag;

}*/


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int flag = -1;
	int bufferInt;
	int contadorIntentos = 0;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			if(contadorIntentos == reintentos)
			{
				flag = -2;
				break;
			}

			printf("%s\n",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				flag = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s\n",mensajeError);
			}

			contadorIntentos++;

		}while(1);

	}

	return flag;
}
