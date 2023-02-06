#include <stdio.h>

//prototipo
long long num_fat(int);

//função auxiliar
long long num_fat(int num){
	long long f=1;
	for(int i=2;i<=num;i++){
		f*=i;
	}
	return f;
}

//função principal
int main(){
	
	int num;
	long long fat;
	printf("Digite o valor de n:\n");
	scanf("%d",&num);
	
	//saída de valores
	fat=num_fat(num);
	
	printf("%d!=%lld\n",num,fat);
	return 0;
}
