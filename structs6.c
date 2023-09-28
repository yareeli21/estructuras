#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar los datos de una persona
typedef struct {
    char nombre[50];
    char ap_paterno[50];
    int edad;
    char sexo;
    char aficiones[7][20];
    int num_aficiones;
} Persona;

// Función para introducir los datos de una persona
Persona *introducirPersona() {
    Persona *nuevaPersona = (Persona *)malloc(sizeof(Persona));
    if (nuevaPersona == NULL) {
        printf("Error: No se pudo reservar memoria para la persona.\n");
        exit(1);
    }

    printf("Introduce el nombre: ");
    scanf("%s", nuevaPersona->nombre);

    printf("Introduce el apellido paterno: ");
    scanf("%s", nuevaPersona->ap_paterno);

    printf("Introduce la edad: ");
    scanf("%d", &nuevaPersona->edad);

    printf("Introduce el sexo (M/F): ");
    scanf(" %c", &nuevaPersona->sexo);

    nuevaPersona->num_aficiones = 0;
    printf("Introduce las aficiones (separadas por comas, máximo 7): ");
    char buffer[256];
    scanf(" %[^\n]", buffer);

    char *token = strtok(buffer, ",");
    while (token != NULL && nuevaPersona->num_aficiones < 7) {
        strcpy(nuevaPersona->aficiones[nuevaPersona->num_aficiones], token);
        nuevaPersona->num_aficiones++;
        token = strtok(NULL, ",");
    }

    return nuevaPersona;
}

// Función para buscar una persona por nombre
Persona *buscarPersonaPorNombre(Persona *personas[], int numPersonas, char nombreBuscado[50]) {
    for (int i = 0; i < numPersonas; i++) {
        if (strcmp(personas[i]->nombre, nombreBuscado) == 0) {
            return personas[i];
        }
    }
    return NULL;
}

// Función para casar a dos personas afines
void casarPersonas(Persona *persona1, Persona *persona2, Persona *personas[], int *numPersonas) {
    printf("Se ha encontrado una persona afín para casar:\n");
    printf("Persona 1:\n");
    printf("Nombre: %s\n", persona1->nombre);
    printf("Apellido paterno: %s\n", persona1->ap_paterno);
    printf("Edad: %d\n", persona1->edad);
    printf("Sexo: %c\n", persona1->sexo);
    printf("Aficiones:\n");
    for (int i = 0; i < persona1->num_aficiones; i++) {
        printf("  %s\n", persona1->aficiones[i]);
    }
    printf("\n");

    printf("Persona 2:\n");
    printf("Nombre: %s\n", persona2->nombre);
    printf("Apellido paterno: %s\n", persona2->ap_paterno);
    printf("Edad: %d\n", persona2->edad);
    printf("Sexo: %c\n", persona2->sexo);
    printf("Aficiones:\n");
    for (int i = 0; i < persona2->num_aficiones; i++) {
        printf("  %s\n", persona2->aficiones[i]);
    }
    printf("\n");

    // Confirmación para eliminar a las personas
    char confirmacion;
    printf("¿Deseas casar a estas dos personas? (S/N): ");
    scanf(" %c", &confirmacion);

    if (confirmacion == 'S' || confirmacion == 's') {
        // Eliminar a las personas del arreglo
        for (int i = 0; i < *numPersonas; i++) {
            if (personas[i] == persona1 || personas[i] == persona2) {
                free(personas[i]);
                for (int j = i; j < *numPersonas - 1; j++) {
                    personas[j] = personas[j + 1];
                }
                (*numPersonas)--;
                i--; // Revisar el siguiente elemento
            }
        }
        printf("Las personas han sido casadas y eliminadas de la agencia matrimonial.\n");
    } else {
        printf("El matrimonio no se realizó.\n");
    }
}

int main() {
    Persona *personas[100]; // Suponemos un máximo de 100 personas
    int numPersonas = 0;

    while (1) {
        printf("\nMenú:\n");
        printf("1. Introducir datos de una persona.\n");
        printf("2. Buscar una persona por nombre.\n");
        printf("3. Casar personas afines.\n");
        printf("4. Salir.\n");
        printf("Selecciona una opción: ");

        int opcion;
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                if (numPersonas < 100) {
                    personas[numPersonas] = introducirPersona();
                    numPersonas++;
                    printf("Datos de la persona almacenados.\n");
                } else {
                    printf("Error: Se ha alcanzado el límite de personas que se pueden almacenar.\n");
                }
                break;
            }
            case 2: {
                char nombreBuscado[50];
                printf("Introduce el nombre de la persona a buscar: ");
                scanf("%s", nombreBuscado);

                Persona *personaEncontrada = buscarPersonaPorNombre(personas, numPersonas, nombreBuscado);

                if (personaEncontrada != NULL) {
                    printf("Persona encontrada:\n");
                    printf("Nombre: %s\n", personaEncontrada->nombre);
                    printf("Apellido paterno: %s\n", personaEncontrada->ap_paterno);
                    printf("Edad: %d\n", personaEncontrada->edad);
                    printf("Sexo: %c\n", personaEncontrada->sexo);
                    printf("Aficiones:\n");
                    for (int i = 0; i < personaEncontrada->num_aficiones; i++) {
                        printf("  %s\n", personaEncontrada->aficiones[i]);
                    }
                } else {
                    printf("Persona no encontrada.\n");
                }
                break;
            }
            case 3: {
                char nombrePersona1[50];
                printf("Introduce el nombre de la primera persona: ");
                scanf("%s", nombrePersona1);

                char nombrePersona2[50];
                printf("Introduce el nombre de la segunda persona: ");
                scanf("%s", nombrePersona2);

                Persona *persona1 = buscarPersonaPorNombre(personas, numPersonas, nombrePersona1);
                Persona *persona2 = buscarPersonaPorNombre(personas, numPersonas, nombrePersona2);

                if (persona1 != NULL && persona2 != NULL && persona1->sexo != persona2->sexo) {
                    int afines = 1; // Suponemos que son afines hasta que se demuestre lo contrario
                    for (int i = 0; i < persona1->num_aficiones; i++) {
                        int coincide = 0;
                        for (int j = 0; j < persona2->num_aficiones; j++) {
                            if (strcmp(persona1->aficiones[i], persona2->aficiones[j]) == 0) {
                                coincide = 1;
                                break;
                            }
                        }
                        if (!coincide) {
                            afines = 0;
                            break;
                        }
                    }

                    if (afines) {
                        casarPersonas(persona1, persona2, personas, &numPersonas);
                    } else {
                        printf("Las personas no son afines para casarse.\n");
                    }
                } else {
                    printf("Error: Una de las personas no existe o tienen el mismo sexo.\n");
                }
                break;
            }
            case 4: {
                // Liberar la memoria de todas las personas antes de salir
                for (int i = 0; i < numPersonas; i++) {
                    free(personas[i]);
                }
                return 0;
            }
            default:
                printf("Opción no válida. Por favor, selecciona una opción válida.\n");
        }
    }

    return 0;
}


