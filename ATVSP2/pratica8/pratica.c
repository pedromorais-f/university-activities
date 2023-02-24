#include "ordenacao.h"
#include <stdio.h>

int main()
{
    //enquanto houver dados
    while (1) {
        int n;
        int time1, time2, pontos1, pontos2;
        int i, npartidas;
        Time *vetor;

        //leia o numero de times
        scanf("%d", &n);

        //se for zero, o programa acaba

        //aloque o vetor

        //calcula o numero de partidas
        npartidas = n * (n - 1) / 2;

        //para cada partida...
        for (i = 0; i < npartidas; ++i) {
            scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);

            // preencher o vetor de estruturas de acordo com os dados lidos
        }

        // ordenar os times
        ordenacao(vetor, n);

        // imprima o resultado

        // desaloque o vetor
    }

    return 0;
}
