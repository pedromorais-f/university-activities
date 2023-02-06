#include <stdio.h>

//protótipo
int num_primo(int,int);

//função auxiliar
int num_primo(int n1,int n2){
	int k;
	for(int i=n1;i<=n2;i++){
		k = 2;
		for(int j=2;j<i;j++){
			if(i%j==0){
				k++;
			}
		}
		
		if(k == 2){
			return i;
		}	
			
	}
	return 0;
}


int main(){

	int n1,n2,i;
	scanf("%d %d",&n1,&n2);
	i=num_primo(n1,n2);
	if(i != 0){
		printf("O menor primo no intervalo[%d,%d] é %d\n",n1,n2,i);
	}
	else{
		printf("Não há número primo neste intervalo!\n");
	}
	return 0;
}
