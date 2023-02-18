#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void ordena(Aluno *alunos, int n) {
	// PREENCHER AQUI
    int i,j;
    Aluno aux;
    int espaco = 1;
    
    do{
        espaco = 3 * espaco + 1;
    }while(espaco < n);

    do{
        espaco /= 3;
        for(i = espaco;i < n;i++){
            aux = alunos[i];
            j = i - espaco;

            while(j >= 0 && compare(aux.nome,alunos[j].nome) < 0){
                alunos[j + espaco] = alunos[j];
                j -= espaco;
            }
            alunos[j + espaco] = aux;
        }
    }while(espaco > 1);
}

// Manter como especificado
int compare(const char* aluno1, const char* aluno2) {
    // PREENCHER AQUI
    int comparacao;
    comparacao = strcmp(aluno1,aluno2);
    return comparacao;
}

/* Manter como especificado */
void imprimeResposta(Aluno* alunos, int n, int k) {
    // PREENCHER AQUI
    printf("%s\n",alunos[n - k].nome);
}

/* Manter como especificado */
Aluno* alocaAlunos(int n) {
    // PREENCHER AQUI 
    Aluno *alunos;
    alunos = (Aluno*)malloc(n * sizeof(Aluno));
    return alunos;
}

/* Manter como especificado */
void liberaAlunos(Aluno** alunos) {
    // PREENCHER AQUI
    free(*alunos);
}

/* Manter como especificado */
void leAlunos(Aluno* alunos, int n) {
    // PREENCHER AQUI
    for(int i = 0;i < n;i++){
        scanf("%s",alunos[i].nome);
    }
}

/* Manter como especificado */
void leQuantidades(int* n, int* k) {
    // PREENCHER AQUI
    scanf("%d %d",n,k);
}

