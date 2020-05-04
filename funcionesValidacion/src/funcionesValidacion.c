/*
 ============================================================================
 Name        : funcionesValidacion.c
 Author      : nicolas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

	setbuf(stdout,NULL);
	char direccion[51];

	if(!utn_getDireccion(direccion,51,"Ingrese direccion: ","No es una direccion valida\n",3))
	{
		printf("La direccion es: %s",direccion);
	}







	return EXIT_SUCCESS;

}
