#include <stdio.h>

int trapezio(int,int,int,int);


int trapezio(int a,int b,int c,int d){
	int resultado;
	resultado=a+b+c+d;
	
	if (a==90 && d==90 && resultado==360){
		return 1;
	}
	else if(a==b && resultado==360){
		return 2;
	}
	else if(a != b && b!=c && c!=d && d!=a && resultado==360){
		return 3;
	}
	else{
		return -1;
	}
}

int main(){
	int a,b;
	printf("Digite os valores das base maior:");
	scanf("%d %d",&a,&b);
	int c,d;
	printf("digite os valores da base menor:");
	scanf("%d %d",&c,&d);
	
	
	
	if(trapezio(a,b,c,d)==1){
		printf("t1");
	}
	if(trapezio(a,b,c,d)==2){
		printf("t2");
	}
	if(trapezio(a,b,c,d)==3){
		printf("t3");
	}
	else if(trapezio(a,b,c,d)==-1){
		printf("Operação inválida");
	}
	return 0;

}
