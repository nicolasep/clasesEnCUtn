/*
 * utn.c
 *
 *  Created on: 18 abr. 2020
 *      Author: Jesi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int printArray(int* pArray, int len)
{
	int i;
	int retorno = -1;
	if(pArray != NULL && len >= 0)
	{
		retorno = 0;
		for(i=0; i<len; i++)
		{
			printf("[DEBUG] Indice: %d - Valor: %d\n ",i,pArray[i]);
		}
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
int ordenarArrayNumerico(int* pArray, int len)
{
	int retorno = -1;
	int i;
	int flagSwap;
	int contador = 0;
	int limiteVariable;

	if(pArray != NULL && len > 0)
	{
		limiteVariable = len -1;
		retorno = 0;
		do
		{
			flagSwap = 0;
			for(i=0; i<limiteVariable;i++)
			{
				contador++;
				if(pArray[i] < pArray[i+1])
				{
					intSwap(pArray+i,pArray+i+1);

					flagSwap = 1;
				}
			}

			limiteVariable--;
		}while(flagSwap);
		retorno = contador;

	}

	return retorno;
}

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
int myGets(char* cadena, int len) // el static es para que la funcion no se pueda usar desde otro archivo o desde el main si esta en otra libreria. son funciones de uso interno
{
	int retorno = 0;

	fflush(stdin);
	fgets(cadena,len,stdin);
	cadena[strlen(cadena)-1] ='\0';
	retorno = 0;

	return retorno;
}
int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];


	if(myGets(buffer,sizeof(buffer))==0 &&  esNumerica(buffer))
	{
		retorno = 0;
		*pResultado = atoi(buffer);
	}

	return retorno;
}


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)


{

	int retorno = -1;

	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s\n",mensaje);

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


int validarNumeroFloat(char* cadena)
{
    int retorno=1;
	int i;
	int contadorPuntos=0;

    for(i=0;cadena[i]!='\0';i++)
    {
        if(cadena[i]<'0' || cadena[i]>'9')
        {
        	// no estoy en el rango de los numeros
        	if(cadena[i]=='.') // es un punto
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
        			if(cadena[i]!='+' && cadena[i]!='-')
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
int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0 &&  validarNumeroFloat(buffer))
	{
		retorno = 0;
		*pResultado = atof(buffer);
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

				if(getFloat(&bufferFloat) &&bufferFloat >= minimo && bufferFloat <= maximo)
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
//cadenas
int validarCadena(char* cadena)
{
    int retorno= 1;
	int i;

    for(i=0;cadena[i]!='\0';i++)
    {
      if((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z'))
      {
    	  retorno = 0;
    	  break;
      }
    }
    return retorno;
}

int getCadena(char* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 &&  validarCadena(buffer))
	    {
		retorno = 0;
		strcpy(pResultado,buffer);
	    }
	}


	return retorno;
}
int utn_getCadena(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	char buffer[4096];

		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			do
			{
				printf("%s\n",mensaje);

				if(getCadena(buffer)==0 && strnlen(buffer,sizeof(buffer)) >= minimo && strnlen(buffer,sizeof(buffer)) <= maximo)
				{
					strcpy(pResultado,buffer);
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
//telefono
int esTelefono(char* telefono)
{
	int retorno = 1;
	int contadorGuiones = 0;
	int i;

	for(i=0; telefono[i]!='\0' ; i++)
	{
		if(telefono[i]<'0' || telefono[i]>'9')
		{

			retorno = 0;
		}
		else
		{
			if(telefono[i] =='-')
			{
				contadorGuiones ++;
			}
		}
	}

	if(contadorGuiones<2)
	{
		retorno = 1;
	}
	else
	{
		retorno = 0;
	}


	return retorno;

}
int getTelefono(char* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0 &&  esTelefono(buffer))
	{
		retorno = 0;
		strcpy(pResultado,buffer);
	}

	return retorno;
}
int utn_getTelefono(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	char buffer[4096];

		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			do
			{
				printf("%s\n",mensaje);

				if(getTelefono(buffer)==0 && sizeof(buffer) >= minimo && sizeof(buffer) <= maximo)
				{
					strcpy(pResultado,buffer);
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
//funciones email

int esEmail(char* cadena)
{
	int retorno = 1;
	int i;
	int contadorArroba = 0;
	int contadorPuntos = 0;
	int tienePuntoCom = 0;

	if(cadena != NULL)
	{
		for(i=0; cadena[i] !='\0'; i++)
		{
			if(cadena[i]=='@')
			{
				contadorArroba++;
				if(contadorArroba > 1)
				{
					retorno = 0;
				}
			}
			else
			{
				if(cadena[i]=='.')
				{
					contadorPuntos++;
					if(contadorPuntos > 3)
					{
						retorno = 0;
					}
					else
					{
						if((cadena[i+1]=='c' && cadena[i+2]=='o' && cadena[i+3]=='m')||(cadena[i+1]=='C' && cadena[i+2]=='O' && cadena[i+3]=='M'))
						{
							tienePuntoCom++;
							if((tienePuntoCom > 1 || tienePuntoCom == 0) && contadorArroba == 1)
							{
								retorno = 0;
							}
						}
					}
				}
			}
		}
		if(tienePuntoCom == 0 || contadorArroba == 0)
		{
			retorno=0;
		}
	}

	return retorno;
}
int getEmail(char* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0 &&  esEmail(buffer))
	{
		retorno = 0;
		strcpy(pResultado,buffer);
	}

	return retorno;
}
int utn_getEmail(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s\n",mensaje);

			if(getEmail(buffer) == 0 && strnlen(buffer,sizeof(buffer))>=minimo && strnlen(buffer,sizeof(buffer))<=maximo)
			{
				strcpy(pResultado,buffer);
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
