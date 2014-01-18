#include "Joueur.hpp"


Joueur::Joueur(int nbJoueurs){
    nb_Joueurs=nbJoueurs;
    m_current=1;
}

int Joueur::getCourrant(){
    return m_current;
}

int Joueur::getNbJoueur(){
    return nb_Joueurs;
}

void Joueur::next(){
    if (m_current==nb_Joueurs){
        m_current=1;
    }
    else{
        m_current++;
    }
}
