#include <stdio.h>
#include <string.h>

#define TAM 50
#define NUM 30


//estrutura
typedef struct {
    
    char nome[TAM];
    float nota;
    int percentual;
}Aluno;

//função principal
int main(){

    FILE *planilha = fopen("alunos.txt","w");

    Aluno aluno[NUM];
    int contador = 0;

    int opcao;
    printf("Digite 1 para entrar um aluno ou 0 para encerrar: ");
    scanf("%d",&opcao);
    getchar();

    while ((opcao == 1) && (contador < NUM)){

        scanf("%s %f %d",aluno[contador].nome,&aluno[contador].nota,&aluno[contador].percentual);
        contador++;

        printf("Digite 1 para entrar um aluno ou 0 para encerrar: ");
        scanf("%d",&opcao);
        getchar();
    }

    fprintf(planilha,"%d\n",contador);
    for(int i = 0;i < contador;i++){

        fprintf(planilha,"%s %.1f %d\n",aluno[i].nome,aluno[i].nota,aluno[i].percentual);
    }

    fclose(planilha);

    return 0;
    
}

