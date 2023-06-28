#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NotaFiscal{
    string num;
    string descricao;
    int quantidade;
    double preco;
public:
    NotaFiscal(string="", string="", int=0, double=0.0);
    ~NotaFiscal();
    
    void setNum(string);
    string getNum() const;

    void setDescricao(string);
    string getDescricao() const;

    void setQuantidade(int);
    int getQuantidade() const;

    void setPreco(double);
    double getPreco() const;

    double getTotalNota(const vector <NotaFiscal>);

    friend ostream& operator<<(ostream&, const NotaFiscal&);
};

NotaFiscal::NotaFiscal(string num, string descricao, int quantidade, double preco){
    this->num = num;
    this->descricao = descricao;
    this->quantidade = quantidade;
    this->preco = preco;
}
NotaFiscal::~NotaFiscal(){}

void NotaFiscal :: setNum(string num){
    this->num = num;
}
string NotaFiscal :: getNum() const{
    return this->num;
}

void NotaFiscal :: setDescricao(string descricao){
    this->descricao = descricao;
}
string NotaFiscal :: getDescricao() const{
    return this->descricao;
}

void NotaFiscal :: setQuantidade(int quantidade){
    this->quantidade = quantidade;
}
int NotaFiscal :: getQuantidade() const{
    return this->quantidade;
}

void NotaFiscal :: setPreco(double preco){
    this->preco = preco;
}
double NotaFiscal :: getPreco() const{
    return this->preco;
}

double NotaFiscal :: getTotalNota(const vector<NotaFiscal> notas){
    double total_preco = 0.0;
    for (auto nota : notas){
        total_preco += (double(nota.getQuantidade()) * nota.getPreco());
    }
    return total_preco;
}

ostream& operator<<(ostream& out, const NotaFiscal& nota){
    out 
    << "Numero....: " << nota.getNum() << endl
    << "Descricao.: " << nota.getDescricao() << endl
    << "Quantidade: " << nota.getQuantidade() << endl
    << "Preco.....: " << nota.getPreco() << endl;

    return out;  
}


int main(int argc, char const *argv[]){
    
    NotaFiscal nota1("001", "Test1", 3, 223.45);
    NotaFiscal nota2("343", "Test2", 3,5676.34);


    vector<NotaFiscal> notas;
    notas.push_back(nota1);
    notas.push_back(nota2);
    double total;

    total = nota2.getTotalNota(notas);

    cout << nota1 << endl;
    cout << nota2 << endl;
    cout << "Total: " << total << endl;

    return 0;
}
