#ifndef PARTIE_HPP
#define PARTIE_HPP
#include "Joueur.hpp"
#include "Jeu.hpp"
#include "Plateau.hpp"

#define HAS_PION(i, j) (Partie::getPartie()->getPlateau()->hasPion(i, j))
#define GET_CASE(i, j) (Partie::getPartie()->getPlateau()->getCase(i, j))


class Partie{
private:
  Jeu *jeu;
  Joueur *joueurs;
  Plateau *plateau;
  void operator=(Partie &){};
  Partie(Partie &);
  Partie(){}
  ~Partie();
public:
  static Partie *getPartie();
  int joueTour ();
  void setJeu(Jeu *j);
  Plateau *getPlateau();
  Joueur *getJoueurs();
  int getNbJoueur();
  void affiche();
};
#endif
