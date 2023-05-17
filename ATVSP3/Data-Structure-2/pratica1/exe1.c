#include "struct.h"


int main(int argc, char const *argv[]){
    
    Aluno alunos[N_ALUNOS];
    AlunoC alunosc[N_ALUNOS];

    FILE *arquivo_alunos = fopen("alunos.txt", "r");
    FILE *arquivo_conceitos = fopen("conceitos.txt", "w");

    int counter = 0;
    while((fscanf(arquivo_alunos, "%d %[A-Z a-z] %f %f %f %d" , &alunos[counter].matricula, alunos[counter].nome, &alunos[counter].nota1, &alunos[counter].nota2, &alunos[counter].nota3, &alunos[counter].faltas) != EOF) || counter < N_ALUNOS){
        alunosc[counter].matricula = alunos[counter].matricula;
        strcpy(alunosc[counter].nome, alunos[counter].nome);

        float media = 0;
        media = (alunos[counter].nota1 + alunos[counter].nota2 + alunos[counter].nota3) / 3.0;

        if(alunos[counter].faltas > 18){
            alunosc[counter].conceito = 'F';
        }else if(media < 6.0){
            alunosc[counter].conceito = 'R';
        }else if(media > 6 && media < 7.5){
            alunosc[counter].conceito = 'C';
        }else if(media > 7.5 && media < 9){
            alunosc[counter].conceito = 'B';
        }else if(media > 9.0 && media < 10.0){
            alunosc[counter].conceito = 'A';
        }

        fprintf(arquivo_conceitos, "%d %29s %c \n", alunosc[counter].matricula, alunosc[counter].nome, alunosc[counter].conceito);

        counter++;
    }
    
    fclose(arquivo_alunos);
    fclose(arquivo_conceitos);

    return 0;
}
