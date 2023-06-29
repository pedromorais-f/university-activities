#include <iostream>
#include <vector>

using namespace std;

class Laurasiatheria{
public:
    virtual void som() = 0;
};

class Carnivora : public Laurasiatheria{
public:
    virtual void som() = 0;
};

class Perissodactyla : public Laurasiatheria{
public:
    virtual void som() = 0;
};

class Artiodactyla : public Laurasiatheria{
public:
    virtual void som() = 0;
};

class Cao : public Carnivora{
public:
    void som(){
        cout << "CAO....." << endl;
    }
};

class Cavalo : public Perissodactyla{
public:
    void som(){
        cout << "CAVALO....." << endl;
    }
};

class Porco : public Artiodactyla{
public:
    void som(){
        cout << "PORCO....." << endl;
    }
};


int main(int argc, char const *argv[]){
    
    vector<Laurasiatheria*> animais;

    Cao *c1 = new Cao;
    Cavalo *cv = new Cavalo;
    Porco *p1 = new Porco;

    animais.push_back(c1);
    animais.push_back(cv);
    animais.push_back(p1);

    for (auto *animal : animais){
        if(typeid(*animal) == typeid(class Cao))
            dynamic_cast<Cao*>(animal)->som();
        else if(typeid(*animal) == typeid(class Cavalo))
            dynamic_cast<Cavalo*>(animal)->som();
        else
            dynamic_cast<Porco*>(animal)->som();
    }

    delete c1;
    delete cv;
    delete p1;
    
    return 0;
}
