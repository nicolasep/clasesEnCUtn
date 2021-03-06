#include "Cliente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"



// MEMORIA DINAMICA

Cliente* cli_new(void)
{
	Cliente* p;

	p = (Cliente*)malloc(sizeof(Cliente));
	if(p!= NULL)
	{
		p->idCliente = 0;
		p->nombre[0]='\0';
		p->apellido[0]='\0';
		p->cuit[0]='\0';

		return p;
	}
	else
	{
		return NULL;
	}

}

int cli_inicializarArrayPunteros(Cliente** array,int len)
//int cli_inicializarArrayPunteros(Cliente* array[],int len) es equivalente
{
	int retorno = -1;
	int i;
	if(array != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			*(array+i) = NULL;
		}
		retorno = 0;
	}


	return retorno;
}

int cli_getEmptyIndexConArrayPunteros(Cliente** array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(*(array+i) == NULL)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
int cli_altaArrayConPunteros(Cliente** array,int limite, int indice, int* idCliente)
{
	int respuesta = -1;
	;
	Cliente* pC = cli_new();

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idCliente != NULL && pC != NULL)
	{
		if(	utn_getNombre(pC->nombre,NOMBRE_LEN,"\nNombre cliente?\n","\nValor incorrecto\n\n",2) == 0 &&
			utn_getNombre(pC->apellido,APELLIDO_LEN,"\nApellido cliente?\n","\nValor incorrecto\n\n",2) == 0 &&
			utn_getCuit(pC->cuit, CUIT_LEN, "\nIngrese cuit sin guiones\n", "\nValor incorrecto\n", 2)==0)
		{
			respuesta = 0;
			pC->idCliente = *idCliente;
			*(array+indice) = pC;

			(*idCliente)++;
			respuesta = 0;
		}
	}
	return respuesta;
}
int cli_imprimirClienteConPunteros(Cliente* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL/* && pElemento->isEmpty == 0*/)
	{
		retorno=0;
		printf("\nID: %d - %s - %s - %s",pElemento->idCliente
										,pElemento->nombre
										,pElemento->apellido
										, pElemento->cuit);
	}
	return retorno;
}
int cli_imprimirClientesConPunteros(Cliente** array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			cli_imprimirClienteConPunteros(*(&array[i]));
		}
	}
	return respuesta;
}
int cli_altaForzadaArrayConPunteros(Cliente** array,int limite, int indice, int* idCliente,char* nombre,char* apellido, char* cuit)

{
	int respuesta = -1;
	Cliente* bufferCliente = cli_new();

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idCliente != NULL && bufferCliente != NULL)
	{
			strncpy(bufferCliente->nombre,nombre,NOMBRE_LEN);
			strncpy(bufferCliente->apellido,apellido,APELLIDO_LEN);
			strncpy(bufferCliente->cuit,cuit,CUIT_LEN);
			respuesta = 0;
			bufferCliente->idCliente = *idCliente;
			bufferCliente->isEmpty = 0;
			*(array+indice) = bufferCliente;
			(*idCliente)++;
	}
	return respuesta;
}

int cli_modificarArrayConPunteros(Cliente** array,int limite, int indice)
{
	int respuesta = -1;
	Cliente* AuxBuffer = cli_new();

	if(array != NULL && limite > 0 && indice < limite && indice >= 0)
	{
		if(	utn_getNombre(AuxBuffer->nombre,NOMBRE_LEN,"\nNombre cliente?\n","\nValor incorrecto\n\n",2) == 0 &&
			utn_getNombre(AuxBuffer->apellido,APELLIDO_LEN,"\nApellido cliente?\n","\nValor incorrecto\n\n",2) == 0 &&
			utn_getCuit(AuxBuffer->cuit, CUIT_LEN, "\nIngrese cuit sin guiones\n", "\nValor incorrecto\n", 2)==0)
		{
			respuesta = 0;
			AuxBuffer->idCliente = array[indice]->idCliente;

			array[indice] = AuxBuffer;
		}
	}
	return respuesta;
}




//////////////////////////
//MEMORIA ESTATICA


/**
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al CLIENTE que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimir(Cliente* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s - %s - %s",pElemento->idCliente
										,pElemento->nombre
										,pElemento->apellido
										, pElemento->cuit);
	}
	return retorno;
}

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser impreso
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimirArray(Cliente* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			cli_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser inicializado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_inicializarArray(Cliente* array,int limite)
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
 * \brief Da de alta un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_altaArray(Cliente* array,int limite, int indice, int* idCliente)
{
	int respuesta = -1;
	Cliente bufferAux;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idCliente != NULL)
	{
		if(	utn_getNombre(bufferAux.nombre,NOMBRE_LEN,"\nNombre cliente?\n","\nValor incorrecto\n\n",2) == 0 &&
			utn_getNombre(bufferAux.apellido,APELLIDO_LEN,"\nApellido cliente?\n","\nValor incorrecto\n\n",2) == 0 &&
			utn_getCuit(bufferAux.cuit, CUIT_LEN, "\nIngrese cuit sin guiones\n", "\nValor incorrecto\n", 2)==0)
		{
			respuesta = 0;
			bufferAux.idCliente = *idCliente;
			bufferAux.isEmpty = 0;
			array[indice] = bufferAux;
			(*idCliente)++;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de clientes a ser modificado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_modificarArray(Cliente* array,int limite, int indice)
{
	int respuesta = -1;
	Cliente AuxBuffer;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(AuxBuffer.nombre,NOMBRE_LEN,"\nNombre cliente?\n","\nValor incorrecto\n\n",2) == 0 &&
			utn_getNombre(AuxBuffer.apellido,APELLIDO_LEN,"\nApellido cliente?\n","\nValor incorrecto\n\n",2) == 0 &&
			utn_getCuit(AuxBuffer.cuit, CUIT_LEN, "\nIngrese cuit sin guiones\n", "\nValor incorrecto\n", 2)==0)
		{
			respuesta = 0;
			AuxBuffer.idCliente = array[indice].idCliente;
			AuxBuffer.isEmpty = 0;
			array[indice] = AuxBuffer;
		}
	}
	return respuesta;
}



/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array cliente Array de cliente
* \param limite Tamaño del array
* \param valorBuscado ID a encontrar
* \return Return (-1) si no encuentra el valor buscado sino, devuelve el indice donde se encuentra el valor buscado
*
*/
int cli_buscarId(Cliente array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 0 && array[i].idCliente == valorBuscado)
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
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el indice de la posicion vacia 0 -1 (ERROR)
 *
 */
int cli_getEmptyIndex(Cliente* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
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
 * \brief Da de alta un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la cliente
 * \param nombre Nombre a ser asignado al cliente
 * \param apellido Apellido a ser asignado al cliente
 * \param cuit Cuit a ser asignado al cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_altaForzadaArray(Cliente* array,int limite, int indice, int* idCliente,char* nombre,char* apellido, char* cuit)

{
	int respuesta = -1;
	Cliente bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idCliente != NULL)
	{
			strncpy(bufferCliente.nombre,nombre,NOMBRE_LEN);
			strncpy(bufferCliente.apellido,apellido,APELLIDO_LEN);
			strncpy(bufferCliente.cuit,cuit,CUIT_LEN);
			respuesta = 0;
			bufferCliente.idCliente = *idCliente;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
			(*idCliente)++;
	}
	return respuesta;
}











