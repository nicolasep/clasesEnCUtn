/*
 ============================================================================
 Name        : practicaEjerFacu.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "repaso.h"


int main(void) {
	/*Ingresar números hasta que el usuario lo decida.
    Los números tienen que estar comprendidos entre -100 y 100.
    Determinar:
    a. Cantidad de números positivos.
    b. Cantidad de números negativos.
    c. Promedio de números.
    d. De los positivos el máximo.
    Aplicar las siguientes funciones:
    a. int getInt(char[], char[], int, int) para el ingreso y validación de datos de tipo entero.
    b. int esPositivo(int) retorna 1 en caso de que el número recibido como parámetro sea positivo, 0 en caso contrario.
    c. float promediarNumeros(int,int): recibe el acumulador y el contador de números y retorna el promedio.
    Crear estas funciones dentro de una biblioteca llamada Repaso2*/


	setbuf(stdout,NULL);

	int buffer;
	int contador = 0;
	int contadorPositivos = 0;
	int contadorNegativos = 0;
	float promedio;
	int maximoPositivo;
	int acumulador = 0;
	char salir;

	do
	{
		system("cls");

		if(getInt("Ingrese un numero entre -100 y 100: ","ERROR\n",-100,100,&buffer))
		{


			if(esPositivo(buffer))
			{

				if(contadorPositivos == 0)
				{
				    maximoPositivo = buffer;
				}
				else if(buffer > maximoPositivo)
				{
					maximoPositivo = buffer;
				}
				contadorPositivos++;
			}
			else
			{
				contadorNegativos++;
			}

			acumulador += buffer;
			contador++;
		}
		//system("pause");

		printf("Para salir ingrese s: ");
		fflush(stdin);
		scanf("%c",&salir);


	}while(salir != 's' && salir != 'S');

	if(contador == 0)
	{
		printf("No se ingrisaron numeros\n");
	}
	else
	{
		promedio = promediarNumeros(acumulador,contador);

		printf("La cantidad de numeros positivos es: %d\n",contadorPositivos);
		printf("La cantidad de numeros negativos es: %d\n",contadorNegativos);
		printf("El numero maximo positivo es: %d\n",maximoPositivo);
		printf("El promedio de los numeros es: %.2f\n",promedio);
	}

	system("pause");


	return EXIT_SUCCESS;
}



