/*
 ============================================================================
 Name        : clase19.c
 Author      : nicolas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	FILE* fp;
	//fopen("c:\\carpeta\\miArchivo.txt"); ejemplo
	int i;
	fp = fopen("archivo.txt","w");//se crea en la carpeta del proyecto, modo W=escribir en modo texto, si no existe lo crea y si existe lo borra
	if(fp != NULL)
	{
		// lo usamos
		//MODO TEXTO
		//1 fn para leer y 1 fn para escribir
		//fprintf(fp,"%d %d  %d ",var1,var2,var3); es como el printf pero poniendo el puntero a file
		i = 127;

		//fprintf(fp,"hola"); //TEXTO // se convierte lo que se escribe a valores de la tabla ascci  //modo "w"
		//fwrite(&i,sizeof(int),1,fp);//BINARIO // copiamos la variable tal como esta en memoria al archivo //modo "wb"

		// lo cerramos
		fclose(fp);
	}
	else
	{
		printf("Error abriendo archivo\n");
	}



	return EXIT_SUCCESS;
}
