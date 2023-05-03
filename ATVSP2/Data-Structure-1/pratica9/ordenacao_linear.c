#include "ordenacao_linear.h"

#include <stdio.h>
#include <string.h>

// Manter como especificado
int char2int(char c) {
    /* Funcao auxiliar para converter um char em um inteiro */
    return (int) (c - '0');
}

// Manter como especificado
void le(Paciente* pacientes, int n) {
    // PREENCHER AQUI
    /*
     * pacientes = vetor onde devem ser salvos os valores lidos
     * n = tamanho do vetor A
     */
    for(int i = 0; i < n; i++){
        scanf("%s",pacientes[i].senha);
        scanf("%s",pacientes[i].nome);
    }
}

// Manter como especificado
void imprime(Paciente* pacientes, int n){
    // PREENCHER AQUI
    /*
     * pacientes = vetor onde devem ser salvos os valores lidos
     * n = tamanho do vetor A
     */
    for(int i = 0; i < n; i++)
        printf("%s %s\n",pacientes[i].senha,pacientes[i].nome);
}

// Manter como especificado
void coutingSort(Paciente* A, Paciente* B, int n, int i) {
    // PREENCHER AQUI
    /*
     * A = vetor a ser ordenado
     * B = vetor auxiliar para armazenar o vetor A ordenado
     * n = tamanho do vetor A
     * i = digito a ser usado na ordenacao
     */
    int C[10],a = 0;

    for(int j = 0; j < 10; j++){
        C[j] = 0;
    }
    for(int k = 0; k < n; k++){
        a = char2int(A[k].senha[i]);
        C[a] = C[a] + 1;
    }
    for(int j = 1; j < 10; j++){
        C[j] = C[j] + C[j - 1];
    }
    for(int k = n - 1; k >= 0; k--){
        a = char2int(A[k].senha[i]);
        B[C[a] - 1] = A[k];
        C[a] = C[a] - 1;
    }
    for(int j = 0; j < n; j++){
        A[j] = B[j];
    }
}

// Manter como especificado
void radixSort(Paciente* pacientes, int n, int m) {
    // Vetor auxiliar a ser usado no couting sort
    Paciente B[MAX_N];
    /*
     * pacientes = vetor a ser ordenado
     * n = tamanho do vetor A
     * m = quantidade de digitos
     */
    for(int i = m - 1; i >= 0; i--)
        coutingSort(pacientes,B,n,i);
}
