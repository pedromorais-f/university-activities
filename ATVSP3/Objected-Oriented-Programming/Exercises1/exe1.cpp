#include <iostream>

using namespace std;

class Retangulo{
private:
    double altura, base;
public:
    Retangulo(double, double);
    double getAltura();
    double getBase();
    double calcularArea();
    double calcularPerimetro();
};

Retangulo::Retangulo(double _altura, double _base){
    altura = _altura;
    base = _base;
}

double Retangulo :: getAltura(){ return altura; }
double Retangulo :: getBase(){ return base; }
double Retangulo :: calcularArea(){ return altura * base; }
double Retangulo :: calcularPerimetro(){ return (2 * altura) + (2 * base); }


int main(int argc, char const *argv[]){
    
    double altura, base;
    cin >> altura >> base;

    Retangulo obj = Retangulo(altura, base);
    cout << "Altura...: " << obj.getAltura() << endl;
    cout << "Base.....: " << obj.getBase() << endl;
    cout << "Area.....: " << obj.calcularArea() << endl;
    cout << "Perimetro: " << obj.calcularPerimetro() << endl;

    return 0;
}