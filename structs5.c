#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura para números complejos
typedef struct {
    double real;
    double imaginario;
} Complejo;

Complejo *crearEstructura(Complejo *comp);
Complejo *pedirDatos(Complejo *comp, int numElem);
Complejo *sumarComplejos(Complejo *a, Complejo *b);
Complejo *restarComplejos(Complejo *a, Complejo *b);
Complejo *multiplicarComplejos(Complejo *a, Complejo *b);
Complejo *dividirComplejos(Complejo *a, Complejo *b);
void menu(Complejo *comp);
void Mensajes(int msg);
void liberar(Compelejo *comp);

void main(){
    Complejo *comp;
   menu(comp);
   liberar(Complejo *comp);

}
// Función para crear un número complejo de manera dinámica
Complejo *crearEstructura() {
    Complejo *nuevoComplejo = (Complejo *)malloc(sizeof(Complejo));
    if (nuevoComplejo == NULL) {
        Mensajes(0);
        exit(1);
    }

    printf("Introduce la parte real del número complejo: ");
    scanf("%lf", &(nuevoComplejo->real));

    printf("Introduce la parte imaginaria del número complejo: ");
    scanf("%lf", &(nuevoComplejo->imaginario));

    return nuevoComplejo;
}

// Función para sumar dos números complejos
Complejo *sumarComplejos(Complejo *a, Complejo *b) {
    Complejo *resultado = (Complejo *)malloc(sizeof(Complejo));
    if (resultado == NULL) {
        printf("Error: No se pudo reservar memoria para el resultado.\n");
        exit(1);
    }

    resultado->real = a->real + b->real;
    resultado->imaginario = a->imaginario + b->imaginario;

    return resultado;
}

// Función para restar dos números complejos
Complejo *restarComplejos(Complejo *a, Complejo *b) {
    Complejo *resultado = (Complejo *)malloc(sizeof(Complejo));
    if (resultado == NULL) {
        printf("Error: No se pudo reservar memoria para el resultado.\n");
        exit(1);
    }

    resultado->real = a->real - b->real;
    resultado->imaginario = a->imaginario - b->imaginario;

    return resultado;
}

// Función para multiplicar dos números complejos
Complejo *multiplicarComplejos(Complejo *a, Complejo *b) {
    Complejo *resultado = (Complejo *)malloc(sizeof(Complejo));
    if (resultado == NULL) {
        printf("Error: No se pudo reservar memoria para el resultado.\n");
        exit(1);
    }

    resultado->real = (a->real * b->real) - (a->imaginario * b->imaginario);
    resultado->imaginario = (a->real * b->imaginario) + (a->imaginario * b->real);

    return resultado;
}

// Función para dividir dos números complejos
Complejo *dividirComplejos(Complejo *a, Complejo *b) {
    Complejo *resultado = (Complejo *)malloc(sizeof(Complejo));
    if (resultado == NULL) {
        printf("Error: No se pudo reservar memoria para el resultado.\n");
        exit(1);
    }

    double denominador = (b->real * b->real) + (b->imaginario * b->imaginario);

    resultado->real = ((a->real * b->real) + (a->imaginario * b->imaginario)) / denominador;
    resultado->imaginario = ((a->imaginario * b->real) - (a->real * b->imaginario)) / denominador;

    return resultado;
}

// Función principal
void menu(Complejo *comp) {
    int opcion;
    COmplejo *comp1,*comp2;

    do {
        printf("\nMenú:\n");
        printf("1. Crear número complejo 1.\n");
        printf("2. Crear número complejo 2.\n");
        printf("3. Sumar números complejos.\n");
        printf("4. Restar números complejos.\n");
        printf("5. Multiplicar números complejos.\n");
        printf("6. Dividir números complejos.\n");
        printf("7. Salir.\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
    comp1=crearEstructura(comp1);
                break;

            case 2:
    comp2=crearEstructura(comp2);
                break;

            case 3:
                if (numero1 == NULL || numero2 == NULL) {
                    printf("Error: Debes crear ambos números complejos primero.\n");
                } else {
                    resultado = sumarComplejos(numero1, numero2);
                    printf("Resultado de la suma: %.2lf + %.2lf i\n", resultado->real, resultado->imaginario);
                    free(resultado);
                }
                break;

            case 4:
                if (numero1 == NULL || numero2 == NULL) {
                    printf("Error: Debes crear ambos números complejos primero.\n");
                } else {
                    resultado = restarComplejos(numero1, numero2);
                    printf("Resultado de la resta: %.2lf + %.2lf i\n", resultado->real, resultado->imaginario);
                    free(resultado);
                }
                break;

            case 5:
                if (numero1 == NULL || numero2 == NULL) {
                    printf("Error: Debes crear ambos números complejos primero.\n");
                } else {
                    resultado = multiplicarComplejos(numero1, numero2);
                    printf("Resultado de la multiplicación: %.2lf + %.2lf i\n", resultado->real, resultado->imaginario);
                    free(resultado);
                }
                break;

            case 6:
                if (numero1 == NULL || numero2 == NULL) {
                    printf("Error: Debes crear ambos números complejos primero.\n");
                } else {
                    resultado = dividirComplejos(numero1, numero2);
                    printf("Resultado de la división: %.2lf + %.2lf i\n", resultado->real, resultado->imaginario);
                    free(resultado);
                }
                break;

            case 7:
                // Liberar la memoria antes de salir
                if (numero1 != NULL) {
                    free(numero1);
                }
                if (numero2 != NULL) {
                    free(numero2);
                }
                return 0;

            default:
                printf("Opción no válida. Por favor, selecciona una opción válida.\n");
        }
    } while (opcion != 7);

    return 0;
}
void Mensajes(int msg){
	char* mensaje[]={"No hay memoria disponible...\n", "Memoria liberada...\n"};

	printf("%s",mensaje[msg]);
}
void liberar(Factura *fac){
	free(fac);
	Mensajes(1);
}
