#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    char apellidoP[50];
    char apellidoM[50];
    int numU;
    float precio[10];
    char estado[50];
} Factura;

// Prototipos de funciones
Factura *crearArregloFactura(int numElem);
Factura *pedirDatos(Factura *fac, int numElem);
void darNumElem(int *);
void mostrarA(Factura *fac, int numElem, char apellido[]);
void mostrarE(Factura *fac, int numElem, char estado[]);
void mostrarT(Factura *fac, int numElem);
void menu(Factura *fac,int numElem);
void Mensajes(int msg);
void liberar(Factura *fac);
void main(){
    Factura *fac;
    int numElem;

    darNumElem(&numElem);
    fac=crearArregloFactura(numElem);
    fac=pedirDatos(fac,numElem);
    menu(fac,numElem);
    liberar(fac);
}
void menu(Factura *fac,int numElem){
int opcion;
char apellido[50];
char estado[50];
  do{
   printf("1. Mostrar las facturas por apellido paterno.\n");
   printf("2. Mostrar las facturas por estado.\n");
   printf("3. Mostrar las facturas por todas las opciones existentes\n");
   printf("4. Exit\n");
   printf("Ingrese la opcion:\n");
   scanf("%d",&opcion);

          switch(opcion){

              case 1:
                      printf("Ingrese el apellido:\n");
                      scanf("%[^\n]",apellido);
                      mostrarA(fac,numElem,apellido);
                      break;
              case 2:
                      printf("Ingrese el estado:\n");
                      scanf("%[^\n]",estado);
                      mostrarE(fac,numElem,estado);
                      break;
              case 3: mostrarT(fac,numElem);
                      break;
              case 4:
                 printf("Se termina el programa jeje, bye:)");
                 break;
              default:
                 printf("Opcion no valida, selecciona otra opcion.\n");
              }

           }while(opcion != 4);

    }
void darNumElem(int *numElem){
    printf("Indique el numero de facturas que desea registrar:\n");
    scanf("%d",numElem);
}
Factura *crearArregloFactura(int numElem) {
    Factura *fac = (Factura *)malloc(numElem * sizeof(Factura));
    if (fac == NULL) {
        Mensajes(0);
        exit(0);
    }
    return fac;
}
Factura *pedirDatos(Factura *fac,int numElem){
    int i,j;
    for(i=0;i<numElem;i++){
        printf("\nIntroduzca los datos de cada cliente\n");
        getchar();
        printf("Dame el nombre:\n");
        scanf("%[^\n]",fac[i].nombre);
        getchar();
        printf("Dame el apellido paterno:\n");
        scanf("%[^\n]",fac[i].apellidoP);
        getchar();
        printf("Dame el apellido materno:\n");
        scanf("%[^\n]",fac[i].apellidoM);
        getchar();
        printf("Ingrese numero de unidades solicitadas:\n");
        scanf("%d",&fac[i].numU);
        getchar();
        printf("Precio de cada unidad:\n");
        for(j=0;j<fac[i].numU;j++){
            scanf("%f",&fac[i].precio);
        }
        getchar();
        printf("Estado en que se encuentra:\n");
        scanf("%[^\n]",fac[i].estado);
        getchar();
    }
    return fac;
}

void mostrarA(Factura *fac, int numElem, char apellido[]) {
    int i, j;
    printf("Facturas por apellido paterno: %s\n", apellido);
    for (i = 0; i < numElem; i++) {
        if (strcmp(fac[i].apellidoP, apellido) == 0) {
            printf("\nNombre: %s %s %s\n", fac[i].nombre, fac[i].apellidoP, fac[i].apellidoM);
            printf("Unidades solicitadas: %d\n", fac[i].numU);
            printf("Precio por unidad:\n");
            for (j = 0; j < fac[i].numU; j++) {
                printf("%.2f\n", fac[i].precio[j]);
            }
            printf("Estado: %s\n", fac[i].estado);
        }
    }
}

void mostrarE(Factura *fac, int numElem, char estado[]) {
    int i, j;
    printf("Facturas por estado: %s\n", estado);
    for (i = 0; i < numElem; i++) {
        if (strcmp(fac[i].estado, estado) == 0) {
            printf("\nNombre: %s %s %s\n", fac[i].nombre, fac[i].apellidoP, fac[i].apellidoM);
            printf("Unidades solicitadas: %d\n", fac[i].numU);
            printf("Precio por unidad:\n");
            for (j = 0; j < fac[i].numU; j++) {
                printf("%.2f\n", fac[i].precio[j]);
            }
            printf("Estado: %s\n", fac[i].estado);
        }
    }
}

void mostrarT(Factura *fac, int numElem) {
    int i, j;
    printf("Todas las facturas existentes\n");
    for (i = 0; i < numElem; i++) {
        printf("\nNombre: %s %s %s\n", fac[i].nombre, fac[i].apellidoP, fac[i].apellidoM);
        printf("Unidades solicitadas: %d\n", fac[i].numU);
        printf("Precio por unidad:\n");
        for (j = 0; j < fac[i].numU; j++) {
            printf("%.2f\n", fac[i].precio[j]);
        }
        printf("Estado: %s\n", fac[i].estado);
    }
}
void Mensajes(int msg){
	char* mensaje[]={"No hay memoria disponible...\n", "Memoria liberada...\n"};

	printf("%s",mensaje[msg]);
}
void liberar(Factura *fac){
	free(fac);
	Mensajes(1);
}



