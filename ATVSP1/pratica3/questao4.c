#include <stdio.h>
  int main()
  {
  	//declaração de variáveis
  	float salario;
  	printf("Entre com o salário:");
  	scanf("%f",&salario);
  	int codigo;
  	printf("Entre com o código do cargo:");
  	scanf("%d",&codigo);
  	
  	//saída de dados
  	switch(codigo)
  	{
  	case 100:
  		printf("Antigo:R$%.2f\nNovo:R$%.2f\nDiferença:R$%.2f\n",salario,(salario*(1.03)),(salario*(1.03) - salario));
  	break;
  	case 101:
  		printf("Antigo:R$%.2f\nNovo:R$%.2f\nDiferença:R$%.2f\n",salario,(salario*(1.05)),(salario*(1.05) - salario));
  	break;
  	case 102:
  		printf("Antigo:R$%.2f\nNovo:R$%.2f\nDiferença:R$%.2f\n",salario,(salario*(1.075)),(salario*(1.075) - salario));
  	break;
  	case 201:
  		printf("Antigo:R$%.2f\nNovo:R$%.2f\nDiferença:R$%.2f\n",salario,(salario*(1.1)),(salario*(1.1) - salario));
  	break;
  	default:
  		printf("Antigo:R$%.2f\nNovo:R$%.2f\nDiferença:R$%.2f\n",salario,(salario*(1.15)),(salario*(1.15) - salario));
  		
  	}
  	return 0;
  }
