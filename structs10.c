#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
       char nombre[25];
       int boleta;
       char semestre[15];
       char sexo;
       float calificaciones[5];
}Estudiante;

//prototipos de las funciones
Estudiante *crearArregloEstudiante(Estudiante *,int);
Estudiante *pedirDatos(Estudiante *,int);
void mostrar(Estudiante*,int);
void darNumElem(int *);
float promedio(float cal[],int numElem);
float mayor(float cal[],int cals);
void Mensajes(int msg);
void liberar(Estudiante *p1);

void main(){
    Estudiante *es;
    int numElem;
    float prom;
    darNumElem(&numElem);
    es=crearArregloEstudiante(es,numElem);
    es=pedirDatos(es,numElem);
    mostrar(es,numElem);
    liberar(es);

}
void darNumElem(int *numElem){
    printf("Indique el numero de estudiantes que conforman el club de Algoritmia:\n");
    scanf("%d",numElem);
}
Estudiante *crearArregloEstudiante(Estudiante *es,int numElem){
    es=(Estudiante*)malloc(numElem*sizeof(Estudiante));
    if(es==NULL){
        Mensajes(0);
        exit(0);
    }
    return es;
}
Estudiante *pedirDatos(Estudiante *es,int numElem){
    int i,j;
    for(i=0;i<numElem;i++){
        printf("\nIntroduzca los datos de cada estudiante del club de Algoritmia\n");
        getchar();
        printf("Dame el nombre:\n");
        scanf("%[^\n]",es[i].nombre);
        getchar();
        printf("Ingrese su boleta:\n");
        scanf("%d",&es[i].boleta);
        getchar();
        printf("Semestre:\n");
        scanf("%[^\n]",es[i].semestre);
        getchar();
        printf("Sexo (H o M)\n");
        scanf("%c",&es[i].sexo);
        getchar();
        printf("Calificaciones:\n");
        for(j=0;j<5;j++){
        scanf("%f",&es[i].calificaciones[j]);
        }
    }
    return es;
}
void mostrar(Estudiante *es,int numElem){
    int i,j;
    printf("\nLos datos de cada estudiante son\n");
    for(i=0;i<numElem;i++){
        printf("Nombre:%s\n",es[i].nombre);
        printf("Boleta:%d\n",es[i].boleta);
        printf("Semestre:%s\n",es[i].semestre);
        printf("Sexo:%c\n",es[i].sexo);
        printf("Calificaciones: ");
        for(j=0;j<5;j++){
            printf("\n%.2f\n",es[i].calificaciones[j]);
        }
        float prom=promedio(es[i].calificaciones,5);
        printf("Promedio de sus calificaciones:\n");
        printf("%.2f\n",prom);
        printf("\n");
        float may=mayor(es[i].calificaciones,5);
        printf("Su calificacion mas alta fue: %.2f\n",may);

    }

}
float mayor(float cal[],int cals){
    int i;
   float may=cal[0];
    for(i=0;i<cals;i++){
        if(cal[i]>=may){
            may=cal[i];
        }
    }
    return may;
}
float promedio(float cal[],int cals){
    int i;
    float sum=0.0,prom;

    for(i=0;i<cals;i++){
        sum+=cal[i];
    }
    prom=sum/cals;
    return prom;
}

void Mensajes(int msg){
	char* mensaje[]={"No hay memoria disponible...\n", "Memoria liberada...\n"};

	printf("%s",mensaje[msg]);
}
void liberar(Estudiante *es){
	free(es);
	Mensajes(1);
}
