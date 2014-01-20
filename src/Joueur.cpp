#include "Joueur.hpp"


Joueur::Joueur(int nbJoueurs){
  nb_Joueurs=nbJoueurs;
  m_current=0;
}

int Joueur::getCourrant(){
    return m_current;
}

int Joueur::getNbJoueur(){
    return nb_Joueurs;
}

void Joueur::next(){
  m_current = (m_current + 1) % nb_Joueurs;
}
