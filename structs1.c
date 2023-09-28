#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
     float x;
     float y;
}Punto;

int menu(Punto *p1);
Punto *crearEstructura();
void darDatos(Punto *);
//void mostrar(Punto *);
//void escoger(int op,Punto *p1);
Punto *puntoM(Punto *p1);
float distanciaEntrePuntos(Punto *p1);
void Mensajes(int msg);
void liberar(Punto*p1);

void main(){
   Punto *p1;
   int op;
   p1=crearEstructura();
   //darDatos(p1);
   op=menu(p1);
   //escoger(op,p1);



}

int menu(Punto *p1){
int opcion;
Punto *medio;
  do{
   printf("1. Da el punto A:\n");
   printf("2. Da el punto B:\n");
   printf("3. Obtenga el punto medio entre A y B\n");
   printf("4. Obtenga la distancia entre el punto A y B\n");
   printf("5. Exit\n");
   printf("Ingrese la opcion:\n");
   scanf("%d",&opcion);

          switch(opcion){

              case 1: darDatos(p1);
                      break;
              case 2: darDatos(p1);
                      break;
              case 3:
                  if (p1[0].x != 0 && p1[1].x != 0) {
                     medio=puntoM(p1);
                  printf("El punto medio entre A y B es (%.2f, %.2f)\n", medio->x, medio->y);
               }
         else {
            printf("Primero debe crear los puntos A y B.\n");
                }
           break;
              case 4:
                 if(p1[0].x != 0 && p1[1].x != 0){
                    float distancia=distanciaEntrePuntos(p1);
                    printf("La distancia entre A y B es %.2f\n",distancia);
               }
               else{
                  printf("Primero debe crear los puntos A y B");
               }
               break;
              case 5:
                 printf("Se termina el programa jeje, bye:)");
                 break;
              default:
                 printf("Opcion no valida, selecciona otra opcion.\n");
              }

           }while(opcion != 5);

    }


Punto *crearEstructura(){

   Punto *p1;

   p1=(Punto*)malloc(2*sizeof(Punto));
       if(p1==NULL){
          Mensajes(0);
          exit(0);
          }
          return p1;
      }
void darDatos(Punto *p1){
	int i;
	for(i=0;i<2;i++){
		 printf("Introduzca el valor de x del punto %d:\n",i+1);
  scanf("%f",&p1[i].x);
  printf("Introduzca el valor de y del punto %d:\n",i+1);
  scanf("%f",&p1[i].y);
		}
}
Punto *puntoM(Punto *p1){
    Punto *pm;
    pm->x=(p1[0].x + p1[1].x)/2;
    pm->y=(p1[0].y + p1[1].y)/2;

    return pm;
}
float distanciaEntrePuntos(Punto *p1){
   return sqrt(pow(p1[1].x - p1[0].x, 2)+ pow(p1[1].y - p1[0].y, 2));
}

void Mensajes(int msg){
	char* mensaje[]={"No hay memoria disponible...\n", "Memoria liberada...\n"};

	printf("%s",mensaje[msg]);
}
void liberar(Punto*p1){
	free(p1);
	Mensajes(1);
}
