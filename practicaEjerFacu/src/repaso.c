/*
 * repaso.c
 *
 *  Created on: 4 abr. 2020
 *      Author: Jesi
 */
#include <stdio.h>
#include <stdlib.h>


int getInt(char mensaje[],char error[],int min, int max, int* numero)
{
	int flag = 0;
	int buffer;


		printf("%s",mensaje);
		if(scanf("%d",&buffer) && buffer <= max && buffer >= min)
		{
			*numero = buffer;
			flag = 1;
		}
		else
		{
			printf("%s\n",error);
			system("pause");
		}

	return flag;
}
int esPositivo(int numero)
{
	int flag = 0;

	if(numero >= 0)
	{
		flag = 1;
	}

	return flag;
}
float promediarNumeros(int numero1, int numero2)
{
	float buffer;

	buffer = (float)numero1 / numero2;

	return buffer;
}
