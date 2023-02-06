#include <stdio.h>


//função principal
int main(){

	int x=1;
	int y=20;
	
	//cabeçalho da tabuada
	printf("\n");
	printf("Tabuada de multiplicação dos números de 1 a 20!\n");
	printf("  |");
	for(int i=x;i<y;i=i + 2){
	
		printf("%8d",i);
	}
	printf("\n");
	for(int l=0;l<=85;l++){
	
		printf("-");
	}
	printf("\n");
	
	
	//coluna dos números usados
	for(int j=x;j<y;j=j + 2){
	
		printf("%3d  |",j);
		for(int k=x;k<y;k=k + 2){
		
			printf("%6d  ",j * k);
		}
		printf("\n");
	}
	return 0;
}

