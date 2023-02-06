#include <stdio.h>
int main()
{
	//declaração de variáveis
	int ddd;
	printf("Entre com o DDD:");
	scanf("%d",&ddd);
	
	//saída de dados com as condições propostas
	switch(ddd)
	{
	case 61:
	printf("Brasília\n");
	break;
	
	case 71:
	printf("Salvador\n");
	break;
	
	case 11:
	printf("São Paulo\n");
	break;
	
	case 21:
	printf("Rio de Janeiro\n");
	break;
	
	case 32:
	printf("Juíz de Fora\n");
	break;
	
	case 19:
	printf("Campinas\n");
	break;
	
	case 27:
	printf("Vitória\n");
	break;
	
	case 31:
	printf("Belo Horizonte\n");
	break;
	
	default:
	printf("DDD não cadastrado\n");
	}
	return 0;
}
