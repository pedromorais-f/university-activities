#include <stdio.h>
  int main()
  {
  	//declaração das variáveis
  	int x,y,z;
  	printf("Entre com os números:");
  	scanf("%d %d %d",&x,&y,&z);
  	
  	//saída de dados com as condições
  	if(x<y && x<z && y<z)
  	{
  	printf("\nMenor:%d\nIntermediário:%d\nMaior:%d",x,y,z);
  	}
  	else if(y<x && y<z && x<z)
  	{
  	printf("\nMenor:%d\nIntermediário:%d\nMaior:%d",y,x,z);
  	}
  	else if(z<x && z<y && y<x)
  	{
  	printf("\nMenor:%d\nIntermediário:%d\nMaior:%d\n",z,y,x);
  	}
  	else if(x>y && x>z && y>z)
  	{
  	printf("\nMenor:%d\nIntermediário:%d\nMaior:%d\n",z,y,x);
  	}
  	else if(y>x && y>z && x>z)
  	{
  	printf("\nMenor:%d\nIntermediário:%d\nMaior:%d\n",z,x,y);
  	}
  	else if(z>x && z>y && y>x)
  	{
  	printf("\nMenor:%d\nIntermediário:%d\nMaior:%d\n",x,y,z);
  	}
  	else if(x>z && x>y && z>y)
  	{
  	printf("\nMenor:%d\nIntermediário:%d\nMaior:%d\n",y,z,x);
  	}
  	else if(y>x && y>z && z>x)
  	{
  	printf("\nMenor:%d\nIntermediário:%d\nMaior:%d\n",x,z,y);
  	}
  	return 0;
 }
  	
