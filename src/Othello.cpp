#include "Othello.hpp"

#define GET_PLATEAU() (Partie::getPartie()->getPlateau())

int Othello::get_j(){
  return (Partie::getPartie()->getJoueurs()->getCourrant());
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

void Othello::capture(int x, int y, int d){
  switch(d){
  case 1: x++; y++ ; break;
  case 2: x++; break;
  case 3: x++; y--; break;;
  case 4: y--; break;;
  case 5: x--; y--; break;
  case 6: x--; break;;
  case 7: x--; y++; break;;
  case 8: y++; break;
  }
  if(GET_CASE(x, y)->getPion() == NULL){ // piont de depart
    return ;
  }
  GET_PLATEAU()->mettrePionDansCase((get_j() == 0)? pO : pX, x, y);
  capture(x, y, d);
}

/*call by: coupValide: 1 = pion ennemi, 2 = pion joueur, 3 = vide*/
int Othello::trouverPion(int x, int y, int e, int d){
  if(!DANS_JEU(x, y) || not HAS_PION(x, y)){
    return 3;
  }
  if(get_j() == GET_CASE(x, y)->getPion()->getJoueur() && e == 1){
    capture(x, y, d);
    return 2;
  }
  return 1;
}

bool Othello::coupValide(int x, int y){
  int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0, d8 = 0, k = 1;
  do{
    d1 = (d1 < 2) ? trouverPion(x-k, y-k, d1, 1) : d1;
    d2 = (d2 < 2) ? trouverPion(x-k, y  , d2, 2) : d2;
    d3 = (d3 < 2) ? trouverPion(x-k, y+k, d3, 3) : d3;
    d4 = (d4 < 2) ? trouverPion(x  , y+k, d4, 4) : d4;
    d5 = (d5 < 2) ? trouverPion(x+k, y+k, d5, 5) : d5;
    d6 = (d6 < 2) ? trouverPion(x+k, y  , d6, 6) : d6;
    d7 = (d7 < 2) ? trouverPion(x+k, y-k, d7, 7) : d7;
    d8 = (d8 < 2) ? trouverPion(x , y-k, d8, 8) : d8;
    k++;
  }
  while(d1<2 || d2<2 || d3<2 || d4<2 || d5<2 || d6<2 || d7<2 || d8<2);
  return (d1==2 || d2==2 || d3==2 || d4==2 || d5==2 || d6==2 || d7==2 || d8==2);
}

bool Othello::peutJouer(){
  return true;
}
void Othello::newPartie(){
  Plateau *p = Partie::getPartie()->getPlateau();
  Joueur *j = Partie::getPartie()->getJoueurs();
  int choix_x, choix_y;
  p->mettrePionDansCase(pO, 3, 3); 
  p->mettrePionDansCase(pO, 4, 4); 
  p->mettrePionDansCase(pX, 3, 4); 
  p->mettrePionDansCase(pX, 4, 3); 
  
  j->next();
  do{
    j->next();
    cout << "Joueur " << j->getCourrant() << endl;
    affichage();
    do{
      cout << "choisissez une position : " << endl;
      cin >> choix_x >> choix_y;
    }while(choix_x < 0 || choix_y < 0 || choix_x > nbLignes || 
	   choix_y > nbColonnes || not coupValide(choix_x, choix_y));
    GET_PLATEAU()->mettrePionDansCase((get_j() == 0)? pO : pX, choix_x, choix_y);
  }while(not p->isFull());
}

void Othello::affichage(){
  Plateau *p = Partie::getPartie()->getPlateau();
  for(int i = 0; i < nbLignes; i++){
    cout << i << " " ;
    for(int j = 0; j< nbColonnes ; j++){
      if(p->hasPion(i, j)){
	switch(p->getCase(i, j)->getPion()->getJoueur()){                       
	case 0: cout << "O "; break;
	case 1: cout << "X "; break;
	}
      } else {
	cout << ". ";
      }
    }
    cout << endl;
  }
  cout << "  ";
  for(int j = 0; j< nbColonnes; j++){
    cout << j << " " ;
  }
  cout << endl;
}
