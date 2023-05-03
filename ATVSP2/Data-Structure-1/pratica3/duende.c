#include "duende.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { NAO=0, SIM } ESCALADO;

struct duende {
    char nome[20];
    int idade;
    ESCALADO escalado;
};

// Manter como especificado
void lerQuantidade(int *qtd) { 
    /* Le a quantidade de duendes que serao inseridos */
    /* PREENCHER AQUI */
    scanf("%d",qtd); 
}

// Manter como especificado
Duende *alocaDuendes(int n) { 
    /* Aloca n de Duendes*/
    /* PREENCHER AQUI */
    Duende *duendes;
    duendes = (Duende*)malloc(n * sizeof(Duende));

    return duendes; 
}

// Manter como especificado
Duende *copiaDuende(Duende *duendes, int i) {
    /* Aloca um novo duende baseado nos dados de um outro duende */ 
    /* PREENCHER AQUI */
    Duende *duendeCopia;
    duendeCopia = (Duende*)malloc(sizeof(Duende));
    *duendeCopia = duendes[i];

    return duendeCopia; 
}

// Manter como especificado
void desalocaDuendes(Duende **duendes){
    /* Desaloca um vetor ou um unico duende alocado dinamicamente */
    /* PREENCHER AQUI */
    free(*duendes); 
}

// Manter como especificado
void lerDuendes(Duende *duendes, int n) {
    /* Lê os dados de n de Duendes */
    /* PREENCHER AQUI */
    for(int i = 0;i < n;i++){
        scanf("%s %d",duendes[i].nome,&duendes[i].idade);
    } 
}

// Manter como especificado
int proximoMaisVelho(Duende *duendes, int n) {
    /* Pega o próximo duende mais velho que ainda nao foi escalado */
    /* PREENCHER AQUI */
    int idadeMaior = 0;
    int posicao;

    for(int i = 0;i < n;i++){  
        if((idadeMaior < duendes[i].idade) && duendes[i].escalado == NAO){
            idadeMaior = duendes[i].idade;
            posicao = i;
        }
    }

    return posicao; 
}

// Manter como especificado
void escalarDuende(Duende *duendes, int index) {
    /* Dado um vetor de duendes, "seta" como escalado um duende */
    /* PREENCHER AQUI */
    duendes[index].escalado = SIM; 
}

// Manter como especificado
void printDuende(Duende *duende) {
    /* Imprime os dados de um duende e um \n no final */
    /* PREENCHER AQUI */
    printf("%s %d\n",duende->nome,duende->idade);
}