#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

#define NOMBRE_LEN 128

static int esId(char* cadena,int limite);
static int esNombreg(char* cadena,int longitud);
static int sonHorasT(char* cadena,int limite);
static int esSueldo(char* cadena,int limite);

/** \brief reserva un espacio en memoria para un empleado, le carga valores iniciales y lo devuelve.
 * \return int si no pudo reservar el espacio en memoria devuelve NULL, de lo contrario devuelve el puntero al espacio en memoria.
 */
Employee* employee_new()
{
	Employee* auxEmployee = (Employee*)malloc(sizeof(Employee));
	if(auxEmployee != NULL)
	{
		auxEmployee->id=0;
		auxEmployee->nombre[0]='\0';
		auxEmployee->horasTrabajadas=0;
		auxEmployee->sueldo=0;
	}

	return auxEmployee;

}
/**\ brief crea un empleado en memoria y le asigna los paramatros pasados
 * \param puntero al espacio en memoria del id a cargar
 * \param puntero al espacio en memoria del nombre a cargar
 * \param puntero al espacio en memoria de las horas trabajadas cargar
 * \param puntero al espacio en memoria del sueldo a cargar
 * \return si salio bien devuelve el empleado con los el puntero del empleado con los datos cargados, de lo contrario devuelve NULL
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* SueldoStr)
{

	Employee* auxEmployee = employee_new();

		if(auxEmployee != NULL &&
		   !employee_setId(auxEmployee,atoi(idStr)) &&
		   !employee_setNombre(auxEmployee,nombreStr)&&
		   !employee_setHorasTrabajadas(auxEmployee,atoi(horasTrabajadasStr))&&
		   !employee_setSueldo(auxEmployee,atoi(SueldoStr)))
		{
			return auxEmployee;
		}
		else
		{
			return NULL;
		}

}
/**\brief libera el espacio en memoria de un empleado
 * \param puntero al espacio en memoria de un empleado
 *
 */
void employee_delete(Employee* pEmployee)
{
	if(pEmployee != NULL)
	{
		free(pEmployee);
	}
}
/**\brief setea id en un empleado
 * \param puntero al espacio en memoria del empleado
 * \param variable a volcar en el empleado
 * \return devuelve 0 si lo pudo cargar, -1 si no pudo o no es un id aceptable
 *
 */
int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	char auxChar[10];
	sprintf(auxChar,"%d",id);
	if(this !=NULL && id > 0 && esId(auxChar,10))
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
/**\brief devuelve el id de un empleado puntual
 * \param puntero al espacio en memoria del empleado
 * \param puntero al espacio en memoria donde se asigna el id del empleado
 * \return devuelve 0 si lo pudo cargar, -1 si no pudo
 *
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}
/**\brief setea id en modo texto en un empleado
 * \param puntero al espacio en memoria del empleado
 * \param puntero al espacio en memoria de ese id
 * \return devuelve 0 si lo pudo cargar, -1 si no pudo o no es un id aceptable
 *
 */
int employee_getIdChar(Employee* this,char* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
	  sprintf(id,"%d",this->id);

		retorno = 0;
	}

	return retorno;
}
/**\brief setea el nombre en un empleado
 * \param puntero al espacio en memoria del empleado
 * \param puntero a la cadena que contiene el nombre a guardar en el empleado
 * \return devuelve 0 si lo pudo cargar, -1 si no pudo o no es un nombre aceptable
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL && esNombreg(nombre,NOMBRE_LEN))
	{
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}
/**\brief de un empleado devuelve el nombre
 * \param puntero al espacio en memoria del empleado
 * \param puntero a la cadena donde se va a retornar el nombre
 * \return devuelve 0 si lo pudo cargar, -1 si no pudo
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre,this->nombre,128);
		retorno = 0;
	}

	return retorno;
}
/**\brief setea las horas trabajadas en un empleado
 * \param puntero al espacio en memoria del empleado
 * \param variable a volcar en el empleado
 * \return devuelve 0 si lo pudo cargar, -1 si no pudo o no es un numero aceptable
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	char auxHorasT[20];
	sprintf(auxHorasT,"%d",horasTrabajadas);
	if(this != NULL && horasTrabajadas >= 0 && sonHorasT(auxHorasT,20))
	{
		this->horasTrabajadas = horasTrabajadas;

		retorno = 0;
	}
	return retorno;
}
/**\brief devuelve las horas trabajadas de un empleado puntual
 * \param puntero al espacio en memoria del empleado
 * \param puntero al espacio en memoria donde se cargan las horas trabajdas del empleado
 * \return devuelve 0 si lo pudo cargar, -1 si no pudo
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;

		retorno = 0;
	}
	return retorno;
}
/**\brief devuelve las horas trabajadas en modo texto de un empleado puntual
 * \param puntero al espacio en memoria del empleado
 * \param puntero al espacio en memoria donde se cargan las horas trabajdas del empleado en modo texto
 * \return devuelve 0 si lo pudo cargar, -1 si no pudo
 *
 */
int employee_getHorasTrabajadasChar(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		sprintf(horasTrabajadas,"%d",this->horasTrabajadas);

		retorno = 0;
	}
	return retorno;
}
/**\brief setea el sueldo en un empleado
 * \param puntero al espacio en memoria del empleado
 * \param variable a volcar en el empleado
 * \return devuelve 0 si lo pudo cargar, -1 si no pudo o no es un numero aceptable
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	char auxSueldo[20];
	sprintf(auxSueldo,"%d",sueldo);
	if(this != NULL && sueldo >= 0 && esSueldo(auxSueldo,20))
	{
		this->sueldo = sueldo;

		retorno = 0;
	}
	return retorno;
}
/**\brief devuelve el sueldo de un empleado puntual
 * \param puntero al espacio en memoria del empleado
 * \param puntero al espacio en memoria donde se carga el sueldo del empleado
 * \return devuelve 0 si lo pudo cargar, -1 si no pudo
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;

		retorno = 0;
	}
	return retorno;
}
/**\brief devuelve el sueldo en modo texto de un empleado puntual
 * \param puntero al espacio en memoria del empleado
 * \param puntero al espacio en memoria donde se carga el sueldo del empleado en modo texto
 * \return devuelve 0 si lo pudo cargar, -1 si no pudo
 *
 */
int employee_getSueldoChar(Employee* this,char* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		sprintf(sueldo,"%d",this->sueldo);

		retorno = 0;
	}
	return retorno;
}
//////////FUNCIONES DE VALIDACION DE GETTERS//////////
/**
 * \brief Verifica si la cadena ingresada es un numero valido
 * \param cadena Cadena de caracteres a ser analizada
 * \param limite de la cadena
 * \return Retorna 1 (verdadero) si el numero es valido y 0 (falso) si no lo es
 *
 */
static int esId(char* cadena,int limite)
{
	int retorno = 1;
	int i;

	for(i=0; i<limite && cadena[i] !='\0'; i++)
	{
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}


	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombreg(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' )&& cadena[i] != ' ')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un numero valido
 * \param cadena Cadena de caracteres a ser analizada
 * \param limite de la cadena
 * \return Retorna 1 (verdadero) si el numero es valido y 0 (falso) si no lo es
 *
 */
static int sonHorasT(char* cadena,int limite)
{
	int retorno = 1;
	int i;

	for(i=0; i<limite && cadena[i] !='\0'; i++)
	{
		if(i==0 && cadena[i] == '+')
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un numero valido
 * \param cadena Cadena de caracteres a ser analizada
 * \param limite de la cadena
 * \return Retorna 1 (verdadero) si el numero es valido y 0 (falso) si no lo es
 *
 */
static int esSueldo(char* cadena,int limite)
{
	int retorno = 1;
	int i;

	for(i=0; i<limite && cadena[i] !='\0'; i++)
	{
		if(i==0 && cadena[i] == '+')
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}


	return retorno;
}
////////////////////////////////////////////////////

/**\brief imprime un empleado por pantalla
 * \param puntero al espacio en memoria de ese empleado
 * \return devuelve 0 si lo pudo imprimir y -1 si no
 *
 */
int employee_printEmployee(Employee* pElement)
{
	int retorno = -1;
	int auxId;
	char auxNombre[128];
	int auxHorasT;
	int auxSueldo;

	if(pElement != NULL &&
	   !employee_getId(pElement,&auxId)&&
	   !employee_getNombre(pElement,auxNombre)&&
	   !employee_getHorasTrabajadas(pElement,&auxHorasT)&&
	   !employee_getSueldo(pElement,&auxSueldo))
	{
		printf("ID: %4d - NOMBRE: %15s - HORAS T: %4d - SUELDO: %d\n",auxId,auxNombre,auxHorasT,auxSueldo);
		retorno = 0;
	}
	return retorno;
}
/**\brief imprime un empleado por pantalla segun el id
 * \param puntero al espacio en memoria de ese empleado
 * \param variable que contiene el id a buscar
 * \return devuelve la ubicacion en la lista si lo pudo imprimir y -1 si no
 *
 */
int employee_printById(LinkedList* pArrayListEmployee, int id)
{
	int retorno = -1;
	int i;
	if(pArrayListEmployee != NULL)
	{
		for(i=0; i<ll_len(pArrayListEmployee);i++)
		{

			if(id == ((Employee*)ll_get(pArrayListEmployee,i))->id)
			{
				employee_printEmployee((Employee*)ll_get(pArrayListEmployee,i));
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
/**\brief busca un empleado por su id y devuelve su ubicacion en la lista
 * \param puntero al espacio en memoria de ese empleado
 * \param variable que contiene el id a buscar
 * \return devuelve la ubicacion en la lista si lo encontro y -1 si no lo encontro
 *
 */
int employee_findById(LinkedList* pArrayListEmployee, int id)
{
	int retorno = -1;
	int i;
	if(pArrayListEmployee != NULL)
	{
		for(i=0; i<ll_len(pArrayListEmployee);i++)
		{
			if(id == ((Employee*)ll_get(pArrayListEmployee,i))->id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
/**\brief buscar el id maximo utilizado hasta ese momento
 * \param puntero al espacio en memoria de la lista a analizar
 * \return devuelve el id maximo hasta el momento 0 -1 si hubo un error
 */
int employee_idMax(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int idMax = 0;

	if(pArrayListEmployee != NULL)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			if(idMax < ((Employee*)ll_get(pArrayListEmployee,i))->id)
			{
				idMax = ((Employee*)ll_get(pArrayListEmployee,i))->id;
			}
		}
		idMax++;

		retorno = idMax;
	}

	return retorno;
}
/**\brief analiza si el sueldo de emplado es mayor a otro  y si son iguales los compara por cantidad de horas trabajadas
 * \param puntero al primer elemento a comparar
 * \param puntero al segundo elemento a comparar
 * \return devuelve 1 si el elemento 1 es mayor, -1 si es menos y si es igual y las horas trabajadas del elemento 1 son mayores devuelve 1 y -1 si son menores
 */
int employee_funcionCriterioPorSueldo(void* item1,void* item2)
{
	int retorno = 0;
	int sueldo1;
	int sueldo2;
	if(item1 != NULL && item2 != NULL)
	{
		Employee* aux1 =(Employee*) item1;
		Employee* aux2 =(Employee*) item2;
		if(!employee_getSueldo(aux1,&sueldo1)&&
		   !employee_getSueldo(aux2,&sueldo2))
		{
			if(sueldo1 > sueldo2)
			{
				retorno = 1;
			}
			else if(sueldo1 < sueldo2)
			{
				retorno = -1;
			}
			else
			{
				retorno = employee_funcionCriterioPorHorasT(item1,item2);
			}
		}

	}
	return retorno;
}
/**\brief compara dos elementos del tipo empleado y devuelve si las horas trabajadas del elemento 1 son mayores que las del elemento 2
 * \param puntero al primer elemento a comparar
 * \param puntero al segundo elemento a comparar
 * \return devuelve 1 si las horas trabajadas del elemento 1 son mayores al elemento 2 o -1 si son menores
 */
int employee_funcionCriterioPorHorasT(void* item1,void* item2)
{
	int retorno = 0;
	int horasT1;
	int horasT2;
	if(item1 != NULL && item2 != NULL)
	{
		Employee* aux1 =(Employee*) item1;
		Employee* aux2 =(Employee*) item2;
		if(!employee_getHorasTrabajadas(aux1,&horasT1)&&
		   !employee_getHorasTrabajadas(aux2,&horasT2))
		{
			if(horasT1 > horasT2)
			{
				retorno = 1;
			}
			else if(horasT1 < horasT2)
			{
				retorno = -1;
			}
		}

	}
	return retorno;
}
/**\brief compara dos elementos del tipo empleado y devuelve si el nombre del elemento 1 es mayor que del elemento 2, en el caso que sean iguales evalua los sueldos
 * \param puntero al primer elemento a comparar
 * \param puntero al segundo elemento a comparar
 * \return devuelve 1 si el elemento 1 es mayor al elemento 2 o -1 si no lo es
 */
int employee_funcionCriterioPorOrdenPorNombre(void* item1,void* item2)
{
	int retorno = 0;
	char nombreAux[128];
	char nombreAux2[128];
	if(item1 != NULL && item2 != NULL)
	{
		Employee* aux1 =(Employee*) item1;
		Employee* aux2 =(Employee*) item2;
		if(!employee_getNombre(aux1,nombreAux)&&
		   !employee_getNombre(aux2,nombreAux2))
		{
			if(strncmp(nombreAux,nombreAux2,128) > 0)
			{
				retorno = 1;
			}
			else if(strncmp(nombreAux,nombreAux2,128) == 0)
			{
				retorno = employee_funcionCriterioPorSueldo(item1,item2);
			}
			else
			{
				retorno = -1;
			}
		}

	}
	return retorno;
}
//funcion criterio map

/**\brief aumenta un 20% los sueldos de los empleados
 * \param puntero al elemento a comparar
 * \return devuelve 1 si pudo concretar el aumento o -1 si el puntero al elemento es NULL
 */
int employee_funcionCriterioAumentar(void* pElement)
{
	int retorno = -1;
	int sueldo;
	int porcentajeAumento = 20;

	if(pElement != NULL)
	{
		Employee* auxEmployee =(Employee*) pElement;
		if(!employee_getSueldo(auxEmployee,&sueldo))
		{
			sueldo =sueldo + ((sueldo*porcentajeAumento) / 100);
			if(!employee_setSueldo(auxEmployee,sueldo))
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
			}
		}

	}
	return retorno;
}

//funcion criterio reduce

/**\brief evalua si el empleado tiene un sueldo menor a 20000 y devuelve el resultado
 * \param puntero al elemento a comparar
 * \return devuelve 1 si el sueldo es menor, 0 si el sueldo no lo es y -1 si el puntero al elemento es NULL
 */
int employee_funcionCriterioMayoresA20(void* pElement)
{
	int retorno = -1;
	int sueldo;

	if(pElement != NULL)
	{
		Employee* auxEmployee =(Employee*) pElement;
		if(!employee_getSueldo(auxEmployee,&sueldo))
		{
			if(sueldo < 20000)
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
			}
		}

	}
	return retorno;
}


//funcion criterio filter

/**\brief verifica si el nombre del empledo empieza con la letra b y devuelve el resultado
 * \param puntero al elemento a comparar
 * \return devuelve 1 si el nombre empieza con esa letra, 0 si no y -1 si el puntero al elemento es NULL
 */
int employee_funcionCriterioNombreConM(void* pElement)
{
	int retorno = -1;
	char nombre[128];


	if(pElement != NULL)
	{
		Employee* auxEmployee =(Employee*) pElement;
		if(!employee_getNombre(auxEmployee,nombre))
		{
			if(nombre[0] == 'b' || nombre[0] == 'B')
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}
LinkedList* employee_crearListaConAumentos(LinkedList* this)
{
	LinkedList* auxList = NULL;
	if(this != NULL)
	{
		auxList = ll_filter(this,employee_funcionCriterioMayoresA20);
		if(auxList != NULL)
		{
			if(!ll_map(auxList,employee_funcionCriterioAumentar))
			{
				if(!ll_reduce(auxList,employee_funcionCriterioNombreConM))
				{
					printf("ok\n");
				}
			}
		}

	}

	return auxList;
}
/**\brief busca el sueldo maximo entre los elementos y lo compara con el numero max
 * \param puntero al elemento a comparar
 * \param puntero al elemento a comparar
 * \param variable a comparar como maximo
 * \return devuelve el numero maximo y -1 si el puntero al elemento es NULL
 */
int employee_funcionCriterioMax(void* item1,void* item2,int max)
{
	int retorno = 0;
	int sueldo1;
	int sueldo2;
	if(item1 != NULL && item2 != NULL)
	{
		Employee* aux1 =(Employee*) item1;
		Employee* aux2 =(Employee*) item2;
		if(!employee_getSueldo(aux1,&sueldo1)&&
		   !employee_getSueldo(aux2,&sueldo2))
		{
			if(max == -1)
			{
				max = sueldo1;
			}
			if(sueldo1 > sueldo2 && sueldo1 > max)
			{
				retorno = sueldo1;
			}
			else if(sueldo1 < sueldo2 && sueldo2 > max)
			{
				retorno = sueldo2;
			}
			else
			{
				retorno = max;
			}
		}

	}
	return retorno;

}

/**\brief busca el sueldo minimo entre los elementos y lo compara con el numero max
 * \param puntero al elemento a comparar
 * \param puntero al elemento a comparar
 * \param variable a comparar como maximo
 * \return devuelve el numero minimo y -1 si el puntero al elemento es NULL
 */
int employee_funcionCriterioMin(void* item1,void* item2,int min)
{
	int retorno = 0;
	int sueldo1;
	int sueldo2;
	if(item1 != NULL && item2 != NULL)
	{
		Employee* aux1 =(Employee*) item1;
		Employee* aux2 =(Employee*) item2;
		if(!employee_getSueldo(aux1,&sueldo1)&&
		   !employee_getSueldo(aux2,&sueldo2))
		{
			if(min == -1)
			{
				min = sueldo1;
			}
			if(sueldo1 < sueldo2 && sueldo1 < min)
			{
				retorno = sueldo1;
			}
			else if(sueldo1 < sueldo2 && sueldo2 < min)
			{
				retorno = sueldo2;
			}
			else
			{
				retorno = min;
			}
		}

	}
	return retorno;

}

/**\brief cuenta los empleados con sueldos mayores a 30000
 * \param puntero al elemento a comparar
 * \return devuelve 1 si el sueldo es mayor y -1 si el puntero al elemento es NULL
 */
int employee_funcionCriterioSueldosMayores30(void* item1)
{
	int retorno = -1;
	int sueldo;
	if(item1 != NULL)
	{
		Employee* aux1 =(Employee*) item1;
		if(!employee_getSueldo(aux1,&sueldo))
		{
			if(sueldo > 30000)
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
			}
		}

	}
	return retorno;

}
/**\brief busca el sueldo minimo y devuelve el resultado
 * \param puntero al elemento a comparar
 * \param puntero al elemento a comparar
 * \return devuelve el 1 si el item1 es menor que el item2 y -1 si el puntero al elemento es NULL
 */
int employee_funcionCriterioMinPelement(void* item1,void* item2)
{
	int retorno = -1;
	int sueldo1;
	int sueldo2;
	if(item1 != NULL && item2 != NULL)
	{
		Employee* aux1 =(Employee*) item1;
		Employee* aux2 =(Employee*) item2;
		if(!employee_getSueldo(aux1,&sueldo1)&&
		   !employee_getSueldo(aux2,&sueldo2))
		{

			if(sueldo1 < sueldo2)
			{
				retorno = 1;
			}
			else if(sueldo2 < sueldo1)
			{
				retorno = 0;
			}

		}

	}
	return retorno;

}
/**\brief busca el sueldo maximo y devuelve el resultado
 * \param puntero al elemento a comparar
 * \param puntero al elemento a comparar
 * \return devuelve el 1 si el item1 es mayor que el item2 y -1 si el puntero al elemento es NULL
 */
int employee_funcionCriterioMaxPelement(void* item1,void* item2)
{
	int retorno = -1;
	int sueldo1;
	int sueldo2;
	if(item1 != NULL && item2 != NULL)
	{
		Employee* aux1 =(Employee*) item1;
		Employee* aux2 =(Employee*) item2;
		if(!employee_getSueldo(aux1,&sueldo1)&&
		   !employee_getSueldo(aux2,&sueldo2))
		{

			if(sueldo1 > sueldo2)
			{
				retorno = 1;
			}
			else if(sueldo2 < sueldo1)
			{
				retorno = 0;
			}

		}

	}
	return retorno;

}


//////PUNTO 1
/**\brief aumenta el sueldo de los empleados segun horas trabajadas
 * \param puntero al elemento a comparar
 * \return devuelve 1 si pudo modificar el sueldo y -1 si el puntero al elemento es NULL
 */
int employee_funcionCriterioAumentarSueldoSegunHoras(void* item1)
{
	int retorno = -1;
	int sueldo;
	int horasT;
	if(item1 != NULL)
	{

		retorno = 0;
		Employee* aux1 =(Employee*) item1;
		if(!employee_getHorasTrabajadas(aux1,&horasT))
		{

			if(horasT >= 100)
			{
				sueldo = (horasT *50)*20;
				employee_setSueldo(aux1,sueldo);
				retorno = 1;
			}
			else if(horasT < 100)
			{
				sueldo = (horasT *30)*20;
				employee_setSueldo(aux1,sueldo);
				retorno = 1;
			}

		}

	}
	return retorno;

}
////PUNTO 2

/**\brief cuenta los empleados con sueldos mayores a 30000
 * \param puntero al elemento a comparar
 * \return devuelve 1 si el sueldo es mayor y -1 si el puntero al elemento es NULL
 */
int employee_funcionCriterioEmpleadosQueTrabajanMas90Hs(void* item1)
{
	int retorno = -1;
	int horasT;
	if(item1 != NULL)
	{
		Employee* aux1 =(Employee*) item1;
		if(!employee_getHorasTrabajadas(aux1,&horasT))
		{
			if(horasT > 90)
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
			}
		}

	}
	return retorno;

}

////PUNTO 3
/**\brief cuenta los empleados con sueldos mayores a 30000
 * \param puntero al elemento a comparar
 * \return devuelve 1 si el sueldo es mayor y -1 si el puntero al elemento es NULL
 */
int employee_funcionCriterioTolalSueldosAPagar(void* item1)
{
	int retorno = -1;
	int sueldo;
	if(item1 != NULL)
	{
		retorno = 0;
		Employee* aux1 =(Employee*) item1;
		if(!employee_getSueldo(aux1,&sueldo))
		{
			retorno = sueldo;
		}

	}
	return retorno;

}
