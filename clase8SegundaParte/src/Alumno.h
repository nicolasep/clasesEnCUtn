/*
 * Alumno.h
 *
 *  Created on: 21 abr. 2020
 *      Author: nico
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

typedef struct
{
	int legajo;
	char nombre[51];
	float altura;
	int isEmpty;
}Alumno;

int imprimirArrayAlumnos(Alumno* pArray, int limite);
int inicializoArray(Alumno* pArray, int limite);

#endif /* ALUMNO_H_ */
