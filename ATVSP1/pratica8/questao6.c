#include <stdio.h>
#include <string.h>

#define TAM 30

//protótipo
void remocao_salto(char *);

//função auxiliar
void remocao_salto(char *palavra){

    int tamanho = strlen(palavra);

    for(int i = 0;i < tamanho;i++){

        if(palavra[i] == '\n'){

            palavra[i] = '\0';
        }
    }
}

//função principal
int main(){

    char palavra[TAM];
    char termino[TAM] = "FIM";

    int controlador = 1;
    
    
    while(controlador == 1){

        printf("Digite uma palavra ou FIM para sair:");
        fgets(palavra,TAM,stdin);
        remocao_salto(palavra);

        int tamanho = strlen(palavra);

        if(strcmp(termino,palavra) == 0){

            controlador = 0;
            break;
        }

        int inicio = 0;
        int final = tamanho - 1;
        int validador = 0;

        while(inicio < final){

            if(palavra[inicio] != palavra[final]){
                printf("%s não é um palíndromo\n",palavra);
                break;
            }
            inicio++;
            final--;
            validador = 1;
        }
        if(validador == 1){

            printf("%s é um palíndromo\n",palavra);
        }
    }
    return 0;
}