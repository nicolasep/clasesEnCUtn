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

	float resultado;
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
	}



	return EXIT_SUCCESS;
}

