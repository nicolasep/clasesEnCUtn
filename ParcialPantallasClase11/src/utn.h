/*
 * utn.h
 *
 *  Created on: 18 abr. 2020
 *      Author: Jesi
 */

#ifndef UTN_H_
#define UTN_H_

int printArray(int* pArray, int len);
void intSwap(int* pNumeroA, int* pNumeroB);
int ordenarArrayNumerico(int* pArray, int len);



int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);



int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


int utn_getCadena(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

int utn_getTelefono(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


int utn_getEmail(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

int utn_getDireccion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

int utn_getCuit(char* pResultado,int longitud ,char* mensaje, char* mensajeError, int reintentos);

#endif /* UTN_H_ */
