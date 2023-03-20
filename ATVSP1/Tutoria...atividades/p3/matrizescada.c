#include <stdio.h>

#define TAM 500

//função principal
int main(){

    int matriz[TAM][TAM];
    
    int coluna,linha;
    scanf("%d %d",&linha,&coluna);
    getchar();

    for(int i = 0;i < linha;i++){
        for(int j = 0;j < coluna;j++){

            //printf("Digite os elementos da primeira linha:");
            scanf("%d",&matriz[i][j]);
        }
    }

    for(int j = 0;j < linha;){
        for(int k = 0;k < coluna;k++){
            
            if((matriz[j][k] != 0) && (matriz[k + 1][j] != 0)){

                printf("N\n");
                return 0;
            }
            else{

                j++;
            }
        } 
    }
     printf("S\n");
  
    return 0;
}   