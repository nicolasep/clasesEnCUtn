/*
 ============================================================================
 Name        : clase2.c
 Author      : Nicolas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


int main(void) {

	setbuf(stdout,NULL);




	/*
	//pedir numeros hasta que el usuario quiera y para dejar de ingresar (888) y dar como resultado maximo y minimo

	    int maximo;
	    int minimo;
	    int bufferInt;
	    int flag = TRUE;
	    int flag2=0;
	    int contador = 1;

	    do
	    {
	        printf("IN NUMERO %d\n",contador);
	        scanf("%d", &bufferInt);

	        if(bufferInt != 888)
	        {
	        	if(flag == TRUE)
	            {
					maximo = bufferInt;
					minimo = bufferInt;
					flag = FALSE;
	            }
	            else
	            {
					if(bufferInt > maximo)
					{
						maximo = bufferInt;
					}
					else
					{
						if(bufferInt < minimo)
						{
						minimo = bufferInt;
						}
					}

	            }
	        }
	        else
	        {
	        	flag2=1;
	        }
	        contador ++;

	    }while(flag2 != 1);
	    printf("\nEl valor minimo es: %d y el valor maximo es: %d",minimo,maximo);
*/
	//ESCRITO POR PROFESOR
	/*
	int maximo;
    int minimo;
    int bufferInt;
    int flag = TRUE;

    do
    {
        printf("INGRESE NUMERO (\"888\" FINALIZA EL INGRESO): ");
        scanf("%d", &bufferInt);
        if(flag == TRUE)
        {
            maximo = bufferInt;
            minimo = bufferInt;
            flag = FALSE;
        }
        else
        {
            if(bufferInt == 888)
            {
                break;
            }
            else
            {
                if(bufferInt > maximo)
                {
                    maximo = bufferInt;
                }
                if(bufferInt < minimo)
                {
                    minimo = bufferInt;
                }
            }

        }
    }
    while(TRUE);  o while(1);

    printf("\nEl valor minimo es: %d y el valor maximo es: %d",minimo,maximo);
	 */





	return EXIT_SUCCESS;
}
