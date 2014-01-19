#include "Puissance4.hpp"

Puissance4::Puissance4(){
  cout << "lala" << endl;
  nbJoueur = 2;
  nbColonnes = 7;
  nbLignes = 6;
  PionFactory &factory=PionFactory::getInstance();
  newPartie();
}

Puissance4::~Puissance4(){
}

int Puissance4::fini(){
    return 0;
}

bool Puissance4::peutJouer(){
  return true;
}


void Puissance4::newPartie (){
  cout << "toto" << endl;
}

void Puissance4::affichage(){
  
}
