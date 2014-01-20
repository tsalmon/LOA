#include "Plateau.hpp"
#include <vector>
#include "Partie.hpp"

Plateau::Plateau(int x, int y){
  unsigned a = 0, b = 0;
  m_nbColonnes=x;
  m_nbLignes=y;
  m_cases = new Case**[x];
  for (int i=0;i< m_nbColonnes; i++){
    m_cases[i] = new Case*[y];
    for(int j=0;j< m_nbLignes; j++){
      m_cases[i][j] = new Case(a++, b++);
    }
  }
}

Case* Plateau::getCase(int x,int y){
  return m_cases[x][y];
}

bool Plateau::isEmpty(){
  for (int i=0;i<m_nbColonnes;i++){
    for(int j=0;j<m_nbLignes;j++){
      if((*m_cases[i][j]).getPion()!=NULL){
	return false;
      }
    }
  }
  return true;
}

bool Plateau::isFull(){
  for (int i=0;i<m_nbColonnes;i++){
    for(int j=0;j<m_nbLignes;j++){
      if((*m_cases[i][j]).getPion()==NULL){
	return true;
      }
    }
  }
  return false;
}

bool Plateau::hasPion(Pion *p){
  for (int i=0;i<m_nbColonnes;i++){
    for(int j=0;j<m_nbLignes;j++){
      if((*m_cases[i][j]).getPion()==p){
	return true;
      }
    }
  }
  return false;
}

bool Plateau::hasPion(int x, int y){
  return ((*m_cases[x][y]).hasPion());
}

void Plateau::mettrePionDansCase(Pion &pion, unsigned int x, unsigned int y){
  this->m_cases[x][y]->addPion(pion);
}

Pion *Plateau::pionDansCase(unsigned int x, unsigned int y){
    return this->m_cases[x][y]->getPion();
}

void Plateau::effacerPionDeCase(unsigned int x, unsigned y){
    this->m_cases[x][y]->retirePion();
}

ostream &operator<<(ostream &os,const Plateau &b) {

    for(int i = 0; i<b.m_nbLignes; ++i){
        os<<i<<" | ";
        for (int j = 0; j<b.m_nbColonnes; ++j) {
            if(!b.m_cases[i][j]->getPion())
            {
                os << "_ ";
            } else {
                os << *(b.m_cases[i][j]->getPion())<<" ";
            }
        }
        os<<endl;;
    }
    for (int j = 0; j<b.m_nbColonnes+2; ++j) {
        os << "__";
    }
    os<<endl<<"    ";
    for (int j = 0; j<b.m_nbColonnes; ++j) {
        os << j<<" ";
    }
    return os<<endl;
}

int Plateau::morePions(){
  int nbjoueurs=Partie::getPartie()->getNbJoueur();
  int *joueurs = new int[nbjoueurs];

  for (int k=0; k<nbjoueurs;k++){
        joueurs[k]=0;}

  for(int i = 0 ; i < m_nbColonnes; i++){
    for(int j = 0 ; j < m_nbLignes; j++){
      if (m_cases[i][j]!=NULL){
        joueurs[m_cases[i][j]->getPion()->getJoueur()]++;
      }
    }
  }
  int maxi=0;
  int second=0;
  int jmaxi;
  for (int k=0; k<nbjoueurs;k++){
        if(joueurs[k]>= maxi){
            second=maxi;
            maxi=joueurs[k];
            jmaxi=k;
        }
  }
  return (maxi==second) ? -1 : jmaxi;
}

int Plateau::get_sizeX(){
  return m_nbLignes;
}

int Plateau::get_sizeY(){
  return m_nbColonnes;
}
