#include "Pion.hpp"


Pion::Pion(string nom, char symbole){
    this->nom = nom;
    this->symbole = symbole;
}

void Pion::setJouer(int j){
    this->jouer = j;
}

int Pion::getJouer(){
    return this->jouer;
}

void Pion::setSymbole(char s){
    this->symbole = s;
}

char Pion::getSymbole() const{
    return this->symbole;
}

ostream &operator<<(ostream &os,const Pion &p) {
    os << p.getSymbole();
    return os;
}
