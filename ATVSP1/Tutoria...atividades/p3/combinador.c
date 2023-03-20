#include <stdio.h>
#include <string.h>

#define TAM 50
#define TAM2 100


//função principal
int main(){

    char string1[TAM];
    char string2[TAM];
    char stringc[TAM2];
    int vezes;
    
    printf("Digite o número de testes a ser feito:");
    scanf("%d",&vezes);
    getchar();
    
    int i = 0;
    while(i < vezes){

        printf("Digite a primeira palavra:\n");
        fgets(string1,TAM,stdin);
        string1[strlen(string1) - 1] = '\0';

        printf("Digite a segunda palavra:\n");
        fgets(string2,TAM,stdin);
        string2[strlen(string2) - 1] = '\0';

        printf("\n");

        int tamanho1 = strlen(string1);
        int tamanho2 = strlen(string2);

        int a = 0;
        int b = 0;
        for(int k = 0;k < tamanho1 + tamanho2;k++){

            if(k % 2 == 0){

                stringc[k] = string1[a];
                a++;
            }

            if(k % 2 != 0) {
            
                stringc[k] = string2[b];
                b++;
            } 
            if(tamanho2 > tamanho1){

                stringc[(tamanho1 + tamanho2) - 1] = string2[tamanho2 - 1];
            }
        }

        printf("%s\n",stringc);

        i++;
    }
    
    return 0;
}