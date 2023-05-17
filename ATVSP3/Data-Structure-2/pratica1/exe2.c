#include "struct.h"


int main(int argc, char const *argv[]){
    
    Aluno aluno;
    char enter;

    FILE *arquivo_txt = fopen("alunos.txt", "r");
    FILE *arquivo_bin = fopen("alunos.bin", "wb");
    
    while (fscanf(arquivo_txt, "%d %[A-Z a-z] %f %f %f %d %[\n]", &aluno.matricula, aluno.nome, &aluno.nota1, &aluno.nota2, &aluno.nota3, &aluno.faltas, &enter) != EOF){
        fwrite(&aluno, sizeof(aluno), 1, arquivo_bin);
    }
    
    fclose(arquivo_txt);
    fclose(arquivo_bin);
    
    return 0;
}
