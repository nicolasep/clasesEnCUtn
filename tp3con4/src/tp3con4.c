#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout,NULL);

	int flagCarga = 0;
    int option;
    char nombreArchivo[64];

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaNombreConM;
    LinkedList* listaNombresMConAumentos;

    do{
    	utn_getNumero(&option,"\nBIENVENIDO, ILIJA UNA OPCION\n"
    			              "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
					          "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
					          "3. Alta de empleado\n"
					          "4. Modificar datos de empleado\n"
					          "5. Baja de empleado\n"
					          "6. Listar empleados\n"
					          "7. Ordenar empleados\n"
					          "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
					          "9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
    						  "10. Aumentar 20 porciento los sueldos\n"
    						  "11. Empleados con sueldos menores a 20000\n"
    						  "12. Crear lista de nombres con B\n"
    						  "13. Crea una nueva lista con los empleados cuyos nombres comiencen con B con sueldo menor a 20, mas aumento\n"
    						  "14. Limpiar lista principal\n"
					          "15. Salir\n","OPCION INCORRECTA\n",1,15,2);

        switch(option)
        {
            case 1:
            	if(flagCarga)
            	{
            		printf("El archivo ya fue cargado\n");
            	}
            	else
            	{
            		if(!utn_getArchivo(nombreArchivo,64,"Ingrese el nombre del archivo: ","Error, no es un nombre aceptable\n",2)&&
            				!controller_loadFromText(nombreArchivo,listaEmpleados))
            		{
                	flagCarga = 1;
            		}
            		else
            		{
            			printf("El archivo no se pudo cargar\n");
            		}
            	}

                break;
            case 2:
            	if(flagCarga)
				{
					printf("El archivo ya fue cargado\n");
				}
				else
				{
					if(!controller_loadFromBinary("data.bin",listaEmpleados))
					{
					flagCarga = 1;
					}
					else
					{
						printf("El archivo no se pudo cargar\n");
					}
				}

            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	if(ll_isEmpty(listaEmpleados))
				{
					printf("Primero debe ingresar al menos un empleado\n");
				}
            	else
            	{
            		controller_editEmployee(listaEmpleados);
            	}

            	break;
            case 5:
            	if(ll_isEmpty(listaEmpleados))
				{
					printf("Primero debe ingresar al menos un empleado\n");
				}
				else
				{
					controller_removeEmployee(listaEmpleados);
				}

            	break;
            case 6:
            	if(ll_isEmpty(listaEmpleados))
				{
					printf("Primero debe ingresar al menos un empleado\n");
				}
				else
				{
					controller_ListEmployee(listaEmpleados);
				}


            	break;
            case 7:
            	if(ll_isEmpty(listaEmpleados))
				{
					printf("Primero debe ingresar al menos dos empleado\n");
				}
				else
				{
					controller_sortEmployee(listaEmpleados);
				}
            	break;
            case 8:
            	if(ll_isEmpty(listaEmpleados))
				{
					printf("No hay empleados a guardar\n");
				}
				else
				{
					if(!utn_getArchivo(nombreArchivo,64,"Ingrese el nombre del archivo: ","Error, no es un nombre aceptable\n",2))
					{
						controller_saveAsText(nombreArchivo,listaEmpleados);
					}
				}

            	break;
            case 9:
            	if(ll_isEmpty(listaEmpleados))
				{
					printf("No hay empleados a guardar\n");
				}
				else
				{
					controller_saveAsBinary("prueba.bin",listaEmpleados);
				}

            	break;
            case 10:
            	if(!ll_isEmpty(listaEmpleados))
            	{
            		if(!ll_map(listaEmpleados,employee_funcionCriterioAumentar) && !utn_confirmacionAccionChar("LISTA MODIFICADA CON EXITO, SI DECEA MOSTRARLA INGRESE S: "))
					{
						controller_ListEmployee(listaEmpleados);
					}
            	}
            	else
            	{
            		printf("Primero debe ingresar empleados\n");
            	}

            	break;
            case 11:
            	if(!ll_isEmpty(listaEmpleados))
				{
            		if(!ll_reduce(listaEmpleados,employee_funcionCriterioMayoresA20) && !utn_confirmacionAccionChar("LISTA REDUCIDA CON EXITO, SI DECEA MOSTRARLA INGRESE S: "))
					{
						controller_ListEmployee(listaEmpleados);
					}
				}
            	else
				{
					printf("Primero debe ingresar empleados\n");
				}

            	break;
            case 12:
            	if(!ll_isEmpty(listaEmpleados))
				{
					listaNombreConM = ll_filter(listaEmpleados,employee_funcionCriterioNombreConM);

					if(listaNombreConM != NULL && !utn_confirmacionAccionChar("LISTA CREADA CON EXITO, SI DECEA MOSTRARLA INGRESE S: "))
					{
						controller_ListEmployee(listaNombreConM);
					}
				}
            	else
				{
					printf("Primero debe ingresar empleados\n");
				}

				break;
            case 13:
            	if(!ll_isEmpty(listaEmpleados))
				{
					listaNombresMConAumentos = employee_crearListaConAumentos(listaEmpleados);

					if(listaNombresMConAumentos != NULL && !utn_confirmacionAccionChar("LISTA CREADA CON EXITO, SI DECEA MOSTRARLA INGRESE S: "))
					{
						controller_ListEmployee(listaNombresMConAumentos);
					}
				}
            	else
				{
					printf("Primero debe ingresar empleados\n");
				}

				break;
            case 14:
            	if(ll_isEmpty(listaEmpleados))
            	{
            		printf("La lista esta vacia\n");
            	}
            	else if(!ll_clear(listaEmpleados))
            	{
            		printf("Se elimino todo el contenido de la lista\n");
            		flagCarga = 0;
            	}
            	break;
        }
    }while(option != 15);


    return 0;
}
