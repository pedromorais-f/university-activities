#include <stdio.h>

//função principal
int main(){

	int vetor[10];
	int vetor1[10];
	int vetor2[20];
	
	int tamanho;
	printf("Digite o tamanho do vetor:");
	scanf("%d",&tamanho);
	
	int a=0;
	int b=tamanho - 1;

	for(int i = 0;i < tamanho;i++){
	
		printf("Digite os valores do primeiro vetor:");
		scanf("%d",&vetor[i]);
	}
	for(int j = 0;j < tamanho;j++){
	
		printf("Digite os valores do segundo vetor:");
		scanf("%d",&vetor1[j]);
	}
	for(int k=0;k < 2 * tamanho;k++){
		
		if(k%2 == 0){
		
		vetor2[k] = vetor[a++];
		printf("%d\n",vetor2[k]);
		}
		if(k%2 != 0){
		
		vetor2[k] = vetor1[b--];
		printf("%d\n",vetor2[k]);
		}	
	}
	return 0;
}


