/*
Escribir una función en C que calcule el valor máximo, el valor mínimo y el promedio
de los elementos en un array de enteros.

La funcion debe recibir los siguientes parámetros:
-Un puntero a un array de enteros (arr).
-Un entero que representa el tamaño del array (largo).
-Dos punteros a enteros (max y min) para almacenar el valor máximo y el valor mínimo, respectivamente.
-Un puntero a un flotante (promedio) para almacenar el promedio de los elementos del array.
*/

#include <stdio.h>

#include "listas.h"

void MaxMinProm(int *arr, int largo, int *max, int *min, float *promedio);

int main() {
    int largo = sizeof(shortLista) / sizeof(shortLista[0]);
    int max, min;
    float promedio;
    // int *maxPtr = &max; //alternativa

    // MaxMinProm(shortLista, largo, maxPtr, &min, &promedio); // alternativa
    MaxMinProm(shortLista, largo, &max, &min, &promedio);
    printf("Maximo:   %d\n", max);
    printf("Minimo:   %d\n", min);
    printf("Promedio: %f\n", promedio);

    return 0;
}

void MaxMinProm(int *arr, int largo, int *max, int *min, float *promedio) {
    int sum = 0;
    *max = *min = arr[0];

    for (int i = 1; i < largo; i++) {
        if (arr[i] > *max) *max = arr[i];
        if (arr[i] < *min) *min = arr[i];
        sum += arr[i];
    }

    *promedio = (float)sum / largo;
}