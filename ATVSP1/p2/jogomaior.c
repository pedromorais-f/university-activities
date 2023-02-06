#include <stdio.h>

int main(){
	int rodadas,n1,n2,p1=0,p2=0,i=0;
	printf("Determine o número de rodadas:");
	scanf("%d",&rodadas);
	if(rodadas ==0){
		printf("Fim de jogo!\n");
		return 0;
	}
	while(i < rodadas){
		printf("Digite os números desejados:");
		scanf("%d %d",&n1,&n2);
		if(n1>n2){
			p1++;	
		}
		else if(n2>n1){
			p2++;
		}
	++i;
	}
	printf("POntuação final do jogador 1:%d\nPontuação final do jogador 2:%d\n",p1,p2);
	return 0;
}
