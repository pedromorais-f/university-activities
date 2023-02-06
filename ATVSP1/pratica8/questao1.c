#include <stdio.h>

#define TAM 30

//protótipo
float calctemperatura(float*);


//função auxiliar
float calctemperatura(float *temperatura){

    float media;
    float soma = 0;


    for(int i = 0;i < TAM;i++){

        printf("Entre com as temperaturas:");
        scanf("%f",&temperatura[i]);

        soma += temperatura[i];
        //printf("%d\n",i);
    }

    media = soma / TAM;

    return media;
}

//função principal

int main(){

    float temperatura[TAM];
    int contadoralto = 0;
    int contadorbaixo = 0;
    float media;
    

    media = calctemperatura(temperatura);

    for(int j = 0;j < TAM;j++){

        if(temperatura[j] > media){

            contadoralto++;
        }
        if(temperatura[j] < media){

            contadorbaixo++;
        }
    }
    
    printf("Acima:%d\n",contadoralto);
    printf("Abaixo:%d\n",contadorbaixo);

    return 0;
}