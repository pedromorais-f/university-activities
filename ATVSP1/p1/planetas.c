#include <stdio.h>

//protótipos
void p_mercurio(float,float*);
void p_venus(float,float*);
void p_terra(float,float*);
void p_marte(float,float*);
void p_jupiter(float,float*);
void p_saturno(float,float*);
void p_urano(float,float*);
void p_netuno(float,float*);
void p_plutao(float,float*);

//funções auxiliares
void p_mercurio(float p,float*resultado)
{
	*resultado=(p/9.8)*3.78;
}
void p_venus(float p,float*resultado)
{
	*resultado=(p/9.8)*8.6;
}
void p_terra(float p,float*resultado)
{
	*resultado=(p/9.8)*9.8;
}
void p_marte(float p,float*resultado)
{
	*resultado=(p/9.8)*3.72;
}
void p_jupiter(float p,float*resultado)
{
	*resultado=(p/9.8)*24.8;
}
void p_saturno(float p,float*resultado)
{
	*resultado=(p/9.8)*10.5;
}
void p_urano(float p,float*resultado)
{
	*resultado=(p/9.8)*8.5;
}
void p_netuno(float p,float*resultado)
{
	*resultado=(p/9.8)*10.8;
}
void p_plutao(float p,float*resultado)
{
	*resultado=(p/9.8)*5.88;
}

//função principal
int main()
{
	//entrada de dados
	float p,resultado;
	printf("Digite o valor do seu peso:\n");
	scanf("%f",&p);
	int escolha;
	printf("Digite um número de 1 a 9 para o planeta correspondente:\n");
	scanf("%d",&escolha);
	
	//saída de dados
	switch(escolha)
	{
	case 1:
		p_mercurio(p,&resultado);
		printf("O peso no planeta Mercúrio é:%.2f\n",resultado);
	break;
	case 2:
		p_venus(p,&resultado);
		printf("O peso no planeta Vênus é:%.2f\n",resultado);
	break;
	case 3:
		p_terra(p,&resultado);
		printf("O peso no planeta Terra é:%.2f\n",resultado);
	break;
	case 4:
		p_marte(p,&resultado);
		printf("O peso no planeta Marte é:%.2f\n",resultado);
	break;
	case 5:
		p_jupiter(p,&resultado);
		printf("O peso no planeta Júpiter é:%.2f\n",resultado);
	break;
	case 6:
		p_saturno(p,&resultado);
		printf("O peso no planeta Saturno é:%.2f\n",resultado);
	break;
	case 7:
		p_urano(p,&resultado);
		printf("O peso no planeta Urano é:%.2f\n",resultado);
	break;
	case 8:
		p_netuno(p,&resultado);
		printf("O peso no planeta Netuno é:%.2f\n",resultado);
	break;	
	case 9:
		p_mercurio(p,&resultado);
		printf("O peso no planeta Plutão é:%.2f\n",resultado);
	break;
	default:
		printf("Não consta este número nas escolhas!\n");
	}
	return 0;	
}
