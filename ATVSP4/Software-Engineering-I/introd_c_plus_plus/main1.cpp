#define EXERC1

#include <cstdlib>
#include <iostream>

using namespace std;
            
#if defined(EXERC1)
// QUEST�O 1: Critique o c�digo abaixo e aponte seus problemas com rela��o:
//          a) � flexibilidade da implementa��o: altera��es em pequenos trechos 
//             do c�digo n�o deveriam exigir recodifica��o de outras partes
//          b) � legibilidade do c�digo: lendo o c�digo � f�cil entrender os 
//             objetos e processos que ele representa. Qual � seu objetivo?

/*

1)a- Pela implementacao do codigo abaixo, seria de grande valia implementar
um construtor para a variavel "a" na classe casa e tambem a fazer a sobrecarga do operador "cout"
para a exibicao das informacoes da classe sem ter que utilizar o metodo "get".

b- Objetivo de tal codigo e instaciar um objeto da classe Casa, contendo um construtor para a variavel orc,
assim como seu getter e setter.


*/
class Casa {
      float orc;
      int a;
public:
       Casa( float o ):orc(o){ cout << "Casa criada..." << endl; }
       void setOrc( float o ) { orc = o; }
       float getOrc( void ) { return orc; }
};

#else
// QUESTAO 2: Corrija os problemas identificado na quest�o 1.
class Casa {
      // Coloque suas corre��es aqui...
      float orc;
      int a;
public:
      Casa(float o, int a){
            this->orc = o;
            this->a = a;
            cout << "Casa criada..." << endl;
      }
      void setOrc(float o){
            this->orc = o;
      }
      float getOrc() const{
            return this->orc;
      }
      friend ostream& operator<<(ostream& out, const Casa& casa){
            out << "Casa:" << casa.orc << endl << casa.a << endl;

            return out;
      }
};
// ...e aqui se necess�rio.
#endif

// QUESTAO 3: Explique o c�digo abaixo e cada uma das linhas de texto que 
// formam sua sa�da.
int main(int argc, char *argv[])
{
    //instaciacao de objetos casa, chamando o construtor para c1
    // e fazendo com que as outras variaveis apontem para o endereco de c1
    Casa c1(7), *c2 = &c1, &c3 = c1;
    
    //Imprimindo o valor da variavel orc de c1
    cout << "C1: " << c1.getOrc() << endl;

    //Mudando o valor da variavel orc em c1
    c1.setOrc(3);

    //Imprimindo o valor da variavel "orc" de c2
    //e tambem de c3
    cout << "C2: " << c2->getOrc() << ", ";
    cout << "C3: " << c3.getOrc() << endl;

    //Imprimindo o endereco de memoria de cada variavel que foi referenciada para "c1"
    cout << "C2: " << c2 << ", C3: " << &c3 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
// QUESTAO 4: Quantas vezes o construtor da classe foi invocado? Por que?
//O construtor foi invocado apenas uma vez, com relacao as outras variaveis, elas so foram rerenciadas a c1.
