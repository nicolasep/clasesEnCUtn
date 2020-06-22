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
    int opcionMostrar;
    int opcionVaciarLista;
    int opcionEliminarLista;
    int listaGuardar;
    int maxMin;
    int contadorSueldoMas30;
    int opcionMaxMin;

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleados2;
    LinkedList* listaEmpleados3;

    Employee* auxEmployee;
    Employee* auxEmployee2;

    do{

    	utn_getNumero(&option,"\nBIENVENIDO, ELIJA UNA OPCION\n"
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
    						  "14. Limpiar listas\n"
					          "15. Eliminar listas\n"
							  "16. Verificar si los emlpeados de la lista 2 estan en la lista 1\n"
    						  "17. Clonar lista 1 en lista 3\n"
    						  "18. Calcula el maximo o minimo de los sueldos de una lista\n"
    						  "19. Cuenta los sueldos que superan los 30000 de una lista\n"
    						  "20. Imprime el empleado con sueldo maximo y minimo\n"
							  "21. Salir\n","OPCION INCORRECTA\n",1,21,2);

        switch(option)
        {
            case 1://CARGA DE ARCHIVO MODO TEXTO
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
            case 2://CARGA DE ARCHIVO MODO BINARIO
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

            case 3://CARGA DE EMPLEADOS EN LISTA 1
            	controller_addEmployee(listaEmpleados);
            	break;

            case 4://EDIATAR EMPLEADOS EN LISTA 1
            	if(ll_isEmpty(listaEmpleados))
				{
					printf("Primero debe ingresar al menos un empleado\n");
				}
            	else
            	{
            		controller_editEmployee(listaEmpleados);
            	}

            	break;
            case 5://REMOVER EMPLEADOS EN LISTA 1
            	if(ll_isEmpty(listaEmpleados))
				{
					printf("Primero debe ingresar al menos un empleado\n");
				}
				else
				{
					controller_removeEmployee(listaEmpleados);
				}

            	break;

            case 6://IMPRIMIR EMPLEADOS
            	if(!utn_getNumero(&opcionMostrar,"Elija la listar:\n"
												"1 - Lista de empleados 1 (Lista principal)\n"
												"2 - Lista de empleados 2\n"
												"3 - Lista de empleados 3\n","Error, opcion incorrecta\n",1,3,2))
            	{

            		switch(opcionMostrar)
            		{
            		case 1:
            			if(ll_isEmpty(listaEmpleados) && ll_len(listaEmpleados)<=0)
						{
							printf("Primero debe ingresar al menos un empleado\n");
						}
						else
						{
							controller_ListEmployee(listaEmpleados);
						}
            			break;
            		case 2:
            			if(ll_isEmpty(listaEmpleados2))
						{
							printf("Primero debe ingresar al menos un empleado\n");
						}
						else
						{
							controller_ListEmployee(listaEmpleados2);
						}
            			break;
            		case 3:
            			if(ll_isEmpty(listaEmpleados3))
						{
							printf("Primero debe ingresar al menos un empleado\n");
						}
						else
						{
							controller_ListEmployee(listaEmpleados3);
						}
            			break;

            		}
            		opcionMostrar = 0;
            	}


            	break;

            case 7://ORDENAR EMPLEADOS DE LISTA 1
            	if(ll_isEmpty(listaEmpleados))
				{
					printf("Primero debe ingresar al menos dos empleado\n");
				}
				else
				{
					controller_sortEmployee(listaEmpleados);
				}
            	break;

            case 8://GUARDAR EN ARCHIVO EN MODO TEXTO
            	if(!utn_getNumero(&listaGuardar,"Elija la listar a guardar:\n"
            													"1 - Lista de empleados 1 (Lista principal)\n"
            													"2 - Lista de empleados 2\n"
            													"3 - Lista de empleados 3\n","Error, opcion incorrecta\n",1,3,2)&&
            	   !utn_getArchivo(nombreArchivo,64,"Ingrese el nombre del archivo: ","Error, no es un nombre aceptable\n",2))
				{

					switch(listaGuardar)
					{
					case 1:
						if(ll_isEmpty(listaEmpleados))
						{
							printf("Primero debe ingresar al menos un empleado\n");
						}
						else
						{
							controller_saveAsText(nombreArchivo,listaEmpleados);
						}
						break;
					case 2:
						if(ll_isEmpty(listaEmpleados2))
						{
							printf("Primero debe ingresar al menos un empleado\n");
						}
						else
						{
							controller_saveAsText(nombreArchivo,listaEmpleados2);
						}
						break;
					case 3:
						if(ll_isEmpty(listaEmpleados3))
						{
							printf("Primero debe ingresar al menos un empleado\n");
						}
						else
						{
							controller_saveAsText(nombreArchivo,listaEmpleados3);
						}
						break;

					}
					opcionMostrar = 0;
				}

            	break;

            case 9://GUARDAR EN ARCHIVO EN MODO BINARIO
            	if(ll_isEmpty(listaEmpleados))
				{
					printf("No hay empleados a guardar\n");
				}
				else
				{
					controller_saveAsBinary("prueba.bin",listaEmpleados);
				}

            	break;

            case 10://USO DE MAP
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
            case 11://USO DE REDUCE
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

            case 12://USO DE FILTER. SE GUARDA EN LISTA 2
            	if(!ll_isEmpty(listaEmpleados))
				{
					listaEmpleados2 = ll_filter(listaEmpleados,employee_funcionCriterioNombreConM);

					if(listaEmpleados2 != NULL && !utn_confirmacionAccionChar("LISTA CREADA CON EXITO, SI DECEA MOSTRARLA INGRESE S: "))
					{
						controller_ListEmployee(listaEmpleados2);
					}
				}
            	else
				{
					printf("Primero debe ingresar empleados\n");
				}

				break;
            case 13://USO DE MAP, REDUCE Y FILTER. SE GUARDA EN LISTA 3
            	if(!ll_isEmpty(listaEmpleados))
				{
					listaEmpleados3 = employee_crearListaConAumentos(listaEmpleados);

					if(listaEmpleados3 != NULL && !utn_confirmacionAccionChar("LISTA CREADA CON EXITO, SI DECEA MOSTRARLA INGRESE S: "))
					{
						controller_ListEmployee(listaEmpleados3);
					}
				}
            	else
				{
					printf("Primero debe ingresar empleados\n");
				}

				break;

            case 14://VACIAR LISTA INDICADA

            	if(!utn_getNumero(&opcionVaciarLista,"Elija la listar a vaciar:\n"
													"1 - Lista de empleados 1 (Lista principal)\n"
													"2 - Lista de empleados 2\n"
													"3 - Lista de empleados 3\n","Error, opcion incorrecta\n",1,3,2))
				{

					switch(opcionVaciarLista)
					{
					case 1:
						if(ll_isEmpty(listaEmpleados))
						{
							printf("La lista se encuentra vacia\n");
						}
						else
						{
							if(!ll_clear(listaEmpleados))
							{
								printf("Se elimino todo el contenido de la lista\n");
								flagCarga = 0;
							}
							else
							{
								printf("no se pudo eliminar el contenido de la lista\n");
							}
						}
						break;
					case 2:
						if(ll_isEmpty(listaEmpleados2))
						{
							printf("La lista se encuentra vacia\n");
						}
						else
						{
							if(!ll_clear(listaEmpleados2))
							{
								printf("Se elimino todo el contenido de la lista\n");
							}
						}
						break;
					case 3:
						if(ll_isEmpty(listaEmpleados3))
						{
							printf("La lista se encuentra vacia\n");
						}
						else
						{
							if(!ll_clear(listaEmpleados3))
							{
								printf("Se elimino todo el contenido de la lista\n");
							}
						}
						break;

					}
					opcionMostrar = 0;
					flagCarga = 0;
				}
				break;

            case 15://ELIMINAR LISTA SELECCIONADA
            	if(!utn_getNumero(&opcionEliminarLista,"Elija la listar a eliminar:\n"
            														"1 - Lista de empleados 1 (Lista principal)\n"
            														"2 - Lista de empleados 2\n"
            														"3 - Lista de empleados 3\n","Error, opcion incorrecta\n",1,3,2))
				{
					switch(opcionEliminarLista)
					{
					case 1:
						if(!ll_deleteLinkedList(listaEmpleados))
						{
							printf("La lista se elimino con exito elementos: %d\n",listaEmpleados->size);

						}
						else
						{
							printf("La lista no existe\n");
						}
						break;
					case 2:
						if(!ll_deleteLinkedList(listaEmpleados2))
						{
							printf("La lista se elimino con exito elementos: %d\n",listaEmpleados->size);
						}
						else
						{
							printf("La lista no existe\n");
						}
						break;
					case 3:
						if(!ll_deleteLinkedList(listaEmpleados3))
						{
							printf("La lista se elimino con exito elementos: %d\n",listaEmpleados->size);
						}
						else
						{
							printf("La lista no existe\n");
						}
						break;

					}
					opcionEliminarLista = 0;
					flagCarga = 0;
				}
				break;

            case 16://containAll
            	if(ll_isEmpty(listaEmpleados))
				{
					printf("La lista se encuentra vacia\n");
				}
				else
				{
					if(ll_containsAll(listaEmpleados,listaEmpleados2))
					{
						printf("Los elementos de la lista 2 estan contenidos en la lista 1\n");
					}
					else
					{
						printf("1 o mas elementos de la lista 2 no se encuentran en la lista 1\n");
					}

				}
            	break;

            case 17: //clone
            	if(ll_isEmpty(listaEmpleados))
            	{
            		printf("La lista se encuentra vacia\n");
            	}
            	else
            	{
            		listaEmpleados3 = ll_clone(listaEmpleados);
            		if(listaEmpleados3 != NULL)
            		{
            			printf("La lista fue clonada con exito\n");
            		}
            	}
            	break;

            case 18://Maximo o minimo de una lista
            	if(!utn_getNumero(&opcionMostrar,"Elija la listar:\n"
            													"1 - Lista de empleados 1 (Lista principal)\n"
            													"2 - Lista de empleados 2\n"
            													"3 - Lista de empleados 3\n","Error, opcion incorrecta\n",1,3,2)&&
            	   !utn_getNumero(&opcionMaxMin,"1 - Obtener el maximo\n"
            			                        "2 - Obtener minimo\n","Opcion incorrecta\n",1,2,2))
				{

					switch(opcionMostrar)
					{
					case 1:
						if(ll_isEmpty(listaEmpleados) && ll_len(listaEmpleados)<=0)
						{
							printf("Primero debe ingresar al menos un empleado\n");
						}
						else
						{
							if(opcionMaxMin == 1)
							{
								maxMin = ll_countMaxMin(listaEmpleados,employee_funcionCriterioMax,opcionMaxMin-1);
								printf("El sueldo maximo es: %d",maxMin);

							}
							else if(opcionMaxMin == 2)
							{
								maxMin = ll_countMaxMin(listaEmpleados,employee_funcionCriterioMin,opcionMaxMin-1);
								printf("El sueldo minimo es: %d",maxMin);
							}


						}
						break;
					case 2:
						if(ll_isEmpty(listaEmpleados2))
						{
							printf("Primero debe ingresar al menos un empleado\n");
						}
						else
						{
							if(opcionMaxMin)
							{
								maxMin = ll_countMaxMin(listaEmpleados2,employee_funcionCriterioMax,opcionMaxMin-1);
								printf("El sueldo maximo es: %d",maxMin);

							}
							else
							{
								maxMin = ll_countMaxMin(listaEmpleados2,employee_funcionCriterioMin,opcionMaxMin-1);
								printf("El sueldo minimo es: %d",maxMin);
							}
						}
						break;
					case 3:
						if(ll_isEmpty(listaEmpleados3))
						{
							printf("Primero debe ingresar al menos un empleado\n");
						}
						else
						{
							if(opcionMaxMin)
							{
								maxMin = ll_countMaxMin(listaEmpleados3,employee_funcionCriterioMax,opcionMaxMin-1);
								printf("El sueldo maximo es: %d",maxMin);

							}
							else
							{
								maxMin = ll_countMaxMin(listaEmpleados3,employee_funcionCriterioMin,opcionMaxMin-1);
								printf("El sueldo minimo es: %d",maxMin);
							}
						}
						break;

					}
					opcionMostrar = 0;
					opcionMaxMin = 0;
				}
				break;

            case 19://count sueldos mayores a 30000
            	if(!utn_getNumero(&opcionMostrar,"Elija la listar:\n"
            													"1 - Lista de empleados 1 (Lista principal)\n"
            													"2 - Lista de empleados 2\n"
            													"3 - Lista de empleados 3\n","Error, opcion incorrecta\n",1,3,2))
				{

					switch(opcionMostrar)
					{
					case 1:
						if(ll_isEmpty(listaEmpleados))
						{
							printf("Primero debe ingresar al menos un empleado\n");
						}
						else
						{
							contadorSueldoMas30 = ll_count(listaEmpleados,employee_funcionCriterioSueldosMayores30);
							printf("Cantidad de sueldos mayores a 30000 de lista1 son: %d\n",contadorSueldoMas30);
						}
						break;
					case 2:
						if(ll_isEmpty(listaEmpleados2))
						{
							printf("Primero debe ingresar al menos un empleado\n");
						}
						else
						{
							contadorSueldoMas30 = ll_count(listaEmpleados2,employee_funcionCriterioSueldosMayores30);
							printf("Cantidad de sueldos mayores a 30000 de lista2 son: %d\n",contadorSueldoMas30);
						}
						break;
					case 3:
						if(ll_isEmpty(listaEmpleados3))
						{
							printf("Primero debe ingresar al menos un empleado\n");
						}
						else
						{
							contadorSueldoMas30 = ll_count(listaEmpleados3,employee_funcionCriterioSueldosMayores30);
							printf("Cantidad de sueldos mayores a 30000 de lista3 son: %d\n",contadorSueldoMas30);
						}
						break;

					}
					opcionMostrar = 0;
				}
            	break;
            case 20:
            	if(ll_isEmpty(listaEmpleados))
				{
					printf("Primero debe ingresar al menos un empleado\n");
				}
				else
				{
					printf("\nEl maximo es: ");
					auxEmployee =(Employee*) ll_countPelement(listaEmpleados,employee_funcionCriterioMaxPelement);
					employee_printEmployee(auxEmployee);

					printf("\nEl minimo es: ");
					auxEmployee2 =(Employee*) ll_countPelement(listaEmpleados,employee_funcionCriterioMinPelement);
					employee_printEmployee(auxEmployee2);
				}
				break;
        }



    }while(option != 21);


    return 0;
}
