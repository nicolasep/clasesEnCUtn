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

int esPalabra(char palabra[])
{
	int tam = strlen(palabra);

	int i;
	for(i=0; i<tam; i++)
	{
		if((palabra[i] !=' ') && (palabra[i] < 'a' || palabra[i] > 'z') && (palabra[i] < 'A' || palabra[i] > 'Z'))
		{
			return 0;
		}
	}
	return 1;
}
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

