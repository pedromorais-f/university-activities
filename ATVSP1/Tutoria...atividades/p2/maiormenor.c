#include <stdio.h>

//função principal
int main(){

	int vetor [5];
	
	for(int i = 0;i<5;i++){
	
		printf("Digite os valores:");
		scanf("%d",&vetor[i]);
	}
	
	int maior=vetor[0];
	int menor=vetor[0];
	
	for(int j=0;j<5;j++){
	
		if(vetor[j] > maior){
		
			maior=vetor[j];
		}
		if(vetor[j] < menor){
		
			menor=vetor[j];
		}
	}
	printf("Maior=%d\n",maior);
	printf("Menor=%d\n",menor);
	return 0;
}
