#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verificaCaixaAlta(char *palavra,int n);

void ordenacao(char *vetor, int n, int *movimentos);

int verificaLetrasRepetidas(char *palavra,int n);
#endif