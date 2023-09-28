#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para los equipos de baloncesto
typedef struct {
    char nombreEquipo[50];
    int victorias;
    int derrotas;
    int perdidasBalon;
    int rebotesCogidos;
    char mejorAnotadorTriples[50];
    int triplesMejorAnotador;
} EquipoBaloncesto;

// Estructura para los equipos de fútbol
typedef struct {
    char nombreEquipo[50];
    int victorias;
    int derrotas;
    int empates;
    int golesAFavor;
    int golesEnContra;
    char goleadorEquipo[50];
    int golesGoleador;
} EquipoFutbol;

// Función para introducir los datos de un equipo de baloncesto
EquipoBaloncesto ingresarEquipoBaloncesto() {
    EquipoBaloncesto equipo;

    printf("Nombre del equipo de baloncesto: ");
    scanf(" %[^\n]", equipo.nombreEquipo);

    printf("Número de victorias: ");
    scanf("%d", &equipo.victorias);

    printf("Número de derrotas: ");
    scanf("%d", &equipo.derrotas);

    printf("Número de pérdidas de balón: ");
    scanf("%d", &equipo.perdidasBalon);

    printf("Número de rebotes cogidos: ");
    scanf("%d", &equipo.rebotesCogidos);

    printf("Nombre del mejor anotador de triples: ");
    scanf(" %[^\n]", equipo.mejorAnotadorTriples);

    printf("Número de triples del mejor triplista: ");
    scanf("%d", &equipo.triplesMejorAnotador);

    return equipo;
}

// Función para introducir los datos de un equipo de fútbol
EquipoFutbol ingresarEquipoFutbol() {
    EquipoFutbol equipo;

    printf("Nombre del equipo de fútbol: ");
    scanf(" %[^\n]", equipo.nombreEquipo);

    printf("Número de victorias: ");
    scanf("%d", &equipo.victorias);

    printf("Número de derrotas: ");
    scanf("%d", &equipo.derrotas);

    printf("Número de empates: ");
    scanf("%d", &equipo.empates);

    printf("Número de goles a favor: ");
    scanf("%d", &equipo.golesAFavor);

    printf("Número de goles en contra: ");
    scanf("%d", &equipo.golesEnContra);

    printf("Nombre del goleador del equipo: ");
    scanf(" %[^\n]", equipo.goleadorEquipo);

    printf("Número de goles del goleador: ");
    scanf("%d", &equipo.golesGoleador);

    return equipo;
}

// Función para mostrar los mejores triplistas de cada equipo de baloncesto
void mostrarMejoresTriplistas(EquipoBaloncesto *equiposBaloncesto, int N) {
    printf("\nMejores triplistas de cada equipo de baloncesto:\n");
    for (int i = 0; i < N; i++) {
        printf("Equipo: %s\n", equiposBaloncesto[i].nombreEquipo);
        printf("Mejor anotador de triples: %s\n", equiposBaloncesto[i].mejorAnotadorTriples);
        printf("Número de triples del mejor triplista: %d\n", equiposBaloncesto[i].triplesMejorAnotador);
        printf("\n");
    }
}

// Función para encontrar al máximo goleador de la liga de fútbol
void encontrarMaximoGoleador(EquipoFutbol *equiposFutbol, int N) {
    char maxGoleador[50];
    int maxGoles = 0;

    for (int i = 0; i < N; i++) {
        if (equiposFutbol[i].golesGoleador > maxGoles) {
            maxGoles = equiposFutbol[i].golesGoleador;
            strcpy(maxGoleador, equiposFutbol[i].goleadorEquipo);
        }
    }

    printf("\nMáximo goleador de la liga de fútbol:\n");
    printf("Nombre del goleador: %s\n", maxGoleador);
    printf("Número de goles: %d\n", maxGoles);
}

// Función para determinar el equipo ganador de la liga de fútbol
void equipoGanadorLiga(EquipoFutbol *equiposFutbol, int N) {
    int maxPuntos = 0;
    char equipoGanador[50];

    for (int i = 0; i < N; i++) {
        int puntos = (equiposFutbol[i].victorias * 3) + equiposFutbol[i].empates;
        if (puntos > maxPuntos) {
            maxPuntos = puntos;
            strcpy(equipoGanador, equiposFutbol[i].nombreEquipo);
        }
    }

    printf("\nEquipo ganador de la liga de fútbol:\n");
    printf("Nombre del equipo: %s\n", equipoGanador);
    printf("Puntos obtenidos: %d\n", maxPuntos);
}

int main() {
    int N;
    printf("Ingrese la cantidad de equipos en ambas ligas: ");
    scanf("%d", &N);

    // Crear arreglos dinámicos de equipos de baloncesto y fútbol
    EquipoBaloncesto *equiposBaloncesto = (EquipoBaloncesto *)malloc(N * sizeof(EquipoBaloncesto));
    EquipoFutbol *equiposFutbol = (EquipoFutbol *)malloc(N * sizeof(EquipoFutbol));

    if (equiposBaloncesto == NULL || equiposFutbol == NULL) {
        printf("Error: No se pudo reservar memoria para los equipos.\n");
        return 1;
    }

    // Introducir la información de los equipos
    for (int i = 0; i < N; i++) {
        printf("\nIngrese la información del equipo #%d:\n", i + 1);
        equiposBaloncesto[i] = ingresarEquipoBaloncesto();
        equiposFutbol[i] = ingresarEquipoFutbol();
    }

    // Mostrar los mejores triplistas de cada equipo de baloncesto
    mostrarMejoresTriplistas(equiposBaloncesto, N);

    // Encontrar el máximo goleador de la liga de fútbol
    encontrarMaximoGoleador(equiposFutbol, N);

    // Determinar el equipo ganador de la liga de fútbol
    equipoGanadorLiga(equiposFutbol, N);

    // Liberar la memoria
    free(equiposBaloncesto);
    free(equiposFutbol);

    return 0;
}
