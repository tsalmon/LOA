#include "Plateau.hpp"
#include <vector>
#include "Partie.hpp"

Plateau::Plateau(int x, int y){
  m_nbColonnes=x;
  m_nbLignes=y;
  for (int i=0;i< m_nbLignes; i++){
      vector<Case> cell;
      this->m_cases.push_back(cell);
    for(int j=0;j< m_nbColonnes; j++){
        this->m_cases[i].push_back(Case(i, j));
        m_casesLibres.push_back(this->m_cases[i][j]);
    }
  }
}

Plateau::~Plateau(){
    m_cases.clear();
    vector< std::vector<Case> >(m_cases).swap(m_cases);
    
    m_casesLibres.clear();
    vector<Case>(m_casesLibres).swap(m_casesLibres);
}


Case* Plateau::getCase(int x,int y){
  return &m_cases[x][y];
}

bool Plateau::isEmpty(){
  for (int i=0;i<m_nbColonnes;i++){
    for(int j=0;j<m_nbLignes;j++){
      if((m_cases[i][j]).getPion()!=NULL){
          return false;
      }
    }
  }
  return true;
}

bool Plateau::isFull(){
  for (int i=0;i<m_nbColonnes;i++){
    for(int j=0;j<m_nbLignes;j++){
      if((m_cases[i][j]).getPion()==NULL){
          return false;
      }
    }
  }
  return true;
}

bool Plateau::hasPion(Pion *p){
  for (int i=0;i<m_nbColonnes;i++){
    for(int j=0;j<m_nbLignes;j++){
      if((m_cases[i][j]).getPion()==p){
	return true;
      }
    }
  }
  return false;
}

bool Plateau::hasPion(int x, int y){
    if ((m_cases[x][y]).hasPion()) {
        return true;
    }
    return false;
}

void Plateau::mettrePionDansCase(Pion *pion, unsigned int x, unsigned int y){
    this->m_cases[x][y].addPion(pion);
    for(std::vector<Case>::iterator it = m_casesLibres.begin(); it != m_casesLibres.end(); ++it) {
        if((*it).getX() == x && (*it).getY() == y){
            m_casesLibres.erase(it);
            break;
        }
    }
}


Pion *Plateau::pionDansCase(unsigned int x, unsigned int y){
    return this->m_cases[x][y].getPion();
}

void Plateau::effacerPionDeCase(unsigned int x, unsigned y){
    this->m_cases[x][y].retirePion();
    this->m_casesLibres.push_back(m_cases[x][y]);
}

ostream &operator<<(ostream &os,const Plateau &b) {

    for(int i = 0; i<b.m_nbColonnes; ++i){
        os<<i<<" | ";
        for (int j = 0; j<b.m_nbLignes; ++j) {
            if(!b.m_cases[i][j].getPion())
            {
                os << "_ ";
            } else {
                /*if(b.m_cases[i][j].getPion()->getSymbole() == ''){
                    int k = 0;
                }*/
                os << *(b.m_cases[i][j].getPion())<<" ";
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
      if (m_cases[i][j].hasPion()){
        joueurs[m_cases[i][j].getPion()->getJoueur()]++;
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
