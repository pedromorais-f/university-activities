#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Disciplina{
    vector<string> professores;
    vector<int> turmas;
    int qtdAlunos;
public:
    Disciplina(int=0);
    ~Disciplina();

    vector<string> getProfessores() const;
    void setProfessores(vector<string>);

    vector<int> getTurmas() const;
    void setTurmas(vector<int>);

    int getQtdalunos() const;
    void setQtdAlunos(int);
};





#endif