/*
 ============================================================================
 Name        : clase4.c
 Author      : 
 Version     : Funciones
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"




int main(void) {

	setbuf(stdout,NULL);


	/*float resultado;
	int numero1;
	int numero2;
	int respuesta;

	printf("\nnumero1?: ");
	scanf("%d",&numero1);

	printf("\nnumero2?: ");
	scanf("%d",&numero2);

	respuesta = dividir(&resultado,numero1,numero2);
	if(respuesta == 0)
	{
		printf("El resultado es: %.2f\n",resultado);
	}
	else
	{
		printf("no es posible dividir por cero\n");
	}*/ //PRIMERA PARTE

	int edad;
	int peso;
	int respuesta;

	 respuesta = utn_getNumero(&edad,"Ingrese la edad\n","Error, la edad debe ser desde 0 a 199\n",1,199,2);
	if(respuesta == 0)
	{
		printf("La edad es: %d",edad);
	}
	else
	{
		if(respuesta == -1)
		{
			printf("error\n");
		}
		else
		{
			printf("Se supero la cantidad de intentos\n\n");
		}

	}

	system("pause");
	system("cls");

	respuesta = utn_getNumero(&peso,"Ingrese la peso\n","Error, la peso debe ser desde 0 a 500\n",0,500,2);
	if(respuesta == 0)
	{
		printf("El peso es: %d\n",peso);
	}
	else
	{
		if(respuesta == -1)
		{
			printf("error\n");
		}
		else
		{
			printf("Se supero la cantidad de intentos\n\n");
		}

	}

	system("pause");





	return EXIT_SUCCESS;
}

