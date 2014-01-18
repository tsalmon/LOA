#include "Pion.hpp"

Pion::Pion(string nom){
    this->nom = nom;
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

char Pion::getSymbole(){
    return this->symbole;
}