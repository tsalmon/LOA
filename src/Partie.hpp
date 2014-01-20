#ifndef PARTIE_HPP
#define PARTIE_HPP
#include "Joueur.hpp"
#include "Jeu.hpp"
#include "Plateau.hpp"

#define HAS_PION(i, j) (Partie::getPartie()->getPlateau()->hasPion(i, j))
#define GET_CASE(i, j) (Partie::getPartie()->getPlateau()->getCase(i, j))
#define GET_J() \
  ((Partie::getPartie()->getJoueurs()->getCourrant() == 0) ? 49 : 65)


class Partie{
private:
  Jeu *jeu;
  Joueur *joueurs;
  Plateau *plateau;
  void operator=(Partie &){};
  Partie(Partie &);
public:
  Partie(){}
  ~Partie(){};
  static Partie *getPartie();
  int joueTour ();
  void setJeu(Jeu *j);
  Plateau *getPlateau();
  Joueur *getJoueurs();
  int getNbJoueur();
  void affiche();
};
#endif
