#include <stdio.h>

#define TAM 10

//função principal
int main(){

    float salario[TAM];
    float medias = 0;
    int filhos[TAM];
    float mediaf = 0;
    float percentual = 0;

    float soma1 = 0;
    float soma2 = 0;
    

    int contador = 0;
    int contador2 = 0;

    

    while(contador < TAM){

        printf("Qual o seu salário e o número de filhos na casa:");
        scanf("%f %d",&salario[contador],&filhos[contador]);
        
        if((salario[contador] < 0) || (filhos[contador] < 0) ){

                break;
        }

        soma2 += salario[contador];
        soma1 += filhos[contador];
        contador++;
        if(salario[contador] >= 1080){

            contador2++;
        }
    }
    medias = soma2 / contador;
    mediaf = soma1 / contador;
    percentual =(float) (contador2 * 100) / (float) contador;
    printf("A média de salário dos entrevistados é %.2f\n",medias);
    printf("A média dos filhos dos entrevistados é %.2f\n",mediaf);
    printf("O percentual de pessoas com mais de 1080 reais de salário é %.2f\n",percentual);
    
    float maior = salario[0];
    for(int i = 0;i < contador;i++){

        if(salario[i] > maior){

            maior = salario[i];
        }
    }
    printf("O maior salário é %.2f\n",maior);
    return 0;
}