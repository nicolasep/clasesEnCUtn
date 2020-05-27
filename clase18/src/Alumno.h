/*
 * Alumno.h
 *
 *  Created on: 26 may. 2020
 *      Author: nico
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
#define NOMBRE_LEN 50

typedef struct
{
	char nombre[NOMBRE_LEN];
	float altura;
	int id;

}Alumno;

Alumno* alumno_new(void);
Alumno* alumno_newParametros(char* nombre, float altura, int id);
void alumno_delete(Alumno* this);


int alumno_deleteIndexArray(Alumno* arrayPunteros[],int limite, int indice);
int alumno_initArray(Alumno* arrayPunteros[],int limite);
int alumno_buscarLibreArray(Alumno* arrayPunteros[],int limite);
int alumno_imprimirArray(Alumno* arrayPunteros[],int limite);
int alumno_buscarPorIdArray(Alumno* arrayPunteros[],int limite, int id);
int alumno_aregarAlumnoArray(Alumno* arrayPunteros[],int limite,char* nombre, float altura, int id);
int alumno_borarPorIdArray(Alumno* arrayPunteros[],int limite, int id);


#endif /* ALUMNO_H_ */
