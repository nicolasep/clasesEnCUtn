/*
 * Alumno.c
 *
 *  Created on: 26 may. 2020
 *      Author: nico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
#include "utn.h"

static int isValidNombre(char* cadena,int longitud);


Alumno* alumno_new(void)
{
	return (Alumno*)malloc(sizeof(Alumno));
}
Alumno* alumno_newParametros(char* nombre, float altura, int id)
{
	Alumno* punteroAlumno = alumno_new();
	if(punteroAlumno != NULL && nombre != NULL && altura > 0 && id > 0)
	{
		strncpy(punteroAlumno->nombre ,nombre,NOMBRE_LEN);
		punteroAlumno->altura = altura;
		punteroAlumno->id = id;

	}
	return punteroAlumno;
}
void alumno_delete(Alumno* this)
{

	if(this != NULL)
	{
		free(this);
	}
}
int alumno_setNombre(Alumno* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,NOMBRE_LEN))
		{
			strncpy(this->nombre ,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}
int alumno_getNombre(Alumno* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);

	}
	return retorno;
}
static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int alumno_deleteIndexArray(Alumno* arrayPunteros[],int limite, int indice)
{
	int retorno = -1;

	if(arrayPunteros != NULL && indice >= 0 && indice <=limite && arrayPunteros[indice] != NULL)
	{
		retorno = 0;
		alumno_delete(arrayPunteros[indice]);
		arrayPunteros[indice] = NULL;
	}
	return retorno;
}
int alumno_initArray(Alumno* arrayPunteros[],int limite)
{
	int retorno = -1;
	int i;

	if(arrayPunteros != NULL && limite > 0)
	{
		for(i=0; i<limite; i++)
		{
			arrayPunteros[i] = NULL;
		}
		retorno = 0;
	}
	return retorno;
}
int alumno_buscarLibreArray(Alumno* arrayPunteros[],int limite)
{
	int retorno = -1;
	int i;

	if(arrayPunteros != NULL && limite > 0)
	{
		retorno = -2;
		for(i=0; i<limite; i++)
		{
			if(arrayPunteros[i] == NULL)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int alumno_imprimirArray(Alumno* arrayPunteros[],int limite)
{
	int retorno = -1;
	int i;

	if(arrayPunteros != NULL && limite > 0)
	{
		printf("\n----LISTA ALUMNOS----\n");
		for(i=0; i<limite; i++)
		{
			if(arrayPunteros[i] != NULL)
			{
				printf("Nombre: %s - ID: %d - Altura: %.2f\n",arrayPunteros[i]->nombre,arrayPunteros[i]->id,arrayPunteros[i]->altura);
			}
		}
	}
	return retorno;
}
int alumno_buscarPorIdArray(Alumno* arrayPunteros[],int limite, int id)
{
	int retorno = -1;
	int i;

	if(arrayPunteros != NULL && limite > 0 && id >= 0)
	{
		retorno = -2;
		for(i=0; i<limite; i++)
		{
			if(arrayPunteros[i] != NULL && arrayPunteros[i]->id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int alumno_aregarAlumnoArray(Alumno* arrayPunteros[],int limite,char* nombre, float altura, int id)
{
	int retorno = -1;
	int indiceLibre;

	if(arrayPunteros != NULL && limite > 0 && id >= 0 && nombre != NULL)
	{
		indiceLibre = alumno_buscarLibreArray(arrayPunteros,limite);
		if(indiceLibre >= 0)
		{
			arrayPunteros[indiceLibre] = alumno_newParametros(nombre,altura,id);
			retorno = indiceLibre;
		}
	}
	return retorno;
}
int alumno_borarPorIdArray(Alumno* arrayPunteros[],int limite, int id)
{
	int retorno = -1;
	int indiceBorrar;

	if(arrayPunteros != NULL && limite > 0)
	{
		indiceBorrar = alumno_buscarPorIdArray(arrayPunteros,limite,id);
		if(indiceBorrar >= 0)
		{
			alumno_deleteIndexArray(arrayPunteros,limite,indiceBorrar);
			retorno = 0;
		}
	}
	return retorno;
}
