#ifndef P4_HPP
#define P4_HPP
#include "Jeu.hpp"
class Puissance4: public Jeu{
public:
  Puissance4(){};
  ~Puissance4(){};
  int fini();
  bool peutJouer();
  void newPartie ();
  int getNbLignes();
  int getNbColonnes();
  int getNbJoueur();
  //int **deplacementPossible (int x, int Y, string Nom);
  string* getListePions ();
  
};

#endif
