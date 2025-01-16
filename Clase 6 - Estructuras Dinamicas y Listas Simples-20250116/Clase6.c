/*
======================== Mostrados en clase ========================
void initLista(ListaEnlazada* lista);
void insFirst(ListaEnlazada* lista, int dato);
void showFull(ListaEnlazada* lista);
void delValue(ListaEnlazada* lista, int dato);

======================== Ejercicio 1 ========================
void showFirst(ListaEnlazada* lista);
void showLast(ListaEnlazada* lista);

======================== Ejercicio 2 ========================
void insLast(ListaEnlazada* lista, int dato);

======================== Ejercicio 3 ========================
void delFirst(ListaEnlazada* lista);
void delLast(ListaEnlazada* lista);
*/

#include <stdio.h>
#include "definitions.h"

/* mostrar */
int main()
{
    ListaEnlazada lista;
    initLista(&lista);

    int valoresIniciales[] = {20, 30, 40, 50};
    int len = sizeof(valoresIniciales) / sizeof(valoresIniciales[0]);

    for (int i = 0; i < len; i++)
    {
        insLast(&lista, valoresIniciales[i]);
    }

    insLast(&lista, 60);
    insFirst(&lista, 10);

    printf("Lista después de insertar elementos:\n");
    showFull(&lista);

    delValue(&lista, 20);
    printf("Lista después de eliminar el valor 20:\n");
    showFull(&lista);

    showFirst(&lista);
    showLast(&lista);

    delFirst(&lista);
    printf("Lista después de eliminar el primer valor\n");
    showFull(&lista);

    delLast(&lista);
    printf("Lista después de eliminar el ultimo valor\n");
    showFull(&lista);

    return 0;
}

/* mostrar */
void initLista(ListaEnlazada *lista)
{
    lista->primerNodo = -1; // Indica que la lista está vacía
    lista->tamaño = 0;
}

/* mostrar */
void insLast(ListaEnlazada *lista, int dato)
{
    if (lista->tamaño >= MAX_NODOS)
    {
        printf("Lista llena, no se puede insertar más elementos.\n");
        return;
    }

    int nuevoIndice = lista->tamaño;
    lista->nodos[nuevoIndice].dato = dato;
    lista->nodos[nuevoIndice].proxNodo = -1;

    if (lista->primerNodo == -1)
    { // Si la lista está vacía, el nuevo nodo es la primerNodo
        lista->primerNodo = nuevoIndice;
    }
    else
    {
        int index = lista->primerNodo;
        while (lista->nodos[index].proxNodo != -1)
        {
            index = lista->nodos[index].proxNodo;
        }
        lista->nodos[index].proxNodo = nuevoIndice; // Conectar el nuevo nodo al final
    }

    lista->tamaño++;
}

/* ejercicio */
void insFirst(ListaEnlazada *lista, int dato)
{
    if (lista->tamaño >= MAX_NODOS)
    {
        printf("Lista llena, no se puede insertar más elementos.\n");
        return;
    }

    int nuevoIndice = lista->tamaño;
    lista->nodos[nuevoIndice].dato = dato;
    lista->nodos[nuevoIndice].proxNodo = lista->primerNodo;
    lista->primerNodo = nuevoIndice;

    lista->tamaño++;
}

/* ejercicio */
void delValue(ListaEnlazada *lista, int dato)
{
    if (lista->primerNodo == -1)
    {
        printf("Lista vacia.\n");
        return;
    }
    int index = lista->primerNodo;
    int anterior = -1;

    while (index != -1 && lista->nodos[index].dato != dato)
    {
        anterior = index;
        index = lista->nodos[index].proxNodo;
    }

    if (index == -1)
    {
        printf("No se encontró el nodo\n");
        return;
    }

    if (anterior == -1)
    { // Si el nodo a eliminar es el primerNodo
        lista->primerNodo = lista->nodos[index].proxNodo;
    }
    else
    {
        lista->nodos[anterior].proxNodo = lista->nodos[index].proxNodo;
    }

    lista->tamaño--;
}

/* ejercicio */
void delFirst(ListaEnlazada *lista)
{
    if (lista->primerNodo == -1)
    {
        printf("Lista vacia.\n");
        return;
    }

    lista->primerNodo = lista->nodos[lista->primerNodo].proxNodo;

    lista->tamaño--;
}

/* mostrar */
void delLast(ListaEnlazada *lista)
{
    if (lista->primerNodo == -1)
    {
        printf("Lista vacia.\n");
        return;
    }
    int index = lista->primerNodo;
    int prevIndex = -1;
    if (lista->nodos[index].proxNodo == -1)
    {
        lista->primerNodo = -1;
    }
    else
    {
        while (lista->nodos[index].proxNodo != -1)
        {
            prevIndex = index;
            index = lista->nodos[index].proxNodo;
        }
        lista->nodos[prevIndex].proxNodo = -1;
    }
    lista->nodos[index].dato = -1;

    lista->tamaño--;
}

/* mostrar */
void showFull(ListaEnlazada *lista)
{
    int index = lista->primerNodo;
    while (index != -1)
    {
        printf("%d -> ", lista->nodos[index].dato);
        index = lista->nodos[index].proxNodo;
    }
    printf("FIN\n");
}

/* ejercicio */
void showFirst(ListaEnlazada *lista)
{
    if (lista->primerNodo == -1)
    {
        printf("La lista está vacía.\n");
        return;
    }
    printf("Primer nodo: %d\n", lista->nodos[lista->primerNodo].dato);
}

/* ejercicio */
void showLast(ListaEnlazada *lista)
{
    if (lista->primerNodo == -1)
    {
        printf("La lista está vacía.\n");
        return;
    }

    int index = lista->primerNodo;
    while (lista->nodos[index].proxNodo != -1)
    {
        index = lista->nodos[index].proxNodo;
    }
    printf("Último nodo: %d\n", lista->nodos[index].dato);
}
