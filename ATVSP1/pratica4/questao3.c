#include <stdio.h> 

//protótipo
void calculaMinutos(int,int,int,int,int*);

//função auxiliar
void calculaMinutos(int hi,int mi,int hf,int mf,int*minutos)
{
	*minutos=(hf*60 + mf) - (hi*60 + mi);
	if(*minutos < 0)
	{
	*minutos= *minutos+1440;
	}
	
}

//função principal
int main()
{
	//entrada de dados 
	int hi,mi;
	printf("Entre com o horário de ínicio:\n");
	scanf("%d %d",&hi,&mi);
	int hf,mf;
	printf("Entre com o horário de término:\n");
	scanf("%d %d",&hf,&mf);
	int minutos;
	
	//saída de dados
	calculaMinutos(hi,mi,hf,mf,&minutos);
	printf("Duração=%d minutos\n",minutos);
	return 0; 
}

