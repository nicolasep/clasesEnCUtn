/*
 * Alumno.c
 *
 *  Created on: 21 abr. 2020
 *      Author: nico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"

int inicializoArray(Alumno* pArray, int limite)
{
	int i;
	for(i=0;i<limite;i++)
	{
		pArray->isEmpty= 1;
	}

	return 1;
}


int imprimirArrayAlumnos(Alumno* pArray, int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0; i<limite; i++)
		{
			if(pArray[i].isEmpty==0)
			{
				printf("\nNombre: %s - Legajo: %d - Altura: %.2f",pArray[i].nombre,pArray[i].legajo,pArray[i].altura);
			}

		}
		retorno = 0;
	}

	return retorno;
}
