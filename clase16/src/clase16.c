/*
 ============================================================================
 Name        : clase16.c
 Author      : nicolas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef int (*tpSaludar)(char*,int);

int saludarEsp(char* mensaje, int numero)
{
	printf("hola %s - %d\n",mensaje,numero);

	return 0;
}
int saludarIng(char* mensaje, int numero)
{
	printf("hello %s - %d\n",mensaje,numero);

	return 0;
}
void saludo(char* mensaje, int numero,tpSaludar pFuncSaludar)
{
	pFuncSaludar(mensaje,numero);
}

int main(void) {

	setbuf(stdout,NULL);


	saludo("AAA",222,saludarEsp);
	saludo("AAA",222,saludarIng);

	return EXIT_SUCCESS;
}
