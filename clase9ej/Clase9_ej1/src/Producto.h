/*
 * Producto.h
 *
 *  Created on: 23 abr. 2020
 *      Author: nico
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef struct
{
	int id;
	char nombre[51];
	char descripcion[51];
	float precio;
	int isEmpty;
}Producto;




#endif /* PRODUCTO_H_ */
