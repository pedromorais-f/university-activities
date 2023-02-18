#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

#define MAX_TAM 30

struct upa{
    char nomeUpa[MAX_TAM];
    int nEmergencia;
    int nUrgencia;
    int nSemUrgencia;
    int nMedicos;
};

int alocarUpa (TADupa **aux,int n){
    *aux = (TADupa*)malloc(n * sizeof(TADupa));
    return 1;
}

void preencheVetor(TADupa *upas, int n){
    for(int i = 0;i < n;i++){
        scanf("%s %d %d %d %d",upas[i].nomeUpa,&upas[i].nEmergencia,&upas[i].nUrgencia,&upas[i].nSemUrgencia,&upas[i].nMedicos);
    }
}

void ordenaUpas(TADupa *upas, int n){
    int i,j,posicao;
    TADupa aux;
    for(i = 0;i < n - 1;i++){
        posicao = i;
        for(j = i + 1;j < n;j++){
            if(upas[posicao].nEmergencia < upas[j].nEmergencia){
                posicao = j;
            }else if(upas[posicao].nEmergencia == upas[j].nEmergencia){
                if(upas[posicao].nUrgencia < upas[j].nUrgencia){
                    posicao = j;
                }else if(upas[posicao].nUrgencia == upas[j].nUrgencia){
                    if(upas[posicao].nSemUrgencia < upas[j].nSemUrgencia){
                        posicao = j;
                    }else if(upas[posicao].nSemUrgencia == upas[j].nSemUrgencia){
                        if(upas[posicao].nMedicos > upas[j].nMedicos){
                            posicao = j;
                        }
                    }
                }
            }
        }
        if(posicao != i){
            aux = upas[i];
            upas[i] = upas[posicao];
            upas[posicao] = aux;
        }
    }
    
}

void imprimeUpas(TADupa *upas, int n){
    for(int i = 0;i < n;i++){
        printf("%s %d %d %d %d\n",upas[i].nomeUpa,upas[i].nEmergencia,upas[i].nUrgencia,upas[i].nSemUrgencia,upas[i].nMedicos);
    }
}

void desalocaUpas(TADupa **aux){
    free(*aux);
}
