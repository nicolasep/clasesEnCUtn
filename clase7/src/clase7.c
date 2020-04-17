/*
 ============================================================================
 Name        : clase7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Ejercicio 1:
 * Escribir la funcion calcularMayor(). La funcion debe recibir dos
 * numeros int y devolver por referencia, el numero mayor.
 * La funcion debe retornar un 1 si encontro un mayor, o un 0
 * si ambos numeros son iguales.
 */
/*
 * Ejercicio 2:
 * crear un programa que permita registrar el valor de temperatura maxima de cada dia de un mes.
 * Definir un array de floats de 31 posiciones. Cada posicion corresponderá a un dia
 * del mes. Hacer un programa con un menu de dos opciones, 1.imprimir array y 2.cargar array
 * Al elegir la opcion 1, se imprimira el indice y el valor de cada posicion del array.
 * Al elegir la opcion 2 que le pida al usuario que ingrese un numero de dia (1 a 31)
 * y luego que ingrese un valor de temperatura. Almacenar el valor en el indice correspondiente
 * Ambas opciones deben volver al menu ppal.
 * Utilizar la funcion utn_getNumeroFloat() de la biblioteca utn.h
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utnPrueba.h"
#define TAM 31



int calcularMayor(int* pResultado, int num1, int num2);
void imprimirArray(float* array, int tam);
int cargarArray(float* array, int tam);
void inicializar(float* array, int tam);




int main(void) {
	setbuf(stdout,NULL);
	//EJERCICIO 2

	float temperaturas[TAM];
	int salir = 1;
	int opcion;

	inicializar(temperaturas,TAM);

	do
	{

		printf("Elija una opcion\n");
		printf("1- Imprimir Temperaturas\n");
		printf("2- Cargar temperaturas\n");
		printf("3- Salir\n");
		scanf("%d",&opcion);

		switch(opcion)
		{
		case 1:
			imprimirArray(temperaturas,TAM);
			break;
		case 2:
			cargarArray(temperaturas,TAM);
			break;
		case 3:
			salir = 0;

		}
		system("cls");
	}while(salir);

	//EJERCICIO 1
	/*int resultado;
	int num1,num2;

	// Pedir dos numeros al usuario con utn_getNumber() y guardarlos
	// en num1 y num 2
	utn_getNumero(&num1,"Ingrese un numero: ","Error, debe ser un numero!!! ",-100000,10000,2);
	utn_getNumero(&num2,"Ingrese un numero: ","Error, debe ser un numero!!! ",-100000,10000,2);

	// luego llamo a la funcion calcularMayor()
	if(calcularMayor(&resultado,num1,num2)==0)
	{
		printf("Los numeros son iguales\n");
	}
	else
	{
		printf("El mayor es:%d\n",resultado);
	}*/



	return EXIT_SUCCESS;
}
int calcularMayor(int* pResultado, int num1, int num2)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		if(num1 > num2)
		{
		 *pResultado = num1;
		 retorno = 1;
		}
		else if(num2 > num1)
		{
			*pResultado = num2;
		}
		else
		{
			*pResultado = 0;
			retorno = 0;
		}
	}

	return retorno;
}
int cargarArray(float* array, int tam)
{
	int retorno = -1;
	int buffer;
	float bufferTemp;

	if(array != NULL && tam > 0)
	{
		if(utn_getNumero(&buffer,"Ingrese el dia: ","Error, no es un dia valido\n",1,31,3)==0)
		{
			if((utn_getNumeroFlotante(&bufferTemp,"Ingrese temperatura: ","Error, no es una temperatura valido\n",-30,60,3)==0))
			{
				array[buffer-1] = bufferTemp;
				retorno = 0;
			}

		}

	}

	return retorno;
}
void inicializar(float* array, int tam)
{
	int i;
	for(i=0; i<tam; i++)
	{
		array[i] = 0;
	}
}
void imprimirArray(float* array, int tam)
{
	int i;

	for(i=0; i<tam ; i++ )
	{
		if(array[i]> 0)
		{
			if(i==0)
			{
				printf("DIA   TEMPERATURA\n");
			}
			printf("%d   %.2f\n",i+1,array[i]);
		}

	}

}

