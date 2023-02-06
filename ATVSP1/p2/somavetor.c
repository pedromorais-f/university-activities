#include <stdio.h>

#define TAM 5

//função principal
int main(){

    float vetor[TAM];
    float soma = 0;

    for(int i = 0;i < TAM;i++){

        printf("N:");
        scanf("%f",&vetor[i]);
        soma += vetor[i];
    }

    printf("Soma:%.2f\n",soma);

    return 0;
}