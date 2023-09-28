#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Persona
typedef struct {
    int edad;
    char nombre[50];
    char direccion[100];
    char telefono[15];
} Persona;

// Función para ingresar los datos de una persona
void ingresarDatosPersona(Persona *persona) {
    printf("Ingrese el nombre: ");
    scanf(" %[^\n]", persona->nombre);

    printf("Ingrese la edad: ");
    scanf("%d", &(persona->edad));

    printf("Ingrese la dirección: ");
    scanf(" %[^\n]", persona->direccion);

    printf("Ingrese el teléfono: ");
    scanf(" %[^\n]", persona->telefono);
}

// Función de comparación para ordenar personas por edad
int compararPorEdad(const void *a, const void *b) {
    const Persona *personaA = (const Persona *)a;
    const Persona *personaB = (const Persona *)b;

    return personaB->edad - personaA->edad; // Orden de mayor a menor
}

// Función para mostrar los datos de las personas ordenadas
void mostrarPersonasOrdenadas(Persona *personas, int N) {
    printf("Personas ordenadas por edad (de mayor a menor):\n");
    for (int i = 0; i < N; i++) {
        printf("Nombre: %s\n", personas[i].nombre);
        printf("Edad: %d\n", personas[i].edad);
        printf("Dirección: %s\n", personas[i].direccion);
        printf("Teléfono: %s\n", personas[i].telefono);
        printf("\n");
    }
}

int main() {
    int N;

    printf("Ingrese la cantidad de personas (N): ");
    scanf("%d", &N);

    // Crear un arreglo dinámico de personas
    Persona *personas = (Persona *)malloc(N * sizeof(Persona));
    if (personas == NULL) {
        printf("Error: No se pudo reservar memoria para las personas.\n");
        return 1;
    }

    // Ingresar los datos de las personas
    for (int i = 0; i < N; i++) {
        printf("\nIngrese los datos de la persona #%d:\n", i + 1);
        ingresarDatosPersona(&personas[i]);
    }

    // Ordenar las personas por edad
    qsort(personas, N, sizeof(Persona), compararPorEdad);

    // Mostrar las personas ordenadas
    mostrarPersonasOrdenadas(personas, N);

    // Liberar la memoria
    free(personas);

    return 0;
}
