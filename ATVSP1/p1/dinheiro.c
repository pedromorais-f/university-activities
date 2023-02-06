#include <stdio.h>
#include <math.h>

//protótipos
void contador_din(float,float*);
void impressao_din

//função auxiliar
void impressao_din(float a,float*resultado){
	float b;
	b=floor(*resultado/a);
	*resultado=*resultado - (b/a);
}
