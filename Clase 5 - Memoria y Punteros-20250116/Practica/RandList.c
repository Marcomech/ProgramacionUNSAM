#include <stdio.h>
#include <stdlib.h>

#define LEN 1000

int main() {
    int temp, r, i, lista[LEN];
    i = LEN;
    while (i--) {
        lista[i] = i;
    }
    i = LEN;
    while (i--) {
        r = lista[rand() % (LEN + 1)];
        temp = lista[i];
        lista[i] = lista[r];
        lista[r] = temp;
    }
    i = LEN;
    while (i--) {
        printf("%d, ", lista[i]);
    }

    return 0;
}