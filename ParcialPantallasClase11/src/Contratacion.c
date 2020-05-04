#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Contratacion.h"
#include "utn.h"




/**
 * \brief Imprime los datos de una contratacion
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_imprimir(Contratacion* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s - %s - %d - ",pElemento->id,pElemento->cuit,pElemento->archivo,pElemento->dias/*,TXT_TIPOS[pElemento->idPantalla]*/);
	}
	return retorno;
}

/**
 * \brief Imprime el array de contratacioness
 * \param array Array de contratacioness a ser actualizado
 * \param limite Limite del array de contratacioness
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_imprimirArray(Contratacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			con_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de contratacioness a ser actualizado
 * \param limite Limite del array de contratacioness
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_inicializarArray(Contratacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un contrataciones en una posicion del array
 * \param array Array de contratacioness a ser actualizado
 * \param limite Limite del array de contratacioness
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al contrataciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_altaArray(Contratacion* array,int limite, int indice, int* id, Pantalla* arrayP, int limiteP)
{
	int respuesta = -1;
	Contratacion bufferContratacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getCuit(bufferContratacion.cuit,CUIT_LEN,"\nIngrese cuit: ","\nError, no es un cuit valido\n",2) &&
			utn_getDescripcion(bufferContratacion.archivo,ARCHIVO_LEN,"\nArchivo?\n","\nERROR\n",2) == 0 &&
			pan_imprimirArray(arrayP,limiteP)==0&&
			utn_getNumero(&bufferContratacion.idPantalla,"\nID pantalla?\n","\nERROR\n",1,limiteP,2) == 0 &&
			pan_buscarIdActivo(arrayP,limiteP,bufferContratacion.idPantalla)==0)
		{
			respuesta = 0;
			bufferContratacion.id = *id;
			bufferContratacion.isEmpty = 0;
			array[indice] = bufferContratacion;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un contratacion en una posicion del array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_modificarArray(Contratacion* array,int limite, int indice)
{
	int respuesta = -1;
	Contratacion bufferContratacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(bufferContratacion.archivo,ARCHIVO_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getDni(bufferContratacion.cuit,CUIT_LEN,"\nDNI?\n","\nERROR\n",2) == 0 )
		{
			respuesta = 0;
			bufferContratacion.id = array[indice].id;
			bufferContratacion.isEmpty = 0;
			array[indice] = bufferContratacion;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int con_bajaArray(Contratacion* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array contratacion Array de contratacion
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int con_buscarId(Contratacion array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de contrataciones
 * \param limite Limite del array de contrataciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int con_getEmptyIndex(Contratacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Ordenar el array de contrataciones por nombre
 * \param array Array de contrataciones
 * \param limite Limite del array de contrataciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int con_ordenarPorNombre(Contratacion* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Contratacion buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].archivo,array[i+1].archivo,ARCHIVO_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}


/**
 * \brief Ordenar el array de contrataciones por nombre y altura
 * \param array Array de contrataciones
 * \param limite Limite del array de contrataciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int cli_ordenarPorNombreAltura(Contratacion* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Contratacion buffer;
	int auxiliarCmp;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
/*
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
				else if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) == 0)
				{
					if(array[i].altura < array[i+1].altura)
					{
						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i+1];
						array[i+1]=buffer;
					}
				}
*/
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(array[i].archivo,array[i+1].archivo,ARCHIVO_LEN);
				if(	 auxiliarCmp > 0 ||
					(auxiliarCmp == 0 && array[i].dias < array[i+1].dias) )
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}



















