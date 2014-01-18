#ifndef PARTIE_HPP
#define PARTIE_HPP
#include "Joueur.hpp"
#include "Jeu.hpp"
#include "Plateau.hpp"
class Partie{
private:
    Jeu jeu;
  Joueur *joueurs;
  Plateau *plateau;
  static Partie laPartie;
  int i;
public:
  int joueTour ();
  Partie(Jeu j);
  Plateau& getPlateau ();
  static Partie* getPartie();
  Joueur getJoueurs(){return joueurs;}
};

#endif
