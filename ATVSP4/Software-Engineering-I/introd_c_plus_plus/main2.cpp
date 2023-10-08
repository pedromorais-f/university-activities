#include <cstdlib>
#include <iostream>

using namespace std;
            
// QUEST�O 1: O c�digo desse exerc�cio � id�ntico ao do exerc�cio anterior. 
//          Por�m o operador "<<" foi sobrecarregado para permitir que 
//          programador implemente de maneira mais f�cil a sa�da do programa.
//          Desta maneira, o codigo a seguir pode ser utilizado para imprimir
//          na tela um objeto "Casa": Casa c1; cout << c1; 
//
//          a) Explique porque o m�todo que sobrecarrega o operador "<<" precisou
//          ser declarado como amigo ("friend") da classe Casa? 
//          b) Explique o funcionamento do novo operador "<<".


/*

1)a- O metodo de sobrecarga e declarado como "friend" para ter acesso aos metodos
privados da classe.

b- O funcionamento do operador "<<" acontecera de forma que toda vez que for usado,exibira
os atributos da classe sem que necessite usar os getters, apenas com a utilizacao do objeto.

*/
class Casa {
      float orc;
public:
		// Casa( float o ):orc(o){ printf("Casa criada..."); }
       Casa( float o ):orc(o){ cout << "Casa criada..." << endl; }
       void setOrc( float o ) { orc = o; }
       float getOrc( void ) { return orc; }
       friend ostream& operator<<( ostream& s, Casa& c) {  s << c.orc; return s; }
};

// QUEST�O 2: Explique o c�digo abaixo e cada uma das linhas de texto que 
// formam sua sa�da.
int main(int argc, char *argv[])
{
    //Instacia-se um objeto da classe casa com seu construtor e referencia-se c2 a variavel c1
    Casa c1(7), &c2 = c1;
    
    //Impressao do conteudo de c1 e c2
    cout << "C1: " << c1.getOrc() << ", C2: " << c2.getOrc() << endl;

    //Mudanca do conteudo das variavel pelo setter de c2 e a impressao dos valores
    c2.setOrc(3);
    cout << "C1: " << c1 << ", C2: " << c2 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}

