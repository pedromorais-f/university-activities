#include <stdio.h>
#include <string.h>

#define N_ALUNOS 3

typedef struct {
    int matricula;
    char nome[30];
    float nota1, nota2, nota3;
    int faltas;
}Aluno;


typedef struct{
    int matricula;
    char nome[30];
    char conceito;
}AlunoC;


