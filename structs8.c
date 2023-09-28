#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar un libro
typedef struct {
    int codigo;
    int cantidadEjemplares;
    char autor[50];
    char titulo[100];
} Libro;

// Función para prestar un libro
void prestarLibro(Libro *biblioteca, int M) {
    int codigoPrestamo;
    printf("Ingrese el código del libro a prestar (1-%d): ", M);
    scanf("%d", &codigoPrestamo);

    // Validar el código del libro
    if (codigoPrestamo < 1 || codigoPrestamo > M) {
        printf("Error: Código de libro inválido. Debe estar entre 1 y %d.\n", M);
        return;
    }

    Libro *libro = &biblioteca[codigoPrestamo - 1];

    // Verificar la cantidad de ejemplares
    if (libro->cantidadEjemplares > 1) {
        printf("Libro prestado:\n");
        printf("Autor: %s\n", libro->autor);
        printf("Título: %s\n", libro->titulo);
        libro->cantidadEjemplares--;
        printf("El libro ha sido prestado correctamente.\n");
    } else if (libro->cantidadEjemplares == 1) {
        printf("Solo queda un ejemplar de lectura en sala. No se puede prestar.\n");
    } else {
        printf("No hay ejemplares disponibles para préstamo.\n");
    }
}

// Función para devolver un libro
void devolverLibro(Libro *biblioteca, int M) {
    int codigoDevolucion;
    printf("Ingrese el código del libro a devolver (1-%d): ", M);
    scanf("%d", &codigoDevolucion);

    // Validar el código del libro
    if (codigoDevolucion < 1 || codigoDevolucion > M) {
        printf("Error: Código de libro inválido. Debe estar entre 1 y %d.\n", M);
        return;
    }

    Libro *libro = &biblioteca[codigoDevolucion - 1];

    printf("Libro a devolver:\n");
    printf("Autor: %s\n", libro->autor);
    printf("Título: %s\n", libro->titulo);

    char confirmacion;
    printf("¿Confirmar la devolución? (S/N): ");
    scanf(" %c", &confirmacion);

    if (confirmacion == 'S' || confirmacion == 's') {
        libro->cantidadEjemplares++;
        printf("La devolución se ha registrado correctamente.\n");
    } else {
        printf("La devolución ha sido cancelada.\n");
    }
}

int main() {
    int M;
    printf("Ingrese la cantidad de libros en la biblioteca: ");
    scanf("%d", &M);

    // Crear un arreglo dinámico de libros
    Libro *biblioteca = (Libro *)malloc(M * sizeof(Libro));
    if (biblioteca == NULL) {
        printf("Error: No se pudo reservar memoria para la biblioteca.\n");
        return 1;
    }

    // Ingresar los datos de los libros
    for (int i = 0; i < M; i++) {
        biblioteca[i].codigo = i + 1; // Códigos de 1 a M
        printf("Ingrese los datos del libro #%d:\n", i + 1);
        printf("Título: ");
        scanf(" %[^\n]", biblioteca[i].titulo);
        printf("Autor: ");
        scanf(" %[^\n]", biblioteca[i].autor);
        printf("Cantidad de ejemplares: ");
        scanf("%d", &biblioteca[i].cantidadEjemplares);
    }

    int opcion;
    do {
        printf("\nMenú:\n");
        printf("1. Prestamo de libros\n");
        printf("2. Devolución de libros\n");
        printf("3. Fin\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                prestarLibro(biblioteca, M);
                break;
            case 2:
                devolverLibro(biblioteca, M);
                break;
            case 3:
                printf("Programa terminado.\n");
                break;
            default:
                printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }
    } while (opcion != 3);

    // Liberar la memoria
    free(biblioteca);

    return 0;
}
