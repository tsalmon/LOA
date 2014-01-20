#ifndef P4_HPP
#define P4_HPP
#include "Jeu.hpp"
#include "Partie.hpp"
class Puissance4: public Jeu{
protected:
  Pion *pX; 
  Pion *pO; 
public:
  Puissance4();
  bool hasP4(int, int);
  void hasP4_sens(int i, int j, int *sens, bool *stop);
  virtual ~Puissance4();
  virtual void affichage();
  virtual int fini();
  virtual bool peutJouer();
  virtual void newPartie ();  
};

#endif
