#include "struct.h"


int main(int argc, char const *argv[]){
    
    Aluno alunos[3];

    alunos[0].matricula = 1234;
    strcpy(alunos[0].nome,"Roger Guedes");
    alunos[0].nota1 = 9.8;
    alunos[0].nota2 = 8.7;
    alunos[0].nota3 = 10.0;
    alunos[0].faltas = 6;

    alunos[1].matricula = 2345;
    strcpy(alunos[1].nome,"Neymar Junior");
    alunos[1].nota1 = 6.0;
    alunos[1].nota2 = 7.0;
    alunos[1].nota3 = 9.4;
    alunos[1].faltas = 3;

    alunos[2].matricula = 3456;
    strcpy(alunos[2].nome,"Diego Costa");
    alunos[2].nota1 = 3.4;
    alunos[2].nota2 = 5.9;
    alunos[2].nota3 = 10.0;
    alunos[2].faltas = 0;


    FILE *file = fopen("alunos.txt", "w");

    for(int i = 0; i < 3; i++){
        fprintf(file, "%d %29s %4.1f %4.1f %4.1f %d\n", alunos[i].matricula, alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].nota3, alunos[i].faltas);
    }

    fclose(file);

    return 0;
}
