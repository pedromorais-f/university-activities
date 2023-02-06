#include <stdio.h>
#include <string.h>

#define TAM 100

//estrutura
typedef struct{

    char nome[TAM];
    float altura;
    int ano;

}Pessoa;


//protótipo
Pessoa inserir_pessoa();
void lista2_pessoas();
void lista3_pessoas();


//função principal
int main(){

    Pessoa pessoas[TAM];
    int i = 0;
    char opcao;
    int controlador = 0;
    int ano1;

    
    while(controlador == 0){
        
        printf("\n\n                                     CADASTRO DE PESSOAS\n");
        for(int k = 0;k < 95;k++){

        printf("-");
        }
        printf("\n");
       
        printf("(1) Novo Cadastro\n");
        printf("(2) Lista das pessoas cadastradas e suas alturas\n");
        printf("(3) Lista de pessoas que nasceram depois de um certo ano\n");
        printf("(0) Sair\n");
        
        printf("\n\n\nOpção:");
        scanf("%c",&opcao);
        getchar();
        
        switch(opcao){

            case '1':
                pessoas[i] = inserir_pessoa();
                i++;
                break;
            case '2':
                lista2_pessoas(i,pessoas);
                break;;
            case '3':
                printf("Escolha o ano para filtrar:");
                scanf("%d",&ano1);
                lista3_pessoas(ano1,pessoas,i);
                break;
            case '0':
                controlador = 1;
                return 0;
            default:
                printf("Opção Inválida\n");
                controlador = 0;     
       } 
    }
    return 0;
}

//funções auxiliares
Pessoa inserir_pessoa(Pessoa pessoas){

    printf("Nome:");
    fgets(pessoas.nome,TAM,stdin);
    pessoas.nome[strlen(pessoas.nome) - 1] = '\0';
    
    printf("Altura:");
    scanf("%f",&pessoas.altura);
    getchar();

    printf("Ano de nascimento:");
    scanf("%d",&pessoas.ano);
    getchar();

    return pessoas;
}

void lista2_pessoas(int i,Pessoa pessoas[]){

    printf("\n\n                 NOME E ALTURA DOS CADASTRADOS\n");
    for(int k = 0;k < 95;k++){

        printf("-");
    }

    printf("\n");

    for(int l = 0;l < i;l++){

        printf("%s  %.2f\n",pessoas[l].nome,pessoas[l].altura);
    }
    printf("\n");
}

void lista3_pessoas(int ano1,Pessoa pessoas[],int i){

    printf("\n\n                    NOME DAS PESSOAS QUE NASCERAM DEPOIS DE %d\n",ano1);
    for(int k = 0;k < 95;k++){

        printf("-");
    }

   for(int m = 0;m < i;m++){

       if(pessoas[m].ano == ano1){

           printf("\n%s\n",pessoas[m].nome);
       }
   }
}