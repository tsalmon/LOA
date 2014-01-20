#include "Othello.hpp"

int Othello::get_j(){
    return ((Partie::getPartie()->getJoueurs()->getCourrant() == 0) ? 0 : 81);
}

Othello::Othello(){
  cout << "==== Othello ==== " << endl;
  
  nbJoueur=2;
  nbLignes=8;
  nbColonnes=8;
  PionFactory &factory=PionFactory::getInstance();
  pO = factory.getPion("blanc");
  pO->setSymbole('O');
  pX = factory.getPion("noir");
  pX->setSymbole('X');
  pX->setJoueur(1);
  pO->setJoueur(0);
  Partie::getPartie()->setJeu(this);
}

Othello::~Othello(){
}

int Othello::fini(){
  return 0;
}
bool Othello::peutJouer(){
  return true;
}
void Othello::newPartie(){
  Plateau *p = Partie::getPartie()->getPlateau();
  Joueur *j = Partie::getPartie()->getJoueurs();
  p->mettrePionDansCase(*pO, 3, 3); 
  p->mettrePionDansCase(*pO, 4, 4); 
  p->mettrePionDansCase(*pX, 3, 4); 
  p->mettrePionDansCase(*pX, 4, 3); 
  
  j->next();
  do{
    j->next();
    affichage();
    break;
  }while(not p->isFull());
}

void Othello::affichage(){
  Plateau *p = Partie::getPartie()->getPlateau();
  for(int i = 0; i < nbLignes; i++){
    for(int j = 0; j< nbColonnes ; j++){
      if(p->hasPion(i, j)){
	switch(p->getCase(i, j)->getPion()->getJoueur()){                       
	case 0: cout << "O "; break;
	case 81: cout << "X "; break;
	}
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
