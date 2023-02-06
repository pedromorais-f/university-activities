#include <stdio.h>
#include <math.h>

//estrutura
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
    Ponto p1;
    float d;

    printf("Digite as coordenadas de C1:");
    scanf("%lf %lf %lf",&c1.centro.x,&c1.centro.y,&c1.raio);

    printf("Digite as coordenadas de P1:");
    scanf("%lf %lf",&p1.x,&p1.y);

    //cálculo
    d = sqrt(pow((c1.centro.x - p1.x),2) + pow((c1.centro.y - p1.y),2));

    if(d > c1.raio){

        printf("P1 está fora de C1\n");
    }
    else if(d < c1.raio){

        printf("P1 está dentro em C1\n");
    }
    else if(d == c1.raio){

        printf("P1 está em C1\n");
    }

    return 0;
}

