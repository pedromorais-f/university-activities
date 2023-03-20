#include <stdio.h>
#include <stdlib.h>
#include <time.h>

  int main(){
  	//declaração das variáveis
  	int n1,n2,i;
  	printf("Declare dois números:");
  	scanf("%d %d",&n1,&n2);
  	
  	//sáida de dados e as condições
  	if (n1<=n2){
  	printf("%d<=%d\n",n1,n2);
  	}
  	else{
  	printf("Desculpe mas não é possível essa condição.\n");
  	return 0;
  	}
  	
        srand(time(NULL));
        i=(rand() %n1 + (n2-n1));
        printf("Número aleatório entre %d e %d:%d\n",n1,n2,i);
   return 0;	
  }
