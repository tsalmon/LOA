#include "Plateau.hpp"
#include <vector>

Plateau::Plateau(int x, int y){
  m_nbColonnes=x;
  m_nbLignes=y;
  //m_cases = new Cases[x];
  /*
    for (int i=0;i< m_nbColonnes; i++){
    for(int j=0;j< m_nbLignes; j++){
    m_cases[i][j]=new Cases(m_nbColonnes,m_nbLignes);
    }
    }
  */
}

Cases Plateau::getCase(int x,int y){
  return m_cases[x][y];
}

bool Plateau::isEmpty(){
  for (int i=0;i<m_nbColonnes;i++){
    for(int j=0;j<m_nbLignes;j++){
      if(m_cases[i][j].getPion()!=NULL){
	return false;
      }
    }
  }
  return true;
}

bool Plateau::isFull(){
  for (int i=0;i<m_nbColonnes;i++){
    for(int j=0;j<m_nbLignes;j++){
      if(m_cases[i][j].getPion()==NULL){
	return true;
      }
    }
  }
  return false;
}

bool Plateau::hasPion(Pion *p){
  for (int i=0;i<m_nbColonnes;i++){
    for(int j=0;j<m_nbLignes;j++){
      if(m_cases[i][j].getPion()==p){
	return true;
      }
    }
  }
  return false;
}


int Plateau::morePions(){
  /* WHATWHATWHATWHAT
  vector<Pions> pions(0);
  vector<int> nbpion(0);
  Pion current;
  bool trouve;
  for (int i=0;i<m_nbColonnes;i++){
    for(int j=0;j<m_nbLignes;j++){
      current=m_cases[i][j]
	for(int k=0;k<pions.size();k++){
	  if(current.getPion()==pions[k]){
	    nbpion[k]++;
	    trouve=true;
	  }
	}
      if(trouve==false){
	pions.push_back(current);
	nbpion.push_back(1);
      }
      trouve=false
        }
  }
  int maxi=0;
  int joueur_associe=0;
  for(int k=0;k<pions.size();k++){
    if(nbpion[k]>maxi){
      maxi=nbpion[k];
      joueur_associe=pions[k].getJoueur();
    }
  }
  for(int k=0;k<pions.size();k++){
    if(nbpion[k]==maxi and joueur_associe!=pions[k].getJoueur(){
        return -1;
      }
      }
    return joueur_associe;
  }
  */
  
  for(int i = 0 ; i < m_nbColonnes; i++){
    for(int j = 0 ; j < m_nbLignes; j++){
      
    }
  }
  return 0;
}
