#include "Partie.hpp"

int Partie::joueTour (){
    jeu.peutJouer();
    joueurs.next();
    int fin=jeu.fini();
    if (fin>=0){
        return fin
    }
    joueurs.next();
    return joueTour();
}

Partie::Partie(Jeu j){
    jeu = j;
    plateau = new Plateau(jeu.getNbColonnes(), jeu.getNbLignes());
    joueurs = new Joueur(jeu.getNbJoueur());

}

Plateau& Partie::getPlateau (){
  return plateau;
}

Partie Partie::getPartie(){
  return &instance;
}

Partie Partie::getJoueurs(){
  return joueurs;
}
