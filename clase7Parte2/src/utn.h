/*
 * utnPrueba.h
 *
 *  Created on: 16 abr. 2020
 *      Author: Jesi
 */

#ifndef UTN_H_
#define UTN_H_

int validarNumeroFloat(char* stringRecibido);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getInt(int* pResultado);
//int esNumerica(char* cadena);
//int myGets(char* cadena, int longitud);
//int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int esNumero(char cadena[]);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

#endif /* UTN_H_ */
