/*
 ============================================================================
 Name        : clase6SegunaParte.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


int main(void) {
	setbuf(stdout,NULL);



	/*
	char nombre[11] = "JUAN"; // el ultimo de lo que se escribe se usa para el '\0' osea que no se pueden usar los 11 lugares, solo 10
	char auxiliar[30];
	char apellido[11];

	//strcpy(nombre,"MARIA"); strcpy no se usa por que es insegura, no se le puede pasar limite a copiar
	//strcpy(auxiliar,nombre);

	strncpy(auxiliar,nombre,sizeof(auxiliar));
	//strncpy(destino,origen,limite de destino);


	//strlen(auxiliar); es insegura por que se le puede poner limite
	strnlen(auxiliar,sizeof(auxiliar));//devuelve la cantidad de letras que tiene la palabra antes del '\0'

	strncat(nombre,"lala",sizeof(nombre));//es para concatenar dos string ACA LE AGREGA A JUAN, LALA respetando el limite

	sprintf(nombre,"mi size of es %d",sizeof(auxiliar)); //imprime en otra variable string. en nombre se guarda el contenido a imprimir

	snprintf(auxiliar,sizeof(auxiliar),"mi size of es %d",2131);// es el modo seguro

	snprintf(auxiliar,sizeof(auxiliar)," %s %s",nombre,apellido); // estaria agregando o copiando nombre y apellido en nombre
	*/
	int auxInt;

	if(utn_getNumero(&auxInt,"numero?\n","error\n",0,2,2)==0)
	{
		printf("\nnumeros es: %d",auxInt);
	}



	return EXIT_SUCCESS;
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
static int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	//scanf("%s",buffer);

	if(myGets(buffer,sizeof(buffer))== 0 &&  esNumerica(buffer))
	{
		retorno = 0;
		*pResultado = atoi(buffer);
	}



	return retorno;
}
static int myGets(char* cadena, int longitud) // el static es para que la funcion no se pueda usar desde otro archivo o desde el main si esta en otra libreria. son funciones de uso interno
{
	int retorno = -1;

	fflush(stdin);
	fgets(cadena,longitud,stdin);
	cadena[strlen(cadena)-1] ='\0';



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
			//scanf("%d",&bufferInt);
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
