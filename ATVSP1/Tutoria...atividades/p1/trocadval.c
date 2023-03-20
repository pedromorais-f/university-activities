#include <stdio.h>

//protótipo
void troca3(int,int,int);


//função auxiliar
void troca3(int a,int b,int c)
{
	int *pa,*pb,*pc;
	pa=&a;
	pb=&b;
	pc=&c;
	a=*&*pb;
	b=*&*pc;
	c=*&*pa;
	printf("A=%d\nB=%d\nC=%d\n",a,b,c);
}


//função principal
int main()
{
	int a=100,b=200,c=300;;
	troca3(a,b,c);
	return 0;
}
