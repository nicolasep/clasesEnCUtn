/*
Ejercicio 1.
Definir un  nuevo tipo de dato que represente un producto.
El producto tiene un nombre una descripcion y un precio.
Hacer un programa que le pida al usuario los datos del producto
y los cargue en una variable del tipo Producto definida en la
funcion main.
Imprmir los campos de la variable producto para chequear que
esten cargadas correctamente.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Producto.h"


int main(void) {

	Producto  producto;

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

	if(utn_getNombre(producto.nombre,NOMBRE_LEN,"Ingrese nombre:","No!",2)==0)
	{

		if(utn_getNombre(producto.descripcion,DESC_LEN,"Description:","No!",2)==0)
		{

			if(utn_getNumeroFlotante(&producto.precio,"Ingresa precio:","No!",0.0,1000000.0,2)==0)
			{
				printf("%s %s Precio:%f\n",producto.nombre,producto.descripcion,producto.precio);
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
