#include <stdio.h>
#include "duende.h"
#include "dtime.h"

int main() {
    int qtdDuendes, qtdTimes;
    Duende *duendes;
    Time *times;

    lerQuantidade(&qtdDuendes);
    qtdTimes = qtdDuendes / 3;
    duendes = alocaDuendes(qtdDuendes);
    times = alocaTimes(qtdTimes);
    lerDuendes(duendes, qtdDuendes);
    escalarTimes(duendes, times, qtdDuendes);
    printTimes(times, qtdTimes);
    desalocaDuendes(&duendes);
    desalocaTimes(&times, qtdTimes);

    /*
        Funçoes de complexidade:
        
        escalarTimes: 3m

        proximoMaisVelho: n
        
        Ordem de complexidade das funções

        escalarTimes: O(m)

        proximoMaisVelho: O(n)
    
    
    */

    return 0; //nao remova
}
