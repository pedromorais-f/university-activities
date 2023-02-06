#include <stdio.h>

//função principal
int main(){

	int conector1[5];
	int conector2[5];
	
	
	for(int i = 0;i < 5;i++){
	
		printf("Digite as saídas do conector1:");
		scanf("%d",&conector1[i]);
		
		if((conector1[i] != 0) && (conector1[i] != 1)){
		
			printf("Valor Inválido!\n");
			return 0;
		}
	}
	printf("\n");
	for(int j = 0;j < 5;j++){
	
		printf("Digite as saídas do conector2:");
		scanf("%d",&conector1[j]);
		
		if((conector1[j] != 0) && (conector1[j] != 1)){
		
			printf("Valor Inválido!\n");
			return 0;
		}
	}
	printf("\n");
	for(int k = 0;k < 5;k++){
	
		if(conector1[k] != conector2[k]){
		
			printf("Y\n");
			break;
		}
		if(conector1[k] == conector2[k]){
		
			printf("N\n");
			break;
		}
	}
	return 0;
}
