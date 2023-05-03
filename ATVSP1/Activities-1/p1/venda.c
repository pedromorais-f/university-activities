#include <stdio.h>

//protótipo
void venda_produto1(float,float*);
void venda_produto2(float,float*);
//função auxiliar
void venda_produto1(float p,float*venda)
{
	*venda=p*1.45;
}
void venda_produto2(float p,float*venda)
{
	*venda=p*1.30;
}

//função principal
int main()
{
	//entrada de dados
	float p,venda;
	printf("Valor da compra do produto:\n");
	scanf("%f",&p);
	
	//saída de dados
	if(p>=0 && p<20)
	{
		venda_produto1(p,&venda);
		printf("Valor de venda com o lucro:%.2f\n",venda);
	}
	else if(p>=20)
	{
		venda_produto2(p,&venda);
		printf("Valor de venda com o lucro:%.2f\n",venda);
	}
	else
	{
		printf("Operação inválida!\n");
	}
	return 0;	
}
