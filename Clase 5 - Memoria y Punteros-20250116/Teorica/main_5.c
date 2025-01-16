#include <stdio.h>
#include <stdbool.h>
#include "print_memoria.c"

#define PRINT_MEMORY
// #define POINTER_OPERATORS
// #define POINTER_and_ARRAYS
// #define POINTER_ARITHMETIC  

#define LEN 3

double jim_global = 99999999;


int main(void) {

    #ifdef PRINT_MEMORY
    bool is_jim_smart = false;
    long long  jims_birth = 1111999;
    char jims_initial = 'j';
    float jims_height = 1.81;
    
    print_memoria(is_jim_smart, jims_birth, jims_initial, jims_height, jim_global); 

    printf("\n\n");
    printf("This is the data segment\n");
    printf("|-------|\n");
    printf("|       | \t\t %p \t\t double jim_global\n", (void*)&jim_global);
    printf("|-------|\n");
    printf("|       | \t\t %p \t\t Next empty address\n", (void*)&jim_global + sizeof(jim_global));
    printf("|-------|\n");
    printf("Difference = %p bytes", sizeof(jim_global));

    #endif

    #ifdef POINTER_OPERATORS
    
    int var = 400;
    int * ptr = &var;

    /* imprimen lo mismo */
    printf("\nptr vs &var\n");
    printf(" ptr = \t %p\n", ptr);  /* lo que esta adentro de ptr */
    printf("&var = \t %p\n", &var); /* la direccion de var */

    *ptr = 300; /* Modifica el valor de la variable a la que esta apuntando ptr*/

    /* imprimen lo mismo*/
    printf("\n*ptr vs var\n");
    printf("*ptr = \t %d\n", *ptr);
    printf(" var = \t %d\n", var);
    #endif

    #ifdef POINTER_and_ARRAYS

    long long arr[LEN] = {1E8 , 3.8E6, 5E5};
    long long *p_arr;
    p_arr = arr;

    printf("long long *p_arr = arr =\t\t %p\n", p_arr);
    p_arr = &arr[0];
    printf("long long *p_arr = &arr[0] =\t\t %p\n", p_arr);

    printf("\n--------------------------------------------\n");

    /* going through the vector */

    for (int i = 0; i < LEN ; i++){
        printf("arr[%d] = \t %lld\n", i, arr[i]); /* Imprime el vallor de arr[i]*/
        /* 1) 1E8     ->  2)  3.8E6   -> 3) 5*/
        /* Imprime el valor de la variable a la que apunta el puntero */
        printf("arr[%d] = \t %lld\t\t (p_arr = %p)\n\n", i, *p_arr, p_arr);
        p_arr++;
        /* 1)arr[0] = 1E8 (p_arr = 0xAA0)     ->  2)arr[2] = 3.8E6 (p_arr = 0xAA8)
           -> 3)arr[3] = 5 (p_arr = 0xAB0) */ 
    }
    #endif

    #ifdef POINTER_ARITHMETIC

    short a, b, add = 10, aux;
    short *ptr_a = &a, *ptr_b = &b;

    printf("Original pointers: ptr_a = %p | ptr_b = %p\n", ptr_a, ptr_b);

    printf("\n1. Increment/Decrement\n");
    ptr_a++;
    printf("ptr_a++ = %p\n", ptr_a--); /* uso el -- para recuperar la direc original */ 
    ptr_b--;
    printf("ptr_b-- = %p\n", ptr_b++); /* uso el ++ para recuperar direc original */

    printf("\n2. Addition / Substraction of integer to pointer\n");
    ptr_a = ptr_a + add; /* ptr_a = ptr_a + sizeof(int) * valued(add)*/
    printf("ptr_a + 10 = \t\t %p\n", ptr_a);
    ptr_a = ptr_a - add;
    printf("(ptr_a + 10) - 10 =\t %p  (recupero original)\n", ptr_a);

    printf("\n3. Substracting 2 pointers of the same type\n");
    aux = ptr_a - ptr_b;
    printf("ptr_a - ptr_b = %d\n", aux);

    printf("\n4. Pointer Comparisson\n");
    if (ptr_a >= ptr_b)
        printf("ptra >= ptr_b");
    else
        printf("ptr_a < ptr_b");

    #endif

    return 0;
}


