#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
int *alocaVetor(int *vetor, int n){
    int *v;
    v = malloc(n * sizeof(int));
    return v;
}

//Manter como especificado
int *desalocaVetor(int *vetor){
    free(vetor);
    return vetor;
}

void ordenacao(int *vetor, int n, int *movimentos){
    int aux;
    int j;
    for(int i = 1;i < n;i++){
        aux = vetor[i];
        for(j = i - 1;j >= 0 && aux < vetor[j];j--){
            vetor[j + 1] = vetor[j];
            *movimentos += 1;
        }
        vetor[j + 1] = aux;
    }
}
