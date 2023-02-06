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

    char nomearq[TAM];
    printf("Digite o nome do arquivo:");
    scanf("%s",nomearq);
    int tamanho = strlen(nomearq);


    printf("\n");
    
    FILE *planilha = fopen(nomearq,"r");

    nomearq[tamanho - 2] = 'a';
    nomearq[tamanho - 3] = 'd';

    printf("Arquivo %s criado com sucesso!\n",nomearq);

    FILE *planilhab = fopen(nomearq,"wb");


    Aluno aluno[NUM];
    float soman = 0;
    float somap = 0;
    int aprovados = 0;
    
    int alunos;
    fscanf(planilha,"%d",&alunos);
    fwrite(&alunos,sizeof(int),1,planilhab);
    
    
    for(int i = 0;i < alunos;i++){
        
        fscanf(planilha,"%s %f %d",aluno[i].nome,&aluno[i].nota,&aluno[i].percentual);
        int tamanho = strlen(aluno[i].nome);
        fwrite(aluno[i].nome,sizeof(char),tamanho,planilhab);
        fwrite(&aluno[i].nota,sizeof(float),1,planilhab);
        fwrite(&aluno[i].percentual,sizeof(int),1,planilhab);
        
        
        soman += aluno[i].nota;
        somap += aluno[i].percentual;
        
        if(aluno[i].nota >= 6){

            aprovados++;
        }
    }

    float median = 0;
    float mediap = 0;
    float paprovados = 0;

    //cálculos
    median = soman/alunos;
    mediap = somap/alunos;
    paprovados = (float)(aprovados * 100) / alunos;

    printf("Nota média: %.1f\n",median);
    printf("Frequência média: %.0f%%\n",mediap);
    printf("Percentual de aprovação: %.0f%%\n",paprovados);
    printf("Nome dos alunos com nota acima da nota média:\n");
    for(int j = 0;j < alunos;j++){

        if(aluno[j].nota >= 6){

            printf("%s\n",aluno[j].nome);
        }
    }

    fclose(planilhab);
    fclose(planilha);
    
    return 0;

}