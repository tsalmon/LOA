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

Partie::Partie(Jeu const &j){
    jeu = j;
    plateau = new Plateau(jeu.getNbColonnes(), jeu.getNbLignes());
    joueurs = new Joueur(jeu.getNbJoueur());

}


static Partie* Partie::getPartie(){
  return &instance;
}
