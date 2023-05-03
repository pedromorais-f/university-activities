#include <stdio.h>
#include <math.h>

//estrutura
typedef struct {

    double x;
    double y;
}Ponto;

//função principal
int main(){

    Ponto p;
    Ponto p2;
    float d;

    printf("Digite os pontos para os cálculos das distâncias:");
    scanf("%lf %lf",&p.x,&p.y);
    scanf("%lf %lf",&p2.x,&p2.y);

    //cálculo
    d = sqrt(pow((p2.x - p.x),2) + pow((p2.y - p.y),2));

    printf("Distância = %.2f\n",d);

    return 0;
}

