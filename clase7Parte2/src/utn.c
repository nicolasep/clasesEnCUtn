/*
 * utnPrueba.c
 *
 *  Created on: 16 abr. 2020
 *      Author: Jesi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarNumeroFloat(char* stringRecibido)
{
    int retorno=1;
	int i;
	int contadorPuntos=0;

    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
        	// no estoy en el rango de los numeros
        	if(stringRecibido[i]=='.') // es un punto
        	{
        		contadorPuntos++;
        		if(contadorPuntos>1)
        		{
        			// encontre un segundo punto, doy error
                    retorno=0;
                    break;
        		}
        	}
        	else
        	{
        		//Hay algo que no es un punto ni numero
        		if(i==0)
        		{
        			// me pongo a ver que onda con el caracter
        			if(stringRecibido[i]!='+' && stringRecibido[i]!='-')
        			{
        				retorno=0;
        				break;
        			}
        		}
        		else
        		{
        			retorno=0;
        			break;
        		}
        	}
        }
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


/*
 *
 int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

	int retorno = -1;

	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s\n",mensaje);
			fflush(stdin);
			if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
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

int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	//scanf("%s",buffer);
	fflush(stdin);
	if(myGets(buffer,sizeof(buffer))== 0 &&  esNumero(buffer))
	{
		retorno = 0;
		*pResultado = atoi(buffer);
	}



	return retorno;
}
int esNumero(char cadena[])
{
	int retorno = 1;
	int tam = strlen(cadena);
	int i;


	for(i=0; i<tam; i++)
	{
		if(cadena[i]>'9' || cadena[i]<'0')
		{
			retorno = 0;
			break;
		}

	}


	return retorno;
}*/

int esNumerica(char* cadena)
{
	int retorno = 1;
	int i = 0;

	if(cadena[0]=='-')
	{
		i = 1;
	}
	for( ; cadena[i] != '\0' ; i++)
	{

		if(cadena[i]>'9' || cadena[i]<'0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}
int myGets(char* cadena, int longitud) // el static es para que la funcion no se pueda usar desde otro archivo o desde el main si esta en otra libreria. son funciones de uso interno
{
	int retorno = -1;

	fflush(stdin);
	fgets(cadena,longitud,stdin);
	cadena[strlen(cadena)-1] ='\0';


	return retorno;
}

