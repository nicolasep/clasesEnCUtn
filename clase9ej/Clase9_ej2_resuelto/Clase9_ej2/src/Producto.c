/*
 * Producto.c
 *
 *  Created on: Apr 23, 2020
 *      Author: ernesto
 */
#include "Producto.h"
#include <stdio.h>






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
