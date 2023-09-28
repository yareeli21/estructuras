#include <stdio.h>
#include <stdlib.h>

// Estructura para representar los datos de un distrito en un año
typedef struct {
    int hombres;
    int mujeres;
    char tendencia;
} DatosDistrito;

// Función para calcular las tendencias de crecimiento en los años 1986, 1991 y 1996
void calcularTendencias(DatosDistrito **padron, int numDistritos, int numAnios) {
    for (int distrito = 0; distrito < numDistritos; distrito++) {
        // Calcular la tendencia en el año 1986
        if (padron[distrito][1].hombres + padron[distrito][1].mujeres >
            padron[distrito][0].hombres + padron[distrito][0].mujeres) {
            padron[distrito][1].tendencia = '+';
        } else if (padron[distrito][1].hombres + padron[distrito][1].mujeres <
                   padron[distrito][0].hombres + padron[distrito][0].mujeres) {
            padron[distrito][1].tendencia = '-';
        } else {
            padron[distrito][1].tendencia = '=';
        }

        // Calcular la tendencia en el año 1991
        if (padron[distrito][2].hombres + padron[distrito][2].mujeres >
            padron[distrito][1].hombres + padron[distrito][1].mujeres) {
            padron[distrito][2].tendencia = '+';
        } else if (padron[distrito][2].hombres + padron[distrito][2].mujeres <
                   padron[distrito][1].hombres + padron[distrito][1].mujeres) {
            padron[distrito][2].tendencia = '-';
        } else {
            padron[distrito][2].tendencia = '=';
        }

        // Calcular la tendencia en el año 1996
        if (padron[distrito][3].hombres + padron[distrito][3].mujeres >
            padron[distrito][2].hombres + padron[distrito][2].mujeres) {
            padron[distrito][3].tendencia = '+';
        } else if (padron[distrito][3].hombres + padron[distrito][3].mujeres <
                   padron[distrito][2].hombres + padron[distrito][2].mujeres) {
            padron[distrito][3].tendencia = '-';
        } else {
            padron[distrito][3].tendencia = '=';
        }
    }
}

// Función para mostrar los distritos con tendencia de crecimiento positiva
void mostrarCrecimientoPositivo(DatosDistrito **padron, int numDistritos, int numAnios) {
    printf("Distritos con tendencia de crecimiento positiva en los cuatro años:\n");
    for (int distrito = 0; distrito < numDistritos; distrito++) {
        int crecimientoPositivo = 1;
        for (int anio = 0; anio < numAnios; anio++) {
            if (padron[distrito][anio].tendencia != '+') {
                crecimientoPositivo = 0;
                break;
            }
        }
        if (crecimientoPositivo) {
            printf("Distrito %d\n", distrito + 1);
        }
    }
}

// Función para mostrar los distritos con tendencia de crecimiento negativa
void mostrarCrecimientoNegativo(DatosDistrito **padron, int numDistritos, int numAnios) {
    printf("Distritos con tendencia de crecimiento negativa en los cuatro años:\n");
    for (int distrito = 0; distrito < numDistritos; distrito++) {
        int crecimientoNegativo = 1;
        for (int anio = 0; anio < numAnios; anio++) {
            if (padron[distrito][anio].tendencia != '-') {
                crecimientoNegativo = 0;
                break;
            }
        }
        if (crecimientoNegativo) {
            printf("Distrito %d\n", distrito + 1);
        }
    }
}

// Función para mostrar los distritos con tendencia de crecimiento estable
void mostrarCrecimientoEstable(DatosDistrito **padron, int numDistritos, int numAnios) {
    printf("Distritos con tendencia de crecimiento estable en los cuatro años:\n");
    for (int distrito = 0; distrito < numDistritos; distrito++) {
        int crecimientoEstable = 1;
        for (int anio = 0; anio < numAnios; anio++) {
            if (padron[distrito][anio].tendencia != '=') {
                crecimientoEstable = 0;
                break;
            }

