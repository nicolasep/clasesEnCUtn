/*
 ============================================================================
 Name        : clase8SegundaParte.c
 Author      : nicolas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"


#define QTY_PERSONAS 1000




int main(void) {

	setbuf(stdout,NULL);


	Alumno auxiliar;
	Alumno arrayAlumnos[QTY_PERSONAS];

	auxiliar.altura = 2.04;
	auxiliar.legajo = 25;
	strcpy(auxiliar.nombre,"JUAN");
	auxiliar.isEmpty = 0;

	printf("Nombre: %s - Legajo: %d - Altura: %.2f",auxiliar.nombre,auxiliar.legajo,auxiliar.altura);


	arrayAlumnos[14] = auxiliar;


	imprimirArrayAlumnos(arrayAlumnos,QTY_PERSONAS);


	return EXIT_SUCCESS;
}
