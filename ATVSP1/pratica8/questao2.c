#include <stdio.h>

#define TAM 15

//função principal

int main(){

    int numero[TAM];
    int n;
    int inicio = 0;
    int aux;


    for(int i = 0;i < TAM;i++){

        printf("Entre com os 15 valores:");
        scanf("%d",&numero[i]);
    }

    printf("Entre com o valor de n:");
    scanf("%d",&n);

    for(int j = 0;j < n;j++){

        aux = numero[inicio];
        
        for(int l = 0;l < TAM;l++){

            numero[l] = numero[l + 1];
        }
    numero[TAM - 1] = aux;
    }
    for(int m = 0;m < TAM;m++){

        printf("%d \n",numero[m]);
    }
    return 0;
}