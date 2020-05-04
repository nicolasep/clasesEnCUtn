/*
Ejercicio 2.
Tomar el programa del ejercicio anterior y agregarle lo siguiente:
1) Una vez que el usuario ingreso los datos, preguntarle si
quiere aplicar un descuento del 25% al precio del producto.
Si acepta, calcular el nuevo precio.
2) Hacer una funcion que reciba la variable producto definida
y que imprima sus valores.
NOTA: Pude pasarse la variable producto por referencia o por
valor. ¿Cual es la diferencia?
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Producto.h"
#include <string.h>

int main(void) {

	Producto  producto;
	char respuesta[2]={'n','\0'};
	float descuento  = 1.25;

	/*
	char auxNombre[NOMBRE_LEN];
	char auxDescripcion[DESC_LEN];
	float auxPrecio;

	if(utn_getNombre(auxNombre,NOMBRE_LEN,"Ingrese nombre:","No!",2)==0)
	{
		//producto.nombre = auxNombre
		strncpy(producto.nombre,auxNombre,NOMBRE_LEN);

		if(utn_getNombre(auxDescripcion,DESC_LEN,"Description:","No!",2)==0)
		{
			// producto.descripcion = auxDescripcion
			strncpy(producto.descripcion,auxDescripcion,DESC_LEN);

			if(utn_getNumeroFlotante(&auxPrecio,"Ingresa precio:","No!",0.0,1000000.0,2)==0)
			{
				producto.precio = auxPrecio;
			}
		}
	}
	*/

	if(utn_getNombre(producto.nombre,CADENA1_LEN,"Ingrese nombre:","No!",2)==0)
	{

		if(utn_getNombre(producto.descripcion,DESC_LEN,"Description:","No!",2)==0)
		{

			if(utn_getNumeroFlotante(&producto.precio,"Ingresa precio:","No!",0.0,1000000.0,2)==0)
			{
				//printf("%s %s Precio:%f\n",producto.nombre,producto.descripcion,producto.precio);
				prod_imprimirProductoPorReferencia(&producto);

				//printf("Desea realizar un descuento del 25%? [s/n]\n");
				//fgets(&respuesta, sizeof(respuesta), stdin);
				if(utn_getNombre(respuesta,2,"Aplicar descuento?[s/n]:","No!",2)==0)
				{
					//if(respuesta[0]=='s')
					if(strncmp(respuesta,"s",2)==0)
					{
						printf("Aplico descuento!\n");
						producto.precio = producto.precio/descuento;

						prod_imprimirProducto(producto);
					}
				}

			}
		}
	}
	/*
	if(   utn_getNombre(producto.nombre,NOMBRE_LEN,"Ingrese nombre:","No!",2)==0
	   && utn_getNombre(producto.descripcion,DESC_LEN,"Description:","No!",2)==0
	   && utn_getNumeroFlotante(&producto.precio,"Ingresa precio:","No!",0.0,1000000.0,2)==0
	   )
	{

	}
	*/
	return EXIT_SUCCESS;
}






















