#include <stdio.h>
#include <string.h>
#include "header.h"
#include "funciones.c"

int main(void){
#ifdef Ej1
    Saludo();
#endif
#ifdef Ej2
    int start, stop;
    printf("\nComienzo del intervalo: \t");
    scanf("%d", &start);
    printf("\nFin del intervalo: \t");
    scanf("%d", &stop);
    Armstrong(start, stop);
#endif
#ifdef Ej3
    int iteracion;
    // unsigned long long res;
    printf("\nIngrese el numero de iteraciones: \t");
    scanf("%d", &iteracion);
    // res = Fibonacci(iteracion);
    printf("El %d de la secuencia de Fibonacci es : \t%lld", iteracion, Fibonacci(iteracion));
    printf("\nPara esta sucecion se llamo a la funcion %lld veces", nroRecurrenciasFibonacci);

#endif
    return 0;
}