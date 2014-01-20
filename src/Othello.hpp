#ifndef OTHELLO_HPP
#define OTHELLO_HPP
#include "Jeu.hpp"
#include "Partie.hpp"

class Othello : public Jeu{
  protected:
  Pion *pX; 
  Pion *pO; 
public:
  Othello();
  int get_j();
  virtual ~Othello();
  void affichage();
  virtual int fini();
  virtual bool peutJouer();
  virtual void newPartie ();  
};

#endif
