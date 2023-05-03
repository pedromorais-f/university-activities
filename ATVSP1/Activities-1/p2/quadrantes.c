#include <stdio.h>

//função principal
int main(){

	int x;
	int y;
	printf("Digite as coordenadas escolhidas:");
	scanf("%d %d",&x,&y);
	
	if((x>0) && (y>0)){
	
		printf("Primeiro quadrante\n");
	}
	else if((x<0) && (y>0)){
	
		printf("Segundo quadrante\n");
	}
	else if((x<0) && (y<0)){
	
		printf("Terceiro quadrante\n");
	}
	else if((x>0) && (y<0)){
	
		printf("Quarto quadrante\n");
	}
	
	while((x != 0) && (y != 0)){
	
		printf("Digite as coordenadas escolhidas:");
		scanf("%d %d",&x,&y);
		
		if((x>0) && (y>0)){
	
		printf("Primeiro quadrante\n");
		}
		else if((x<0) && (y>0)){
	
		printf("Segundo quadrante\n");
		}
		else if((x<0) && (y<0)){
	
		printf("Terceiro quadrante\n");
		}
		else if((x>0) && (y<0)){
	
		printf("Quarto quadrante\n");
		}
	}
	return 0;
}	
	
