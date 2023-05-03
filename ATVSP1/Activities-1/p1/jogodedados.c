#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//função principal


int main(){
	
	//entrada de dados do usuário
	int aposta,d1,d2,soma;
	printf("Digite o valor de sua aposta:\n");
	scanf("%d",&aposta);
	
	//cálculo
	srand(time(NULL));
	d1=rand()%6;
	d2=rand()%6;
	soma=d1 + d2;
	
	//saída de dados
	if(aposta==soma){
	printf("Resultado=%d\nParabéns,você ganhou!\n",soma);
	}
	else {
		printf("Resultado=%d\nDesculpe,você perdeu!\n",soma);
	}
	return 0;
}
