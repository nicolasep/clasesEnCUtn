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



int myGets(char* cadena, int len);
int esNumerica(char* cadena);
int getInt(int* pResultado);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int getFloat(float* pResultado);
int validarNumeroFloat(char* cadena);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int validarCadena(char* cadena);
int getCadena(char* pResultado);
int utn_getCadena(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int esTelefono(char* telefono);
int getTelefono(char* pResultado);
int utn_getTelefono(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int esEmail(char* cadena);
int getEmail(char* pResultado);
int utn_getEmail(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);




#endif /* UTN_H_ */
