#include "Puissance4.hpp"

#define GET_CURRENT_PLAYER() (->getCourrant())
#define NEXT_PLAYER() (Partie::getPartie()->getJoueurs()->next())


Puissance4::Puissance4(){
  cout << "==== Puissance 4 ====" << endl;
  PionFactory &factory=PionFactory::getInstance();  
  pO = factory.getPion("O");
  //pO->setJoueur(0);
  //pO->setSymbole('O');
  pX = factory.getPion("X");
  //pX->setSymbole('X');
  //pX->setJoueur(1);
  nbJoueur = 2;
  nbColonnes = 7;
  nbLignes = 6;
  Partie::getPartie()->setJeu(this);
}

Puissance4::~Puissance4(){}

int Puissance4::fini(){
    return 0;
}

bool Puissance4::peutJouer(){
  return true;
}

bool Puissance4::hasP4(){
  return false;
}

void Puissance4::newPartie (){
  Plateau *p = Partie::getPartie()->getPlateau();
  Joueur *j = Partie::getPartie()->getJoueurs();
  int choix_pos = 0;
  j->next();
  do{
    int i=0;
    j->next();
    affichage();
    do{
      cout << "choissisez une position : " << endl;
      cin >> choix_pos;
    }while(choix_pos < 0 || choix_pos >= nbLignes);
    for(;i < nbLignes && not p->hasPion(i, choix_pos); i++){}
    p->mettrePionDansCase(*pX, i, choix_pos);
  }while(hasP4());
  cout << "fin" << endl;
}

void Puissance4::affichage(){
  Plateau *p = Partie::getPartie()->getPlateau();
  cout << "col : " << nbColonnes << ", line : " << nbLignes << endl;
  for(int i = 0; i < nbLignes; i++){
    for(int j = 0; j< nbColonnes ; j++){
      if(p->hasPion(i, j)){
	cout << "x" << " ";
      } else {
	cout << ". ";
      }
    }
    cout << endl;
  }
  for(int j = 0; j< nbColonnes; j++){
    cout << j << " " ;
  }
  cout << endl;
}
