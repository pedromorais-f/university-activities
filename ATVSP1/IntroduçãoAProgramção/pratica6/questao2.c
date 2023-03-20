#include <stdio.h>

//protótipo
int num_primo(int);

//função auxiliar
int num_primo(int n1){
	int k = 0;
	for(int j=1;j<=n1;j++){
		if(n1%j==0){
			k++;
		}
	}
		
	if(k == 2){
		return n1;
	}	
	return 0;		
	}
	



int main(){

	int n1,d;
	printf("Digite um número:\n");
	scanf("%d",&n1);
	d=num_primo(n1);
	if(d != 0){
		printf("%d é um número primo!\n",n1);
	}
	else{
		printf("%d não é um número primo!\n",n1);
	}
	return 0;
}
