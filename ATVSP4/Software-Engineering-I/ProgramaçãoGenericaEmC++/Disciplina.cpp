#include "Disciplina.h"


Disciplina :: Disciplina(int qtdAlunos){
    this->qtdAlunos = qtdAlunos;
}
Disciplina :: ~Disciplina(){}

vector<string> Disciplina :: getProfessores() const{return this->professores;}
void Disciplina :: setProfessores(vector<string> professores){
    this->professores = professores;
}

vector<int> Disciplina :: getTurmas() const{return this->turmas;}
void Disciplina :: setTurmas(vector<int> turmas){
    this->turmas = turmas;
}

int Disciplina :: getQtdalunos() const{return this->qtdAlunos;}
void Disciplina :: setQtdAlunos(int qtdalunos){
    this->qtdAlunos = qtdAlunos;
}