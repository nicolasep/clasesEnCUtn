/*
 ============================================================================
 Name        : funcionesUtnOk.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void) {

	setbuf(stdout,NULL);

	char palabra[30];

	/*
	if(utn_getTelefono(&palabra,"Ingrese telefono con maximo un guion: ","Error\n",6,12,3)==0)
	{
		printf("el telefono esta bien, es: %s",palabra);
	}
	else
	{
		printf("hubo error\n");
	}

*/
	if(utn_getEmail(&palabra,"Ingrese email: ","Error\n",6,20,3)==0)
		{
			printf("el email esta bien, es: %s",palabra);
		}
		else
		{
			printf("hubo error\n");
		}
/*
	if(utn_getCadena(&palabra,"Ingrese palabra: ","Error\n",1,20,3)==0)
			{
				printf("la palabra esta bien, es: %s",palabra);
			}
			else
			{
				printf("hubo error\n");
			}*/
	return EXIT_SUCCESS;
}

