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
  virtual ~Othello();
  virtual void affichage();
  virtual int fini();
  virtual bool peutJouer();
  virtual void newPartie ();  
};

#endif
