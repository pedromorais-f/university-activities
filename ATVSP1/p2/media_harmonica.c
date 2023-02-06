#include <stdio.h>

//função principal

int main(){

	int numeros;
	int validador=0;
	float h,soma;
	
	while(validador==0){
		printf("Quantos números quer digitar?");
		scanf("%d",&numeros);
		if(numeros<0){
			printf("Números negativos não são permitidos nesta opção!\n");
		}
		else if(numeros == 0){
		
			printf("Número inválido,Digite novamente!\n");
		}
		else{
		
			validador=1;
		}
	}
	for(int i=1;i <= numeros;i++){
	
		float n;
		printf("Número %d:",i);
		scanf("%f",&n);
		
		soma += 1/n;	
	}
	
	//média harmônica
	h=numeros/soma;
	
	printf("Média Harmônica:%.2f\n",h);
	return 0;
}
