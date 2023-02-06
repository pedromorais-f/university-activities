#include <stdio.h>
#include <string.h>


int main(){

    FILE *arquivo = fopen("nacao.txt","r");
    char pais[30];
    
    
    
    int n,m;
    printf("Digite um intervalo de impressão dos países:");
    scanf("%d %d",&n,&m);
    while((n < 1) || (m > 216)){

        printf("VALOR INVÁLIDO\n");
        printf("Digite um intervalo de impressão dos países:");
        scanf("%d %d",&n,&m);
    }
    int numero;

    for(int k = 1;k <= 216;k++){

        fscanf(arquivo,"%d",&numero);
        fgets(pais,30,arquivo);
        int tamanho = strlen(pais);
        pais[tamanho - 1] = '\0';
        if((numero >= n) && (numero <= m)){

            for(int i = n;i < m;i++){

                fgets(pais,30,arquivo);
                int tamanho = strlen(pais);
                pais[tamanho - 1] = '\0';

                for(int j = 0;j < tamanho;j++){

                    
                    printf("%c",pais[j]);
                }
                    printf("\n");
            }
        }
        numero++;
    }
    fclose(arquivo);
    return 0;
}