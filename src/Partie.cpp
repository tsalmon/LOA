#include "Partie.hpp"


Partie::Partie(){}
Partie::Partie(Partie &l){}
void Partie::operator=(Partie &l){}

int Partie::joueTour (){
    jeu->peutJouer();
    joueurs->next();
    int fin=jeu->fini();
    if (fin>=0){
        return fin;
    }
    joueurs->next();
    return joueTour();
}

void Partie::setJeu(Jeu *j){
    this->jeu = j;
    plateau = new Plateau(jeu->getNbColonnes(), jeu->getNbLignes());
    joueurs = new Joueur(jeu->getNbJoueur());
}

Partie *Partie::getPartie(){
    static Partie instance;
    return &instance;
}

Plateau &Partie::getPlateau(){
  return *plateau;
}

Joueur *Partie::getJoueurs(){
    return joueurs;
}
