/*
 ============================================================================
 Name        : practicaFuncionesW.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nico.h"

int main(void) {


	setbuf(stdout,NULL);

	//char numero[21];
	//int esNum;
	//int numeros;

/*
	printf("Ingrese algo: ");
	fflush(stdin);
	//scanf("%s",&numero);
	gets(numero);

	esNum = esNumero(numero);
	printf("\n\n%d\n",esNum);

	*/

/*
	esNum  = utn_getNumero(&numeros,"Ingrese un numero: ","Error, deben ser numeros",-1000000,100000,3);
	if(esNum == 0)
	{
		printf("el numero ingresado es: %d\n",numeros);
	}
	else
	{
		printf("se supero la cantidad de intentos\n");
	}
	//printf("\n\n%d\n",esNum);

	 */

	char buffer[100];
	int salioBien;

	salioBien = utn_getCadena(&buffer,"Ingrese una palabra: ","Error, deben ser letras\n",1,50,3);
	if(salioBien==0)
	{
		printf("La palabra es: %s\n",buffer);
	}
	else
	{
		printf("se supero la cantidad de intentos\n");
	}




	system("pause");






	return EXIT_SUCCESS;
}
