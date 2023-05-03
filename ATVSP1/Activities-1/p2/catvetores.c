#include <stdio.h>

#define TAM 5
#define TAM2 10

//função principal
int main(){

    int vetor1[TAM];
    int vetor2[TAM];
    int vetor3[TAM2];

    int a = 0;
    int b = 0;

    for(int i = 0;i < TAM;i++){

        scanf("%d",&vetor1[i]);
    }
    printf("\n");
    for(int j = 0;j < TAM;j++){

        scanf("%d",&vetor2[j]);
    }
    for (int l = 0; l < TAM2; l++)
    {
        if(l < TAM){

            vetor3[l] = vetor1[a++];
            printf("%d",vetor3[l]);
        }
        else if (l >= TAM){
        
            vetor3[l] = vetor2[b++];
            printf("%d\n",vetor3[l]);
        }
        
    }
    
    
    return 0;
}
