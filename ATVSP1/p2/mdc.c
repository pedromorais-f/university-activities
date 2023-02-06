#include <stdio.h>

//protótipo
int euclides_mdc(int x,int y);

//função auxiliar
int euclides_mdc(int x,int y){
	int r = x % y;
	if(r==0){
	return y;
	}
	else{
		while(r!=0){
			r=x % y;
			x=y;
			y=r;
			return r;
			}		
	}
	return 0;
	}
	

//função principal
int main(){
	int x,y,resposta;
	printf("Digite os números desejados:\n");
	scanf("%d %d",&x,&y);
	
	resposta=euclides_mdc(x,y);
	printf("Mdc=%d\n",resposta);
	return 0;

}
