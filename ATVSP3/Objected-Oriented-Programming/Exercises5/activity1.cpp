#include <iostream>
#include <vector>
#include <math.h>
#include <typeinfo>

using namespace std;

class Forma{
public:
    virtual double getArea() = 0;
};

class FormaBidimencional : public Forma{
public:
    virtual double getArea() = 0;
};

class FormaTridimencional : public Forma{
public:
    virtual double getArea() = 0;
    virtual double getVolume() = 0;
};


class Circulo : public FormaBidimencional{
    double raio;
public:
    Circulo(double raio){
        this->raio = raio;
    }
    double getArea(){
        return 3.14 * pow(this->raio, 2);
    }
};


class Esfera : public FormaTridimencional{
    double raio;
public:
    Esfera(double raio){
        this->raio = raio;
    }
    double getArea(){
        return 4 * 3.14 * pow(this->raio, 2);
    }
    double getVolume(){
        return (4 * 3.14 * pow(this->raio, 3)) / 3 ;
    }
};





int main(int argc, char const *argv[]){
    
    vector<Forma*> formas;

    Circulo *c1 = new Circulo(4.5);
    Esfera *e1 = new Esfera(5.8);

    formas.push_back(c1);
    formas.push_back(e1);

    for (auto *forma : formas){
        if(typeid(*forma) == typeid(class Circulo))
            cout << "Area do Circulo:" << dynamic_cast<Circulo*>(forma)->getArea() << endl;
        else if(typeid(*forma) == typeid(class Esfera)){
            cout << "Area da Esfera:" << dynamic_cast<Esfera*>(forma)->getArea() << endl;
            cout << "Volume da Esfera:" << dynamic_cast<Esfera*>(forma)->getVolume() << endl;
        }
    }
    
    delete c1;
    delete e1;
    
    
    return 0;
}
