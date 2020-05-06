#ifndef CONTRATACION_H_
#define CONTRATACION_H_

#define ARCHIVO_LEN 50
#define CUIT_LEN 20
#include "Pantalla.h"

typedef struct
{
	char archivo[ARCHIVO_LEN];
	char cuit[CUIT_LEN];
	//float altura;
	int isEmpty;
	int id;
	int idPantalla; // agregado
	int dias; // agregado
}Contratacion;


int con_imprimir(Contratacion* auxProducto);
int con_inicializarArray(Contratacion* array,int limite);
//int con_altaArray(Contratacion* array,int limite, int indice, int* id);
int con_getEmptyIndex(Contratacion* array,int limite);
int con_imprimirArray(Contratacion* array,int limite);
int con_buscarId(Contratacion array[], int limite, int valorBuscado);
int con_modificarArray(Contratacion* array,int limite, int indice);
int con_bajaArray(Contratacion* array,int limite, int indice);
int con_ordenarPorNombre(Contratacion* array,int limite);

int con_altaArray(Contratacion* array,int limite, int indice, int* id,Pantalla* arrayP, int limiteP);
//int con_altaArray(Contratacion* array,int limite, int indice, int* id, Pantalla* arrayP, int limiteP)
#endif /* CONTRATACION_H_ */
