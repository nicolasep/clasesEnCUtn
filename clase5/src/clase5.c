/*
 ============================================================================
 Name        : clase5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define EDDADESSIZE 5

int main(void) {

	setbuf(stdout,NULL);
//EJERCICIO 1
/*PEDIRLE AL USUARIO 5 EDADES Y LUEGO IMPRIMIRLAS*/
	int numeros[EDDADESSIZE];

	int i;
	for(i=0; i<EDDADESSIZE; i++)
	{
		utn_getNumero((numeros+i),"Ingrese un numero: ","Error, debe ser un numero\n",-100000,100000,3);
	}

	int f;
	for(f=0; f<EDDADESSIZE; f++)
	{
		printf("La edad %d es: %d\n",f+1,numeros[f]);
	}

	system("pause");
	/* ECHO POR EL PROFE

	  // EJERCICIO: Pedirle al usuario 5 edades y LUEGO
	// imprimir las 5 edades. Definir un array de 5 posiciones.
	// y usar la funcion utn_getNumero() para pedir los valores


	int edad;

	int edades[EDADESSIZE];
	int i;

	// recorro para cargar en forma secuencial
	for(i=0; i<EDADESSIZE; i++)
	{
		if(utn_getNumero(&edad,"Ingrese edad:","Esta edad no va\n",1,120,3)==0)
		//if(utn_getNumero(&  (edades[i]) ,"Ingrese edad:","Esta edad no va\n",1,120,3)==0)
		{
			 //en edades escribo edad en la posicion "i"
			 edades[i] = edad; // guardo edad en el casillero "i"
		}
		else
		{
			printf("Sonaste no tenes idea lo que es una eda'\n");
		}
	}

	// recorro para imprimir
	for(i=0; i<EDADESSIZE; i++)
	{
		printf("%d ",edades[i]);
	}
	 */

	/*// pasaje por referencia // imprimirArray(&edad);
	void imprimirArray(int* e)
	{
		int j;
		*e = 9; // leo o escribo el valor
	}
	// pasaje por valor // imprimirArray(edad);
	void imprimirArray(int e)
	{
		int j;
		 // no puedo escribir la variable de afuera
		j = e + 7; // leo el valor
	}*/

	return EXIT_SUCCESS;
}

//void imprimirArray()

