#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    int **matriz;
    int soma = 0;
    float media = 0;

    printf("Digite o tamanho da matriz:");
    scanf("%d",&n);
    getchar();

    matriz = malloc(n * sizeof(int*));
    for(int j = 0;j < n;j++){

        matriz[j] = malloc(n * sizeof(int));
    }
    
    int contador = 0;
    int controlador = 0;
    char caracter;
    scanf("%c",&caracter);
    getchar();

    switch(caracter){
    
    case 'S':

        printf("Digite os valores da matriz n x n:\n");
        for(int j = 0;j < n;j++){

            for(int k = 0;k < n;k++){

                scanf("%d",&matriz[j][k]);
                getchar();
            }
        }
        
        for(int i = n - 1;i > 0;i--){

            for(int j = 1 + controlador;j < n;j++){

                soma += matriz[j][i];
            }
            controlador++;
        }
        
        printf("%d\n",soma);
        break;

    case 'M': 

        printf("Digite os valores da matriz n x n:\n");
        for(int j = 0;j < n;j++){

            for(int k = 0;k < n;k++){

                scanf("%d",&matriz[j][k]);
                getchar();
            }
        }
        
        for(int i = n - 1;i > 0;i--){

            for(int j = 1 + controlador;j < n;j++){

                /*if(matriz[i][j] == matriz[i][controlador]){

                    a++;
                    break;
                }*/
                
                contador++;
                soma += matriz[j][i];
                //printf("%d\n",soma);
            }
            controlador++;
        }
        media = soma / (float)contador;
        
        printf("%.0f\n",media);
        break;   
    
    default:

        printf("\nCaracter inválido!!!!\n");
        break;
    }
    return 0;
}