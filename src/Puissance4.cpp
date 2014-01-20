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
  //Partie::getPartie()->setJeu(this);
}

Puissance4::~Puissance4(){
}

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
    j->next();
    affichage();
    cout << "choissisez une position : " << endl;
    cin >> choix_pos;
    if(choix_pos > -1 && choix_pos < nbLignes){
      int i=0;
      /*
      for(;i < nbLignes && not p->hasPion(i, choix_pos); i++){
	cout << i << endl;
	}
      */
      //p->mettrePionDansCase(*pX, i, choix_pos);
    }
  }while(not hasP4());
  delete(p);
  delete(j);
}

void Puissance4::affichage(){
  Plateau *p = Partie::getPartie()->getPlateau();
  for(int i = 0; i < nbLignes; i++){
    for(int j = 0; j< nbColonnes; j++){
      if(p->hasPion(i, j)){
	cout << p->pionDansCase(i, j) << " ";
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
