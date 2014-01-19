#include "Partie.hpp"

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
    joueurs = new Joueur(j->getNbJoueur());
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

int Partie::getNbJoueur(){
    return 0;
}

void Partie::affiche(){
  
}
