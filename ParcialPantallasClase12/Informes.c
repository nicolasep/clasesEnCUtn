/*
 * Informes.c
 *
 *  Created on: May 5, 2020
 *      Author: Mauro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pantalla.h"
#include "Contratacion.h"
#include "utn.h"

static const char TXT_TIPOS[2][4]={"LCD","LED"};

int info_imprimirPantallasContratadasByCuit(Contratacion* arrayContrataciones,int limiteContrataciones,Pantalla* arrayPantallas,int limitePantallas,char* auxiliarCuit)
{
	int retorno = -1;
	int i;
	int indiceArrayPantalla;
	int idPantalla;
	if(arrayContrataciones != NULL && limiteContrataciones > 0 && arrayPantallas != NULL && limitePantallas > 0 && auxiliarCuit != NULL)
	{
		for(i=0;i<limiteContrataciones;i++)
		{
			if(strncmp(arrayContrataciones[i].cuit,auxiliarCuit,CUIT_LEN) == 0)
			{
				retorno = 0;
				idPantalla = arrayContrataciones[i].idPantalla;
				indiceArrayPantalla = pan_buscarId(arrayPantallas,limitePantallas,idPantalla);

				printf("\nID: %d - Archivo: %s - Cuit: %s - Dias: %d - IdPantalla: %d",arrayContrataciones[i].id,arrayContrataciones[i].archivo,arrayContrataciones[i].cuit,arrayContrataciones[i].dias,arrayContrataciones[i].idPantalla);
				printf(" - %s - %s - %.2f - %s",arrayPantallas[indiceArrayPantalla].nombre,arrayPantallas[indiceArrayPantalla].direccion,arrayPantallas[indiceArrayPantalla].precio,TXT_TIPOS[arrayPantallas[indiceArrayPantalla].tipo]);
			}
		}
	}
	return retorno;
}
