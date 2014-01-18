#ifndef PARTIE_HPP
#define PARTIE_HPP
#include "Joueur.hpp"
#include "Jeu.hpp"
#include "Plateau.hpp"
class Partie{
private:
  Joueur *joueurs;
  Plateau plateau;
  static Partie laPartie;
public:
  void joueTour ();
  void victory (int);
  void defaite ();
  void egalite ();
  Partie();
  Plateau& getPlateau ();
};

#endif
