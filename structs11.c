#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura ASIGNACIÓN
typedef struct {
    float TRANSPORTE;
    float COMIDA;
    float VACACIONES;
} ASIGNACION;

// Definición de la estructura DEDUCCIÓN
typedef struct {
    float SEGURO;
    float AH; // Ahorro Habitacional
} DEDUCCION;

// Definición de la estructura EMPLEADO
typedef struct {
    int CODIGO;
    int ACTIVO;
    char SEXO;
    float SUELDO_HORA;
    int HORAS_TRAB;
    ASIGNACION *AS; // Puntero a ASIGNACIÓN
    DEDUCCION *DE;  // Puntero a DEDUCCIÓN
} EMPLEADO;

// Función para crear una variable de tipo EMPLEADO de manera dinámica
EMPLEADO *crearEmpleado() {
    EMPLEADO *nuevoEmpleado = (EMPLEADO *)malloc(sizeof(EMPLEADO));
    if (nuevoEmpleado == NULL) {
        printf("Error: No se pudo reservar memoria para el empleado.\n");
        exit(1);
    }
    nuevoEmpleado->AS = (ASIGNACION *)malloc(sizeof(ASIGNACION));
    if (nuevoEmpleado->AS == NULL) {
        printf("Error: No se pudo reservar memoria para las asignaciones.\n");
        exit(1);
    }
    nuevoEmpleado->DE = (DEDUCCION *)malloc(sizeof(DEDUCCION));
    if (nuevoEmpleado->DE == NULL) {
        printf("Error: No se pudo reservar memoria para las deducciones.\n");
        exit(1);
    }
    return nuevoEmpleado;
}

// Función para inicializar los campos del registro EMPLEADO con datos proporcionados por el usuario
void inicializarEmpleado(EMPLEADO *empleado) {
    printf("Ingrese el código del empleado: ");
    scanf("%d", &(empleado->CODIGO));

    printf("Ingrese el estado activo (1 para activo, 0 para inactivo): ");
    scanf("%d", &(empleado->ACTIVO));

    printf("Ingrese el sexo del empleado (M/F): ");
    scanf(" %c", &(empleado->SEXO));

    printf("Ingrese el sueldo por hora del empleado: ");
    scanf("%f", &(empleado->SUELDO_HORA));

    printf("Ingrese las horas trabajadas del empleado: ");
    scanf("%d", &(empleado->HORAS_TRAB));

    printf("Ingrese la asignación de transporte: ");
    scanf("%f", &(empleado->AS->TRANSPORTE));

    printf("Ingrese la asignación de comida: ");
    scanf("%f", &(empleado->AS->COMIDA));

    printf("Ingrese la asignación de vacaciones: ");
    scanf("%f", &(empleado->AS->VACACIONES));

    printf("Ingrese la deducción de seguro: ");
    scanf("%f", &(empleado->DE->SEGURO));

    printf("Ingrese la deducción de ahorro habitacional: ");
    scanf("%f", &(empleado->DE->AH));
}

// Función para calcular el sueldo total del empleado
float calcularSueldoTotal(EMPLEADO *empleado) {
    float SH = empleado->SUELDO_HORA;
    int HT = empleado->HORAS_TRAB;
    float A = empleado->AS->TRANSPORTE + empleado->AS->COMIDA + empleado->AS->VACACIONES;
    float D = empleado->DE->SEGURO + empleado->DE->AH;
    float ST = (SH * HT) + A - D;
    return ST;
}

// Función para mostrar el sueldo total del empleado
void mostrarSueldoTotal(float sueldoTotal) {
    printf("Sueldo Total del empleado: %.2f\n", sueldoTotal);
}

int main() {
    EMPLEADO *empleado = crearEmpleado();

    inicializarEmpleado(empleado);

    float sueldoTotal = calcularSueldoTotal(empleado);

    mostrarSueldoTotal(sueldoTotal);

    // Liberar la memoria
    free(empleado->AS);
    free(empleado->DE);
    free(empleado);

    return 0;
}
