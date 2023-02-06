#include <stdio.h>
  //cálculo da área de um triangulo
    int main()
    {
  	//declaração das variáveis  
    	float base,altura,area;
        printf("Insira os valores da base e altura do triângulo:\n");
        scanf("%f %f",&base,&altura);
    
  	//cálculo da área
        area=(base*altura)/2;
        
  	//resultado da conta em condições     
    	if(base>0 && altura>0)
    	{
       	printf("área=%.3f\n",area);
        }
        else if(base <= 0 && altura <= 0)
        {
        printf("Não é possível este cálculo!");
        return 0;
        }
   	else
    	{
       	printf("Isso não existe!\n");
    	}  
        return 0;
    }
