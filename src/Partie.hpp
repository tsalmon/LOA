#ifndef PARTIE_HPP
#define PARTIE_HPP
#include "Joueur.hpp"
#include "Jeu.hpp"
#include "Plateau.hpp"
class Partie{
private:
    Jeu *jeu;
    Joueur *joueurs;
    Plateau *plateau;    
  void operator=(Partie &l){};
  Partie(Partie &);
public:
  Partie(){}
  ~Partie(){};
  static Partie *getPartie();
  int joueTour ();
  void setJeu(Jeu *j);
  Plateau &getPlateau();
  Joueur *getJoueurs();
  int getNbJoueur();
  void affiche();  
};
#endif
