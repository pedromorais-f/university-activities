#include <iostream>
#include <string>

using namespace std;

class Cliente{
private:
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


class Data : public Cliente{
private:
    int dia;
    int mes;
    int ano;
public:
    Data(string="", int=0, string="", int=0, int=0, int=0);
    ~Data();
    void setDia(int);
    int getDia() const;
    void setMes(int);
    int getMes() const;
    void setAno(int);
    int getAno() const;
};

Data::Data(string nome, int id, string endereco, int dia, int mes, int ano) : Cliente(nome, id, endereco){
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


class Conta : public Data{
private:
    int num_conta;
    double saldo;
public:
    Conta(string="", int=0, string="", int=0, int=0, int=0, int=0, double=200.0);
    ~Conta();
};

Conta::Conta(string nome, int id, string endereco, int dia, int mes, int ano, int num_conta, double saldo) : Data(nome, id, endereco, dia, mes, ano){
    this->num_conta = num_conta;
    this->saldo = saldo;
}

Conta::~Conta(){}



int main(int argc, char const *argv[]){
    

    return 0;
}
