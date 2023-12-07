#include "Estudante.h"


Estudante::Estudante(string nome, int matricula, float coeficiente){
    this-> nome = nome;
    this-> matricula = matricula;
    this-> coeficiente = coeficiente;
}
Estudante :: ~Estudante(){}


string Estudante :: getNome() const{return this->nome;}
void Estudante :: setNome(string nome){
    this->nome = nome;
}

int Estudante :: getMatricula() const{return this->matricula;}
void Estudante :: setMatricula(int matricula){
    this->matricula = matricula;
}

vector<int> Estudante :: getTurma() const{return this-> turmas;}
void Estudante :: setTurma(vector<int> turmas){
    this-> turmas = turmas;
}

vector<string> Estudante :: getMaterias() const{return this-> materias;}
void Estudante :: setMaterias(vector<string> materias){
    this-> materias = materias;
}

float Estudante :: getCoeficiente() const{return this->coeficiente;}
void Estudante :: setCoeficiente(float coefiente){
    this->coeficiente = coeficiente;
}