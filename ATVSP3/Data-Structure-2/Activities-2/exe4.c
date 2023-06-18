#include <stdio.h>

#define MM 4

typedef long TipoChave;

typedef struct TipoRegistro
{
    TipoChave Chave;
} TipoRegistro;

typedef struct TipoPagina *TipoApontador;

typedef struct TipoPagina
{
    short n;
    TipoRegistro r[MM];
    TipoApontador p[MM + 1];
} TipoPagina;

void Minimo(TipoRegistro *x, TipoApontador Ap)
{
    int pag = 1;
    if(Ap->p[pag - 1] != NULL)
        Minimo(x, Ap->p[pag - 1]);
    else
        *x = Ap->r[0];
}

int main(int argc, char const *argv[])
{

    return 0;
}
