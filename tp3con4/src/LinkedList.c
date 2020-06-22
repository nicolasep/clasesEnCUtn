#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }


    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{

	Node* auxNode = NULL;
	int indice;
	if(this != NULL && nodeIndex < this->size && nodeIndex >= 0)
	{
		auxNode = this->pFirstNode;
		indice = 0;
		do
		{
			if(indice == nodeIndex)
			{
			  break;
			}
			else
			{
				auxNode = auxNode->pNextNode;
				indice++;
			}
		}while(indice < ll_len(this));
	}
    return auxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{

	int returnAux = -1;
	Node* nodeNew;
	Node* nodeAux;

	if(nodeIndex >= 0 && this != NULL && nodeIndex <= ll_len(this))
	{
		nodeNew = (Node*)malloc(sizeof(Node));
		if(nodeNew != NULL)
		{
			nodeNew->pElement = pElement;
			nodeNew->pNextNode = NULL;
			if(nodeIndex == 0)
			{
				nodeNew->pNextNode = this->pFirstNode;
				this->pFirstNode = nodeNew;
			}
			else if(nodeIndex==this->size)
			{
				nodeAux = getNode(this,nodeIndex-1);
				nodeAux->pNextNode = nodeNew;
			}
			else
			{
				nodeAux = getNode(this,nodeIndex-1);
				nodeNew->pNextNode = nodeAux->pNextNode;
				nodeAux->pNextNode = nodeNew;
			}
		}
		this->size++;
		returnAux = 0;
	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(!addNode(this,ll_len(this),pElement))
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxNode = getNode(this,index);
    	if(auxNode != NULL)
    	{
    		returnAux = auxNode->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;

    if(this != NULL && index >= 0 && index <ll_len(this))
    {
    	if(index == 0)
    	{
    		auxNode = this->pFirstNode;
    		auxNode->pElement = pElement;
    	}
    	else
    	{
    		auxNode = getNode(this,index);
    		if(auxNode != NULL)
			{
				auxNode->pElement = pElement;
			}
    	}
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxNode = NULL;
    Node* auxNode2 = NULL;
    void* auxpElement = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	returnAux = 0;
    	auxNode = getNode(this,index);
    	auxNode2 = getNode(this,index-1);
    	auxpElement = auxNode->pElement;
    	if(index == 0)
    	{
    		if(auxNode != NULL)
    		{
    			this->pFirstNode = auxNode->pNextNode;
    			auxNode = NULL;
    			free(auxpElement);
    		}
    	}
    	else
    	{
    		if(auxNode != NULL && auxNode2 != NULL)
    		{
    			auxNode2->pNextNode = auxNode->pNextNode;
    			auxNode = NULL;
    			free(auxpElement);
    		}
    	}
    	this->size--;
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	do
    	{
    		if(!ll_remove(this,0))
    		{
    			returnAux = 0;
    		}
    	}while(ll_len(this) > 0);
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if(!ll_clear(this))
    	{
    		free(this);
    		this->pFirstNode = NULL;
    		this->size = 0;
    		returnAux = 0;
    	}

    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indice = 0;
    void* aux = NULL;
    if(this != NULL)
    {
    	do
    	{
    		aux = ll_get(this,indice);

    		if(pElement == aux)
    		{
    			returnAux = indice;
    			break;
    		}
    	    indice++;

    	}while(indice < ll_len(this));

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if(ll_len(this) > 0)
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >=0 && index <=ll_len(this))
    {
    	if(addNode(this,index,pElement)==0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this !=NULL && index >= 0 && index <ll_len(this))
    {
    	returnAux = ll_get(this,index);
    	ll_remove(this,index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* aux = NULL;
    int indice = 0;
    if(this != NULL)
    {
    	returnAux = 0;
    	do
    	{
    		aux = ll_get(this,indice);
			if(aux == pElement && aux!= NULL)
			{
				returnAux = 1;
				break;
			}
			indice++;

    	}while(indice < ll_len(this));

    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* aux = NULL;
    int indice = 0;
    if(this != NULL && this2 != NULL)
    {
    	do
		{
			returnAux = 1;
			aux = ll_get(this2,indice);

				if(!ll_contains(this,aux))
				{
					returnAux = 0;
					break;
				}
				indice++;


		}while(indice < ll_len(this2));
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray =NULL;
    int indice;
    void* aux = NULL;
    if(this != NULL && from >= 0 && to>=from && to<=ll_len(this))
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		indice = from;
			do
			{
				aux = ll_get(this,indice);
				ll_add(cloneArray,aux);

				indice++;

			}while(indice < to);
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		cloneArray = ll_subList(this,0,ll_len(this));
    	}
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* aux = NULL;
    void* aux2 = NULL;
    void* auxSwap = NULL;
    int limite = ll_len(this)-1;
    int flagSwap;
    int i;
    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
    	returnAux = 0;
		do
		{
			flagSwap = 0;
			for(i=0;i<limite;i++)
			{
			 aux = ll_get(this,i);
			 aux2 = ll_get(this,i+1);
			 auxSwap = aux;
				if((pFunc(aux,aux2))== -1 && order == 0)
				{
					ll_set(this,i,aux2);
					ll_set(this,i+1,auxSwap);
					flagSwap = 1;
				}
				else if((pFunc(aux,aux2))== 1 && order == 1)
				{
					ll_set(this,i,aux2);
					ll_set(this,i+1,auxSwap);
					flagSwap = 1;
				}
			}
			limite--;
		}while(flagSwap);
    }

    return returnAux;

}
/*agarra cada elemento de linkedlist y se lo pasa como parametro a la funcion
 * por ejemplo incrementar el salario de los empleados de lista*/

/** \brief realiza una accion sobre cada elemento de la lista que decide la funcion criterio
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
	int retorno = -1;
	int indice = 0;
	void* pElement = NULL;
	if(this != NULL && pFunc != NULL)
	{
		do
		{
			pElement = ll_get(this,indice);

			if(pFunc(pElement))
			{
				retorno = 0;
			}

			indice++;
		}while(indice < ll_len(this));
	}

	return retorno;
}

/*dice si se elimina o no ese elemento de la lista, el que se paso a la funcion criterio
 * se llama por cada elemento de la lista, devuelve la lista sin los elementos. hay que recorrerla desde el final*/

/** \brief elimina de la lista elementos elejidos por la funcion criterio
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_reduce(LinkedList* this, int (*pFunc)(void*))
{
	int retorno = -1;
	void* pElement = NULL;
	int indice = ll_len(this)-1;

	if(this != NULL && pFunc != NULL)
	{
		do
		{
			pElement = ll_get(this,indice);
			if(!pFunc(pElement))
			{
				ll_remove(this,indice);
			}
			indice--;
			retorno = 0;
		}while(indice >= 0);
	}
	return retorno;
}
/*devuelve una nueva lista con elementos que decide la funcion criterio*/

/** \brief crea una nueva lista y la devuelve con elementos elejidos por la funcion criterio
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
 */

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
  LinkedList* auxLista = NULL;
  void* pElement = NULL;
  int indice = 0;

  if(this != NULL && pFunc != NULL)
  {
	  auxLista = ll_newLinkedList();
	  do
	  {
		  if(auxLista != NULL)
		  {
			  pElement = ll_get(this,indice);
			  if(pFunc(pElement))
			  {
				  ll_add(auxLista,pElement);
			  }
		  }
		  indice++;

	  }while(indice < ll_len(this));

  }

  return auxLista;
}
//LinkedList* ll_countMaxMin(this,int)

/** \brief Buscar el maximo o minimo segun ordene la funcion criterio y devuelve el indice
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int [1] Indica buscar minimo - [0] Indica buscar maximo
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                (maximo o minimo) Si ok
 */
int ll_countMaxMin(LinkedList* this, int (*pFunc)(void* ,void*,int),int tipo)
{
    int returnAux =-1;
    void* aux = NULL;
    void* aux2 = NULL;

    int auxInt;
    int limite = ll_len(this)-1;
    int flagSwap;
    int i;
    if(this != NULL && pFunc != NULL)
    {
		do
		{
			flagSwap = 0;
			for(i=0;i<limite;i++)
			{
			 aux = ll_get(this,i);
			 aux2 = ll_get(this,i+1);
			 if(i==0)
			 {
				 auxInt = -1;
			 }
			 auxInt = pFunc(aux,aux2,auxInt);
			 	 if(tipo == 0)
			 	 {
			 		 if(i==0)
			 		 {
			 			returnAux = auxInt;
			 		 }
			 		 else if(auxInt > returnAux)
			 		 {
			 			returnAux = auxInt;
			 		 }

			 	 }
			 	 else if(tipo == 1)
			 	 {
			 		 if(i==0)
					 {
			 			returnAux = auxInt;
					 }
					 else if(auxInt < returnAux)
					 {
						returnAux = auxInt;
					 }
			 	 }

			}
			limite--;
		}while(flagSwap);
    }

    return returnAux;

}
/** \brief cuenta la cantidad de elementos que cumplen con la funcion criterio y lo devuelve
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                (la suma total) Si ok
 */
int ll_count(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux =-1;
    void* aux = NULL;
    int i=0;
    if(this != NULL && pFunc != NULL)
    {
		do
		{

			 aux = ll_get(this,i);
			 if(i==0)
			 {
				 returnAux = 0;
			 }

			 if(pFunc(aux)==1)
			 {
				returnAux++;
			 }

			 i++;

		}while(i < ll_len(this));
    }

    return returnAux;

}
/** \brief cuenta la cantidad de elementos que cumplen con la funcion criterio y lo devuelve
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                (el elemento) Si ok
 */
LinkedList* ll_countPelement(LinkedList* this, int (*pFunc)(void*, void*))
{

    void* aux = NULL;
    void* returnAux = NULL;

    int i=0;
    if(this != NULL && pFunc != NULL)
    {
		do
		{

			 aux = ll_get(this,i);
			 if(i==0)
			 {
				 returnAux = aux;
			 }
			 else if(pFunc(aux,returnAux) == 1)
			 {
				 returnAux = aux;
			 }

			 i++;

		}while(i < ll_len(this));
    }

    return returnAux;

}
/*cantidadDeEmpleadosQueTrabajnMasDe8 = funcion ll_count(listaEmpleados,empleadosTrabajanMasDe8Horas);
 *
 * funcion ll_count()
 * devuelve lo que va contando, se puede usar para sacar un maximo o para saber por ejemplo cuantos empleados trabajan mas de 8 horas
 *
 * hacer reduce para sacar maximo
 * LinkedList* ll_mayor(LinkedList* this, int (*funArgumento)(void*)
 * {
 * int i;
 * void* element = NULL;
 *
 *   if(this != NULL && funArgumento != NULL)
 *   {
 *   	for(i=0; i<ll_len(this);i++)
 *   	{
 *   		element = ll_get(this,i);
 *
 *   		valor = funArgument(element);
 *   		if(valor>mayor)
 *   		{
 *   			mayor = valor;
 *   		}
 *   	}
 *   }
 *
 * }
 * */

/*
int nose()
{

	if(valor>mayor)
	{
		mayor = valor;
	}
}
*/
