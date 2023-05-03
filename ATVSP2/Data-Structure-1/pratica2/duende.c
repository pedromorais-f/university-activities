#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duende.h"

struct duende { 

    char nome[21];
    int idade;
    ESCALADO escalado;
};

struct time { 

    char nomeLider[21];
    char nomeConfeiteiro[21];
    char nomeEntregador[21];
    char nomeEmbrulhador[21];
    int idadeLider;
    int idadeConfeiteiro;
    int idadeEntregador;
    int idadeEmbrulhador;
 };

// Manter como especificado
void lerQuantidade(int *qtdDuendes){ 

    scanf("%d",qtdDuendes);
}

// Manter como especificado
Duende *alocaDuendes(int qtdDuendes){ 

    Duende *vet;
    vet = malloc(qtdDuendes * sizeof(Duende));

    return vet;
}

// Manter como especificado
Time *alocaTimes(int qtdTimes){ 

    Time *vet;
    vet = malloc(qtdTimes * sizeof(Time));
}

// Manter como especificado
void desalocaDuendes(Duende **duendes){

    free(*duendes);
}

// Manter como especificado
void desalocaTimes(Time **times){

    free(*times);
}

// Manter como especificado
void lerDuendes(Duende *duendes, int qtdDuendes){

    for(int i = 0;i < qtdDuendes;i++){

        scanf("%s %d",duendes[i].nome,&duendes[i].idade);
    }
}

// Manter como especificado
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes){
    int i, index;
    int qtdTime = qtdDuendes/4;
    // Escalando os lideres
    for (i=0; i<qtdTime; i++) {
        
        index = proximoMaisVelho(duendes,qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeLider,duendes[index].nome); 
        times[i].idadeLider = duendes[index].idade; 
    }

    // Escalando os confeiteiros
    for (i=0; i<qtdTime; i++) {
        
        index = proximoMaisVelho(duendes,qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeConfeiteiro,duendes[index].nome); 
        times[i].idadeConfeiteiro = duendes[index].idade; 
    }

    // Escalando os entregador
    for (i=0; i<qtdTime; i++) {
        
        index = proximoMaisVelho(duendes,qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeEntregador,duendes[index].nome); 
        times[i].idadeEntregador = duendes[index].idade; 
    }

    // Escalando os embrulhador
    for (i=0; i<qtdTime; i++) {
        
        index = proximoMaisVelho(duendes,qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeEmbrulhador,duendes[index].nome); 
        times[i].idadeEmbrulhador = duendes[index].idade; 
    }
}

int proximoMaisVelho(Duende *duendes, int qtdDuendes){

    int idademaior;
    int posicao;

    idademaior = 0;
    for(int i = 0;i < qtdDuendes;i++){

        if((idademaior < duendes[i].idade) && duendes[i].escalado == NAO){

            idademaior = duendes[i].idade;
            posicao = i;
        }
    }

    return posicao; 
}

// Manter como especificado
void printTimes(Time *times, int qtdTimes){
    for (int i=0; i<qtdTimes; i++) {
        printf("Time %d\n", i+1);
        printf("PILOTO > %s %d\n", times[i].nomeLider, times[i].idadeLider);
        printf("CONFEI > %s %d\n", times[i].nomeConfeiteiro, times[i].idadeConfeiteiro);
        printf("ENTREG > %s %d\n", times[i].nomeEntregador, times[i].idadeEntregador);
        printf("EMBRUL > %s %d\n\n", times[i].nomeEmbrulhador, times[i].idadeEmbrulhador);
    }
}
