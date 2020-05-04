/*
 * Producto.c
 *
 *  Created on: Apr 23, 2020
 *      Author: ernesto
 */
#include "Producto.h"
#include <stdio.h>


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

void prod_imprimirProductoPorReferencia(Producto* pProd)
{
	printf("%s %s Precio:%f\n", pProd->nombre,
								pProd->descripcion,
								pProd->precio);

}
