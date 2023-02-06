#include <stdio.h>

void somaprod(int a,int b,int *p,int *q)
{
	*p=a + b;
	*q=a * b;
}
int main()
{
int s,p,a,b;
scanf("%d %d",&a,&b);
somaprod(a,b,&s,&p);
printf("Soma=%d Produto=%d",s,p);
return 0;
}
