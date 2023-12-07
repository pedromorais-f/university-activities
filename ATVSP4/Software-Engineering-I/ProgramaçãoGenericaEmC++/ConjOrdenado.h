#include <iostream>
#include <vector>
#include "ConjNaoOrdenado.h"

using namespace std;

template<typename T>
class ConjOrdenado : public ConjNaoOrdenado<T> {

public:

    void adicionarElemento(T element){
        ConjNaoOrdenado<T> :: pushElemento(element);
        sort(this->begin(), this->end());
    }

};