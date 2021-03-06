#ifndef CLIENTE_H_
#define CLIENTE_H_

#define NOMBRE_LEN 50
#define APELLIDO_LEN 20
#define CUIT_LEN 12


typedef struct
{
	char nombre[NOMBRE_LEN];
	char apellido[APELLIDO_LEN];
	char cuit[CUIT_LEN];
	int isEmpty;
	int idCliente;
}Cliente;


//MEMORIA DINAMICA
Cliente* cli_new(void);
int cli_inicializarArrayPunteros(Cliente** array,int len);
int cli_getEmptyIndexConArrayPunteros(Cliente** array,int limite);
int cli_altaArrayConPunteros(Cliente** array,int limite, int indice, int* idCliente);
int cli_imprimirClienteConPunteros(Cliente* pElemento);
int cli_imprimirClientesConPunteros(Cliente** array,int limite);
int cli_altaForzadaArrayConPunteros(Cliente** array,int limite, int indice, int* idCliente,char* nombre,char* apellido, char* cuit);


/////
int cli_imprimir(Cliente* auxBuffer);
int cli_inicializarArray(Cliente* array,int limite);
int cli_altaArray(Cliente* array,int limite, int indice, int* id);
int cli_getEmptyIndex(Cliente* array,int limite);
int cli_imprimirArray(Cliente* array,int limite);
int cli_buscarId(Cliente array[], int limite, int valorBuscado);
int cli_modificarArray(Cliente* array,int limite, int indice);


int cli_altaForzadaArray(Cliente* array,int limite, int indice, int* idCliente,char* nombre,char* apellido, char* cuit);

#endif /* CLIENTE_H_ */
