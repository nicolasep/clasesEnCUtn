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

#define EDADESSIZE 5

void imprimirArray(int listaDeEdades[], int len);
void calcularPromedio(int arrayInt[], int len, float* pResultado);

int main(void) {

	setbuf(stdout,NULL);

	/*
    EJERCICIO 1
     PEDIRLE AL USUARIO 5 EDADES Y LUEGO IMPRIMIRLAS*/
	int numeros[EDADESSIZE];
	float promedio;

	int i;
	for(i=0; i<EDADESSIZE; i++)
	{
		utn_getNumero((numeros+i),"Ingrese un numero: ","Error, debe ser un numero\n",-100000,100000,3);
	}

	imprimirArray(numeros,EDADESSIZE);

    /*
	int f;
	for(f=0; f<EDADESSIZE; f++)
	{
		printf("La edad %d es: %d\n",f+1,numeros[f]); es lo mismo que la funcion imprimirArray
	}*/

	calcularPromedio(numeros,EDADESSIZE,&promedio);//ejercicio 2

	printf("El promedio es: %.2f\n",promedio);


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

	/*void imprimirArray(int listaDeEdades[],int len);


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
	imprimirArray(edades,EDADESSIZE);


}

//EL NOMBRE DEL ARRAY ES LA DIRECCCION DE MEMORIA DONDE COMIENZA EL ARRAY
//Al recibir un array, tambien se recibe su tamaño

// recibir array -> por referencia (no se hace una copia, es el meesmo)
//void imprimirArray(int* listaDeEdades)
void imprimirArray(int listaDeEdades[],int len)
{
	int i;
	for(i=0; i<len; i++)
	{
		printf("%d ",listaDeEdades[i]);
	}
}*/

	//EJERCICIO HACER UNA FUNCION QUE CALCULE EL PROMEDIO Y LO DEVUELVA



	system("pause");

	return EXIT_SUCCESS;
}

void imprimirArray(int listaDeEdades[], int len)
{
	int i;
	for(i=0; i<len; i++)
		{
			printf("%d ",listaDeEdades[i]);
		}
}
void calcularPromedio(int arrayInt[], int len, float* pResultado)//ejercicio 2
{
	int acumulador = 0;
	float promedio;

	int i;
	if(pResultado != NULL && arrayInt != NULL && len > 0)
	{
		for(i=0; i< len; i++)
		{
			acumulador += arrayInt[i];
		}
		promedio = (float) acumulador/len;
		*pResultado = promedio;
	}

}
