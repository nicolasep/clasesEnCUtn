/*
 * musicos.h
 *
 *  Created on: 20 abr. 2020
 *      Author: Jesi
 */

#ifndef MUSICOS_H_
#define MUSICOS_H_
typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	int edad;
	int idOrquesta;
	int idInstrumnto;
	int isEmpty;
}musico;


#endif /* MUSICOS_H_ */
