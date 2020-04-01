/*
 ============================================================================
 Name        : clase1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	setbuf(stdout,NULL);

  /*
	int numero;
	setbuf(stdout,NULL); // para desactivar el buffer e imprima el mensaje

	printf("Ingrese un numero: ");


	scanf("%d",&numero);

	printf("ingresaste: %d",numero);
*/
	/*

	int numero1;
	int numero2;
	int suma;
	int resta;
	float division;
	int multiplicacion;

	printf("Ingrese un numero: ");
	scanf("%d",&numero1);
	printf("Ingrese otro numero: ");
	scanf("%d",&numero2);

	suma=numero1+numero2;
	resta=numero1-numero2;
	division=numero1/numero2;
	multiplicacion=numero1*numero2;

	printf("La suma es: %d\n",suma);
	printf("La resta es: %d\n",resta);
	printf("La multiplicacion es: %d\n",multiplicacion);
	printf("La division es: %.2f",division);
*/
	int numero;
	int acumulador=0;
	float promedio;
	int i;

	for(i=0;i<5;i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d",&numero);
		acumulador+=numero;

	}
	promedio = acumulador/i;
	printf("El promedio es: %.2f",promedio);





	return EXIT_SUCCESS;
}
