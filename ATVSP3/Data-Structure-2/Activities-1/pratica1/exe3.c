#include "struct.h"


int main(int argc, char const *argv[]){
    
    Aluno alunos[N_ALUNOS];

    FILE *arquivo_bin = fopen("alunos.bin", "rb");
    fread(alunos, sizeof(Aluno), N_ALUNOS, arquivo_bin);
    fclose(arquivo_bin);

    AlunoC alunosc[N_ALUNOS];    
    FILE *arquivo_conceito = fopen("conceitos.bin", "wb");

    int counter = 0;
    while (counter < N_ALUNOS){
        alunosc[counter].matricula = alunos[counter].matricula;
        strcpy(alunosc[counter].nome, alunos[counter].nome);

        float media = 0;
        media = (alunos[counter].nota1 + alunos[counter].nota2 + alunos[counter].nota3) / 3.0;

        if(alunos[counter].faltas > 18)
            alunosc[counter].conceito = 'F';
        else if(media < 6.0)
            alunosc[counter].conceito = 'R';
        else if(media > 6 && media < 7.5)
            alunosc[counter].conceito = 'C';
        else if(media > 7.5 && media < 9)
            alunosc[counter].conceito = 'B';
        else if(media > 9.0 && media < 10.0)
            alunosc[counter].conceito = 'A';

        counter++;
    }
    fwrite(&alunosc, sizeof(AlunoC), N_ALUNOS, arquivo_conceito);

    fclose(arquivo_conceito);
    
    return 0;
}
