#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
    
    int x;
    int y;
}Ponto;

typedef struct{

    Ponto centro;
    double raio;
}Circunferencia;

int main(){

    FILE *arquivo = fopen("circulos.txt","r"); 
    
    int n;
    printf("Digite o número de circunferencias:");
    scanf("%d",&n);

    Circunferencia *c = malloc(n * sizeof(Circunferencia));
    float *area = malloc(n * sizeof(float));

    for(int i = 0;i < n;i++){

        fscanf(arquivo,"%d %d %lf",&c[i].centro.x,&c[i].centro.y,&c[i].raio);
        area[i] = 3 * pow(c[i].raio,2);
    }

    float maior = area[0];
    int j;
    int circulomaior;
    for(j = 0;j < n;j++){

        if(area[j] > maior){

            maior = area[j];
            circulomaior = j;
        }
    }

    printf("\n\n");

    printf("Maior círculo = C%d\n",circulomaior + 1);
    printf("Coordenadas:\n");
    printf("    X = %d\n",c[circulomaior].centro.x);
    printf("    Y = %d\n",c[circulomaior].centro.y);

    //verificação da inscrição da circunferencia
    int contador = 0;
    float *d = malloc(n * sizeof(float));
    for(int k = 0;k < n;k++){

        d[k] = sqrt(pow((c[circulomaior].centro.x - c[k].centro.x),2) + pow((c[circulomaior].centro.y - c[k].centro.y),2));
        if(d[k] < c[circulomaior].raio - c[k].raio){

            contador++;
        }
    }
    printf("Quantidade de circunferencias inscritas: %d circunferencias\n",contador);

    fclose(arquivo);
    return 0;
}