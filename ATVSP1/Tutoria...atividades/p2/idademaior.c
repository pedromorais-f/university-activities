#include <stdio.h>

int main(){

	float matricula;
	int idade;
	int i = 0;
	printf("Digite o número da matrícula:");
	scanf("%f",&matricula);
		
	printf("Digite a idade do aluno:");
	scanf("%d",&idade);
	
	while(idade >= 18){
		printf("Digite o número da matrícula:");
		scanf("%f",&matricula);
		
		printf("Digite a idade do aluno:");
		scanf("%d",&idade);
		
		if(idade > 20){
		
			i++;
		}
		if(idade < 18){
		
			printf("Número de alunos maior de 20 anos:%d\n",i);
			break;
		}
		}
	return 0;	
}
