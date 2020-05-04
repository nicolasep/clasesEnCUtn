/*
Ejercicio 4.
Tomar el ejercicio 3 y realizar una funcion que reciba el
array, un indice, y le permita al usuario cargar los datos
 en el item de la posicion especificada por el indice.

 */
/*
Ejercicio 5.
Tomar el ej 4 y agregar a la biblioteca producto funcion que
me devuelva el indice de un item vacio (sin cargar) o -1
en caso de error o de que no haya mas lugar.
Esta funcion debe recibir el array y su longitud:

int prod_getEmptyIndex(Producto lista[], int len);

 */
/*
Ejercicio 6.
Tomar la biblioteca producto del ej5  y realizar un programa
con un menu de dos opciones:

    a) Cargar un producto
    b) Imprimir lista productos

Se debera utilizar la funcion que devuelve una posicion vacia
para indicar en que posicion del array se guardaran los datos
ingresados.

 */
/*
Ejercicio 7.
Agregar al tipo de dato el campo ID que represente un
identificador unico. Modificar el codigo anterior para
que el ID se genere automaticamente. Se debera cargar
el ID automaticamente al cargar un producto, y se debera
 imprimir al imprimir la lista.

 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Producto.h"

#define PROD_LEN	100

int main(void) {
	setbuf(stdout,NULL);

	//int indice=0;

	Producto productos[PROD_LEN];
	prod_initArray(productos,PROD_LEN);
	int lastId = 1;
	int opcion;
	harkodearProductos(productos,PROD_LEN,&lastId);

	/*if(prod_cargarProducto(productos,PROD_LEN,indice)==1)
	{
		printf("carga exitosa en posicion %d",indice);
	}*/

	do
	{
		opcion = menuPrincipal();

		switch(opcion)
		{
		case 1:
			if(!prod_cargarProductov2(productos,PROD_LEN,lastId))
			{
				lastId ++;
			}
			break;
		case 2:
			if(lastId > 1)
			{
				prod_imprimirProductos(productos,PROD_LEN);
			}
			else
			{
				printf("\nPRIMERO DEBE CARGAR PRODUCTOS\n");
			}

			break;
		}

	}while(opcion !=0);

	return EXIT_SUCCESS;
}
