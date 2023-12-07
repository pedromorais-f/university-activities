#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Estudante{
    string nome;
    int matricula;
    vector<int> turmas;
    vector<string> materias;
    float coeficiente;
public:
    Estudante(string="", int=0, float=0.0);
    ~Estudante();

    string getNome() const;
    void setNome(string);

    int getMatricula() const;
    void setMatricula(int);

    vector<int> getTurma() const;
    void setTurma(vector<int>);

    vector<string> getMaterias() const;
    void setMaterias(vector<string>);

    float getCoeficiente() const;
    void setCoeficiente(float);
};


#endif