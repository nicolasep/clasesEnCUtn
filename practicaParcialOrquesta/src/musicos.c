/*
 * musicos.c
 *
 *  Created on: 20 abr. 2020
 *      Author: Jesi
 */


int inicializar(musico* lista, int len)
{
	int retorno = -1;
	int i;
	for(i=0; i<len; i++)
	{
		lista[i].isEmpty = 0;
	}
	retorno = 0;

	return retorno;
}
int buscarLibre(musico* lista,int len)
{
	int indice = -1;
	int i;
	for(i=0; i<len; i++)
	{
		if(lista[i].isEmpty==0)
		{
			indice = i;
		}
	}
	return indice;
}
