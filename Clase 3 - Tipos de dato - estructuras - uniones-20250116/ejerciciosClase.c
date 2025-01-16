#include <stdio.h>
#include <string.h>
struct personaStruct {
    char nombre[50];
    int edad;
    float altura;
};

union personaUnion {
    char nombre[50];
    int edad;
    float altura;
};

int main() {

    persona1.edad = 32;
    printf("Edad:   %d \n", persona1.edad);

    persona1.altura = 1.80;
    printf("Altura: %f \n", persona1.altura);
    printf("Edad:   %d \n", persona1.edad);

    return 0;
}
/*-------------------------------------------------------*/
#include <stdio.h>

struct ejemplo_struct {
    int i;
    float f;
    char str1[20];
    char str2[20];
    char str3[20];
};

union ejemplo_union {
    int i;
    float f;
    char str1[20];
    char str2[20];
    char str3[20];
};

int main() {
    struct ejemplo_struct ej_str;
    union ejemplo_union ej_uni;

    printf("Tamaño de struct: %lu \n", sizeof(ej_str));
    printf("Tamaño de union:  %lu \n", sizeof(ej_uni));

    return 0;
}

/*-------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>

struct datos_bancarios {
    int nroCuenta;
    char nombre[20];
    union identificacion {
        uint32_t dni;
        uint64_t pasaporte;
    } identificacion;
};

int main() {
    struct datos_bancarios persona1 = {
        .nombre = "Juan",
        .nroCuenta = 1230,
        .identificacion.dni = 40085741,
    };

    printf("Nombre:           %s\n", persona1.nombre);
    printf("Numero de Cuenta: %d\n", persona1.nroCuenta);
    printf("DNI:              %d\n", persona1.identificacion.dni);

    persona1.identificacion.pasaporte = 12345678901234;
    printf("Pasaporte:        %lu\n", persona1.identificacion.pasaporte);
    printf("DNI:              %d\n", persona1.identificacion.dni);

    return 0;
}
