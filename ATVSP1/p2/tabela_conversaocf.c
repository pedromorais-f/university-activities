#include <stdio.h>

//função principal
int main(){

    int min = 1;
    int max = 5;
    float c;

    //cabeçalho
    printf("\n");
    
    printf("TABELA DE CONVERSÃO DE TEMPERATURAS\n");

    for(int i =0;i < 80;i++){

        printf("-");
    }
    printf("\n");
    for(int j = min;j <= max;j++){

        printf("%7d |",j);
    }

    printf("\n");

    for(int l =0;l < 80;l++){

        printf("-");
    }
    printf("\n");

    //tabela das conversões
    for(int n = min;n <=max;n++){

        c = 1.8 * (n - 32);
        printf("%.2f  |",c);
    }
        
    
    printf("\n");

    return 0;
}