/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
 *      Author: Jesi
 */
#include <stdio.h>
#include <stdlib.h>

int dividir(float* pResultado, int numero1, int numero2)
{
	int flag = -1;
	float resultado;

	if(pResultado !=NULL && numero2 != 0)
	{
		resultado =(float) numero1/numero2;
		*pResultado = resultado;
		flag = 0;
	}
	return flag;

}
