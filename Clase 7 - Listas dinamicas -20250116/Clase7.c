/* FIFO (First in -> First out)*/

#include <stdio.h>
#include <stdlib.h>

#include "definitions.h"

void main() {
    Nodo* PrimerNodo = NULL;

    insFirst(&PrimerNodo, 10);
    insFirst(&PrimerNodo, 20);
    insFirst(&PrimerNodo, 30);
    insFirst(&PrimerNodo, 40);
    insFirst(&PrimerNodo, 50);
    insFirst(&PrimerNodo, 60);
    insFirst(&PrimerNodo, 70);
    insFirst(&PrimerNodo, 80);

    printf("\nLista enlazada: \n\t");
    showFull(PrimerNodo);

    delLast(&PrimerNodo);
    printf("\nLista enlazada: \n\t");
    showFull(PrimerNodo);

    delLast(&PrimerNodo);
    printf("\nLista enlazada: \n\t");
    showFull(PrimerNodo);

    delLast(&PrimerNodo);
    printf("\nLista enlazada: \n\t");
    showFull(PrimerNodo);
    return 0;
}

Nodo* createNodo(int nuevoDato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        printf("Error en la creacion del nodo\n");
        exit(1);
    }
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->next = NULL;
    return nuevoNodo;
}

void insFirst(Nodo** PrimerNodo, int nuevoDato) {
    Nodo* nuevoNodo = createNodo(nuevoDato);

    if (*PrimerNodo == NULL) {
        *PrimerNodo = nuevoNodo;
        return;
    }

    Nodo* viejoPrimerNodo = *PrimerNodo;
    nuevoNodo->next = viejoPrimerNodo;
    *PrimerNodo = nuevoNodo;
}

void delLast(Nodo** PrimerNodo) {
    if (*PrimerNodo == NULL) {
        printf("La lista esta vacia\n");
        return;
    }
    Nodo *actual, *previo;
    actual = *PrimerNodo;

    while (actual->next != NULL) {
        previo = actual;
        actual = actual->next;
    }
    previo->next = NULL;
    free(actual);
}

void showFull(Nodo* PrimerNodo) {
    Nodo* actual = PrimerNodo;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->next;
    }
    printf("NULL\n");
}

void freeList(Nodo* PrimerNodo) {
    Nodo* actual = PrimerNodo;
    Nodo* anterior;
    while (actual != NULL) {
        anterior = actual;
        actual = actual->next;
        free(anterior);
    }
}
