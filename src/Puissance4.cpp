#include "Puissance4.hpp"


Puissance4::Puissance4(){
  cout << "==== Puissance 4 ====" << endl;
  
  *pO = PionFactory::getInstance().getPion("O");
  pO->setJoueur(0);
  pO->setSymbole('O');
  *pX = PionFactory::getInstance().getPion("X");
  pX->setSymbole('X');
  pX->setJoueur(1);
  
  nbJoueur = 2;
  nbColonnes = 7;
  nbLignes = 6;

  Partie::getPartie()->setJeu(this);
}

int Puissance4::get_j(){
  return ((Partie::getPartie()->getJoueurs()->getCourrant() == 0) ? 49 : 65);
}

Puissance4::~Puissance4(){}

int Puissance4::fini(){
    return 0;
}

bool Puissance4::peutJouer(){
  return true;
}

void Puissance4::hasP4_sens(int i, int j, int *sens, bool *stop){
  if((not stop[0]) && i > -1 && j > -1 && i<getNbLignes() && j<getNbColonnes()){
    if(not HAS_PION(i, j)|| GET_CASE(i, j)->getPion()->getJoueur() !=get_j()){
      *stop = true;
    } else {
      (*sens)++;
    }
  } 
}

bool Puissance4::hasP4(int x, int y){
  int sens[8];
  bool stop[8];
  for(int i = 0 ; i < 8; i++){
    sens[i] = 0;
    stop[i] = false;
  }
  
  for(int i = 0; i < 4; i++){
    /* sens haut gauche */
    hasP4_sens(x-i, y-i, &(sens[0]), &(stop[0]));
    /* sens gauche */
    hasP4_sens(x, y-i, &(sens[1]), &(stop[1]));
    /* sens bas gauche */
    hasP4_sens(x+i, y-i, &(sens[2]), &(stop[2]));
    /* sens bas */
    hasP4_sens(x+i, y, &(sens[3]), &(stop[3]));
    /* sens bas droite */
    hasP4_sens(x+i, y+i, &(sens[4]), &(stop[4]));
    /* sens droite */
    hasP4_sens(x, y+i, &(sens[5]), &(stop[5]));
    /* sens haut droite */
    hasP4_sens(x-i, y+i, &(sens[6]), &(stop[6]));
    /* sens haut */
    hasP4_sens(x-i, y+i, &(sens[7]), &(stop[7]));
  }
  for(int i = 0; i < 4; i++){
    if(sens[i] + sens[i+4] -1 > 3){
      return true;
    } 
  }
  return false;
}

void Puissance4::newPartie (){
  Plateau *p = Partie::getPartie()->getPlateau();
  Joueur *j = Partie::getPartie()->getJoueurs();
  int choix_pos = 0;
    int i=0;
  j->next();
  do{
    j->next();
    cout << j->getCourrant()<< endl;
    affichage();
    do{
      i = 0;
      cout << "choissisez une position : " << endl;
      cin >> choix_pos;
      for(;i < nbLignes && not p->hasPion(i, choix_pos); i++){}
    }while(choix_pos < 0 || 
	   choix_pos > nbLignes || 
	   (i == 0 && p->hasPion(i, choix_pos)));
    i = (i==0)? 0 : i-1;
    if(j->getCourrant() == 0){
      p->mettrePionDansCase(pO, i, choix_pos);
    } else {
      p->mettrePionDansCase(pX, i, choix_pos);
    }
  }while(not hasP4(i, choix_pos));
  affichage();
  cout << "Le joueur " << j->getCourrant() << "a gagné "<<  endl; 
}

void Puissance4::affichage(){
  Plateau *p = Partie::getPartie()->getPlateau();
  for(int i = 0; i < nbLignes; i++){
    for(int j = 0; j< nbColonnes ; j++){
      if(p->hasPion(i, j)){
	switch(p->getCase(i, j)->getPion()->getJoueur()){
	case 49: cout << "O "; break;
	case 65: cout << "X "; break;
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
