//GAMBOA CAMPOS WILBERTH MANUEL
//Firmado: Tamajire 
//github https://github.com/WilberthGamboa


#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

typedef struct Factores Factores;
struct Factores
{
    float lineal;
    int elevar;
};

//petición de los limite
//void leerLimites(int a, int b, int n);
//
//void leerFunciones(Factores variables[],int cantidad,float constante);


float deltaX(float a, float b, int n); //AQUI SE SACA LA NORMAL

void riemmanIzquierda(float *incrementos,float a,int n,float delta); //incremento IZQUIERDO
void riemmanDerecha(float *incrementos,float a,int n,float delta); 
void riemmanMedio(float *incrementos,float a,int n,float delta);
//void establecerFactores
float sumatorias(Factores variables[], float*incrementos,float *aumentos,int cantidad,int n,float constante); //aumento
//IMPRIMIR
void elementosParticion(int *elementos,int n);
void imprimir(float *incrementos,int n);
void imprimirdos(float * aumentos,int n);
void imprimirFormula(Factores variables[],int cantidad,float delta,int n);

double pow(double x, double y);

int main(){
    printf("PROGRAMA AREA BAJO LA CURVA SUMA DE RIEMMAN-Gamboa Wilberth\n");
    printf("EJECTUTAR COMO ADMINISTRADOR (checar notas)");
    printf("PUEDE CALCULAR CUALQUIER FUNCION POLINOMIAL \n");
    printf("ALERTA!!!!!, el programa no verifica las entradas,LIMITES ACEPTAN DECIMALES\n");
    printf("El programa al final muestra los datos ingresados\n");
    printf("--------------------------------------------\n");
    //VARIABLES PARA LOS LIMITES Y PARTICION
    float a,b;
    int n;
    int i;
    //leerLimites(a,b,n);
    printf("\nInserte los limites\n");
    //limite a
    printf("Inserte el limite inferior(a)\n");
    scanf("%f",&a);
    //limite b
    printf("Inserte el limite superior(b)\n");
    scanf("%f",&b);
    //Particion
    printf("Inserte el orden de particion\n");
    scanf("%d",&n);
    //Lectura de la función
    Factores variables[50];
    int cantidad;
    float constante;
    //leerFunciones(variables,cantidad,constante);
    printf("Inserte la cantidad de terminos (SIN CONTAR INDEPENDIENTE)\n");
    scanf("%d",&cantidad);
    for(i=0;i<cantidad;i++){
        printf("Inserte el termino lineal\n");
        
        scanf("%f",&variables[i].lineal);
        printf("Inserte el valor del exponente\n");
        scanf("%d",&variables[i].elevar);
    }
    printf("Inserte termino independiente\n");
    scanf("%f",&constante);
    //Obtener delta
    float delta;
    delta=deltaX(a,b,n);
    //los dos vectores
    float *incrementos,*aumentos;
    int *elementos;
    incrementos= (float*)malloc(n*sizeof(float));
    aumentos=(float*)malloc(n*sizeof(float));
    elementos=(int*)malloc(n*sizeof(int));
    //Generar e imprimir el valor de los incrementos y la norma de la partici´on como un arreglo.
     int opcion;
    printf("Seleccione la opcion (ESCRIBA EL DIGITO): \n 1)Extremo izquierdo 2)Extremo derecho 3)Punto medio \n");
    scanf("%d",&opcion);

    switch (opcion)
    {
    case 1:
        riemmanIzquierda(incrementos,a,n,delta);
        break;
    case 2:
        riemmanDerecha(incrementos,a,n,delta);
        break;
    case 3:
        riemmanMedio(incrementos,a,n,delta);
        break;

    default:
        riemmanIzquierda(incrementos,a,n,delta);
        break;
    }
    system("cls");
    printf("RESPUESTA\n");
    //f ) Generar e imprimir el aumento como un arreglo
    printf("Listado de elementos de la particion como un arreglo\n");
    elementosParticion(elementos, n);
     float area;
    area=sumatorias(variables,incrementos,aumentos,cantidad,n,constante);
    area=area*delta;
    printf("\nValor de los incrementos como arreglo\n");
    imprimir(incrementos,n);
    printf("\nNorma\n");
    printf("%f\n",delta);
    printf("Valor de los aumentos como arreglo\n");
    imprimirdos(aumentos,n);
    //formula
    imprimirFormula(variables, cantidad,delta, n);
    printf("\nEl area es:%.2f unidades cuadradas\n",area);
    
    system("pause");
    
    return 0;
    

}
/*
void leerLimites(int a, int b, int n){
    printf("Inserte los limites\n");
    //limite a
    printf("Inserte el limite inferior(a)\n");
    scanf("%d",&a);
    //limite b
    printf("Inserte el limite superior(b)\n");
    scanf("%d",&b);
    //Particion
    printf("Inserte el orden de particion\n");
    scanf("%d",&n);
    
}


void leerFunciones(Factores variables[],int cantidad,float constante){
    printf("Inserte la cantidad de terminos dependientes (SIN CONTAR INDEPENDIENTE)\n");
    scanf("%d",&cantidad);
    for(int i=0;i<cantidad;i++){
        printf("Inserte el termino lineal\n");
        scanf("%f",&variables[i].lineal);
        printf("Inserte el termino cuadratico\n");
        scanf("%d",&variables[i].elevar);
    }
    printf("Inserte la constante\n");
    scanf("%f",&constante);
    
}
*/

float deltaX(float a, float b, int n){
    return (float)(b-a)/(float)n;

}

void riemmanIzquierda(float *incrementos, float a,int n,float delta){
	int i;
    incrementos[0]=a;
    
    for( i=1;i<n;i++){
        incrementos[i]=incrementos[i-1]+delta;
        
        
        
    }
}

void riemmanDerecha(float *incrementos, float a,int n,float delta){
	int i;
    incrementos[0]=a+delta;
    
    for( i=1;i<n;i++){
        incrementos[i]=incrementos[i-1]+delta;
        
        
        
    }
}

void riemmanMedio(float *incrementos, float a,int n,float delta){
	int i;
    float aux=a;
    float aux2=a+delta;
    float medio =(aux+aux2)/2;
    incrementos[0]=medio;
    
    for(i=1;i<n;i++){
        aux=aux+delta;
        aux2=aux2+delta;
        medio =(aux+aux2)/2;
        incrementos[i]=medio;
        
        
        
    }
}


float sumatorias(Factores variables[], float*incrementos,float *aumentos,int cantidad,int n,float constante){
    float aux=0;
    float area=0;
    int i;
    /*
    for (int i = 0; i < n; i++){
         aumentos[i]=0;
    }
    */
    for ( i = 0; i < n; i++){
    	int j;
        for(j=0;j<cantidad;j++){
            aux= pow(incrementos[i],variables[j].elevar);
            
            aumentos[i]=aumentos[i]+(aux*variables[j].lineal);
          
        }
        aumentos[i]=aumentos[i]+constante;
       // printf("\nPRUEBA LOCO %lf\n",aumentos[i]);
        area=area+aumentos[i];
       
    }
    return area;
    
}
void elementosParticion(int * elementos,int n){
	int i;
    for( i=0;i<n;i++){
        elementos[i]=i;
    }
    for(i=0;i<n;i++){
        printf("[x%d] ",elementos[i]);
    }
    
    
}


void imprimir(float *incrementos,int n){
	int i;
    
    for ( i = 0; i < n; i++)
    {
        
         printf("[%.2f] ",incrementos[i]);
    }
}
void imprimirdos(float *aumentos,int n){
	int i;
    for ( i = 0; i < n; i++)
    {
         printf("[%.2f]",aumentos[i]);
    }
}

void imprimirFormula(Factores variables[],int cantidad,float delta,int n){
	int i;
    printf("\nSumatoria de i=0,con i hasta n=%d",n);
    printf("Con f=");
    for( i =0;i<cantidad;i++){
        printf("+ %.1fx^%d ",variables[i].lineal,variables[i].elevar);
    }
    printf(" multiplicado por delta de x = %.2f",delta);
    
}

