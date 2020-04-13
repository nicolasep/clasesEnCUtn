/*
 * nico.c
 *
 *  Created on: 2 abr. 2020
 *      Author: Jesi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h> para linux

int getInt(char mensaje[])
{
	int numero;
	printf("%s",mensaje);
	scanf("%d",&numero);

	return numero;

}
char getCadena(char mensaje[], int tam)
{

	char palabra[tam];
	printf("%s",mensaje);
	fflush(stdin);
	//__fpurge(stdin); //para linux
	fgets(palabra,tam,stdin);


	return palabra[tam];
}
char getChar(char mensaje[])
{

	char aux;
	printf("%s",mensaje);
	fflush(stdin);
	//__fpurge(stdin); //para linux
	scanf("%c",&aux);

	return aux;
}

float getFloat(char mensaje[])
{
	float numero;
	printf("%s",mensaje);
	scanf("%f",&numero);

	return numero;
}
int esTelefono(char telefono[])
{
	int tam = strlen(telefono);
	int contadorGuiones = 0;
	int i;

	for(i=0; i<tam; i++)
	{
		if(telefono[i] < '0' || telefono[i] > '9')
		{
			return -1;
		}
		else
		{
			if(telefono[i] == '-')
			{
				contadorGuiones ++;
			}
		}
	}
	if(contadorGuiones == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int esEmail(char cadena[])
{
	int retorno = -1;
	int contadorArroba = 0;
	int contadorPuntos = 0;

	int tam = strlen(cadena);
	int i;
	for(i=0; i<tam; i++)
	{
		if(cadena[i] == '@')
		{
			contadorArroba ++;
		}
		else
		{
			if(cadena[i] == '.')
			{
				contadorPuntos ++;
			}
		}
	}

	return retorno;
}
int esAlphaNumerico(char numero[])
{
	int tam = strlen(numero);
	int contadorLetras = 0;
	int contadorNumeros = 0;
	int i;

	for(i=0; i<tam; i++)
	{
		if(numero[i] < 'a' || numero[i] > 'z' || numero[i] < 'A' || numero[i] > 'Z' || numero[i] < '0' || numero[i] > '9')
		{
			return 0;
		}
		else
		{
			if((numero[i] >='a' && numero[i] <='z') || (numero[i] >='A' && numero[i] <='Z'))
			{
				contadorLetras ++;
			}
			else if(numero[i] >='0' && numero[i] <='9')
			{
				contadorNumeros ++;
			}
		}
	}
	if(contadorLetras > 0 && contadorNumeros > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//funciona
int esPalabra(char palabra[])
{
	int tam = strlen(palabra);
	int retorno = 0;

	int i;
	for(i=0; i<tam; i++)
	{
		if((palabra[i] !=' ') && (palabra[i]<'a' || palabra[i]>'z') && (palabra[i]<'A' || palabra[i]>'Z'))
		{
			retorno = -1;
		}
	}
	return retorno;
}
//funciona
int utn_getCadena(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	char bufferChar[100];
	int tam;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s\n",mensaje);
			gets(bufferChar);
			if((esPalabra(bufferChar))==0)
			{
				tam = strlen(bufferChar);
				if(tam >= minimo && tam <= maximo)
				{
					strcpy(pResultado,bufferChar);
					retorno = 0;
					break;
				}
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
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}



		}while(reintentos >= 0);


	}

	return retorno;
}*/
//funciona
int esNumero(char cadena[])
{
	int retorno = 0;
	int tam = strlen(cadena);
	int i;


	for(i=0; i<tam; i++)
	{
		if(cadena[i]>'9' || cadena[i]<'0')
		{
			retorno = -1;
			break;
		}

	}


	return retorno;
}
//funciona
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

	int retorno = -1;
	int bufferInt;
	char bufferChar[64];


	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s\n",mensaje);
			fflush(stdin);
			gets(bufferChar);

			if((esNumero(bufferChar))==0)
			{
				bufferInt = atoi(bufferChar);
				if(bufferInt >= minimo && bufferInt <= maximo)
				{

					*pResultado = bufferInt;
					retorno = 0;
					break;
				}

			}
			else
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
//no se uso
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
//no se uso
int esNumerico(char palabra[])
{
	int tam = strlen(palabra);
	int i;

	for(i=0; i<tam; i++)
	{
		if(palabra[i] < 0 || palabra[i] > 9)
		{
			return 0;
		}
	}

	return 1;
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
