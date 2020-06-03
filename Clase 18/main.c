#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Alumno.h"

#define QTY_ALUMNOS 100

/**
 * 1 Alta alumno listo
 * 2 Baja alumno listo
 * 3 Modificar alumno
 * 4 Ordenar por nombre
 * 5 Imprimir listo
 * 6 Informe promedio alturas
 * 7 Informe alumno mas alto
 **/


int main(void)
{

	/*
	//ARCHIVOS

	//LECTURA EN MODO TEXTO DE DATOS SEPARADOS POR COM
	//PARSER
	Alumno* arrayDePunterosAlumnos[QTY_ALUMNOS];
	char buffer[128];
	char a[128];
	char b[128];
	char c[128];
	int i = 0;
	//int a,b,c,d;
	FILE* fp = fopen("archivo.txt","rb");
	if(fp != NULL)
	{

		//fgets(buffer,sizeof(buffer),fp);// SE PUEDE LEER LINEAS, LEE HASTA QUE ENCUENTRA UN ENTER
		//printf("%s",buffer);
		//fcanf(fp,"%d,%d,%d,%d\n",&a,&b,&c,&d); // devuelve la cantidad de variables que pudo escribir
		Alumno* auxAlumno;
		do
		{
			//fscanf(fp,"%d,%[^,],%[^,],%d\n",&a,b,c,&d)==4
			if(fscanf(fp,"%[^,],%[^,],%[^\n]\n",a,b,c)==3)
			{
				printf("%s - %s - %s",a,b,c);
				auxAlumno = alumno_newParametros(b,atof(c),atoi(a));
				if(auxAlumno != NULL)
				{
					arrayDePunterosAlumnos[i]= auxAlumno;
					i++;
				}

			}

		}while(!feof(fp));

	}




	FILE* fp;
		//fopen("c:\\carpeta\\miArchivo.txt"); ejemplo
		//int i;

	 //ESCRIBIR
	//fp = fopen("archivo.txt","wb");//se crea en la carpeta del proyecto, modo W=escribir en modo texto, si no existe lo crea y si existe lo borra
	if(fp != NULL)
	{
		// lo usamos
		//MODO TEXTO
		//1 fn para leer y 1 fn para escribir
		//fprintf(fp,"%d %d  %d ",var1,var2,var3); es como el printf pero poniendo el puntero a file
		//i = 127;

		//fprintf(fp,"hola"); //TEXTO // se convierte lo que se escribe a valores de la tabla ascci  //modo "w"
		//fwrite(&i,sizeof(int),1,fp);//BINARIO // copiamos la variable tal como esta en memoria al archivo //modo "wb"


		Alumno a;
		a.altura = 1.9;
		a.id = 1;
		sprintf(a.nombre,"Nicolas");
		fwrite(&a,sizeof(Alumno),1,fp);

	//LEER
	fp = fopen("archivo.txt","r");
	Alumno a;
	a.altura = 1.9;
	a.id = 1;


	fread(&a,sizeof(Alumno),1,fp);

// lo cerramos
		fclose(fp);
	}
	else
	{
		printf("Error abriendo archivo\n");
	}



	return 0;
*/



	/////////////////////////////

	setbuf(stdout,NULL);

	Alumno* arrayPunterosAlumno[QTY_ALUMNOS];

	int opcion;
	int idAlumnoInicial = 1;
	float promedioAlturas;
	float maxAltura;

	if(!alumno_initArray(arrayPunterosAlumno,QTY_ALUMNOS))
	{
		printf("INIT OK\n");
/*
		alumno_cargaForzada(arrayPunterosAlumno,QTY_ALUMNOS,"Nicolas",172.3,&idAlumnoInicial);
		alumno_cargaForzada(arrayPunterosAlumno,QTY_ALUMNOS,"Matias",190.1,&idAlumnoInicial);
		alumno_cargaForzada(arrayPunterosAlumno,QTY_ALUMNOS,"Jose",167.9,&idAlumnoInicial);
		alumno_cargaForzada(arrayPunterosAlumno,QTY_ALUMNOS,"Alejandro",168.2,&idAlumnoInicial);
		alumno_cargaForzada(arrayPunterosAlumno,QTY_ALUMNOS,"Mauricio",178.8,&idAlumnoInicial);
*/
		do
		{
			utn_getNumero(&opcion,"1 Alta alumno\n"
				  			      "2 Baja alumno\n"
					              "3 Modificar alumno\n"
                                  "4 Ordenar por nombre\n"
                                  "5 Imprimir\n"
                                  "6 Informe promedio alturas\n"
                                  "7 Informe alumno mas alto\n"
								  "8 Guardar en modo texto\n"
								  "9 Guardar en modo binario\n"
								  "10 Cargar datos de un archivo de texto\n"
								  "11 Cargar datos de un archivo binario\n"
								  "12 Salir","Opcion incorrecta\n",1,12,2);

			switch(opcion)
			{
			case 1:
				if(!alumno_getAlumnoConsola(arrayPunterosAlumno,QTY_ALUMNOS,&idAlumnoInicial))
				{
					printf("Alumno cargado con exito\n");
					alumno_imprimirArray(arrayPunterosAlumno,QTY_ALUMNOS);
				}
				break;
			case 2:
				alumno_baja(arrayPunterosAlumno,QTY_ALUMNOS);
				break;
			case 3:
				alumno_modificar(arrayPunterosAlumno,QTY_ALUMNOS);
				break;
			case 4:
				alumno_ordenarPorNombreEId(arrayPunterosAlumno,QTY_ALUMNOS);
				alumno_imprimirArrayConGet(arrayPunterosAlumno,QTY_ALUMNOS);
				break;
			case 5:
				alumno_imprimirArrayConGet(arrayPunterosAlumno,QTY_ALUMNOS);
				break;
			case 6:
				info_mostrarPromedioAlturas(arrayPunterosAlumno,QTY_ALUMNOS,&promedioAlturas);
				break;
			case 7:
				info_mostraralumnoMasAlto(arrayPunterosAlumno,QTY_ALUMNOS,&maxAltura);
				break;
			case 8://Guardar en modo texto
				alumnoGuardarEnTxt(arrayPunterosAlumno,QTY_ALUMNOS);
				break;
			case 9://Guardar en modo binario
				alumnoGuardarEnBin(arrayPunterosAlumno,QTY_ALUMNOS);
				break;
			case 10://Cargar datos de un archivo de texto
				alumnoLeerEnTxt(arrayPunterosAlumno,QTY_ALUMNOS);
				break;
			case 11://Cargar datos de un archivo binario
				alumnoCargarEnBin(arrayPunterosAlumno,QTY_ALUMNOS);
				break;

			}

		}while(opcion != 12);


	}

	return 0;
}
