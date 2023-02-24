# ifndef ordenacao_h
# define ordenacao_h

typedef struct {
    // preencher com os dados de cada time
} Time;

// Manter como especificado
void ordenacao(Time *vetor, int n);

// Manter como especificado
Time *alocaVetor(int n);

// Manter como especificado
void desalocaVetor(Time **vetor);

// faz a comparacao utilizada para ordenar os times
int compare(Time t1, Time t2);

# endif
