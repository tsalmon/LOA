#ifndef PARTIE_HPP
#define PARTIE_HPP
#include "Joueur.hpp"
#include "Jeu.hpp"
#include "Plateau.hpp"
class Partie{
private:
  Joueur *joueurs;
  Plateau *plateau;
  static Partie laPartie;
  int i;
public:
  int joueTour ();
  void victory (int);
  void defaite ();
  void egalite ();
  Partie(int nb_joueurs);
  Plateau& getPlateau ();
  static Partie getPartie();
};

#endif
