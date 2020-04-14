/*
 * nico.h
 *
 *  Created on: 2 abr. 2020
 *      Author: Jesi
 */

#ifndef NICO_H_
#define NICO_H_

int getInt(char mensaje[]);
char getCadena(char mensaje[], int tam);
char getChar(char mensaje[]);
float getFloat(char mensaje[]);
int esTelefono(char telefono[]);
int esAlphaNumerico(char numero[]);
int esPalabra(char palabra[]);
int esNumerico(char palabra[]);

int esNumero(char cadena[]);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getNumero(int* pResultado, char* mensaje, char* mensajeError);

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int utn_getCadena(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int esEmail(char cadena[]);


#endif /* NICO_H_ */
