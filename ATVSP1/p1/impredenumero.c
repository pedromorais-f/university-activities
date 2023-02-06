#include <stdio.h>
	int main(){
	//declaração de valores
	int a,b,c,d,e,x;
	scanf("%d",&x);
	
	//cálculo
	a=x/10000%10;
	b=x/1000%10;
	c=x/100%10;
	d=x/10%10;
	e=x%10;
	
	//saída
	printf("%d %d %d %d %d",a,b,c,d,e);
	return 0;
	}
	
	
	

