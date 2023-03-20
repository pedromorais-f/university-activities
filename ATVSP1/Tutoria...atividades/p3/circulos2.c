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

    FILE *arquivo = fopen("circulos.bin","r");

    int n,m;
    printf("Digite o número de n e m:");
    scanf("%d %d",&n,&m);
    while(n >= m){

        printf("Valor inválido,n tem que ser menor que m.\n");
        printf("Digite o número de n e m:");
        scanf("%d %d",&n,&m);
    }

    Circunferencia *c = malloc((m - n) * sizeof(Circunferencia));

    for(int i = n;i <= m;i++){

        fscanf(arquivo,"%d %d %lf",&c[i].centro.x,&c[i].centro.y,&c[i].raio);
    }

    float d;
    for(int k = n;k <= m;k++){

        printf("C%d:     |",k);
        for(int l = n;l <= m;l++){

            d = sqrt(pow((c[k].centro.x - c[l].centro.x),2) + pow((c[k].centro.y - c[l].centro.y),2));
            printf("%.2f  ",d);
        }
        printf("\n\n");
    }

    fclose(arquivo);
    return 0;
}