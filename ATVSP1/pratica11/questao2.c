#include <stdio.h>
#include <stdlib.h>

// Recebe uma matriz e seus índices e retorna a matriz transposta
double** transposta(double **A, int m, int n);

// Aloca espaço para uma matriz m x n. Se não for possível criar a matriz retorna NULL
double** criaMatriz(int m, int n);

// libera o espaço utilizado por uma matriz
void liberaMatriz(double** A, int m);


int main(){

   int m , n;
   double **A;
   double **T;

    printf("Digite o valor de m e n:");
    scanf("%d %d",&m,&n);

    A = criaMatriz(m,n);

     printf("Digite a matriz:\n");
    for(int i = 0;i < m;i++){
        
        for(int j = 0;j < n;j++){

            scanf("%lf",&A[i][j]);
        }
    }

    T = transposta(A,m,n);

    printf("\nTransposta:\n");
    for(int k = 0;k < n;k++){

        for(int l = 0;l < m;l++){

            printf("%.0lf ",T[k][l]);
        }
        printf("\n");
    }

    liberaMatriz(A,m);
    for(int s = 0;s < n;s++){

        free(T[s]);
    }
    free(T);

    return 0;
}

//função auxiliar
double** criaMatriz(int m, int n){

    double **A;

    A = malloc(m * sizeof(double*));
    for(int j = 0;j < m;j++){

        A[j] = malloc(n * sizeof(double));
    }

        return A;

}

double** transposta(double **A, int m, int n){

    double **T;

    T = criaMatriz(n,m);
    
    for(int o = 0;o < m;o++){
        
        for(int p = 0;p < n;p++){

            T[p][o] = A[o][p];
        }
    }    
    return T;
}

void liberaMatriz(double** A, int m){

    for(int q = 0;q < m;q++){

        free(A[q]);
    }
    free(A);
}