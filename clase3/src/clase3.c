/*
 ============================================================================
 Name        : clase3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumar(int num1,int num2);
int restar(int num1, int num2);
int multiplicar(int num1, int num2);
int dividir(int num1, int num2, float* resultado);

int main(void) {
	setbuf(stdout,NULL);


	/*// EJERCICIO
// 1 programa que pida unnumero al usuario, despues que pida una operacion (+ - / * )
// y despues que pida otro numero. Segun la operacion ingresada, se llamará a una funcion
// que ejecute la operacion (sumar() restar() multiplicar() dividir())
// y luego mostrar al usuario el resultado. El mostrar resultado NOOOOO puede estar dentro de
// las funciones que crean para hacer la operacion. En la funcion dividir, validar no dividir por
// cero*/

	char opcion;
	int num1;
	int num2;
	int resultado1;
	float resultadoDivision;
	int flagDivision;


	printf("Ingreese un numero: ");
	scanf("%d",&num1);


	printf("Elija una opcion\n");
	printf("1 - SUMAR\n");
	printf("2 - RESTAR\n");
	printf("3 - DIVIDIR\n");
	printf("4 - MULTIPLICAR\n");
	fflush(stdin);
	scanf("%c",&opcion);

	printf("\nIngreese otro numero: ");
	scanf("%d",&num2);
	switch(opcion)
	{
	case '1':
		resultado1 = sumar(num1,num2);
		break;
	case '2':
		resultado1 = restar(num1,num2);
		break;
	case '3':
		flagDivision = dividir(num1,num2,&resultadoDivision);
		break;
	case '4':
		resultado1 = multiplicar(num1, num2);
		break;
	default:
		printf("Opcion incorrecta\n");
	}


	if(opcion == '3')
	{
		if(flagDivision)
		{
			printf("El resultado de la operacion es : %.2f",resultadoDivision);
		}
		else
		{
			printf("No see puede dividir por 0\n");
		}

	}
	else
	{
		printf("El resultado de la operacion es : %d",resultado1);
	}



	return EXIT_SUCCESS;
}

int sumar(int num1,int num2)
{
	int resultado = num1 + num2;

	return resultado;

}
int restar(int num1, int num2)
{
	int resultado = num1 - num2;

	return resultado;
}
int multiplicar(int num1, int num2)
{
	int resultado = num1 * num2;

	return resultado;
}

int dividir(int num1, int num2, float* resultado)
{
	int flag=0;

		if(num2 == 0)
		{

		}
		else
		{
			*resultado = (float) num1/num2;
			flag = 1;
		}
	return flag;
}


/* EJERCICIO PROFESOR
 #include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>


int dividir(int operador1, int operador2,float* direccionDeVariableDeRetorno);

int main(void)
{
	setbuf(stdout,NULL);

	int a=27;
	int b=2;
	float resultado;
	int retHuboError;

	printf("la direccion de resultado en el main es: %d\n",&resultado);


	retHuboError = dividir(a,b,&resultado);
	if(retHuboError==1)
	{
		printf("no se puede dividir");
	}
	else
	{
		printf("resultado:%f",resultado);
	}



    return EXIT_SUCCESS;
}

int dividir(int operador1, int operador2,float* direccionDeVariableDeRetorno)
{
	float resul;
	int huboError;

	printf("la direccion de resultado en funcion dividir es: %d",direccionDeVariableDeRetorno);

	if(operador2!=0)
	{
		resul =  (float)operador1 / operador2;
		// escribir en la direccion direccionDeVariableDeRetorno el resultado de la division "resul"
		// HACER (ni idea como)

		//escribimeEnLamemoriaEsto(direccionDeVariableDeRetorno,resul);
		(*direccionDeVariableDeRetorno) = resul;

		huboError=0;//no hubo error
	}
	else
	{
		huboError=1;//hubo error
	}
	return huboError;
}
 */

