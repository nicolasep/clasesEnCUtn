/*
 * Producto.h
 *
 *  Created on: Apr 23, 2020
 *      Author: ernesto
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#define CADENA1_LEN	50
#define DESC_LEN	50

//defino el tipo de dato Producto
/*
struct S_Producto {
	char nombre[NOMBRE_LEN];
	char descripcion[DESC_LEN];
	float precio;
};
typedef	struct S_Producto Producto;
*/

typedef struct {
	char nombre[CADENA1_LEN];
	char descripcion[DESC_LEN];
	float precio;
}Producto;

void prod_imprimirProducto(Producto prod);


#endif /* PRODUCTO_H_ */
