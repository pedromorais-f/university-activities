#include <stdio.h>

#define TAM 3

//função principal
int main(){

    int matriz[TAM][TAM];

    int soma1 = 0;
    int somaall = 0;
    

    for(int i = 0;i < TAM;i++){

        for(int j  = 0;j < TAM;j++){

            scanf("%d\n",&matriz[i][j]);
        }
    }
   for(int l = 0;l < TAM;l++){

        soma1 += matriz[l][0];
    }
    printf("Soma:%d\n",soma1);

    int mult = matriz[0][0];
    for(int m = 1;m < TAM;m++){

        mult = mult * matriz[0][m];
    }
    printf("Produto:%d\n",mult);

    for(int n = 0;n < TAM;n++){

        for(int o = 0;o < TAM;o++){

            somaall += matriz[n][o];
        }
    }
    printf("Soma Total:%d\n",somaall);

    return 0;
}