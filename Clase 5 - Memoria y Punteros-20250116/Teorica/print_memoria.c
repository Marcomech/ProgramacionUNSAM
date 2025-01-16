#include <stdio.h>
#include <stdbool.h>

void print_memoria(bool is_smart, long long birth, char initial, float height, double global) {
    // Array of void* to hold memory addresses

    bool *ptr_is_smart = &is_smart;
    long long  *ptr_birth = &birth;
    char *ptr_initial = &initial;
    float *ptr_height = &height;
    double *ptr_global = &global;
    
    printf("Memory (pile) \t\t Computer Address \t Variable Name\n");

    printf("|-------|\n");
    printf("|       | \t\t %p \t\t bool is_smart\n", ptr_is_smart);
    printf("|-------|\n");
    ptr_is_smart++;
    printf("|       | \t\t %p \t\t Next empty address\n", ptr_is_smart);
    printf("|-------|\n");
    printf("Difference = %d bytes", sizeof(is_smart));
    printf("\n\n");

    printf("|-------|\n");
    printf("|       | \t\t %p \t\t int birth\n", ptr_birth);
    printf("|-------|\n");
    ptr_birth++;
    printf("|       | \t\t %p \t\t Next empty address\n", ptr_birth);
    printf("|-------|\n");
    printf("Difference = %lu bytes", sizeof(birth));
    printf("\n\n");

    printf("|-------|\n");
    printf("|       | \t\t %p \t\t char initial\n", ptr_initial);
    printf("|-------|\n");
    ptr_initial++;
    printf("|       | \t\t %p \t\t Next empty address\n", ptr_initial);
    printf("|-------|\n");
    printf("Difference = %lu bytes", sizeof(initial));
    printf("\n\n");

    printf("|-------|\n");
    printf("|       | \t\t %p \t\t float height\n", ptr_height);
    printf("|-------|\n");
    ptr_height++;
    printf("|       | \t\t %p \t\t Next empty address\n", ptr_height);
    printf("|-------|\n");
    printf("Difference = %lu bytes", sizeof(height));
    printf("\n\n");

    printf("|-------|\n");
    printf("|       | \t\t %p \t\t double global\n", ptr_global);
    printf("|-------|\n");
    ptr_global++;
    printf("|       | \t\t %p \t\t Next empty address\n", ptr_global);
    printf("|-------|\n");
    printf("Difference = %lu bytes", sizeof(global));
    printf("\n\n\n\n");

    
}

