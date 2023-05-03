#include <stdio.h>
#include <stdlib.h>

//protótipo
int multiplicaMatrizes(int *** R, int ** A, int n, int m, int ** B, int p, int q);
int** criaMatriz(int m, int n);

//função principal
int main(){

    int ** R;
    int **A;
    int **B;
    int n,m,p,q;

    printf("Digite os tamanhos da matriz A:\n");
    scanf("%d %d",&n,&m);

    A = criaMatriz(n,m);

    printf("Digite os dados da matriz A:\n");
    for(int j = 0;j < n;j++){

        for(int k = 0;k < m;k++){

            scanf("%d",&A[j][k]);
        }
    }

    printf("Digite os tamanhos da matriz B:\n");
    scanf("%d %d",&p,&q);

    B = criaMatriz(p,q);

    printf("Digite os dados da matriz B:\n");
    for(int j = 0;j < p;j++){

        for(int k = 0;k < q;k++){

            scanf("%d",&B[j][k]);
        }
    }

    if(multiplicaMatrizes(&R,A,n,m,B,p,q)){

        
        printf("Resultado de A x B:\n");
        
        for(int i = 0;i < n;i++){

            for(int j = 0;j < q;j++){

                printf("%d ",R[i][j]);
            }
            printf("\n");
        }
        
    }
        

    else{

        printf("Não é possível multiplicar as matrizes A e B.\n");
    }

    for(int s = 0;s < n;s++){

        free(A[s]);
    }
    free(A);

    for(int s = 0;s < p;s++){

        free(B[s]);
    }
    free(B);
    for(int s = 0;s < n;s++){

        free(R[s]);
    }
    free(R);

    return 0;
}

//função auxiliar
int multiplicaMatrizes(int *** R, int ** A, int n, int m, int ** B, int p, int q){

    *R = criaMatriz(n,q);
    
    for(int i = 0;i < n;i++){

            for(int j = 0;j < q;j++){

                int multiplicacao = 0;
                for(int k = 0;k < p;k++){

                    multiplicacao += A[i][k] * B[k][j];
                }
                R[0][i][j] = multiplicacao;
            }
        
    }    
    if((n == q) || (m == p)){

        return 1;
    }
    else{

        return 0;
    }

    return 0;
}

int** criaMatriz(int m, int n){

    int **matrix;
    matrix = malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++){
        matrix[i] = malloc(n * sizeof(int));
    }
    return matrix;
}