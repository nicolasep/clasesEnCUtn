/*
 ============================================================================
 Name        : clase7Parte2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * Ejercicio 3: Definir una funcion validarFloat() que reciba un array de chars en donde los
 * caracteres representan un numero decimal. La funcion deberá devolver en su valor de retorno
 * si la cadena recibida contiene o no un valor numerico en formato texto.
 *

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int validarFloat(char* cadena)
{
 int retorno = -1;
 int contadorPuntos = 0;

  int i;
	if(cadena != NULL)
	{
		for(i=0; cadena[i]!='\0'; i++)
		 {
			 if(cadena[i] <'0' || cadena[i]>'9')
			 {
				 if(cadena[i] !='.')
				 {
					 contadorPuntos++;
					 if(contadorPuntos>1)
					 {
						retorno=0;
						break;
					 }
				 }

			 }
			 else
			 {
				if(i == 0)
				{
					if(cadena[i] !='+' || cadena[i] !='-')
					{
						retorno=0;
						break;
					}
				}
				else
				{
					retorno = 0;
					break;
				}
			 }

		 }

		 retorno = 1;
	}
 return retorno;
}

int main(void) {


	char numero[8];

	// prueba 1
	numero[0]='3';
	numero[1]='.';
	numero[2]='1';
	numero[3]='4';
	numero[4]='\0';

	// prueba 2
	numero[0]='2';
	numero[1]='3';
	numero[2]='5';
	numero[3]='7';
	numero[4]='\0';

	// prueba 3
	numero[0]='2';
	numero[1]='.';
	numero[2]='5';
	numero[3]='.';
	numero[4]='9';
	numero[5]='\0';

	// prueba 4
	numero[0]='h';
	numero[1]='o';
	numero[2]='l';
	numero[3]='a';
	numero[4]='\0';

	if(validarFloat(numero)==1)
	{
		printf("El numero %s es valido, se puede convertir a float!\n",numero);
	}
	else
	{
		printf("error\n");
	}

	return EXIT_SUCCESS;
}
*/


	/*
	 * Ejercicio 4:
	 * Completar la funcion getFloat() para que devuelva un numero float ingresado por el usuario
	 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int validarFloat(char* buff);

static int getFloat(float* pResultado);

int main(void) {

	setbuf(stdout,NULL);
	float precio;
	printf("Ingrese un precio:");
	if(getFloat(&precio)==1)
	{
		printf("El precio es valido:%f",precio);
	}
	else
	{
		printf("Valor incorrecto");
	}

	return EXIT_SUCCESS;


}
static int getFloat(float* pResultado)
{
	int retorno = 0;
	char buffer[128];

	fgets(buffer,sizeof(buffer),stdin);
	buffer[strlen(buffer)-1] = '\0';


	if(validarFloat(buffer)==1)
	{
		*pResultado = atof(buffer);
		retorno = 1;
	}

	return retorno;
}
static int validarFloat(char* buff)
{
	int ret=-1;
	int i=0;
	int contadorPuntos=0;
	while(buff[i]!='\0')
	{
		if(buff[i]<'0' || buff[i]>'9')
		{
			if(buff[i]!='.')
			{
				break;
			}
			else
			{
				contadorPuntos++;
				if(contadorPuntos>1)
					break;
			}
		}
		i++;
	}
	if(buff[i]=='\0')
		ret=1;
	return ret;
}

