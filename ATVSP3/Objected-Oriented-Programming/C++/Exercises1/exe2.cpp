#include <iostream>
#include <string>

using namespace std;

class Cliente{
    string nome;
    int id;
    string endereco;
public:
    Cliente(string="", int=0, string="");
    ~Cliente();
    void setNome(string);
    string getNome() const;
    void setId(int);
    int getId() const;
    void setEndereco(string);
    string getEndereco() const;
};

Cliente::Cliente(string nome, int id, string endereco){
    this->nome = nome;
    this->id = id;
    this->endereco = endereco;
}
Cliente::~Cliente(){}

void Cliente::setNome(string nome) { this->nome = nome; }
string Cliente::getNome() const { return nome;}
void Cliente::setId(int id) { this->id = id; }
int Cliente::getId() const{ return id; }
void Cliente::setEndereco(string endereco){ this->endereco = endereco; }
string Cliente::getEndereco() const{ return endereco; }


class Data{
    int dia;
    int mes;
    int ano;
public:
    Data(int=0, int=0, int=0);
    ~Data();
    void setDia(int);
    int getDia() const;
    void setMes(int);
    int getMes() const;
    void setAno(int);
    int getAno() const;
};

Data::Data(int dia, int mes, int ano){
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

Data::~Data(){}

void Data::setDia(int dia) { this->dia = dia; }
int Data::getDia() const { return dia;}
void Data::setMes(int mes) { this->mes = mes; }
int Data::getMes() const{ return mes; }
void Data::setAno(int endereco){ this->ano = ano; }
int Data::getAno() const{ return ano; }


class Conta{
private:
    int num_conta;
    double saldo;
    Cliente cliente;
    Data data;
public:
    Conta(int, double, Cliente&, Data&);
    ~Conta();
    bool depositar(double);
    bool saque(double);
    bool tranferencia(Conta&, double);
    void mostrarDados() const;
};

Conta::Conta(int num_conta, double saldo, Cliente& cliente, Data& data){
    this->num_conta = num_conta;
    this->saldo = saldo;
    this->cliente = cliente;
    this->data = data;
}

Conta::~Conta(){}

bool Conta::depositar(double valor){
    if(valor > 0){
        saldo += valor;
        return true;
    }

    return false;
}

bool Conta::saque(double valor){
    if(valor > 0 && (saldo > valor)){
        saldo -= valor;
        return true;
    }else{
        cout << "Error" << endl;
        return false;
    }
}

bool Conta::tranferencia(Conta& cliente, double valor){
    if(valor > 0 && saldo > valor){
        cliente.saldo += valor;
        saldo -= valor;
        return true;
    }else{
        cout << "Error" << endl;
        return false;
    }
}

void Conta::mostrarDados() const{
     cout << "Informacoes Gerais: " << cliente.getNome()  <<  cliente.getEndereco()  << cliente.getId()  << endl;
     cout << "Data de entrada: " <<  data.getDia() << "/" <<  data.getMes() << "/" <<  data.getAno()  << endl;
     cout << "Numero da Conta: " <<  num_conta << endl;
     cout << "Saldo: " <<  saldo << endl;   
}

int main(int argc, char const *argv[]){
    
    Cliente c1(" Jose", 1234, " Rua 1 "), c2(" Joao", 5678, " Rua 2 ");
    Data d1(23, 3, 1980), d2(21, 7, 2012);
    Conta con1(198, 0.0, c1, d1), con2(205, 500.0, c2, d2);

    con1.mostrarDados();

    cout << endl;
    cout << endl;

    con2.mostrarDados();

    cout << "--------------------------------------------" << endl;

    con2.tranferencia(con1, 200.0);

    con1.mostrarDados();

    cout << endl;
    cout << endl;

    con2.mostrarDados();

    cout << "--------------------------------------------" << endl;

    con1.saque(100.0);
    con2.depositar(100.0);

    con1.mostrarDados();

    cout << endl;
    cout << endl;

    con2.mostrarDados();

    cout << "--------------------------------------------" << endl;

    
    return 0;
}
