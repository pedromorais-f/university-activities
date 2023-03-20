#include <stdio.h>
#include <string.h>

#define TAM 200
#define TAM2 10000

//estrutura
typedef struct {
    
    char nome[TAM];
    char funcao[TAM];
    int idade;
    float salario;

}Funcionario;

//protótipo
void remocao_salto(Funcionario *);

//função principal
int main(){

    Funcionario func[TAM2];
    char terminar[] = "FIM";
    int i = 0;

    for(int j = 0;j < TAM2;j++){

        strcpy(func[j].nome,"NULL");
        strcpy(func[j].funcao,"NULL");
        func[j].idade = 0;
        func[j].salario = 0.0;
    }
    
    
    printf("\n\n                           CADASTRO DOS FUNCIONÁRIOS\n");
    for(int l = 0;l < 95;l++){

        printf("-");
    }

    for(i = 0;i < TAM2;i++){

        printf("\n\nNome do funcionário ou FIM para sair:");
        fgets(func[i].nome,TAM,stdin);
        func[i].nome[strlen(func[i].nome) - 1] = '\0';

        if(strcmp(terminar,func[i].nome) == 0){

            break;
        }
        
        printf("\nIdade:");
        scanf("%d",&func[i].idade);
        getchar();
    
        
        printf("\nFunção:");
        fgets(func[i].funcao,TAM,stdin);
        func[i].nome[strlen(func[i].funcao) - 1] = '\0';
        
       
        printf("\nSalário:");
        scanf("%f",&func[i].salario);
        getchar();
    }

    printf("\n\n                               LISTA DE CADASTRADOS\n");
    for(int l = 0;l < 95;l++){

        printf("-");
    }

    printf("\n\n");

    printf("|NOME           \t|IDADE           \t|FUNÇÃO          \t|SALÁRIO          \t|\n");
    for(int l = 0;l < 95;l++){

        printf("-");
    }
    printf("\n");
    
    for(int k = 0;k < i;k++){

        printf("|%s   |",func[k].nome);
        printf(" %d   |",func[k].idade);
        printf(" %s   |",func[k].funcao);
        printf(" %.2f |\n",func[k].salario);
        
    }
    return 0;
}

