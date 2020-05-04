/*
 * Producto.c
 *
 *  Created on: Apr 23, 2020
 *      Author: ernesto
 */
#include "Producto.h"
#include "utn.h"
#include <stdio.h>
#include <string.h>


int menuPrincipal()
{
	int opcion;
	printf("ELIJA UNA OPCION\n");
	printf("1- CARGAR PRODUCTO\n");
	printf("2- IMPRIMIR LISTADO DE PRODUCTOS\n");
	printf("INGRESE 0 PARA SALIR\n");
	utn_getNumero(&opcion,"OPCION: ","OPCION INCORRECTA\n",0,2,4);
	return opcion;
}


//EJERCICIO 5
int prod_getEmptyIndex(Producto* lista, int len)
{
	int indice = -1;
	int i;

	if(lista != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(lista[i].isEmpty == 1)
			{
				indice = i;
				break;
			}
		}
	}


	return indice;
}

int prod_cargarProducto(Producto* pArray,int limite,int indice)
{
	int retorno = -1;
	char auxNombre[50];
	char auxDescripcion[50];
	float auxPrecio;
	//int i;
	if(pArray != NULL && limite>0 && indice<limite)
	{
		if(!utn_getNombre(auxNombre,50,"\nIngrese nombre: ","Error nombre",2))
		{
			if(!utn_getNombre(auxDescripcion,50,"\nIngrese Descripcion: ","Error descripcion",2))
			{
				if(!utn_getNumeroFlotante(&auxPrecio,"Ingrese Precio","Error precio",0.00,900.50,2))
				{
					strncpy(pArray[indice].nombre,auxNombre,50);
					strncpy(pArray[indice].descripcion,auxDescripcion,50);
					pArray[indice].precio=auxPrecio;
					pArray[indice].isEmpty=0;
					retorno = 0 ;
				}
			}
		}
	}
	return retorno;
}

//ACTUALIZADO CON EJERCICIO 5
int prod_cargarProductov2(Producto* pArray,int limite,int lastId)
{
	int retorno = -1;
	Producto prodAux;
	int indiceArray = prod_getEmptyIndex(pArray,limite);

	//int i;
	if(pArray != NULL && limite>0 && indiceArray != -1)
	{
		if(!utn_getNombre(prodAux.nombre,50,"\nIngrese nombre: ","Error nombre",2))
		{
			if(!utn_getNombre(prodAux.descripcion,50,"\nIngrese Descripcion: ","Error descripcion",2))
			{
				if(!utn_getNumeroFlotante(&prodAux.precio,"Ingrese Precio","Error precio",1.00,200000.50,2))
				{
					pArray[indiceArray] = prodAux; // copia magica

					pArray[indiceArray].isEmpty=0;
					pArray[indiceArray].id = lastId;
					retorno = 0 ;
				}
			}
		}
	}
	return retorno;
}


//int prod_initArray(Producto array[], int len)
int prod_initArray(Producto* array, int len)
{
	int ret=-1;
	if(array!=NULL && len>=0)
	{
		// iterar el array y por cada elemento
		// cargar el campo isEmpty = 1
		int i;
		for(i=0; i<len; i++)
		{
			//i : indice del array 0...99
			// array[i] es una variable Producto
			array[i].isEmpty=1;
		}
		ret=0;
	}

	return ret;
}









void prod_imprimirProducto(Producto prod)
{
	printf("%s %s Precio:%f\n",prod.nombre,
			                   prod.descripcion,
							   prod.precio);

}
//PARTE EJERCICIO 6
int prod_imprimirProductos(Producto* pProd,int len)
{
	int retorno = -1;
	int mostroTitulo = 0;
	int i;

	if(pProd != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(pProd[i].isEmpty == 0)
			{
				if(mostroTitulo == 0)
				{
					printf("ID   NOMBRE     DESCRIPCION    PRECIO\n\n");
					mostroTitulo = 1;
				}
				prod_imprimirProductoPorReferencia(pProd+i);
			}
		}
	}


	return retorno;
}
void prod_imprimirProductoPorReferencia(Producto* pProd)
{
	printf("%d %10s %12s     %.2f\n",  pProd->id,
									pProd->nombre,
									pProd->descripcion,
									pProd->precio);

}

void harkodearProductos(Producto* pProd, int len, int* lastId)
{
	char nombres[6][21]={{"MONITOR"},{"GABINETE"},{"MAUSE"},{"PARLANTES"},{"TECLADO"}};
	char descripciones[6][21]={{"SAMSUNG"},{"TERMALTAKE"},{"GENIUS"},{"LOGITECH"},{"MICROSOFT"}};
	float precios[6]={12000.0,6852.4,1240.6,632.1,1702.9};
	int indiceArray;
	int i;

	if(pProd != NULL && len > 0 && lastId > 0)
	{
		for(i=0; i<5;i++)
		{
			indiceArray = prod_getEmptyIndex(pProd,len);

			if(indiceArray != -1)
			{
				pProd[indiceArray].id=*lastId;
				strcpy(pProd[indiceArray].nombre,nombres[i]);
				strcpy(pProd[indiceArray].descripcion,descripciones[i]);
				pProd[indiceArray].precio=precios[i];
				pProd[indiceArray].isEmpty = 0;
				*lastId+=1;
			}
		}

	}

}
