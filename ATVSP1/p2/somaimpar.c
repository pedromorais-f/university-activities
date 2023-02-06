#include <stdio.h>


//função principal

int main(){

	int numero;
	printf("Digite o número desejado:");
	scanf("%d",&numero);
	
	int j = numero + 1;
	
	printf("\n");
	
	int repeticoes,i=0;
	printf("Quantas repetições?\n");
	scanf("%d",&repeticoes);
	
	printf("\n");
	
	int soma = 0;
	
	while(i<repeticoes){
	
		if((numero % 2) != 0){
		
			soma += numero;
			numero = numero + 2;
		}
		else{
		
			soma += j;
			j = j + 2;	
		}
	i++;
	}
	printf("O resultado final é:%d\n",soma);
	return 0;
}
