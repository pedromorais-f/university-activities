#include <iostream>
#include <string>

using namespace std;

class Professor
{
private:
    string nome;
    string matricula;
    int idade;
public:
    Professor(string="", string="", int=0);
    ~Professor();
    string getNome() const;
    string getMatricula() const;
    int getIdade() const;
    void setNome(string);
    void setMatricula(string);
    void setIdade(int);
    friend ostream& operator<<(ostream&, const Professor&);
};

Professor::Professor(string nome, string matricula, int idade)
{
    this->nome = nome;
    this->matricula = matricula;
    this->idade = idade;
}
Professor::~Professor(){}

string Professor::getNome() const{ return nome; }
string Professor::getMatricula() const{ return matricula; }
int Professor::getIdade() const{ return idade; }

void Professor::setNome(string nome){ this->nome = nome; }
void Professor::setMatricula(string matricula){ this->matricula = matricula; }
void Professor::setIdade(int idade){ this->idade = idade; }

ostream& operator<<(ostream& out, const Professor& professor){
    out 
    << "\nNome.....: " << professor.nome
    << "\nMatricula: " << professor.matricula
    << "\nIdade....: " << professor.idade << endl;

    return out;
}



class ProfDE : public Professor
{
private:
    double salario;
public:
    ProfDE(string="", string="", int=0, double=1200.0);
    ~ProfDE();
    friend ostream& operator<<(ostream&, const ProfDE&);
    void setSalario(double);
    double getSalario() const;
};

ProfDE::ProfDE(string nome, string matricula, int idade, double salario) : Professor(nome, matricula, idade)
{
    this->salario = salario;
}

ProfDE::~ProfDE(){}

void ProfDE::setSalario(double salario){ this->salario = salario; }
double ProfDE::getSalario() const{ return salario; }

ostream& operator<<(ostream& out, const ProfDE& profde){
    out
    << "\nNome.....: " << profde.getNome()
    << "\nMatricula: " << profde.getMatricula()
    << "\nIdade....: " << profde.getIdade()
    << "\nSalario..: " << profde.salario << endl;

    return out;
}

class ProfHorista : public Professor
{
private:
    double salario;
    int horas_semana;
public:
    ProfHorista(string="", string="", int=0, double=1000.0, int=0);
    ~ProfHorista();
    void setSalario(double);
    double getSalario() const;
    void setHoras(int);
    int getHoras() const;
    friend ostream& operator<<(ostream&, const ProfHorista&);
};

ProfHorista::ProfHorista(string nome, string matricula, int idade, double salario, int horas_semana) : Professor(nome, matricula, idade)
{
    this->salario = salario;
    this->horas_semana = horas_semana;
}

ProfHorista::~ProfHorista(){}

void ProfHorista::setSalario(double salario){ this->salario = salario; }
double ProfHorista::getSalario() const{ return salario; }
void ProfHorista::setHoras(int horas_semana){ this->horas_semana = horas_semana; }
int ProfHorista::getHoras() const{ return horas_semana; }

ostream& operator<<(ostream& out, const ProfHorista& profHorista){
    out
    << "\nNome...........: " << profHorista.getNome()
    << "\nMatricula......: " << profHorista.getMatricula()
    << "\nIdade..........: " << profHorista.getIdade()
    << "\nSalario........: " << profHorista.salario
    << "\nHoras P/ Semana: " << profHorista.horas_semana << endl;

    return out;
}

int main(int argc, char const *argv[]){
    
    Professor prof("Jose Xavier", "1234-32455", 45);
    cout << "----------------------------------------";
    cout << prof;
    cout << "----------------------------------------";


    ProfDE profde("Carlos Soares", "13134-3423432", 34, 5000.0);
    cout << profde;
    cout << "----------------------------------------";

    ProfHorista profho("Sergio Alberto", "3223-43543", 56, 4625.0, 12);
    cout << profho;
    cout << "----------------------------------------" << endl;
    
    return 0;
}
