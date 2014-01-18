#include "Partie.hpp"

int Partie::joueTour (){
  joueurs.next();
}

void Partie::victory (int){}
void Partie::defaite (){}
void Partie::egalite (){}

Partie::Partie(int nb_joueurs){
  plateau = new Plateau();
  joueurs = new Joueur[nb_joueurs];
  for(int i = 0; i < nb_joueurs; i++){
    joueurs[i] = new Joueur();
  }
}

Plateau& Partie::getPlateau (){
  return plateau;
}

Partie Partie::getPartie(){
  static Partie instance;
  return instance;
}
