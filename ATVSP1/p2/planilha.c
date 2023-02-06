#include <stdio.h>

#define TAM 50

//função principal
int main(){

    int n;
    printf("Entre com o número de alunos da classe:");
    scanf("%d",&n);
    
    float media;
    float turma = 0;
    float mturma = 0;
    float notas[TAM][4];
    int aprovados = 0;

    for(int i = 0;i < n;i++){

        for(int j = 0;j < 4;j++){

            printf("Nota do aluno nas provas e no trabalho prático:");
            scanf("%f",&notas[i][j]);
        }
        media = ((0.2 * notas[i][0]) + (0.2 * notas[i][1]) + (0.2 * notas[i][2]) + (0.4 * notas[i][3]));
        turma += media;
        if(media >= 6){

            aprovados++;
        }
        printf("\n");
    }
    mturma = turma/n;
    printf("Quantidade de aprovados:%d\n",aprovados);
    printf("Média da turma:%.2f\n",mturma);

    return 0;
}