#include "ordenacao.h"

void verificaCaixaAlta(char *palavra,int n){
    for(int i = 0; i < n; i ++){
        if(palavra[i] < 97){
            palavra[i] += 32;
        }
    }
}

void ordenacao(char *vetor, int n, int *movimentos){
    char aux;
    *movimentos = 0;
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

int verificaLetrasRepetidas(char *palavra,int n){
    for(int i = 0; i < n; i++){
        if(palavra[i] == palavra[i + 1]){
            return 1;
        }
    }

    return 0;
}