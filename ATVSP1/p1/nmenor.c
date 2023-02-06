#include <stdio.h>

//FUNÇÃO PRINCIPAL

int main()
{
	//entrada de dados
	int a,b,c,d,e;
	printf("Digite os 5 números escolhidos:\n");
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	
	//saída de dados
	if(a<b && a<c && a<d && a<e)
	{
		printf("Menor número:%d\n",a);
	}
	else if(b<a && b<c && b<d && b<e)
	{
		printf("Menor número:%d\n",b);
	}
	else if(c<a && c<b && c<d && c<e)
	{
		printf("Menor número:%d\n",c);
	}
	else if(d<a && d<b && d<c && d<e)
	{
		printf("Menor número:%d\n",d);
	}
	else if(e<a && e<b && e<c && e<d)
	{
		printf("Menor número:%d\n",e);
	}
	else
	{
		printf("Todos os números são iguais!\n");
	}
	return 0;
}
