#include <stdio.h>
#include <stdlib.h>

int verificamatriz(int **,int);


int main(){

    int **matriz;
    int n;

    printf("Digite o valor de n:");
    scanf("%d",&n);

    matriz = malloc(n * sizeof(int*));
    for(int j = 0;j < n;j++){

        matriz[j] = malloc(n * sizeof(int));
    }

    printf("Digite os valores da matriz n x n:\n");
    for(int j = 0;j < n;j++){

        for(int k = 0;k < n;k++){

            scanf("%d",&matriz[j][k]);
        }
    }

    if(verificamatriz(matriz,n) == 1){

        printf("Esta matriz é um quadrado mágico!\n");
    }
    else{

        printf("Esta matriz NÃO é um quadrado mágico!\n");
    }

    return 0;
}

int verificamatriz(int **matriz,int n){

    int somalinhas = 0;
    int somacolunas = 0;
    int somadiagonalp = 0;
    int somadiagonals = 0;
    int soma1 = 0;
    int a = 0;
    

    for(int i = 0;i < n;i++){

        for(int j = 0;j < n;j++){

            somalinhas += matriz[i][j];
        }
        soma1 +=  matriz[0][i];
    }
    //printf("\n%d\n\n",soma1);
    //printf("%d\n\n",somalinhas);

    if(soma1 == (somalinhas/n)){

        for(int k = 0;k < n;k++){

            for(int l = 0;l < n;l++){

                somacolunas += matriz[l][k];
            }
        }
        //printf("\n%d\n\n",soma1);
        //printf("%d\n\n",somacolunas);
        if(soma1 == (somacolunas/n)){

            for(int m = 0;m < n;m++){

                somadiagonalp += matriz[m][m];
            }
            //printf("\n%d\n\n",soma1);
            //printf("%d\n\n",somadiagonalp);
            if(soma1 == (somadiagonalp)){

                for(int o = n - 1;o >= 0;o--){
 
                    somadiagonals += matriz[a++][o];
                    if(a > n){

                        break;
                    }
                }
                //printf("\n%d\n\n",soma1);
                //printf("%d\n\n",somadiagonals);
                if(soma1 == somadiagonals){

                    return 1;
                }
                else{

                    return 0;
                }
            }
            else{

                return 0;
            }
        }
        else{

            return 0;
        }
    }
    else{

        return 0;
    }

    return 0;
}