#include <stdio.h>
#include <stdlib.h>


int main(){

    float soma = 0;
    float media = 0;
    
    int n;
    int aux;
    
    int maior = 0;
    int menor = 0;
    
    int *vetor2;
    int *vetor3;


    printf("Digite o valor de n: ");
    scanf("%d",&n);
    
    int *vetor1 = malloc(n * sizeof(int));
    
    printf("Digite os valores do vetor:");
    for(int i = 0;i < n;i++){

        scanf("%d",&vetor1[i]);

        soma += vetor1[i];
    }

    media = soma / (float)n ;

    printf("A média é: %.1f\n",media);

    for(int p = n - 1;p >= 0;p--){

        for(int q = 0;q < p;q++){

            if(vetor1[q] > vetor1[q + 1]){

                aux = vetor1[q];
                vetor1[q] = vetor1[q + 1];
                vetor1[q + 1] = aux;
            }
        }
    }

    for(int j = 0;j < n;j++){

        if(vetor1[j] >= media){

            maior ++;
        }

        if(vetor1[j] < media){

            menor++;
        }
    }
    
    vetor2 = malloc(maior * sizeof(int));
    vetor3 = malloc(menor * sizeof(int));

    int a = 0;
    int b = 0;
    
    for(int m = 0;m < n;m++){

        if(vetor1[m] >= media){

            vetor2[a++] = vetor1[m];
        }

        if(vetor1[m] < media){

            vetor3[b++] = vetor1[m];
        }
    }

    
    printf("Vetor com os valores abaixo da média: [");
    for(int k = 0;k < menor;k++){

        printf(" %d ",vetor3[k]);
    }
    printf("]\n");

    printf("Vetor com os valores iguais ou acima da média: [");
    for(int l = 0;l < maior;l++){

        printf(" %d ",vetor2[l]);
    }
    printf("]\n");

    free(vetor3);
    free(vetor2);
    free(vetor1);

    return 0;

}