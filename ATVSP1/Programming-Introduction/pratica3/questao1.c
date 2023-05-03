#include <stdio.h>
  int main()
  {
  	//declaração da variável
  	int x;
  	printf("Entre com o ano:");
  	scanf("%d",&x);
  	
  	//saída de dados com suas condições
  	if(x%4 ==0 && x%100 != 0)
  	{
  	printf("O ano %d é bissexto\n",x);
  	}
  	else if(x%100 ==0 && x%400 == 0)
  	{
  	printf("O ano %d é bissexto\n",x);
  	}
  	else
  	{
  	printf("O ano %d não é bissexto\n",x);
  	} 
  	return 0;
  }
