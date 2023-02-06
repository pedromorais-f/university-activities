#include <stdio.h>

//função principal
int main(){

	int hi,mi;
	printf("Digite o horário atual:");
	scanf("%d %d",&hi,&mi);
	
	int hf,mf;
	printf("Digite o horário que deseja acordar:");
	scanf("%d %d",&hf,&mf);
	
	int resultado;
	
	resultado=((hf * 60) + mf) - ((hi * 60) + mi);
	
	if(resultado <= 0){
	
	resultado = resultado + 1440;
	}
	
	printf("Tempo para acordar é:%d\n",resultado);
	
	while((hi != 0) || (mi != 0) || (hf != 0) || (mf != 0)){
	
		printf("Digite o horário atual:");
		scanf("%d %d",&hi,&mi);
	
		printf("Digite o horário que deseja acordar:");
		scanf("%d %d",&hf,&mf);
	
		resultado=((hf * 60) + mf) - ((hi * 60) + mi);
	
		if(resultado <= 0){
	
		resultado = resultado + 1440;
		}
	
		printf("Tempo para acordar é:%d\n",resultado);
	}
	return 0;
}
