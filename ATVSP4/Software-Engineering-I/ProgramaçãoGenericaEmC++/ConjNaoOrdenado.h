#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class ConjNaoOrdenado{
    vector <T> conjunto;
public:
    ConjNaoOrdenado(){}
    ~ConjNaoOrdenado(){}

    void pushElemento(T elemento){
        this->conjunto.push_back(elemento);
    }
    
    int Count(){
        return this->conjunto.size();
    }

    T Sum(){
        T sum = 0;

        for(auto &elemento : this->conjunto){
            sum += elemento;
        }

        return sum;
    }

    double average(){
        T sum = Sum();
        int count = Count();

        double average;
        average = sum / count

        return average;
    }


};
