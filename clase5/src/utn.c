/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
 *      Author: Jesi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/*
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			//printf("%s\n",mensaje);
			//scanf("%d",&bufferInt);
			if((getNumero(&bufferInt,mensaje,mensajeError))==0)
			{
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}
			}



		}while(reintentos >= 0);


	}

	return retorno;
}

*/
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s\n",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}

		}while(reintentos >= 0);


	}

	return retorno;
}
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			do
			{
				printf("%s\n",mensaje);
				scanf("%f",&bufferFloat);
				if(bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pResultado = bufferFloat;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}

			}while(reintentos >= 0);


		}

		return retorno;
}

int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;

		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			do
			{
				printf("%s\n",mensaje);
				fflush(stdin);
				scanf("%c",&bufferChar);
				if(bufferChar >= minimo && bufferChar <= maximo && ((bufferChar >= 'a' && bufferChar <= 'z')|| (bufferChar >= 'A' && bufferChar <= 'Z')))
				{
					*pResultado = bufferChar;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}

			}while(reintentos >= 0);


		}

		return retorno;
}
/*
int getNumero(int* pResultado, char* mensaje, char* mensajeError)
{

	int retorno = -1;
	char buffer[100];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		fgets(buffer,sizeof(buffer),stdin);

		if((esNumero(buffer)) == 0)
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
		else
		{
			printf("%s",mensajeError);
		}
	}

	return retorno;
}
int esNumero(char* cadena)
{
	int retorno = 0;
	int tam = strlen(cadena);
	int i;

	for(i=0; i<tam; i++)
	{
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = -1;
			break;
		}

	}

	return retorno;
}
int esPalabra(char* palabra)
{
	int retorno = -1;
	int tam = strlen(palabra);
	int i;

	for(i=0; i<tam; i++)
	{

	}


	return retorno;
}
*/


