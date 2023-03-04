
#include "ordenacao.h"


int main(){

    int p;
    scanf("%d",&p);


    for(int i = 0; i < p; i++){
        char *palavra;
        int movimentos;
        
        char nome[43];
        scanf("%s",nome);

        int tam = strlen(nome);

        palavra = malloc(tam * sizeof(char));

        strcpy(palavra,nome);

        verificaCaixaAlta(palavra,tam);

        int verificacao = verificaLetrasRepetidas(palavra,tam);

        ordenacao(palavra,tam,&movimentos);


        if(movimentos > 0 || verificacao == 1){
            printf("%s: N\n",nome);
        }else if(movimentos == 0){
            printf("%s: O\n",nome);
        }

        free(palavra);
    }

    return 0;
}