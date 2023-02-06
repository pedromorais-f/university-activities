#include <stdio.h>
#include <string.h>

#define TAM 70

//protótipo
void remocao_salto(char *);

//função auxiliar
void remocao_salto(char *nome){

    int tamanho = strlen(nome);

    for(int i = 0;i < tamanho;i++){

        if(nome[i] == '\n'){

            nome[i] = '\0';
        }
    }
}

//função principal
int main(){

    char nome[TAM];
    char sobrenome1[TAM];
    //char sobrenomec[TAM];
    printf("Digite o nome completo:");
    fgets(nome,TAM,stdin);
    remocao_salto(nome);
    printf("\n");

    int tamanho = strlen(nome);

    int sobrenome = 0;

    for(int i = tamanho - 1;i > 0;i--){

        sobrenome1[sobrenome] = nome[i];
        if(nome[i] == ' '){

            break;
        }
        sobrenome ++;
    }

    for(int j = sobrenome;j >= 0;j--){

        printf("%c",sobrenome1[j]);
    }
    printf(",");
    for(int k = 0;k < tamanho - sobrenome;k++){

        printf("%c",nome[k]);
    }
    printf("\n");
    int letras = 0;
    
    for(int l = 0;l < tamanho;l++){

        if(nome[letras] == ' '){

            l++;
        }
        letras++;  
    }
    printf("\nTotal de letras:%d\n",letras);
    printf("\nTotal de letras do último sobrenome:%d\n",sobrenome);

    return 0;
}
