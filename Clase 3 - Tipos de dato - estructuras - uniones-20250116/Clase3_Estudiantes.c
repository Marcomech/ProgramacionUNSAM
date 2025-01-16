#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StructEstudiante {
    int id;
    char nombre[50];
    union {
        char mail[50];
        char tel[15];
    } InfoContacto;
    int tipoContacto;  // 0 mail, 1 telefono,
    float promedio;
};

int main() {
    struct StructEstudiante estudiante;
    char filename[] = "estudiantes.dat";
    float promedioIngresado;
    int choice, cantidadEstudiantes;

    do {
        printf("\n----------------------------\n");
        printf("\nMenu:\n");
        printf("1. Agregar estudiante\n");
        printf("2. Mostrar estudiantes\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%d", &choice);
        getchar();
        printf("\n----------------------------\n");

        switch (choice) {
            case 1:
                if (cantidadEstudiantes < 20) {
                    printf("ID: ");
                    scanf("%d", &estudiante.id);
                    getchar();

                    printf("Nombre: ");
                    fgets(estudiante.nombre, sizeof(estudiante.nombre), stdin);
                    estudiante.nombre[strcspn(estudiante.nombre, "\n")] = '\0';

                    printf("Promedio: ");
                    scanf("%f", &estudiante.promedio);
                    getchar();

                    printf("Tipo de contacto (0 mail, 1 tel): ");
                    scanf("%d", &estudiante.tipoContacto);
                    getchar();

                    if (estudiante.tipoContacto == 0) {
                        printf("Mail: ");
                        fgets(estudiante.InfoContacto.mail, sizeof(estudiante.InfoContacto.mail), stdin);
                        estudiante.InfoContacto.mail[strcspn(estudiante.InfoContacto.mail, "\n")] = '\0';
                    } else if (estudiante.tipoContacto == 1) {
                        printf("Telefono: ");
                        fgets(estudiante.InfoContacto.tel, sizeof(estudiante.InfoContacto.tel), stdin);
                        estudiante.InfoContacto.tel[strcspn(estudiante.InfoContacto.tel, "\n")] = '\0';
                    }

                    FILE *file = fopen(filename, "ab");
                    if (file == NULL) {
                        perror("Error abriendo el archivo");
                        exit(1);
                    }
                    fwrite(&estudiante, sizeof(struct StructEstudiante), 1, file);
                    fclose(file);
                    printf("Estudiante guardado. \n");
                    cantidadEstudiantes++;
                } else {
                    printf("Cantidad de estudiantes mayor al maximo.\n");
                }
                break;

            case 2:
                if (cantidadEstudiantes == 0) {
                    printf("No hay estudiantes ingresados.\n");
                    break;
                }
                FILE *file = fopen(filename, "rb");
                if (file == NULL) {
                    perror("Error abriendo el archivo");
                    exit(1);
                }
                while (fread(&estudiante, sizeof(struct StructEstudiante), 1, file)) {
                    printf("\n----------------------------\n");

                    printf("ID: %d\n", estudiante.id);
                    printf("Nombre: %s\n", estudiante.nombre);
                    printf("Promedio: %.2f\n", estudiante.promedio);

                    if (estudiante.tipoContacto == 0) {
                        printf("Mail:  %s\n", estudiante.InfoContacto.mail);
                    } else if (estudiante.tipoContacto == 1) {
                        printf("Telefono:  %s\n", estudiante.InfoContacto.tel);
                    }
                    printf("\n");
                }
                fclose(file);
                break;

            case 3:
                printf("Saliendo.....\n");
                break;

            default:
                printf("Opcion invalida\n");
                break;
        }
    } while (choice != 3);
}
