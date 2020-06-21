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
    LinkedList* nuevaLista;

    nuevaLista = (LinkedList*) malloc(sizeof(LinkedList));

    if(nuevaLista != NULL)
    {
        nuevaLista->size = 0;
        nuevaLista->pFirstNode = NULL;
    }

    return nuevaLista;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int cantidad = -1;

    if(this != NULL)
    {
        cantidad = this->size;
    }

    return cantidad;
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
    int len = ll_len(this);
    Node* pNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < len)
    {
        pNode = this->pFirstNode;
        for(int i = 0; i < nodeIndex; i++)
        {
            pNode = pNode->pNextNode;
        }
    }
    return pNode;
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
    int len = ll_len(this);
    Node* newNode = NULL;
    Node* NodeAnterior;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= len)
    {
        newNode = (Node*) malloc(sizeof(Node));

        if(newNode != NULL)
        {
            newNode->pElement = pElement;
            newNode->pNextNode = NULL;

            if(nodeIndex == 0)
            {
                newNode->pNextNode = this->pFirstNode;
                this->pFirstNode = newNode;
            }
            else
            {
                NodeAnterior = getNode(this,nodeIndex - 1);
                newNode->pNextNode = NodeAnterior->pNextNode;
                NodeAnterior->pNextNode = newNode;
            }
            this->size++;
            returnAux = 0;
        }
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
    int len = ll_len(this);

    if(this != NULL)
    {
        addNode(this,len,pElement);
        returnAux = 0;
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
    Node* returnAux = NULL;
    void* pElement = NULL;
    int len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
        returnAux = getNode(this,index);
        pElement = returnAux->pElement;
    }
    return pElement;
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
    int len = ll_len(this);
    Node* auxNode;

    if(this != NULL && index >= 0 && index < len)
    {
        auxNode = getNode(this,index);
        auxNode->pElement = pElement;
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
    int returnAux = - 1;
    int len = ll_len(this);
    Node* nodeIndex = getNode(this,index);
    Node* nodePrev = getNode(this, index - 1);

    if (this != NULL && index >= 0 && index < len)
    {
        if (index == 0)
        {
            if (nodeIndex != NULL)
            {
                this->pFirstNode = nodeIndex->pNextNode;
                nodeIndex = NULL;
                free(nodeIndex);
                this->size--;
                returnAux = 0;
            }
            else if(index == (len - 1))
            {
                if(nodeIndex != NULL)
                {
                    nodePrev->pNextNode = NULL;
                }
            }
            else
            {
                if(nodeIndex != NULL && nodePrev != NULL)
                {
                    nodePrev->pNextNode = nodeIndex->pNextNode;
                    nodeIndex = NULL;
                    free(nodeIndex);
                    this->size--;
                    returnAux = 0;
                }
            }
        }
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
    int len = ll_len(this);
    int contador = 0;

    for(int i = 0; i < len; i++)
    {
        ll_remove(this,i);
        contador++;
    }

    if(contador == len)
    {
        returnAux = 0;
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
        if(ll_clear(this) == 0)
        {
            free(this);
            this = NULL;
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
    int len = ll_len(this);
    Node* auxNode;

    if(this != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            auxNode = getNode(this,i);
            if(auxNode->pElement == pElement)
            {
                returnAux = i;
                break;
            }
        }
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
    int returnAux = 1;

    if(this == NULL)
    {
        returnAux = -1;
    }
    else
    {
        if(this->size > 0)
        {
            returnAux = 0;
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
    int len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
        addNode(this,index,pElement);
        returnAux = 0;
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
    Node* auxNode = getNode(this,index);
    int len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
        returnAux = auxNode->pElement;
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
    int len = ll_len(this);
    void* auxElement;
    int flag = 1;

    if(this != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            auxElement = ll_get(this,i);
            if(auxElement == pElement)
            {
                returnAux = 1;
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            returnAux = 0;
        }
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
    int returnAux = - 1;
    int len = ll_len(this2);
    void* auxElement;
    int flag = 1;

    if(this != NULL && this2 != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            auxElement = ll_get(this2,i);
            if(ll_contains(this,auxElement))
            {
                flag = 0;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag)
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
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);
    void* auxElement;

    if(this != NULL && (from >= 0 && from < len) && (to > from && to <= len))
    {
        cloneArray = ll_newLinkedList();
        for(int i = from; i < to; i++)
        {
            auxElement = ll_get(this,i);
            ll_add(cloneArray,auxElement);
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
    int len = ll_len(this);

    if(this != NULL)
    {
        cloneArray = ll_subList(this,0,len);
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
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = - 1;
    int len = ll_len(this);
    Node* auxElementI = NULL;
    Node* auxElementJ = NULL;
    Node* auxNode = (Node*) malloc(sizeof(Node));

    if(this != NULL && (order == 1 || order == 0) && len > 0 && auxNode != NULL && pFunc != NULL)
    {
        for(int i = 0; i < len - 1; i++)
        {
            auxElementI = getNode(this, i);
            if(auxElementI != NULL)
            {
                for(int j = i + 1; j < len; j++)
                {
                    auxElementJ = getNode(this, j);
                    if(auxElementJ != NULL)
                    {
                        if((pFunc(auxElementI->pElement, auxElementJ->pElement)) > 0 && order == 1)
                        {
                            auxNode->pElement = auxElementI->pElement;
                            auxElementI->pElement = auxElementJ->pElement;
                            auxElementJ = auxNode->pElement;
                        }
                        else if((pFunc(auxElementI->pElement, auxElementJ->pElement)) < 0 && order == 0)
                        {
                            auxNode->pElement = auxElementI->pElement;
                            auxElementI->pElement = auxElementJ->pElement;
                            auxElementJ->pElement = auxNode->pElement;
                        }
                    }
                }
            }
        }
        returnAux = 0;
    }
    free(auxNode);
    return returnAux;
}
