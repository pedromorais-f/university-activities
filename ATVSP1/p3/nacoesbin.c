#include <stdio.h>
#include <string.h>


int main(){

    char nomearq[13] = "nacao.txt";
    FILE *arquivo = fopen(nomearq,"r");
    char pais[30];

    int tamanho1 = strlen(nomearq);
    
    nomearq[tamanho1 - 2] = 'a';
    nomearq[tamanho1 - 3] = 'd';
    FILE *arquivobin = fopen(nomearq,"wb");

    
    
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
        fwrite(&numero,sizeof(int),1,arquivobin);
        fgets(pais,30,arquivo);
        int tamanho = strlen(pais);
        pais[tamanho - 1] = '\0';
        fwrite(&pais,sizeof(char),tamanho,arquivobin);
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
    fclose(arquivobin);
    return 0;
}