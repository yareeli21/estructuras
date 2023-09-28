#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[15];
    char ap_pat[15];
    int edad;
    char carrera[15];
} Datos;

typedef struct {
    Datos pers;
    char deportes[30];
    int medallas;
} Deportista;

// Prototipos de funciones
Deportista *crearArregloDeportistas(int N);
void llenarDatosDeportistas(Deportista *arr, int N);
float calcularPromedioMedallas(Deportista *arr, int N);
int contarMayoresAlPromedio(Deportista *arr, int N, float promedio);
void encontrarMaxMinMedallas(Deportista *arr, int N);

int main() {
    int N;
    printf("Ingrese el numero de deportistas: ");
    scanf("%d", &N);

    Deportista *deportistas = crearArregloDeportistas(N);
    llenarDatosDeportistas(deportistas, N);

    float promedioMedallas = calcularPromedioMedallas(deportistas, N);
    int numMayoresAlPromedio = contarMayoresAlPromedio(deportistas, N, promedioMedallas);

    printf("Numero promedio de medallas obtenidas: %.2f\n", promedioMedallas);
    printf("Número de estudiantes con mas medallas que el promedio: %d\n", numMayoresAlPromedio);

    encontrarMaxMinMedallas(deportistas, N);

    free(deportistas);
    return 0;
}

Deportista *crearArregloDeportistas(int N) {
    Deportista *arr = (Deportista *)malloc(N * sizeof(Deportista));
    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria para el arreglo.\n");
        exit(1);
    }
    return arr;
}

void llenarDatosDeportistas(Deportista *arr, int N) {
    for (int i = 0; i < N; i++) {
        printf("Ingrese los datos del deportista #%d:\n", i + 1);
        printf("Nombre: ");
        scanf("%s", arr[i].pers.nombre);
        printf("Apellido Paterno: ");
        scanf("%s", arr[i].pers.ap_pat);
        printf("Edad: ");
        scanf("%d", &(arr[i].pers.edad));
        printf("Carrera: ");
        scanf("%s", arr[i].pers.carrera);
        printf("Deporte: ");
        scanf("%s", arr[i].deportes);
        printf("Número de medallas: ");
        scanf("%d", &(arr[i].medallas));
    }
}

float calcularPromedioMedallas(Deportista *arr, int N) {
    int totalMedallas = 0;
    for (int i = 0; i < N; i++) {
        totalMedallas += arr[i].medallas;
    }
    return (float)totalMedallas / N;
}

int contarMayoresAlPromedio(Deportista *arr, int N, float promedio) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i].medallas > promedio) {
            count++;
        }
    }
    return count;
}

void encontrarMaxMinMedallas(Deportista *arr, int N) {
    int maxMedallas = arr[0].medallas;
    int minMedallas = arr[0].medallas;
    int indexMax = 0;
    int indexMin = 0;

    for (int i = 1; i < N; i++) {
        if (arr[i].medallas > maxMedallas) {
            maxMedallas = arr[i].medallas;
            indexMax = i;
        }
        if (arr[i].medallas < minMedallas) {
            minMedallas = arr[i].medallas;
            indexMin = i;
        }
    }

    printf("Deportista con mas medallas:\n");
    printf("Nombre: %s\n", arr[indexMax].pers.nombre);
    printf("Carrera: %s\n", arr[indexMax].pers.carrera);
    printf("Numero de medallas: %d\n", maxMedallas);

    printf("Deportista con menos medallas:\n");
    printf("Nombre: %s\n", arr[indexMin].pers.nombre);
    printf("Carrera: %s\n", arr[indexMin].pers.carrera);
    printf("Numero de medallas: %d\n", minMedallas);
}
