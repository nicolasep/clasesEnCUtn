/*
Ejercicio 1.
Definir un tipo nuevo tipo de dato que represente un producto.
El producto tiene un nombre una descripcion y un precio.
Hacer un programa que le pida al usuario los datos del producto
y los cargue en una variable del tipo Producto definida en la
funcion main.
Imprmir los campos de la variable producto para chequear que
esten cargadas correctamente.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn2.h"
#include "Producto.h"



int main(void) {

	setbuf(stdout,NULL);

	//Producto producto;
	Producto producto;



	if(  utn_getCadena(producto.nombre,"Ingrese nombre: ","Error\n",3,51,2)==0
	  && utn_getCadena(producto.descripcion,"Ingrese descripcion: ","Error\n",3,51,2)==0
	  && utn_getNumeroFlotante(&producto.precio,"Ingrese precio: ","Error\n",0,10000,2)==0)
	{
		printf("%s %s Precio: %.2f\n",producto.nombre,producto.descripcion,producto.precio);

	}




	return EXIT_SUCCESS;
}
/*
int addProducto(Producto* list, int len,int id)
{
	int retorno = -1;
	Producto aux;
	char nombre[51];
	char descripcion[51];
	float precio;
	int arrayResultados[3];



	if(list != NULL && len > 0)
	{
		if(utn_getCadena(nombre,"Ingrese nombre del producto: ","Error, ingrese solo letras\n",3,50,3)
		 &&utn_getCadena(descripcion,"Ingrese descripcion del producto: ","Error, ingrese solo letras\n",3,50,3)
		 &&arrayResultados[2] = utn_getNumeroFlotante(precio,"Ingrese precio: ","Error, no es un numero admitido\n",1,100000,3))
		{

		}



	}



	return retorno;
}

int printProductos(Producto* list, int len)
{
	int retorno = -1;
	int mostroMensaje = 0;
	int i;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				if(mostroMensaje==0)
				{
					printf("ID\tNOMBRE\tAPELLIDO\tSALARIO\tSECTOR\n");

				 mostroMensaje = 1;
				}
				retorno = printEmployee(list,len,i);
			}

		}
	}
	return retorno;
}*/
