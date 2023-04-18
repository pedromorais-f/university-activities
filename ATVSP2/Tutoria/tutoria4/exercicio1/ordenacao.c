#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

struct upa{
    int emergencia;
    int urgencia;
    int semUrgencia;
    int medicos;
    char nome[20];
};

int alocarUpa (TADupa **aux,int n){
    *aux = (TADupa*)malloc(n * sizeof(TADupa));
    return 1;
}

void preencheVetor(TADupa *upas, int n){
    for(int i = 0;i < n;i++){
        scanf("%s %d %d %d %d",upas[i].nome,&upas[i].emergencia,&upas[i].urgencia,&upas[i].semUrgencia,&upas[i].medicos);
    }
}

void ordenaUpas(TADupa *upas, int n){
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i += 1){
            TADupa temp = upas[i];
  
            int j;            
            for (j = i; j >= gap && compare(upas[j - gap],temp) == 2; j -= gap)
                upas[j] = upas[j - gap];
              
            upas[j] = temp;
        }
    }
}

void imprimeUpas(TADupa *upas, int n){
    for(int i = 0;i < n;i++){
        printf("%s %d %d %d %d\n",upas[i].nome,upas[i].emergencia,upas[i].urgencia,upas[i].semUrgencia,upas[i].medicos);
    }
}

void desalocaUpas(TADupa **aux){
    free(*aux);
}

int compare(TADupa upa1,TADupa upa2){
    if(upa1.emergencia > upa2.emergencia){
        return 1;
    }else if(upa1.emergencia < upa2.emergencia){
        return 2;
    }else{
        if(upa1.urgencia > upa2.urgencia){
            return 1;
        }else if(upa1.urgencia < upa2.urgencia){
            return 2;
        }else{
            if(upa1.semUrgencia < upa2.semUrgencia){
                return 1;
            }else if(upa1.semUrgencia > upa2.semUrgencia){
                return 2;
            }else{
                if(upa1.medicos > upa2.medicos){
                    return 1;
                }else if(upa1.medicos < upa2.medicos){
                    return 2;
                }
            }
        }
    }

    return 0;
}
