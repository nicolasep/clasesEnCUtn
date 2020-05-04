/*
 * Alumno.c
 *
 *  Created on: Apr 21, 2020
 *      Author: Mauro
 */

#include "Alumno.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * \brief 	Imprimo el array de alumnos
 * \param pArray Puntero al array de alumnos
 * \param longitud Define el tamaño del array
 * \return Retorna 0 (EXITO) si OK y -1 (ERROR)
 *
 */
int imprimirArrayAlumnos(Alumno* pArray,int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty == 0 )
			{
				printf("\nNombre: %s - Legajo: %d - Altura: %f", pArray[i].nombre,pArray[i].legajo,pArray[i].altura);

			}
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief 	Inicializo el array de alumnos
 * \param pArray Puntero al array de alumnos
 * \param longitud Define el tamaño del array
 * \return Retorna 0 (EXITO) si OK y -1 (ERROR)
 *
 */
int inicializoArrayAlumnos(Alumno* pArray,int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}
