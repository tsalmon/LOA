#include "Pion.hpp"


Pion::Pion(string nom){
    this->nom = nom;
}

void Pion::setJoueur(int j){
  joueur = j;
}

int Pion::getJoueur(){
    return this->joueur;
}

void Pion::setSymbole(char s){
  symbole = s;
}

char Pion::getSymbole() const{
  return symbole;
}

string Pion::getNom() const{
  return nom;
}

ostream &operator<<(ostream &os,const Pion &p) {
  if(p.getSymbole() == 0){
    os << 'O'; 
  } else {
    os << p.getSymbole();
  }
  return os;
}


