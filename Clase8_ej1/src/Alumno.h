/*
 * Alumno.h
 *
 *  Created on: Apr 21, 2020
 *      Author: Mauro
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

int imprimirArrayAlumnos(Alumno* pArray,int limite);
int inicializoArrayAlumnos(Alumno* pArray,int limite);

#endif /* ALUMNO_H_ */
