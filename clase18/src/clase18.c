/*
 ============================================================================
 Name        : clase18.c
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
#include "utn.h"


#define QTY_ALUMNOS 100

int main(void) {
	setbuf(stdout,NULL);

	Alumno* arrayPunterosAlumno[QTY_ALUMNOS];


	if(!alumno_initArray(arrayPunterosAlumno,QTY_ALUMNOS))
	{
		printf("init ok\n");

		if(!alumno_aregarAlumnoArray(arrayPunterosAlumno,QTY_ALUMNOS,"Juan",1.85,111))
		{
			printf("ALTA OK\n");
		}
		if(!alumno_aregarAlumnoArray(arrayPunterosAlumno,QTY_ALUMNOS,"Ana",1.65,112))
		{
			printf("ALTA OK\n");
		}

		alumno_imprimirArray(arrayPunterosAlumno,QTY_ALUMNOS);

		if(!alumno_borarPorIdArray(arrayPunterosAlumno,QTY_ALUMNOS,111))
		{
			printf("BORRADO OK\n");
		}
		alumno_imprimirArray(arrayPunterosAlumno,QTY_ALUMNOS);
	}


	return EXIT_SUCCESS;
}
