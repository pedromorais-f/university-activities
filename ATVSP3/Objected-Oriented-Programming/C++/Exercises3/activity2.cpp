#include <iostream>

using namespace std;

class Conta
{
    double saldo;
public:
    Conta(double = 0.0);
    ~Conta();
    void credito(double);
    void debito(double);
    void setSaldo(double);
    double getSaldo() const;
    friend ostream& operator<<(ostream&, const Conta&);
};

Conta::Conta(double saldo){
    if(saldo >= 0)
        this->saldo = saldo;
    else{
        this->saldo = 0.0;
        cout << "Invalid Value" << endl;
    }
}
Conta::~Conta(){}

void Conta :: credito(double valor){
    if(valor > 0)
        this->saldo += valor;
}

void Conta :: debito(double valor){
    if(valor > 0)
        this->saldo -= valor;
}

void Conta :: setSaldo(double saldo){
    this->saldo = saldo;
}
double Conta :: getSaldo() const{
    return this->saldo;
}

ostream& operator<<(ostream& out, const Conta& obj){
    out << "Saldo: " << obj.saldo << endl;
    return out;
}


int main(int argc, char const *argv[]){
    
    Conta obj(1200.34);
    obj.credito(500.0);
    obj.debito(433.56);

    cout << obj << endl;
    
    return 0;
}
