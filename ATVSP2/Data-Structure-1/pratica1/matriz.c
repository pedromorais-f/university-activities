#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>

void lerOrdem(int *ordem) {

    scanf("%d",ordem);
}

//manter como especificado
double **alocaMatriz(int ordem) {

    double **m;
    m = malloc(ordem * sizeof(double*)); 
    for (int i = 0; i < ordem; i++){ 
        
        m[i] = malloc(ordem * sizeof(double));
    }
    return m;
}

//manter como especificado
void desalocaMatriz(double ***M, int ordem) {

    for(int i = 0;i < ordem;i++){

        free(M[0][i]);
    }
    free(M[0]);
}

//manter como especificado
void lerOperacao(char *operacao) {

    getchar();
    scanf("%c",operacao);
    getchar();
}

void lerMatriz(double **M, int ordem) {

    for(int i = 0;i < ordem;i++){

        for(int j = 0;j < ordem;j++){

            scanf("%lf",&M[i][j]);
        }
    }
}

double somaMatriz(double **M, int ordem) {

    double soma = 0;
    int contador = 0;
    
    for(int i = 0;i < (ordem / 2) - 1;i++){

        contador++;
        for(int j = contador;j < (ordem - contador);j++){

            soma += M[i][j];
        }
        
        if(contador == (ordem / 2) - 1){

            break;
        }
    }

    return soma;
}

double media(double resultado, int ordem) {

    int contador = 0;
    int qtd_numeros = 0;

    double media;
        
    for(int i = 0;i < (ordem / 2) - 1;i++){

        contador++;
        for(int j = contador;j < (ordem - contador);j++){

            qtd_numeros += 1;
        }
        
        if(contador == (ordem / 2) - 1){

            break;
        }
    }

    media = resultado / qtd_numeros;

    return media;
}

void printResultado(double resultado) {

    printf("%.1lf\n",resultado);
}
