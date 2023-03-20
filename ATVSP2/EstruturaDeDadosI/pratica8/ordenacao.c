#include "ordenacao.h"
#include <stdlib.h>
#include<stdio.h>

// Manter como especificado
Time *alocaVetor(int n) {
    Time *times = (Time*)malloc(n * sizeof(Time));
    for(int i = 0; i < n; i++){
        times[i].inscricao = i + 1;
        times[i].pontos = 0;
        times[i].cestasMarcadas = 0;
        times[i].cestasRecebidas = 0;
        times[i].razao = 0;
    }

    return times;
}

// Manter como especificado
void desalocaVetor(Time **vetor) {
    free(*vetor);
}

void heapRefaz(Time *times,int esq,int dir){
    int i = esq;
    int j = i * 2 + 1;
    Time aux = times[i];

    while(j <= dir){
        if(j < dir && compare(times[j],times[j + 1]) == 1){
            j++;
        }
        if(compare(aux,times[j]) == 2){
            break;
        }
        times[i] = times[j];
        i = j;
        j = i * 2 + 1;
    }
    times[i] = aux;
}

void heapConstroi(Time *times,int n){
    int esq = (n / 2) - 1;
    
    while(esq >= 0){
        heapRefaz(times,esq,n - 1);
        esq--;
    }
}

// implemente sua funcao de ordenacao aqui, que deve invocar a funcao compare
void ordenacao(Time *vetor, int n) {
    heapConstroi(vetor,n);
    
    while(n > 1){
        Time aux = vetor[n - 1];
        vetor[n - 1] = vetor[0];
        vetor[0] = aux;
        n--;
        heapRefaz(vetor,0,n - 1);
    }
}

// compara dois elementos do vetor de times, indicado se o metodo de ordenacao deve troca-los de lugar ou nao
int compare(const Time t1, const Time t2) {
    if(t1.pontos > t2.pontos){
        return 1;
    }else if(t2.pontos > t1.pontos){
        return 2;
    }else{
        if(t1.razao > t2.razao){
            return 1;
        }else if(t2.razao > t1.razao){
            return 2;
        }else{
            if(t1.cestasMarcadas > t2.cestasMarcadas){
                return 1;
            }else if(t2.cestasMarcadas > t1.cestasMarcadas){
                return 2;
            }else{
                if(t1.inscricao < t2.inscricao){
                    return 1;
                }
                else if(t2.inscricao < t1.inscricao){
                    return 2;
                }
            }
        }
    }
    
}

void atualizarDados(Time *times,int time1,int time2,int cestas1,int cestas2){
    times[time1 - 1].cestasMarcadas += cestas1;
    times[time1 - 1].cestasRecebidas += cestas2;

    times[time2 - 1].cestasMarcadas += cestas2;
    times[time2 - 1].cestasRecebidas += cestas1;

    if(cestas1 > cestas2){
        times[time1 - 1].pontos += 2;
        times[time2 - 1].pontos += 1;
    }else{
        times[time1 - 1].pontos += 1;
        times[time2 - 1].pontos += 2;
    }
}

void calcularSaldoDeCestas(Time *times,int n){
    int cestasMarcadas;
    int cestasRecebidas;
    float razao;

    for(int i = 0; i < n; i++){
        cestasMarcadas = times[i].cestasMarcadas;
        cestasRecebidas = times[i].cestasRecebidas;

        if(cestasRecebidas == 0){
            razao = cestasMarcadas;
        }else{
            razao = ((float)cestasMarcadas) / cestasRecebidas;
        }

        times[i].razao += razao;
    }
}

void imprimeCampeonato(Time *times,int instancia,int n){
    printf("Instancia %d\n",instancia);

    for(int i = 0; i < n; i++){
        printf("%d ",times[i].inscricao);
    }

    printf("\n");

}
