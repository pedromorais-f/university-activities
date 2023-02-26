# ifndef ordenacao_h
# define ordenacao_h

typedef struct {
    // preencher com os dados de cada time
    int cestasMarcadas;
    int cestasRecebidas;
    float razao;
    int pontos;
    int inscricao;
} Time;

// Manter como especificado
void ordenacao(Time *vetor, int n);

// Manter como especificado
Time *alocaVetor(int n);

// Manter como especificado
void desalocaVetor(Time **vetor);

void heapRefaz(Time *times,int esq,int dir);

void heapConstroi(Time *times,int n);

// faz a comparacao utilizada para ordenar os times
int compare(Time t1, Time t2);

void atualizarDados(Time *times,int time1,int time2,int pontos1,int pontos2);

void calcularSaldoDeCestas(Time *times,int n);

void imprimeCampeonato(Time *times,int instancia,int n);

# endif
