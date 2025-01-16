/*
Realizar una funcion que implemente un BubbleSort:

El Bubble Sort es un algoritmo de ordenamiento que funciona
-revisando cada elemento de la lista que va a ser ordenada con el siguiente,
-intercambiándolos de posición si están en el orden equivocado.
-repetir el proceso hasta que no se necesiten másintercambios

*/

#include <stdio.h>
#include <stdlib.h>

#include "listas.h"

void mostrarLista(int *lista, int longitud);
void BubbleSort(int *lista, int longitud);

int main() {
    int size = sizeof(shortLista) / sizeof(shortLista)[0];

    printf("\nLista inicial: \n\t");
    mostrarLista(shortLista, size);

    printf("\nBubble Sort: \n\t");
    BubbleSort(shortLista, size);
    mostrarLista(shortLista, size);

    return 0;
}

void mostrarLista(int *lista, int longitud) {
    int i;

    for (i = 0; i < longitud; i++) {
        printf("%d, ", lista[i]);
    }
    printf("\n");
}

void BubbleSort(int *lista, int longitud) {
    int i, j, temp;

    for (j = 0; j < longitud - 1; j++) {
        for (i = 0; i < longitud - 1 - j; i++) {
            if (lista[i] > lista[i + 1]) {
                temp = lista[i + 1];
                lista[i + 1] = lista[i];
                lista[i] = temp;
            }
        }
    }
}
