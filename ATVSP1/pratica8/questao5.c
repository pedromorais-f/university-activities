#include <stdio.h>

#define TAM 10

//função principal
int main(){

    int matriz1[TAM][TAM];
    int matriz2[TAM][TAM];
    int matrizr[TAM][TAM];

    int m,n,p,q;
    printf("Entre com os valores de m,p,q,n:");
    scanf("%d %d %d %d",&m,&p,&q,&n);

    printf("\n");

    while((m >=10) || (n >=10) || (p >= 10) || (q >= 10) || (p != q) || (m <= 0) || (n <= 0) || (p <= 0) || (q <= 0)){

        printf("Valores inválidos!");
        printf("\n");
        printf("Entre com os valores de m,p,q,n:");
        scanf("%d %d %d %d",&m,&p,&q,&n);
    }
    
    printf("Entre com os elementos da matriz:");
    for(int i = 0;i < m;i++){
        
        for(int j = 0;j < p;j++){

            scanf("%d",&matriz1[i][j]);
        }
    }
    
    printf("\n");

    printf("Entre com os elementos da matriz:");
    for(int k = 0;k < q;k++){
        
        for(int l = 0;l < n;l++){

            scanf("%d",&matriz2[k][l]);
        }
    }

    printf("\n");

    for(int i = 0;i < m;i++){

        for(int l = 0;l < n;l++){

            int n = 0;
            for(int m = 0;m < q;m++){

                n += matriz1[i][m] * matriz2[m][l];
            }
            
            matrizr[i][l] = n;
            printf("%d ",matrizr[i][l]);
        }
        
        printf("\n");
        printf("\n");
    }
    return 0; 
}