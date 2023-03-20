#include <stdio.h>
#include <math.h>


//estruturas
typedef struct {

    double x;
    double y;
}Ponto;

typedef struct {

    Ponto centro;
    double raio;
    
}Circunferencia;

//função principal
int main(){

    Circunferencia c1;
    Circunferencia c2;
    float d;

    printf("Digite as coordenadas de C1:");
    scanf("%lf %lf %lf",&c1.centro.x,&c1.centro.y,&c1.raio);

    printf("Digite as coordenadas de C2:");
    scanf("%lf %lf %lf",&c2.centro.x,&c2.centro.y,&c2.raio);

    //calculo
    d = sqrt(pow((c2.centro.x - c1.centro.x),2) + pow((c2.centro.y - c2.centro.y),2));

    if(c1.raio > c2.raio){

        if(d < (c1.raio - c2.raio)){

            printf("C2 é interna a C1\n");
        }

        else{

            printf("Não existe circunferencia internas\n");
        }
    }
    
    else if(c2.raio > c1.raio){

        if(d < (c2.raio - c1.raio)){

            printf("C1 é interna a C2\n");
        }

        else{

            printf("Não existe circunferencia internas\n");
        }
    }

    return 0;
}
