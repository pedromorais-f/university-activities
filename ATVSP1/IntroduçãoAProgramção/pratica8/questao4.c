#include <stdio.h>
#include <stdlib.h>

#define TAM 100000
#define TAM2 501

//protótipo
void numeros_aleatorios(int *,int *);

//função auxiliar
void numeros_aleatorios(int *vetor,int *vetor1){
    
    int n;
    printf("Entre com número inteiro <= 500:");
    scanf("%d",&n);

    while((n > 500) || (n <= 0)){

        printf("Entre com número inteiro <= 500:");
        scanf("%d",&n);
    }

    for(int k = 0;k < TAM2;k++){

        vetor1[k] = 0;
    }

    srand(5);
    for(int i = 0;i < TAM;i++){

        int numeros = rand() % n + 1;
        vetor[i] = numeros;
        vetor1[numeros] = vetor1[numeros] + 1;
    }

    for(int j = 1;j <= n;j++){

        printf("A[%d] = %d\n",j,vetor1[j]);
    }
}

//função principal
int main(){

    int vetor[TAM];
    int vetor1[TAM2];

    numeros_aleatorios(vetor,vetor1);

    return 0;
}
