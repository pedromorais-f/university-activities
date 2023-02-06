#include <stdio.h>

//função principal

int main(){

	int x,y;
	int validador=0;
	
	while(validador == 0){
	
		printf("Digite os valores de x e y:");
		scanf("%d %d",&x,&y);
		if((x>0) && (y>0) && (x%2==0) && (y%2==0) && (y>x)){
		
			validador=1;
		}
		else if((x%2 != 0) || (y%2 != 0)){
		
			printf("Apenas número pares são aceitos.\n");
		}
		else if(x>y){
		
			printf("x deve ser menor do que y.\n");
		}
		else if((x<=0) || (y<=0)){
		
			printf("Apenas números positivos são aceitos.\n");
		}
	}
	int linha= (((y-x)/2) + 1);
	for(int i=0;i<linha;i++){
	
		int espaco;
		espaco=(((y-x)/2)-i);
		
		int asterisco;
		asterisco=x + (2 * i);
		
		
		for(int j=1;j<=espaco;j++){
		
			printf(" ");
		}
		for(int k=1;k<=asterisco;k++){
		
			printf("*");
		}
	printf("\n");
	}
	return 0;
}
