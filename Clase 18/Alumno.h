/*
 * Alumno.h
 *
 *  Created on: May 26, 2020
 *      Author: Mauro
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
#define NOMBRE_LEN 50

typedef struct
{
	char nombre[NOMBRE_LEN];
	float altura;
	int id;
}Alumno;

Alumno* alumno_new(void);
Alumno* alumno_newParametros(char* nombre,float altura,int id);
void alumno_delete(Alumno* this);

int alumno_setNombre(Alumno* this,char* nombre);
int alumno_getNombre(Alumno* this,char* nombre);
int alumno_setIdTxt(Alumno* this,char* id);
int alumno_setId(Alumno* this,int id);
int alumno_getIdTxt(Alumno* this,char* id);
int alumno_getId(Alumno* this,int* id);
int alumno_setAltura(Alumno* this,float altura);
int alumno_getAltura(Alumno* this,float* altura);
int alumno_setAlturaTxt(Alumno* this,char* altura);
int alumno_getAlturaTxt(Alumno* this,char* altura);
int alumno_getAlumnoConsola(Alumno* array[], int len, int* id);

int alumno_cargaForzada(Alumno* array[], int len ,char* nombre,float altura,int* id);

int alumno_imprimirArrayConGet(Alumno* arrayPunteros[],int limite);
int alumno_imprimirAlumnoConGet(Alumno* pElement);

int alumno_baja(Alumno** this,int len);
int alumno_modificar(Alumno** this,int len);
int alumno_ordenarPorNombreEId(Alumno* array[],int limite);

int info_mostrarPromedioAlturas(Alumno* this[],int len, float* pResultado);
int info_mostraralumnoMasAlto(Alumno* this[],int len, float* pResultado);

int alumnoGuardarEnTxt(Alumno* list[],int len);
int alumnoGuardarEnBin(Alumno* list[],int len);

int alumnoLeerEnTxt(Alumno* list[],int len);
int alumnoCargarEnBin(Alumno* list[],int len);
/**************************************************************/

int alumno_initArray(Alumno* arrayPunteros[],int limite);
int alumno_buscarLibreArray(Alumno* arrayPunteros[],int limite);
int alumno_imprimirArray(Alumno* arrayPunteros[],int limite);
int alumno_deleteIndexInArray(Alumno* arrayPunteros[],int limite, int indice);
int alumno_buscarPorIdArray(Alumno* arrayPunteros[],int limite, int id);
int alumno_agregarAlumnoArray(Alumno* arrayPunteros[],int limite, char* nombre, float altura, int id);
int alumno_borrarPorIdArray(Alumno* arrayPunteros[],int limite, int id);

#endif /* ALUMNO_H_ */
