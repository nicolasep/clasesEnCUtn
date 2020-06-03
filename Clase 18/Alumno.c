/*
 * Alumno.c
 *
 *  Created on: May 26, 2020
 *      Author: Mauro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Alumno.h"

static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);
static int esAltura(char* cadena, int longitud);


Alumno* alumno_new(void)
{
	Alumno* auxiliarP = NULL;
	auxiliarP = (Alumno*) malloc(sizeof(Alumno));
	return auxiliarP;
}

Alumno* alumno_newParametros(char* nombre,float altura,int id)
{
	Alumno* punteroAlumno = NULL;
	punteroAlumno = alumno_new();
	if(punteroAlumno != NULL)
	{
		/*strncpy(punteroAlumno->nombre,nombre,NOMBRE_LEN);
		punteroAlumno->altura = altura;
		punteroAlumno->id=id;*/
		alumno_setNombre(punteroAlumno,nombre);
		alumno_setAltura(punteroAlumno,altura);
		alumno_setId(punteroAlumno,id);

	}
	return punteroAlumno;
}

void alumno_delete(Alumno* this)
{
	if(this != NULL)
	{
		free(this);
	}
}


int alumno_setNombre(Alumno* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}

int alumno_getNombre(Alumno* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}

int alumno_setIdTxt(Alumno* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,10))
		{
			retorno = 0;
			this->id = atoi(id);
		}
	}
	return retorno;
}

int alumno_setId(Alumno* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

int alumno_getIdTxt(Alumno* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",this->id);
	}
	return retorno;
}
int alumno_getId(Alumno* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		 *id = this->id;
	}
	return retorno;
}

int alumno_setAltura(Alumno* this,float altura)
{
	int retorno = -1;
	if(this != NULL && altura >= 0)
	{
		retorno = 0;
		this->altura = altura;
	}
	return retorno;
}
int alumno_getAltura(Alumno* this,float* altura)
{
	int retorno = -1;
	if(this != NULL && altura != NULL)
	{
		retorno = 0;
		 *altura = this->altura;
	}
	return retorno;
}
int alumno_setAlturaTxt(Alumno* this,char* altura)
{
	int retorno = -1;
	if(this != NULL && altura != NULL)
	{
		if(esAltura(altura,20))
		{
			retorno = 0;
			this->altura = atof(altura);
		}
	}
	return retorno;
}
int alumno_getAlturaTxt(Alumno* this,char* altura)
{
	int retorno = -1;
	if(this != NULL && altura != NULL)
	{
		retorno = 0;
		sprintf(altura,"%f",this->altura);
	}
	return retorno;
}

int alumno_getAlumnoConsola(Alumno* array[], int len, int* id)
{
	int retorno = -1;
	char auxString[100];
	float auxFloat;

	if(array != NULL && len > 0 && id != NULL)
	{
		if(!utn_getNombre(auxString,NOMBRE_LEN,"Ingrese nombre: ","Error, no debe contener nmeros\n",2) &&
		   !utn_getNumeroFlotante(&auxFloat,"Ingrese la Altura en cm: ","Error, deben ser numeros\n",1.1,220.9,2))
		{
			if(alumno_agregarAlumnoArray(array,len,auxString,auxFloat,*id) >= 0)
			{
				*id += 1;
				retorno = 0;
			}
		}
	}

	return retorno;
}
int alumno_cargaForzada(Alumno* array[], int len ,char* nombre,float altura,int* id)
{
	int retorno = -1;

	if(array != NULL && len > 0 && id != NULL && nombre != NULL && altura > 0 && id != NULL)
	{

		if(alumno_agregarAlumnoArray(array,len,nombre,altura,*id) >= 0)
		{
			(*id)++;
			retorno = 0;
		}
	}

	return retorno;
}
int alumno_imprimirArrayConGet(Alumno* arrayPunteros[],int limite)
{
	int retorno=-1;
	int i;
	if(arrayPunteros != NULL && limite > 0)
	{
		printf("\n-----LISTA ALUMNOS-----\n");
		for(i=0;i<limite;i++)
		{
			if(arrayPunteros[i] != NULL &&
			   !alumno_imprimirAlumnoConGet(arrayPunteros[i]))
			{
				retorno= 0;
			}
		}
	}
	return retorno;
}
int alumno_imprimirAlumnoConGet(Alumno* pElement)
{
	int retorno=-1;
	int auxInt;
	char auxString[NOMBRE_LEN];
	float auxFloat;

	if(pElement != NULL &&
	   !alumno_getId(pElement,&auxInt)&&
	   !alumno_getNombre(pElement,auxString)&&
	   !alumno_getAltura(pElement,&auxFloat))
	{
		printf("ID: %d - Nombre: %s - Altura: %.2f\n",auxInt,auxString,auxFloat);
		retorno= 0;
	}
	return retorno;
}
int alumno_baja(Alumno** this,int len)
{
	int retorno = -1;
	int idBaja;
	int indice;

	if(this != NULL && len > 0)
	{

		if(!alumno_imprimirArrayConGet(this,len) &&
		   !utn_getNumero(&idBaja,"Ingrese el ID a dar de baja: ","No es un numero admitido",1,len,2) &&
		   (indice = alumno_buscarPorIdArray(this,len,idBaja))>= 0)
		{
			printf("El alumno seleccionado es\n");
			alumno_imprimirAlumnoConGet(this[indice]);
			if(!utn_confirmacionAccionChar("Para confirma ingrese S/s")&&
			   !alumno_deleteIndexInArray(this,len,indice))
			{
				printf("Alumno eliminado con exito\n");
				retorno = 0;
			}
		}
	}

	return retorno;
}
int alumno_modificar(Alumno** this,int len)
{
	int retorno = -1;
	int indice;
	int idAModificar;
	int opcionSeleccionada;
	char auxString[NOMBRE_LEN];
	float auxFloat;

	if(this != NULL && len > 0)
	{
		if(!alumno_imprimirArrayConGet(this,len) &&
			!utn_getNumero(&idAModificar,"Seleccione el ID del alumno a modificar: ","Error, debe ser un numero\n",1,len,2)&&
			(indice = alumno_buscarPorIdArray(this,len,idAModificar))>= 0)
		{
			utn_getNumero(&opcionSeleccionada,"Elija una opcion\n"
					                          "1 - Modificar nombre\n"
					                          "2 - Modificar altura\n"
					                          "3 - Salir\n", "Error, No es una opcion valida\n",1,3,2);
			switch(opcionSeleccionada)
			{
			case 1:
				if(!utn_getNombre(auxString,NOMBRE_LEN,"Ingrese el nuevo nombre: ","Error, deben ser letras\n",2)&&
				   !utn_confirmacionAccionChar("Comfirme el cambio de nombre con S/s: "))
				{
					if(!alumno_setNombre(this[indice],auxString))
					{
						printf("Nombre modificado con exito\n");
						retorno = 0;
					}
				}
				break;
			case 2:
				if(!utn_getNumeroFlotante(&auxFloat,"Ingrese la nueva altura en cm: ","Error, deben ser numeros\n",1,230,2)&&
				   !utn_confirmacionAccionChar("Comfirme el cambio de altura con S/s: "))
				{
					if(!alumno_setAltura(this[indice],auxFloat))
					{
						printf("Altura modificada con exito\n");
						retorno = 0;
					}
				}
				break;
			default:
				printf("Operacion cancelada\n");
				break;
			}
		}

	}


	return retorno;
}
/**
 * \brief Ordenar el array de clientes por nombre
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int alumno_ordenarPorNombreEId(Alumno* array[],int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Alumno* buffer;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i] != NULL && array[i+1] != NULL &&
				   strncmp(array[i]->nombre,array[i+1]->nombre,NOMBRE_LEN) > 0 /*||
				  (strncmp(array[i]->nombre,array[i+1]->nombre,NOMBRE_LEN)==0 && array[i]->id > array[i+1]->id)*/)
				{
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
					flagSwap = 1;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}

int info_mostrarPromedioAlturas(Alumno* this[],int len, float* pResultado)
{
	int retorno = -1;
	float auxAltura;
	float acumulador = 0;
	int i;
	if(this != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(this[i] != NULL)
			{
				if(!alumno_getAltura(this[i],&auxAltura))
				{
					acumulador += auxAltura;
				}
			}
		}
		*pResultado = acumulador / i;
		retorno = 0;

	}

	return retorno;
}
int info_mostraralumnoMasAlto(Alumno* this[],int len, float* pResultado)
{
	int retorno = -1;
	float auxAltura;
	float auxMax = 0;
	int cargoValorInicial = 0;
	int i;
	if(this != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(this[i] != NULL)
			{
				if(cargoValorInicial == 0 ||
					(!alumno_getAltura(this[i],&auxAltura) && auxAltura > auxMax))
				{
					auxMax = auxAltura;

					cargoValorInicial = 1;
				}
			}
		}
		*pResultado = auxMax;
		retorno = 0;

	}

	return retorno;
}
int alumnoGuardarEnTxt(Alumno* list[],int len)
{
	int retorno = -1;
	int i;
	char auxNombre[51];
	float auxAltura;
	int auxId;
	FILE* p;
	p =fopen("alumnos.txt","w");

	if(list != NULL && len > 0 && p != NULL)
	{
		for(i=0; i<len; i++)
		{
			if(list[i] != NULL &&
			  !alumno_getNombre(list[i],auxNombre) &&
			  !alumno_getAltura(list[i],&auxAltura) &&
			  !alumno_getId(list[i],&auxId))
			{
				//fprintf(fp,"%s,%s,%f\n",nombreAux,idAux,alturaAux);

				fprintf(p,"%d,%s,%.2f\n",auxId,auxNombre,auxAltura);
				retorno = 0;
			}
		}
	}
	fclose(p);


	return retorno;
}
int alumnoGuardarEnBin(Alumno* list[],int len)
{
	int retorno = -1;
	int i;
	char auxNombre[51];
	float auxAltura;
	int auxId;
	FILE* p;
	p =fopen("alumnosB.bin","wb");

	if(list != NULL && len > 0 && p != NULL)
	{
		for(i=0; i<len; i++)
		{
			if(list[i] != NULL &&
			  !alumno_getNombre(list[i],auxNombre) &&
			  !alumno_getAltura(list[i],&auxAltura) &&
			  !alumno_getId(list[i],&auxId))
			{
				//fprintf(fp,"%s,%s,%f\n",nombreAux,idAux,alturaAux);

				//fprintf(p,"%d,%s,%.2f\n",auxId,auxNombre,auxAltura);
				fwrite(list[i],sizeof(Alumno),1,p);
				retorno = 0;
			}
		}
	}
	fclose(p);


	return retorno;
}
int alumnoLeerEnTxt(Alumno* list[],int len)
{
	int retorno = -1;
	int i =0;
	FILE* p;
	p =fopen("alumnos.txt","r");
	char a[100];
	char b[100];
	char c[100];
	Alumno* aux;

	if(list != NULL && len > 0 && p != NULL)
	{
		do
		{
			if(fscanf(p,"%[^,],%[^,],%[^\n]\n",a,b,c)==3)
			{
				aux = alumno_newParametros(b,atof(c),atoi(a));
				if(p!=NULL)
				{
					list[i] = aux;
					i++;
					if(i>=len)
						break; // ya llene todo el array
				}
			}
			else
				break;

		}
		while(feof(p)==0);
		retorno = i;
	}
	fclose(p);

	return retorno;
}
int alumnoCargarEnBin(Alumno* list[],int len)
{
	int retorno = -1;
	int i=0;
	Alumno aux;
	FILE* p;
	p =fopen("alumnosB.bin","rb");


	if(list != NULL && len > 0 && p != NULL)
	{
		int fin=0;
		do{
			fin = fread(&aux,sizeof(Alumno),1,p);
			if(fin != 0)
			{
				list[i] = alumno_newParametros(aux.nombre,aux.altura,aux.id);
				i++;
			}
		}
		//while(fin!=0);
		while(feof(p)==0);
		retorno = i;
	}
	fclose(p);


	return retorno;
}

/**********************************************************************/

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada sea un numero flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si es un numero flotante y 0 (falso) si no lo es
 *
 */
static int esAltura(char* cadena, int longitud)
{
    int retorno=1;
	int i;
	int contadorPuntos=0;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0;i<longitud  && cadena[i]!='\0';i++)
		{
			if(cadena[i]<'0' || cadena[i]>'9')
			{

				if(cadena[i]=='.')
				{
					contadorPuntos++;
					if(contadorPuntos>1)
					{

						retorno=0;
						break;
					}
				}
				else
				{

					if(i==0)
					{

						if(cadena[i]!='+' && cadena[i]!='-')
						{
							retorno=0;
							break;
						}
					}
					else
					{
						retorno=0;
						break;
					}
				}
			}
		}
	}


    return retorno;
}

/**********************************************************************/


int alumno_deleteIndexInArray(Alumno* arrayPunteros[],int limite, int indice)
{
	int retorno=-1;
	if(arrayPunteros != NULL && indice >= 0 && indice < limite && arrayPunteros[indice] != NULL )
	{
		retorno = 0;
		alumno_delete(arrayPunteros[indice]);
		arrayPunteros[indice] = NULL;
	}
	return retorno;
}


int alumno_initArray(Alumno* arrayPunteros[],int limite)
{
	int retorno=-1;
	int i;
	if(arrayPunteros != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			arrayPunteros[i] = NULL;
		}
	}
	return retorno;
}

int alumno_buscarLibreArray(Alumno* arrayPunteros[],int limite)
{
	int retorno=-1;
	int i;
	if(arrayPunteros != NULL && limite > 0)
	{
		retorno = -2;
		for(i=0;i<limite;i++)
		{
			if(arrayPunteros[i] == NULL)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int alumno_imprimirArray(Alumno* arrayPunteros[],int limite)
{
	int retorno=-1;
	int i;
	if(arrayPunteros != NULL && limite > 0)
	{
		printf("\n-----LISTA ALUMNOS-----\n");
		for(i=0;i<limite;i++)
		{
			if(arrayPunteros[i] != NULL)
			{
				printf("Nombre: %s- ID: %d - Altura: %.2f\n",arrayPunteros[i]->nombre,arrayPunteros[i]->id,arrayPunteros[i]->altura);

			}
		}
	}
	return retorno;
}

int alumno_buscarPorIdArray(Alumno* arrayPunteros[],int limite, int id)
{
	int retorno=-1;
	int i;
	if(arrayPunteros != NULL && limite > 0 && id >= 0)
	{
		retorno = -2;
		for(i=0;i<limite;i++)
		{
			if(arrayPunteros[i] != NULL && arrayPunteros[i]->id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int alumno_agregarAlumnoArray(Alumno* arrayPunteros[],int limite, char* nombre, float altura, int id)
{
	int retorno=-1;
	int indiceLibre;
	if(arrayPunteros != NULL && limite > 0 && nombre != NULL && id >= 0)
	{
		indiceLibre = alumno_buscarLibreArray(arrayPunteros,limite);
		if(indiceLibre >= 0)
		{
			arrayPunteros[indiceLibre] = alumno_newParametros(nombre,altura,id);
			retorno = indiceLibre;
		}

	}

	return retorno;
}


int alumno_borrarPorIdArray(Alumno* arrayPunteros[],int limite, int id)
{
	int retorno=-1;
	int indiceBorrar;
	if(arrayPunteros != NULL && limite > 0 && id >= 0)
	{
		indiceBorrar = alumno_buscarPorIdArray(arrayPunteros,limite,id);
		if(indiceBorrar >= 0)
		{
			if(!alumno_deleteIndexInArray(arrayPunteros,limite,indiceBorrar))
			{
				retorno=0;
			}
		}
	}
	return retorno;
}

