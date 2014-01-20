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

void capture(int x, int y, int j, int d){
  if(jeu[x][y] == '.'){
    return ;
  }
  jeu[x][y] = PION_JOUEUR(j);
  switch(d){
  case 1: capture(x+1, y+1, j, d); break;
  case 2: capture(x+1, y, j, d); break;
  case 3: capture(x+1, y-1, j, d); break;;
  case 4: capture(x, y-1, j, d); break;;
  case 5: capture(x-1, y-1, j, d); break;
  case 6: capture(x-1, y, j, d); break;;
  case 7: capture(x-1, y+1, j, d); break;;
  case 8: capture(x, y+1, j, d); break;
  }
}
int trouver(int x, int y, int j, int e,int d){
  if(!DANS_JEU(x, y) || jeu[x][y] == '.'){
    return 3;
  }
  if((PION_JOUEUR(j) == jeu[x][y]) && e == 1){
    capture(x, y, j, d);
    return 2;
  }
  return 1;
}
int peutJouer(int x, int y, int j){
  int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0, d8 = 0, k = 1;
  do{
    d1 = (d1 < 2) ? trouver(x-k, y-k, j, d1, 1) : d1;
    d2 = (d2 < 2) ? trouver(x-k, y  , j, d2, 2) : d2;
    d3 = (d3 < 2) ? trouver(x-k, y+k, j, d3, 3) : d3;
    d4 = (d4 < 2) ? trouver(x  , y+k, j, d4, 4) : d4;
    d5 = (d5 < 2) ? trouver(x+k, y+k, j, d5, 5) : d5;
    d6 = (d6 < 2) ? trouver(x+k, y  , j, d6, 6) : d6;
    d7 = (d7 < 2) ? trouver(x+k, y-k, j, d7, 7) : d7;
    d8 = (d8 < 2) ? trouver(x , y-k, j, d8, 8) : d8;
    k++;
  }
  while(d1<2 || d2<2 || d3<2 || d4<2 || d5<2 || d6<2 || d7<2 || d8<2);
  return (d1==2 || d2==2 || d3==2 || d4==2 || d5==2 || d6==2 || d7==2 || d8==2);
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